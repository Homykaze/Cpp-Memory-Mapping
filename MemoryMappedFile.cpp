/// Implementations for the general purpose MemoryMappedFile

#include "MemoryMappedFile.hpp"

namespace projectname 
{
	/// Constructor definition.
	MemoryMappedFile::MemoryMappedFile(unsigned int handle, unsigned int size)
		:mapView(this->map(handle)), size_(size){}

	/// Map function definition.
	void* MemoryMappedFile::map(unsigned int handle)
	{
		void* map = ::mmap(nullptr, this->size(), PROT_READ | PROT_WRITE, MAP_SHARED, handle, 0);
		if (map == MAP_FAILED) 
		{
			throw std::runtime_error("Unable to memory map file contents.");
		}
		return static_cast<void*>(map);
	}

	/// Size function definition.
	int MemoryMappedFile::size() const noexcept
	{
		return this->size_;
	}
}