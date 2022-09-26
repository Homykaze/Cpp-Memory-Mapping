#include "MemoryMappedFile.hpp"

namespace projectname
{
    class MemoryMappedFileRead : public MemoryMappedFile
    {
    public:
        /// Constructor, can be reimplemented to use only `PROT_READ` flag.
        /// \param handle File descriptor.
        /// \param size File size in bytes.
        explicit MemoryMappedFileRead(unsigned int handle, unsigned int size);

        /// Destructor.
        /// Unmaps the memory mapped file and closes the file handle.
        ~MemoryMappedFileRead() final;

        /// Reads the desired amount of bytes from the file,
        /// starting from the current file position,
        /// and storing them in the given byte-buffer.
        /// Char is used, because its size is exactly 1 byte,
	    /// which is a multiple of page size, memory size unit for the kernel
        /// \param buffer Destination buffer for the read operation.
        /// \param offset Offset in bytes from file's origin.
        /// \param len Desired length to read.
        void read(char* buffer, int offset, int len);

    private:
        /// Neither copy-constructor, nor assignment operator are needed
        MemoryMappedFileRead(const MemoryMappedFile&) = delete;
        MemoryMappedFileRead& operator=(const MemoryMappedFile&) = delete;
    };
}