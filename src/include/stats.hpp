#ifndef __SPARSE__STATS_HPP__
#define __SPARSE__STATS_HPP__

#include <cstdlib>

struct Stats
{
	size_t total_read = 0;
	size_t total_written = 0;
	size_t total_saved = 0;
	void print() const;
};

#endif
