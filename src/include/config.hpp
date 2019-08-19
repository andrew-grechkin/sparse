#ifndef __SPARSE__CONFIG_HPP__
#define __SPARSE__CONFIG_HPP__

#include <cstddef>

struct Config
{
	static Config& get();

    size_t verbose = 0;
    size_t buf_size = 0;
    char *input_file = nullptr;
    char *file = nullptr;

    int parse(int argc, char ** argv);

	Config(const Config&) = delete;
	void operator= (const Config&) = delete;

private:
	Config() {}
};

#endif
