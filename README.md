# Implementation of a read-only memory mapped file interface
Designed and documented a class-interface to create memory mapped files, as well a subclass to read memory mapped files in the simplest way I can imagine. The purpose of a memory mapped file is to replace direct operations with the file on a disk by reading or writing data in the operating system directly, which can positively affect the performance of working with files, reduce the number of reads/writes, and even getting the possibility to share files between different programs without the need to write everything to disk.

Inheritance is used to create other subclasses, such as: MemoryMappedFileWrite, MemoryMappedFileReadWrite. For now I only feel confident about reading.