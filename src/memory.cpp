#include "memory.hpp"

#include <cstring>

bool is_memory_dirty(const void* buf, size_t size)
{
	auto ptr = static_cast<const char*>(buf);
	return *ptr || std::memcmp(ptr, ptr + 1, size - 1);
}
