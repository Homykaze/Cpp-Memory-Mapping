/// General purpose memory-mapped file class
/// Use a memory mapped file to efficiently read and modify
/// the contents of random access files.

/// In case a subclass for writing is implemented,
/// everything will be compatible, however, only a subclass
/// for reading is implemented in this repository

#ifndef PROJECTNAME_HPP
#define PROJECTNAME_HPP

#include <stdexcept>
#include <sys/mman.h>

namespace projectname
{
	class MemoryMappedFile
	{
	public:
		/// Constructor
		/// \param handle File descriptor.
		/// \param size File size in bytes.
		MemoryMappedFile(unsigned int handle, unsigned int size);

		/// Default destructor
		virtual ~MemoryMappedFile() = default;

		/// Returns the size of the file.
        /// \return File size in bytes.
		[[nodiscard]]
		virtual int size() const noexcept;

	protected:
		/// Pointer to the memory mapped view of the file contents.
	    void* const mapView;

	private:
		/// File size in bytes.
		unsigned int size_;

		/// Creates a memory mapped view of the file contents.
		/// Throws runtime_error if file cannot be accessed.
        /// \return Pointer to the start of the memory map.
		void* map(unsigned int handle) noexcept;
	};
}
#endif