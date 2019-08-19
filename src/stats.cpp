#include "stats.hpp"

#include <cstdio>

void Stats::print() const
{
	std::printf("Read    total: %lu bytes\n", total_read);
	std::printf("Saved   total: %lu bytes\n", total_saved);
	std::printf("Written total: %lu bytes\n", total_written);
}
