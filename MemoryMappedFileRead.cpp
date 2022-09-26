#include "MemoryMappedFileRead.hpp"

namespace projectname
{
	/// Constructor definition.
	MemoryMappedFileRead::MemoryMappedFileRead(unsigned int handle, unsigned int size)
		:MemoryMappedFile(handle, size){}

	/// Destructor definition.
	MemoryMappedFileRead::~MemoryMappedFileRead()
    {
        if (mapView != MAP_FAILED)
        {
            int unmapped = munmap(mapView, size());
        }
    }

	/// Reading method definition uses chars to read exatly 1 byte per iteration.
	void MemoryMappedFileRead::read(char* buffer, int offset, int len)
	{
		for (unsigned int i = 0; i < len; i++)
		{
			*(buffer + i) = *(reinterpret_cast<char*>(this->mapView) + offset + i);
		}
	}
}