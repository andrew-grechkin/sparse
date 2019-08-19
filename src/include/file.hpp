#ifndef __SPARSE__FILE_HPP__
#define __SPARSE__FILE_HPP__

#include <cstdlib>

class File
{
	public:
		~File();
		File(const char* path);
		void save_sparce_file(int src);
		void save_sparce_file(int src, int buf_size);
		size_t current_offset() const;

	private:
		int fd;
};

#endif
