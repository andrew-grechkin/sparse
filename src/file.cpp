#include "config.hpp"
#include "file.hpp"
#include "stats.hpp"
#include "memory.hpp"

#include <cstdlib>
#include <cstdio>
#include <err.h>
#include <unistd.h>
#include <fcntl.h>

File::~File()
{
	if (close(fd))
		warn("Unable to properly close destination file");
}

File::File(const char* path)
{
	auto mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	fd = open(path, O_WRONLY | O_CREAT | O_EXCL, mode);

	if (fd == -1)
		err(EXIT_FAILURE, "Unable to create file '%s'", path);
}

void File::save_sparce_file(int src)
{
	auto& config = Config::get();

	auto buf = malloc(config.buf_size);
	if (!buf)
		err(EXIT_FAILURE, "Unable to create buffer");

	auto stats = Stats();
	while (true) {
		auto bytes_read = read(src, buf, config.buf_size);

		if (bytes_read == 0) {
			break;
		} else if (bytes_read < 0) {
			err(EXIT_FAILURE, "Unable to read data from source");
		}

		stats.total_read += bytes_read;
		if (is_memory_dirty(buf, bytes_read)) {
			auto bytes_written = write(fd, buf, bytes_read);
			if (bytes_written != bytes_read) {
				err(EXIT_FAILURE, "Unable to write into destination file");
			}
			stats.total_written += bytes_written;
		} else {
			lseek(fd, bytes_read, SEEK_CUR);
			ftruncate(fd, current_offset());
			stats.total_saved += bytes_read;
		}
	}

	if (config.verbose) {
		printf("Buffer used:   %ld bytes\n", config.buf_size);
		stats.print();
	}
}

size_t File::current_offset() const
{
	return lseek(fd, 0, SEEK_CUR);
}
