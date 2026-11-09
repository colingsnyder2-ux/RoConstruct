// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09-rbx2008 roc_g3d_jpeg_throw_414d7d8a47fb28a0.cpp

// Candidate translation unit (score above; library headers required).
/**
  @file GImage_jpeg.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
/**
 @file BinaryInput.h
 
 @maintainer Morgan McGuire, graphics3d.com
 
 @created 2001-08-09
 @edited  2005-06-07

 Copyright 2000-2005, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_BINARYINPUT_H
#define G3D_BINARYINPUT_H

#ifdef _MSC_VER
// Disable conditional expression is constant, which occurs incorrectly on inlined functions
#   pragma  warning(push)
#   pragma warning( disable : 4127 )

// signed/unsigned warnings (TODO: revisit)
#   pragma warning (disable:4267)
#endif

#include <assert.h>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Color4.h"
#include "G3D/Color3.h"
#include "G3D/Vector4.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2.h"
#include "G3D/g3dmath.h"
#include "G3D/debug.h"
#include "G3D/System.h"


namespace G3D {

#if defined(G3D_WIN32) || defined(G3D_LINUX)
    // Allow writing of integers to non-word aligned locations.
    // This is legal on x86, but not on other platforms.
    #define G3D_ALLOW_UNALIGNED_WRITES
#endif

/**
 Sequential or random access byte-order independent binary file access.
 Files compressed with zlib and beginning with an unsigned 32-bit int
 size are transparently decompressed when the compressed = true flag is
 specified to the constructor.

 For every readX method there are also versions that operate on a whole
 Array, std::vector, or C-array.  e.g. readFloat32(Array<float32>& array, n)
 These methods resize the array or std::vector to the appropriate size
 before reading.  For a C-array, they require the pointer to reference
 a memory block at least large enough to hold <I>n</I> elements.

 Most classes define serialize/deserialize methods that use BinaryInput,
 BinaryOutput, TextInput, and TextOutput.  There are text serializer 
 functions for primitive types (e.g. int, std::string, float, double) but not 
 binary serializers-- you <B>must</b> call the BinaryInput::readInt32 or
 other appropriate function.  This is because it would be very hard to 
 debug the error sequence: <CODE>serialize(1.0, bo); ... float f; deserialize(f, bi);</CODE>
 in which a double is serialized and then deserialized as a float. 
 */
class BinaryInput {
private:

    // The initial buffer will be no larger than this, but 
    // may grow if a large memory read occurs.  50 MB
    enum {INITIAL_BUFFER_LENGTH = 50000000};

    /**
     is the file big or little endian
     */
    G3DEndian       fileEndian;
    std::string     filename;

    bool            swapBytes;

    /** Next position to read from in bitString during readBits. */
    int             bitPos;

    /** Bits currently being read by readBits.  
        Contains at most 8 (low) bits.  Note that
        beginBits/readBits actually consumes one extra byte, which
        will be restored by writeBits.*/
    uint32          bitString;

    /** 1 when between beginBits and endBits, 0 otherwise. */
    int             beginEndBits;

    /** When operating on huge files, we cannot load the whole file into memory.
        This is the file position to which buffer[0] corresponds.
        */
    size_t          alreadyRead;

    /**
     Length of the entire file, in bytes.  
     For the length of the buffer, see bufferLength
     */
    int             length;

    /** Length of the array referenced by buffer. May go past the end of the file!*/
    int             bufferLength;
    uint8*          buffer;

    /**
     Next byte in file, relative to buffer.
     */
    int             pos;

    /**
     When true, the buffer is freed in the destructor.
     */
    bool            freeBuffer;

    /** Ensures that we are able to read at least minLength from startPosition (relative
        to start of file). */
    void loadIntoMemory(int startPosition, int minLength = 0);

    /** Verifies that at least this number of bytes can be read.*/
    inline void prepareToRead(size_t bytes) {
        debugAssertM((int)pos + (int)bytes + (int)alreadyRead <= (int)length, "Read past end of file.");

        if ((int)pos + (int)bytes > (int)bufferLength) {
            loadIntoMemory((int)pos + (int)alreadyRead, (int)bytes);    
        }
    }

    // Not implemented on purpose, don't use
    BinaryInput(const BinaryInput&);
    BinaryInput& operator=(const BinaryInput&);
    bool operator==(const BinaryInput&);

public:

    /** false, constant to use with the copyMemory option */
    static const bool       NO_COPY;

	/**
	 If the file cannot be opened, a zero length buffer is presented.
	 */
    BinaryInput(
        const std::string&  filename,
        G3DEndian           fileEndian,
        bool                compressed = false);

    /**
     Creates input stream from an in memory source.
     Unless you specify copyMemory = false, the data is copied
     from the pointer, so you may deallocate it as soon as the
     object is constructed.  It is an error to specify copyMemory = false
     and compressed = true.

     To decompress part of a file, you can follow the following paradigm:

     <PRE>
        BinaryInput master(...);

        // read from master to point where compressed data exists.

        BinaryInput subset(master.getCArray() + master.getPosition(), 
                           master.length() - master.getPosition(),
                           true, true);

        // Now read from subset (it is ok for master to go out of scope)
     </PRE>
     */
    BinaryInput(
        const uint8*        data,
        int                 dataLen,
        G3DEndian           dataEndian,
        bool                compressed = false,
        bool                copyMemory = true);

    virtual ~BinaryInput();


    std::string getFilename() const {
        return filename;
    }

    /**
     Returns a pointer to the internal memory buffer.
     May throw an exception for huge files.
     */
    const uint8* getCArray() const {
        if (alreadyRead > 0) {
            throw std::exception("Cannot getCArray for a huge file");
        }
        return buffer;
    }

    /**
     Performs bounds checks in debug mode.  [] are relative to
     the start of the file, not the current position.
     Seeks to the new position before reading (and leaves 
     that as the current position)
     */
    inline const uint8 operator[](int n) {
        setPosition(n);
        return readUInt8();
    }

    /**
     Returns the length of the file in bytes.
     */
    inline int getLength() const {
        return length;
    }

    inline int size() const {
        return getLength();
    }

    /**
     Returns the current byte position in the file,
     where 0 is the beginning and getLength() - 1 is the end.
     */
    inline int getPosition() const {
        return (int)pos + (int)alreadyRead;
    }

    /**
     Sets the position.  Cannot set past length.
     May throw a char* when seeking backwards more than 10 MB on a huge file.
     */
    inline void setPosition(int p) {
        debugAssertM(p <= length, "Read past end of file");
        pos = (int)p - (int)alreadyRead;
        if ((pos < 0) || (pos > bufferLength)) {
            loadIntoMemory((int)pos + (int)alreadyRead);
        }
    }

    /**
     Goes back to the beginning of the file.
     */
    inline void reset() {
        setPosition(0);
    }

    inline int8 readInt8() {
        prepareToRead(1);
        return buffer[pos++];
    }

    inline bool readBool8() {
        return (readInt8() != 0);
    }

    inline uint8 readUInt8() {
        prepareToRead(1);
        return ((uint8*)buffer)[pos++];
    }

    uint16 inline readUInt16() {
        prepareToRead(2);

        pos += 2;
        if (swapBytes) {
            uint8 out[2];
            out[0] = buffer[pos - 1];
            out[1] = buffer[pos - 2];
            return *(uint16*)out;
        } else {
            #ifdef G3D_ALLOW_UNALIGNED_WRITES
                return *(uint16*)(&buffer[pos - 2]);
            #else
                uint8 out[2];
                out[0] = buffer[pos - 2];
                out[1] = buffer[pos - 1];
                return *(uint16*)out;
            #endif
        }

    }

    inline int16 readInt16() {
        uint16 a = readUInt16();
        return *(int16*)&a;
    }

    inline uint32 readUInt32() {
        prepareToRead(4);

        pos += 4;
        if (swapBytes) {
            uint8 out[4];
            out[0] = buffer[pos - 1];
            out[1] = buffer[pos - 2];
            out[2] = buffer[pos - 3];
            out[3] = buffer[pos - 4];
            return *(uint32*)out;
        } else {
            #ifdef G3D_ALLOW_UNALIGNED_WRITES
                return *(uint32*)(&buffer[pos - 4]);
            #else
                uint8 out[4];
                out[0] = buffer[pos - 4];
                out[1] = buffer[pos - 3];
                out[2] = buffer[pos - 2];
                out[3] = buffer[pos - 1];
                return *(uint32*)out;
            #endif
        }
    }


    inline int32 readInt32() {
        uint32 a = readUInt32();
        return *(int32*)&a;
    }

    uint64 readUInt64();

    inline int64 readInt64() {
        uint64 a = readUInt64();
        return *(int64*)&a;
    }

    inline float32 readFloat32() {
        uint32 a = readUInt32();
        return *(float32*)&a;
    }    

    inline float64 readFloat64() {
        uint64 a = readUInt64();
        return *(float64*)&a;
    }

    /**
     Returns the data in bytes.
     @deprecated Use readBytes(void*, int).
     */
    void readBytes(int n, void* bytes);

    /**
     Returns the data in bytes.
     */
    inline void readBytes(void* bytes, int n) {
        readBytes(n, bytes);
    }

    /**
     Reads an n character string.  The string is not
     required to end in NULL in the file but will
     always be a proper std::string when returned.
     */
    std::string readString(int n);

    /**
     Reads until NULL or the end of the file is encountered.
     */
    std::string readString();

    /**
     Reads until NULL or the end of the file is encountered.
     If the string has odd length (including NULL), reads 
     another byte.
     */
    std::string readStringEven();


    std::string readString32();

    Vector4 readVector4();
    Vector3 readVector3();
    Vector2 readVector2();

    Color4 readColor4();
    Color3 readColor3();

    /**
     Skips ahead n bytes.
     */
    inline void skip(int n) {
        setPosition((int)pos + (int)alreadyRead + n);
    }

	/**
	 Returns true if the position is not at the end of the file
	 */
	inline bool hasMore() const {
		return (int)pos + (int)alreadyRead < (int)length;
	}

    /** Prepares for bit reading via readBits.  Only readBits can be
        called between beginBits and endBits without corrupting the
        data stream. */
    void beginBits();

    /** Can only be called between beginBits and endBits */
    uint32 readBits(int numBits);

    /** Ends bit-reading. */
    void endBits();

#   define DECLARE_READER(ucase, lcase)\
    void read##ucase(lcase* out, int n);\
    void read##ucase(std::vector<lcase>& out, int n);\
    void read##ucase(Array<lcase>& out, int n);

    DECLARE_READER(Bool8,   bool)
    DECLARE_READER(UInt8,   uint8)
    DECLARE_READER(Int8,    int8)
    DECLARE_READER(UInt16,  uint16)
    DECLARE_READER(Int16,   int16)
    DECLARE_READER(UInt32,  uint32)
    DECLARE_READER(Int32,   int32)
    DECLARE_READER(UInt64,  uint64)
    DECLARE_READER(Int64,   int64)
    DECLARE_READER(Float32, float32)
    DECLARE_READER(Float64, float64)    
#   undef DECLARE_READER
};


}

#endif

#ifdef _MSC_VER
#   pragma  warning(pop)
#endif

/**
 @file BinaryOutput.h
 
 @maintainer Morgan McGuire, graphics3d.com
 
 @created 2001-08-09
 @edited  2006-01-24

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_BINARYOUTPUT_H
#define G3D_BINARYOUTPUT_H

#include "G3D/platform.h"
#include <assert.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "G3D/Color4.h"
#include "G3D/Color3.h"
#include "G3D/Vector4.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2.h"
#include "G3D/g3dmath.h"
#include "G3D/debug.h"
#include "G3D/BinaryInput.h"
#include "G3D/System.h"

#ifdef _MSC_VER
#   pragma warning (push)
// Conditional is constant (wrong in inline)
#   pragma warning (disable : 4127)
#endif
namespace G3D {

/**
 Sequential or random access byte-order independent binary file access.

 The compress() call can be used to compress with zlib.

 Any method call can trigger an out of memory error (thrown as char*) 
 when writing to "<memory>" instead of a file.

 Compressed writing and seeking backwards is not supported for huge files
 (i.e., BinaryOutput may have to dump the contents to disk if they 
 exceed available RAM).
 */
class BinaryOutput {
private:
    std::string     filename;

    bool            committed;

    /** 0 outside of beginBits...endBits, 1 inside */
    int             beginEndBits;

    /** The current string of bits being built up by beginBits...endBits.
        This string is treated semantically, as if the lowest bit was
        on the left and the highest was on the right.*/
    int8            bitString;

    /** Position (from the lowest bit) currently used in bitString.*/
    int             bitPos;

    // True if the file endianess does not match the machine endian
    bool            swapBytes;

    uint8*          buffer;
    
    /** Size of the elements used */
    int             bufferLen;

    /** Underlying size of memory allocaded */
    int             maxBufferLen;

    /** Next byte in file */
    int             pos;

    /** is this initialized? */
    bool            init;

    /** Number of bytes already written to the file.*/
    size_t          alreadyWritten;             

    void reserveBytesWhenOutOfMemory(size_t bytes);

    void reallocBuffer(size_t bytes, size_t oldBufferLen);

    /**
     Make sure at least bytes can be written, resizing if
     necessary.
     */
    inline void reserveBytes(int bytes) {
        debugAssert(bytes > 0);
        size_t oldBufferLen = (size_t)bufferLen;

        bufferLen = iMax(bufferLen, (pos + bytes));
        if (bufferLen > maxBufferLen) {
            reallocBuffer(bytes, oldBufferLen);
        }
    }

    // Not implemented on purpose, don't use
    BinaryOutput(const BinaryOutput&);
    BinaryOutput& operator=(const BinaryOutput&);
    bool operator==(const BinaryOutput&);

public:

    /**
     You must call setEndian() if you use this (memory) constructor.
     */
    BinaryOutput();

    /**
     Doesn't actually open the file; commit() does that.
     Use "<memory>" as the filename if you're going to commit
     to memory.
     */
    BinaryOutput(
        const std::string&  filename,
        G3DEndian           fileEndian);

    ~BinaryOutput();
    
    /** Compresses the data in the buffer in place, 
        preceeding it with a little-endian uint32 indicating 
        the uncompressed size.

        Call immediately before commit().

        Cannot be used for huge files (ones where the data
        was already written to disk)-- will throw char*.
     */
    void compress();

    /**
     Returns a pointer to the internal memory buffer.
     */
    inline const uint8* getCArray() const {
        return buffer;
    }

    void setEndian(G3DEndian fileEndian);

    std::string getFilename() const {
        return filename;
    }

    /**
     Write the bytes to disk.  It is ok to call this 
     multiple times; it will just overwrite the previous file.

     Parent directories are created as needed if they do
     not exist.

     <B>Not</B> called from the destructor; you must call
     it yourself.

     @param flush If true (default) the file is ready for reading when the method returns, otherwise 
      the method returns immediately and writes the file in the background.
    */
    void commit(bool flush = true);

    /**
     Write the bytes to memory (which must be of
     at least size() bytes).
     */
    void commit(uint8*);

    /**
      A memory BinaryOutput may be reset so that it can be written to again
      without allocating new memory.  The underlying array will not be deallocated,
      but the reset structure will act like a newly intialized one.
     */
    void reset();


    inline int length() const {
        return (int)bufferLen + (int)alreadyWritten;
    }

    /**
     Returns the length of the file in bytes.
     @deprecated use BinaryOutput.size
     */
    inline int getLength() const {
        return length();
    }

    inline int size() const {
        return length();
    }

    /**
     Sets the length of the file to n, padding
     with 0's past the current end.  Does not
     change the position of the next byte to be
     written unless n < size().

     Throws char* when resetting a huge file to be shorter
     than its current length.
     */
    inline void setLength(int n) {
        n = n - (int)alreadyWritten;

        if (n < 0) {
            throw std::exception("Cannot resize huge files to be shorter.");
        }

        if (n < bufferLen) {
            pos = n;
        }
        if (n > bufferLen) {
            reserveBytes(n - bufferLen);
        }
    }

    /**
     Returns the current byte position in the file,
     where 0 is the beginning and getLength() - 1 is the end.
     */
    inline int position() const {
        return (int)pos + (int)alreadyWritten;
    }

    /** @deprecated */
    inline int getPosition() const {
        return position();
    }


    /**
     Sets the position.  Can set past length, in which case
     the file is padded with zeros up to one byte before the
     next to be written.

     May throw a char* exception when seeking backwards on a huge file.
     */
    inline void setPosition(int p) {
        p = p - (int)alreadyWritten;

        if (p > bufferLen) {
            setLength(p + (int)alreadyWritten);
        }

        if (p < 0) {
            throw "Cannot seek more than 10 MB backwards on huge files.";
        }

        pos = p;
    }


    void writeBytes(
        const void*         b,
        int                 count) {

        reserveBytes(count);
        debugAssert(pos >= 0);
        debugAssert(bufferLen >= count);
        System::memcpy(buffer + pos, b, count);
        pos += count;
    }

    /**
     Writes a signed 8-bit integer to the current position.
     */
    inline void writeInt8(int8 i) {
        reserveBytes(1);
        buffer[pos] = *(uint8*)&i;
        pos++;
    }

    inline void writeBool8(bool b) {
        writeInt8(b ? 1 : 0);
    }

    inline void writeUInt8(uint8 i) {
        reserveBytes(1);
        buffer[pos] = i;
        pos++;
    }

    void writeUInt16(uint16 u);

    inline void writeInt16(int16 i) {
        writeUInt16(*(uint16*)&i);
    }

    void writeUInt32(uint32 u);

    inline void writeInt32(int32 i) {
        debugAssert(beginEndBits == 0);
        writeUInt32(*(uint32*)&i);
    }

    void writeUInt64(uint64 u);

    inline void writeInt64(int64 i) {
        writeUInt64(*(uint64*)&i);
    }

    inline void writeFloat32(float32 f) {
        debugAssert(beginEndBits == 0);
        writeUInt32(*(uint32*)&f);
    }

    inline void writeFloat64(float64 f) {
        writeUInt64(*(uint64*)&f);
    }

    /**
     Write a string with NULL termination.
     */
    inline void writeString(const std::string& s) {
        writeString(s.c_str());
    }

    void writeString(const char* s);

    /**
     Write a string, ensuring that the total length
     including NULL is even.
     */
    void writeStringEven(const std::string& s) {
        writeStringEven(s.c_str());
    }

    void writeStringEven(const char* s);


    void writeString32(const char* s);

    /**
     Write a string with a 32-bit length field in front
     of it.
     */
    void writeString32(const std::string& s) {
        writeString32(s.c_str());
    }

    void writeVector4(const Vector4& v);

    void writeVector3(const Vector3& v);

    void writeVector2(const Vector2& v);

    void writeColor4(const Color4& v);

    void writeColor3(const Color3& v);

    /**
     Skips ahead n bytes.
     */
    inline void skip(int n) {
        if (pos + n > bufferLen) {
            setLength((int)pos + (int)alreadyWritten + n);
        }
        pos += n;
    }

    /** Call before a series of BinaryOutput::writeBits calls. Only writeBits 
        can be called between beginBits and endBits without corrupting the stream.*/
    void beginBits();

    /** Write numBits from bitString to the output stream.  Bits are numbered from
        low to high.
    
        Can only be 
        called between beginBits and endBits.  Bits written are semantically
        little-endian, regardless of the actual endian-ness of the system.  That is,
        <CODE>writeBits(0xABCD, 16)</CODE> writes 0xCD to the first byte and 
        0xAB to the second byte.  However, if used with BinaryInput::readBits, the ordering
        is transparent to the caller.
      */
    void writeBits(uint32 bitString, int numBits);

    /** Call after a series of BinaryOutput::writeBits calls. This will
        finish out with zeros the last byte into which bits were written.*/
    void endBits();


#   define DECLARE_WRITER(ucase, lcase)\
    void write##ucase(const lcase* out, int n);\
    void write##ucase(const std::vector<lcase>& out, int n);\
    void write##ucase(const Array<lcase>& out, int n);

    DECLARE_WRITER(Bool8,   bool)
    DECLARE_WRITER(UInt8,   uint8)
    DECLARE_WRITER(Int8,    int8)
    DECLARE_WRITER(UInt16,  uint16)
    DECLARE_WRITER(Int16,   int16)
    DECLARE_WRITER(UInt32,  uint32)
    DECLARE_WRITER(Int32,   int32)
    DECLARE_WRITER(UInt64,  uint64)
    DECLARE_WRITER(Int64,   int64)
    DECLARE_WRITER(Float32, float32)
    DECLARE_WRITER(Float64, float64)    
#   undef DECLARE_WRITER

};

}
#endif

#ifdef _MSC_VER
#   pragma warning (pop)
#endif

 
 /**
 Pick up libjpeg headers locally on Windows, but from the system on all other platforms.
*/
extern "C" {
#ifdef G3D_WIN32
	#include "../IJG/jconfig.h"
	#include "../IJG/cdjpeg.h"
#else
	#include <jconfig.h>
	#include <jpeglib.h>
#endif
}

namespace G3D {


const int jpegQuality = 96;

/**
 The IJG library needs special setup for compress/decompressing
 from memory.  These classes provide them.  
 
 The format of this class is defined by the IJG library; do not
 change it.
 */ 
class memory_destination_mgr {
public:
	struct jpeg_destination_mgr pub;
	JOCTET*                     buffer;
	int                         size;
	int                         count;
};

typedef memory_destination_mgr* mem_dest_ptr;

/**
 Signature dictated by IJG.
 */
static void init_destination (
    j_compress_ptr              cinfo) {

	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;

	dest->pub.next_output_byte = dest->buffer;
	dest->pub.free_in_buffer = dest->size;
	dest->count=0;
}

/**
 Signature dictated by IJG.
 */
static boolean empty_output_buffer (
    j_compress_ptr              cinfo) {

	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;

	dest->pub.next_output_byte = dest->buffer;
	dest->pub.free_in_buffer = dest->size;

	return TRUE;
}

/**
 Signature dictated by IJG.
 */
static void term_destination (
    j_compress_ptr              cinfo) {

	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
	dest->count = dest->size - dest->pub.free_in_buffer;
}

/**
 Signature dictated by IJG.
 */
static void jpeg_memory_dest (
    j_compress_ptr              cinfo,
    JOCTET*                     buffer,
    int                         size) {

	mem_dest_ptr dest;

	if (cinfo->dest == NULL) {
        // First time for this JPEG object; call the
        // IJG allocator to get space.
		cinfo->dest = (struct jpeg_destination_mgr*)
			(*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, 
                                        JPOOL_PERMANENT,
                       				    sizeof(memory_destination_mgr));
	}

	dest                            = (mem_dest_ptr) cinfo->dest;
	dest->size                      = size;
	dest->buffer                    = buffer;
	dest->pub.init_destination      = init_destination;
	dest->pub.empty_output_buffer   = empty_output_buffer;
	dest->pub.term_destination      = term_destination;
}
  
////////////////////////////////////////////////////////////////////////////////////////

#define INPUT_BUF_SIZE  4096

/**
 Structure dictated by IJG.
 */
class memory_source_mgr {
public:
    struct jpeg_source_mgr  pub;
	int                     source_size;
	unsigned char*          source_data;
	boolean                 start_of_data;
	JOCTET*                 buffer;
};


typedef memory_source_mgr* mem_src_ptr;


/**
 Signature dictated by IJG.
 */
static void init_source(
    j_decompress_ptr        cinfo) {

    mem_src_ptr src = (mem_src_ptr) cinfo->src;

    src->start_of_data = TRUE;
}


/**
 Signature dictated by IJG.
 */
static boolean fill_input_buffer(
    j_decompress_ptr        cinfo) {

	mem_src_ptr src = (mem_src_ptr) cinfo->src;

	size_t bytes_read = 0;

	if (src->source_size > INPUT_BUF_SIZE)
		bytes_read = INPUT_BUF_SIZE;
	else
		bytes_read = src->source_size;

	memcpy (src->buffer, src->source_data, bytes_read);

	src->source_data += bytes_read;
	src->source_size -= bytes_read;

	src->pub.next_input_byte = src->buffer;
	src->pub.bytes_in_buffer = bytes_read;
	src->start_of_data = FALSE;


	return TRUE;
}


/**
 Signature dictated by IJG.
 */
static void skip_input_data(
    j_decompress_ptr        cinfo,
    long                    num_bytes) {

	mem_src_ptr src = (mem_src_ptr)cinfo->src;

	if (num_bytes > 0) {
		while (num_bytes > (long) src->pub.bytes_in_buffer) {
			num_bytes -= (long) src->pub.bytes_in_buffer;
			boolean s = fill_input_buffer(cinfo);
            debugAssert(s); (void)s;
		}

		src->pub.next_input_byte += (size_t) num_bytes;
		src->pub.bytes_in_buffer -= (size_t) num_bytes;
	}
}


/**
 Signature dictated by IJG.
 */
static void term_source (
    j_decompress_ptr        cinfo) {
    (void)cinfo;
	// Intentionally empty
}


/**
 Signature dictated by IJG.
 */
static void jpeg_memory_src (
    j_decompress_ptr        cinfo,
    JOCTET*                 buffer,
    int                     size) {

	mem_src_ptr src;

	if (cinfo->src == NULL) {
        // First time for this JPEG object
		cinfo->src = (struct jpeg_source_mgr*)
			(*cinfo->mem->alloc_small)(
                (j_common_ptr) cinfo,
                JPOOL_PERMANENT,
				sizeof(memory_source_mgr));
		
        src = (mem_src_ptr)cinfo->src;
		
        src->buffer = (JOCTET*)
			(*cinfo->mem->alloc_small)(
                (j_common_ptr) cinfo,
                JPOOL_PERMANENT,
				INPUT_BUF_SIZE * sizeof(JOCTET));
	}

	src = (mem_src_ptr)cinfo->src;
	src->pub.init_source        = init_source;
	src->pub.fill_input_buffer  = fill_input_buffer;
	src->pub.skip_input_data    = skip_input_data;

    // use default method
	src->pub.resync_to_restart  = jpeg_resync_to_restart;
	src->pub.term_source        = term_source;
	src->source_data            = buffer;
	src->source_size            = size;

    // forces fill_input_buffer on first read
	src->pub.bytes_in_buffer    = 0;
    
    // until buffer loaded
    src->pub.next_input_byte = NULL; 
}


void GImage::encodeJPEG(
    BinaryOutput&           out) const {

	if (channels != 3) {
		// Convert to three channel
		GImage tmp = *this;
		tmp.convertToRGB();
		tmp.encodeJPEG(out);
		return;
	}

    debugAssert(channels == 3);
    out.setEndian(G3D_LITTLE_ENDIAN);

    // Allocate and initialize a compression object
    jpeg_compress_struct    cinfo;
    jpeg_error_mgr          jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

    // Specify the destination for the compressed data.
    // (Overestimate the size)
    int buffer_size = width * height * 3 + 200;
    JOCTET* compressed_data = (JOCTET*)System::malloc(buffer_size);
	jpeg_memory_dest(&cinfo, compressed_data, buffer_size);


    cinfo.image_width       = width;
    cinfo.image_height      = height;

	// # of color components per pixel
    cinfo.input_components  = 3;

    // colorspace of input image
    cinfo.in_color_space    = JCS_RGB; 
    cinfo.input_gamma       = 1.0;
    
    // Set parameters for compression, including image size & colorspace
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, jpegQuality, false);
    cinfo.smoothing_factor = 0;
    cinfo.optimize_coding = TRUE;
//    cinfo.dct_method = JDCT_FLOAT;
    cinfo.dct_method = JDCT_ISLOW;
    cinfo.jpeg_color_space = JCS_YCbCr;

    // Initialize the compressor
    jpeg_start_compress(&cinfo, TRUE);

    // Iterate over all scanlines from top to bottom
	// pointer to a single row
    JSAMPROW row_pointer[1];
    
    // JSAMPLEs per row in image_buffer
    int row_stride = cinfo.image_width * 3;
    while (cinfo.next_scanline < cinfo.image_height) {
	    row_pointer[0] = &(_byte[cinfo.next_scanline * row_stride]);
	    jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    // Shut down the compressor
    jpeg_finish_compress(&cinfo);
    
    // Figure out how big the result was.
    int outLength = ((mem_dest_ptr)cinfo.dest)->count;

    //	Release the JPEG compression object
    jpeg_destroy_compress(&cinfo);

    // Copy into an appropriately sized output buffer.
    out.writeBytes(compressed_data, outLength);

    // Free the conservative buffer.
    System::free(compressed_data);
    compressed_data = NULL;
}



/* Roblox 2008: libjpeg errors throw instead of exit() (error_exit at 0x50b530). */
static void jpegErrorExit(j_common_ptr cinfo) {
    (*cinfo->err->output_message)(cinfo);
    jpeg_destroy(cinfo);
    char buffer[JMSG_LENGTH_MAX];
    (*cinfo->err->format_message)(cinfo, buffer);
    throw std::runtime_error(buffer);
}

void GImage::decodeJPEG(
    BinaryInput&                input) {

	struct jpeg_decompress_struct   cinfo;
	struct jpeg_error_mgr           jerr;
    int                             loc = 0;

    channels = 3;
    // We have to set up the error handler, in case initialization fails.
	cinfo.err = jpeg_std_error(&jerr);
	jerr.error_exit = jpegErrorExit;

    // Initialize the JPEG decompression object.
	jpeg_create_decompress(&cinfo);

	// Specify data source (eg, a file, for us, memory)
	jpeg_memory_src(&cinfo, const_cast<uint8*>(input.getCArray()), input.size());

	// Read the parameters with jpeg_read_header()
	jpeg_read_header(&cinfo, TRUE);

	// Set parameters for decompression
	// (We do nothing here since the defaults are fine)

	// Start decompressor
	jpeg_start_decompress(&cinfo);

	// Get and set the values of interest to this object
	this->width     = cinfo.output_width;
	this->height    = cinfo.output_height;

	// Prepare the pointer object for the pixel data
    _byte = (uint8*)System::malloc(width * height * 3);

 	// JSAMPLEs per row in output buffer
    int bpp         = cinfo.output_components;
    int row_stride  = cinfo.output_width * bpp;

	// Make a one-row-high sample array that will go away when done with image
    JSAMPARRAY temp = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    // Read data on a scanline by scanline basis
	while (cinfo.output_scanline < cinfo.output_height) {

        // We may need to adjust the output based on the
        // number of channels it has.
        switch (bpp) {
	    case 1:
            // Grayscale; decompress to temp.
    		jpeg_read_scanlines(&cinfo, temp, 1);

            // Expand to three channels
            {
                uint8* scan     = &(_byte[loc * 3]);
                uint8* endScan  = scan + (width * 3);
                uint8* t        = *temp;

                while (scan < endScan) {
                    uint8 value = t[0];

                    // Spread the value 3x.
                    scan[0] = value;
                    scan[1] = value;
                    scan[2] = value;

                    scan    += 3;
                    t       += 1;
                }
            }
		    break;

	    case 3:
            // Read directly into the array
            {
                // Need one extra level of indirection.
                uint8*     scan = _byte + loc;
                JSAMPARRAY ptr  = &scan;
    		    jpeg_read_scanlines(&cinfo, ptr, 1);
            }
		    break;

	    case 4:
            // RGBA; decompress to temp.
    		jpeg_read_scanlines(&cinfo, temp, 1);

            // Drop the 3rd channel
            {
                uint8* scan     = &(_byte[loc * 3]);
                uint8* endScan  = scan + width * 3;
                uint8* t        = *temp;

                while (scan < endScan) {
                    scan[0] = t[0];
                    scan[1] = t[1];
                    scan[2] = t[2];
                    
                    scan    += 3;
                    t       += 4;
                }
            }
		    break;

	    default:
		    throw Error("Unexpected number6 of channels.", input.getFilename());
	    }

		loc += row_stride;
	}

	// Finish decompression
	jpeg_finish_decompress(&cinfo);

	// Release JPEG decompression object
	jpeg_destroy_decompress(&cinfo);
}


}
