#include "config.hpp"
#include "file.hpp"

#include <cstdio>
#include <error.h>
#include <unistd.h>
#include <err.h>

int main(int argc, char **argv)
{
	auto& config = Config::get();

	auto err = config.parse(argc, argv);
	if (!err) {
		auto src = 0;
		if (config.input_file) {
		}

		auto dst = File(config.file);
		dst.save_sparce_file(src);

		if (src && close(src))
			::err(EXIT_FAILURE, "Unable to close source");

		return EXIT_SUCCESS;
	}

	return err;
}
