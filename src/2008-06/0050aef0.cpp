// from server: 100% by king_originala
// from server: 21% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_g3d_bmp_exception_38498d93767fe727.cpp

// Candidate translation unit (score above; library headers required).
/**
  @file GImage_bmp.cpp
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

#include "G3D/Log.h"

namespace G3D {

#ifndef G3D_WIN32
/**
 This is used by the Windows bitmap I/O.
 */
static const int BI_RGB = 0;
#endif

void GImage::encodeBMP(
    BinaryOutput&       out) const {

    debugAssert(channels == 1 || channels == 3);
    out.setEndian(G3D_LITTLE_ENDIAN);

    uint8 red;
    uint8 green;
    uint8 blue;
    int pixelBufferSize = width * height * 3;
    int fileHeaderSize = 14;
    int infoHeaderSize = 40;
    int BMScanWidth;
    int BMPadding;

    // First write the BITMAPFILEHEADER
    //
    //  WORD    bfType; 
    //  DWORD   bfSize; 
    //  WORD    bfReserved1; 
    //  WORD    bfReserved2; 
    //  DWORD   bfOffBits; 

    // Type
    out.writeUInt8('B');
    out.writeUInt8('M');

    // File size
    out.writeUInt32(fileHeaderSize + infoHeaderSize + pixelBufferSize);

    // Two reserved fields set to zero
    out.writeUInt16(0);
    out.writeUInt16(0);

	// The offset, in bytes, from the BITMAPFILEHEADER structure
    // to the bitmap bits.
    out.writeUInt32(infoHeaderSize + fileHeaderSize);

    // Now the BITMAPINFOHEADER
    //
    //  DWORD  biSize; 
    //  LONG   biWidth; 
    //  LONG   biHeight; 
    //  WORD   biPlanes; 
    //  WORD   biBitCount 
    //  DWORD  biCompression; 
    //  DWORD  biSizeImage; 
    //  LONG   biXPelsPerMeter; 
    //  LONG   biYPelsPerMeter; 
    //  DWORD  biClrUsed; 
    //  DWORD  biClrImportant; 

    // Size of the info header
    out.writeUInt32(infoHeaderSize);
 
    // Width and height of the image
	out.writeUInt32(width);
    out.writeUInt32(height);

    // Planes ("must be set to 1")
    out.writeUInt16(1);

    // BitCount and CompressionType
    out.writeUInt16(24);
    out.writeUInt32(BI_RGB);

    // Image size ("may be zero for BI_RGB bitmaps")
    out.writeUInt32(0);

    // biXPelsPerMeter
    out.writeUInt32(0);
    // biYPelsPerMeter
    out.writeUInt32(0);

    // biClrUsed
    out.writeUInt32(0); 

    // biClrImportant
    out.writeUInt32(0); 
    
    BMScanWidth = width * 3;

    if (BMScanWidth & 3) {
        BMPadding = 4 - (BMScanWidth & 3);
    } else {
        BMPadding = 0;
    }

    int hStart = height - 1;
    int hEnd   = -1;
    int hDir   = -1;
    int dest;

    // Write the pixel data
    for (int h = hStart; h != hEnd; h += hDir) {
        dest = channels * h * width;
        for (int w = 0; w < width; ++w) {

            if (channels == 3) {
                red   = _byte[dest];
                green = _byte[dest + 1];
                blue  = _byte[dest + 2];
            } else {
                red   = _byte[dest];
                green = _byte[dest];
                blue  = _byte[dest];
            }

            out.writeUInt8(blue);
            out.writeUInt8(green);
            out.writeUInt8(red);

            dest += channels;
        }

        if (BMPadding) {
            out.skip(2);
        }
    }
}


void GImage::decodeBMP(
    BinaryInput&            input) {

    // The BMP decoding uses these flags.
    static const uint16 PICTURE_NONE               = 0x0000;
    static const uint16 PICTURE_BITMAP             = 0x1000;

    // Compression Flags
    static const uint16 PICTURE_UNCOMPRESSED       = 0x0100;
    static const uint16 PICTURE_MONOCHROME         = 0x0001;
    static const uint16 PICTURE_4BIT               = 0x0002;
    static const uint16 PICTURE_8BIT               = 0x0004;
    static const uint16 PICTURE_16BIT              = 0x0008;
    static const uint16 PICTURE_24BIT              = 0x0010;
    static const uint16 PICTURE_32BIT              = 0x0020;

    (void)PICTURE_16BIT;
    (void)PICTURE_32BIT;

    // This is a simple BMP loader that can handle uncompressed BMP files.
    // Verify this is a BMP file by looking for the BM tag.
    input.reset();
    std::string tag = input.readString(2);
    if (tag != "BM") {
        throw Error("Not a BMP file", input.getFilename());
    }

    channels = 3;
	// Skip to the BITMAPINFOHEADER's width and height
	input.skip(16);

    width  = input.readUInt32();
    height = input.readUInt32();

	// Skip to the bit count and compression type
	input.skip(2);

    uint16 bitCount        = input.readUInt16();
    uint32 compressionType = input.readUInt32();

    uint8 red;
    uint8 green;
    uint8 blue;
    uint8 blank;

	// Only uncompressed bitmaps are supported by this code
    if ((int32)compressionType != BI_RGB) {
        throw Error("BMP images must be uncompressed", input.getFilename());
    }

    uint8* palette = NULL;

	// Create the palette if needed
    if (bitCount <= 8) {

        // Skip to the palette color count in the header
        input.skip(12);

        int numColors = input.readUInt32();

        palette = (uint8*)System::malloc(numColors * 3);
        debugAssert(palette);

        // Skip past the end of the header to the palette info
        input.skip(4);

        int c;
        for(c = 0; c < numColors * 3; c += 3) {
            // Palette information in bitmaps is stored in BGR_ format.
            // That means it's blue-green-red-blank, for each entry.
            blue  = input.readUInt8();
            green = input.readUInt8();
            red   = input.readUInt8();
            blank = input.readUInt8();

            palette[c]     = red;
            palette[c + 1] = green;
            palette[c + 2] = blue;
        }
	}

    int hStart = 0;
    int hEnd   = 0;
    int hDir   = 0;

    if (height < 0) {
        height = -height;
        hStart = 0;
        hEnd   = height;
        hDir   = 1;
    } else {
        //height = height;
        hStart = height - 1;
        hEnd   = -1;
        hDir   = -1;
    }

    _byte = (uint8*)System::malloc(width * height * 3);
    debugAssert(_byte);

    int BMScanWidth;
    int BMPadding;
    uint8 BMGroup;
    uint8 BMPixel8;
    int currPixel;
    int dest;
    int flags = PICTURE_NONE;

    if (bitCount == 1) {
        // Note that this file is not necessarily grayscale, since it's possible
        // the palette is blue-and-white, or whatever. But of course most image
        // programs only write 1-bit images if they're black-and-white.
        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_MONOCHROME;

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = (width + 7) >> 3;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        // Powers of 2
        int pow2[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 3 * h * width;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMGroup = input.readUInt8();

                // Now we read the pixels. Usually there are eight pixels per byte,
                // since each pixel is represented by one bit, but if the width
                // is not a multiple of eight, the last byte will have some bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "width" number of pixels.
                for (int i = 7; i >= 0; --i) {
                    if (currPixel < width) {
                        int src  = 3 * ((BMGroup & pow2[i]) >> i);
                    
                        _byte[dest]     = palette[src];
                        _byte[dest + 1] = palette[src + 1];
                        _byte[dest + 2] = palette[src + 2];
                    
                        ++currPixel;
                        dest += 3;
                    }
                }
            }
        }

	} else if (bitCount == 4) {

        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_4BIT;

        // For bitmaps, each scanline is dword-aligned.
        int BMScanWidth = (width+1) >> 1;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 3 * h * width;

            for (int w = 0; w < BMScanWidth; w++) {

                BMGroup = input.readUInt8();
                int src[2];
                src[0] = 3 * ((BMGroup & 0xF0) >> 4);
                src[1] = 3 * (BMGroup & 0x0F);

                // Now we read the pixels. Usually there are two pixels per byte,
                // since each pixel is represented by four bits, but if the width
                // is not a multiple of two, the last byte will have only four bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "Width" number of pixels.

                for (int i = 0; i < 2; ++i) {
                    if (currPixel < width) {
                        int tsrc  = src[i];
                    
                        _byte[dest]     = palette[tsrc];
                        _byte[dest + 1] = palette[tsrc + 1];
                        _byte[dest + 2] = palette[tsrc + 2];

                        ++currPixel;
                        dest += 3;
                    }
                }
            }
        }

	} else if (bitCount == 8) {
        
        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_8BIT;

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = width;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMPixel8 = input.readUInt8();

                if (currPixel < width) {
                    dest = 3 * ((h * width) + currPixel);
                    int src  = 3 * BMPixel8;
                    
                    _byte[dest]     = palette[src];
                    _byte[dest + 1] = palette[src + 1];
                    _byte[dest + 2] = palette[src + 2];
                    
                    ++currPixel;
                }
            }
        }

    } else if (bitCount == 16) {

        System::free(_byte);
        _byte = NULL;
        System::free(palette); 
        palette = NULL;
    	throw Error("16-bit bitmaps not supported", input.getFilename());

	} else if (bitCount == 24) {
        input.skip(20);

        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_24BIT;

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = width * 3;

        if (BMScanWidth & 3) {
            BMPadding = 4 - (BMScanWidth & 3);
        } else {
            BMPadding = 0;
        }

        for (int h = hStart; h != hEnd; h += hDir) {
            dest = 3 * h * width;
            for (int w = 0; w < width; ++w) {

                blue  = input.readUInt8();
                green = input.readUInt8();
                red   = input.readUInt8();

                _byte[dest]     = red;
                _byte[dest + 1] = green;
                _byte[dest + 2] = blue;

                dest += 3;
            }

            if (BMPadding) {
                input.skip(2);
            }
        }

	} else if (bitCount == 32) {

        System::free(_byte);
        _byte = NULL;
        System::free(palette); 
        palette = NULL;
    	throw Error("32 bit bitmaps not supported", input.getFilename());
    
    } else {
        // We support all possible bit depths, so if the
        //     code gets here, it's not even a real bitmap.
        System::free(_byte);
        _byte = NULL;
        throw Error("Not a bitmap!", input.getFilename());
	}

    System::free(palette); 
    palette = NULL;
}


void GImage::decodeICO(
    BinaryInput&            input) {

	// Header
	uint16 r = input.readUInt16();
	debugAssert(r == 0);
	r = input.readUInt16();
	debugAssert(r == 1);

	// Read the number of icons, although we'll only load the
	// first one.
	int count = input.readUInt16();

	channels = 4;

	debugAssert(count > 0);

    const uint8* headerBuffer = input.getCArray() + input.getPosition();
    int maxWidth = 0, maxHeight = 0;
    int maxHeaderNum = 0;
    for (int currentHeader = 0; currentHeader < count; ++currentHeader) {
        
        const uint8* curHeaderBuffer = headerBuffer + (currentHeader * 16);
        int tmpWidth = curHeaderBuffer[0];
        int tmpHeight = curHeaderBuffer[1];
        // Just in case there is a non-square icon, checking area
        if ((tmpWidth * tmpHeight) > (maxWidth * maxHeight)) {
            maxWidth = tmpWidth;
            maxHeight = tmpHeight;
            maxHeaderNum = currentHeader;
        }
    }

    input.skip(maxHeaderNum * 16);

	width = input.readUInt8();
	height = input.readUInt8();
	int numColors = input.readUInt8();
	
    _byte = (uint8*)System::malloc(width * height * channels);
    debugAssert(_byte);

	// Bit mask for packed bits
	int mask = 0;

	int bitsPerPixel = 8;

	switch (numColors) {
	case 2:
		mask      = 0x01;
		bitsPerPixel = 1;
		break;

	case 16:
		mask      = 0x0F;
		bitsPerPixel = 4;
		break;

	case 0:
		numColors = 256;
		mask      = 0xFF;
		bitsPerPixel = 8;
		break;
    default:
    	throw Error("Unsupported ICO color count.", input.getFilename());
	}

	input.skip(5);
	// Skip 'size' unused
        input.skip(4);

	int offset = input.readUInt32();

	// Skip over any other icon descriptions
    input.setPosition(offset);

	// Skip over bitmap header; it is redundant
	input.skip(40);

	Array<Color4uint8> palette;
    palette.resize(numColors, true);
	for (int c = 0; c < numColors; ++c) {
		palette[c].b = input.readUInt8();
		palette[c].g = input.readUInt8();
		palette[c].r = input.readUInt8();
		palette[c].a = input.readUInt8();
	}

	// The actual image and mask follow

	// The XOR Bitmap is stored as 1-bit, 4-bit or 8-bit uncompressed Bitmap 
	// using the same encoding as BMP files. The AND Bitmap is stored in as 
	// 1-bit uncompressed Bitmap.
	// 
	// Pixels are stored bottom-up, left-to-right. Pixel lines are padded 
	// with zeros to end on a 32bit (4byte) boundary. Every line will have the 
	// same number of bytes. Color indices are zero based, meaning a pixel color 
	// of 0 represents the first color table entry, a pixel color of 255 (if there
	// are that many) represents the 256th entry.
/*
	int bitsPerRow  = width * bitsPerPixel;
	int bytesPerRow = iCeil((double)bitsPerRow / 8);
	// Rows are padded to 32-bit boundaries
	bytesPerRow += bytesPerRow % 4;

	// Read the XOR values into the color channel
	for (int y = height - 1; y >= 0; --y) {
		int x = 0;
		// Read the row
		for (int i = 0; i < bytesPerRow; ++i) {
			uint8 byte = input.readUInt8();
			for (int j = 0; (j < 8) && (x < width); ++x, j += bitsPerPixel) {
				int bit = ((byte << j) >> (8 - bitsPerPixel)) & mask;
				pixel4(x, y) = colorTable[bit];
			}
		}
	}
*/
    int hStart = 0;
    int hEnd   = 0;
    int hDir   = 0;

    if (height < 0) {
        height = -height;
        hStart = 0;
        hEnd   = height;
        hDir   = 1;
    } else {
        //height = height;
        hStart = height - 1;
        hEnd   = -1;
        hDir   = -1;
    }

    int BMScanWidth;
    uint8 BMGroup;
    uint8 BMPixel8;
    int currPixel;
    int dest;

    if (bitsPerPixel == 1) {
        // Note that this file is not necessarily grayscale, since it's possible
        // the palette is blue-and-white, or whatever. But of course most image
        // programs only write 1-bit images if they're black-and-white.

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = (width + 7) >> 3;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        // Powers of 2
        int pow2[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 3 * h * width;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMGroup = input.readUInt8();

                // Now we read the pixels. Usually there are eight pixels per byte,
                // since each pixel is represented by one bit, but if the width
                // is not a multiple of eight, the last byte will have some bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "width" number of pixels.
                for (int i = 7; i >= 0; --i) {
                    if (currPixel < width) {
                        int src  = ((BMGroup & pow2[i]) >> i);
                    
                        _byte[dest]     = palette[src].r;
                        _byte[dest + 1] = palette[src].g;
                        _byte[dest + 2] = palette[src].b;
                    
                        ++currPixel;
                        dest += 4;
                    }
                }
            }
        }

	} else if (bitsPerPixel == 4) {

        // For bitmaps, each scanline is dword-aligned.
        int BMScanWidth = (width+1) >> 1;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 4 * h * width;

            for (int w = 0; w < BMScanWidth; w++) {

                BMGroup = input.readUInt8();
                int src[2];
                src[0] = ((BMGroup & 0xF0) >> 4);
                src[1] = (BMGroup & 0x0F);

                // Now we read the pixels. Usually there are two pixels per byte,
                // since each pixel is represented by four bits, but if the width
                // is not a multiple of two, the last byte will have only four bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "Width" number of pixels.

                for (int i = 0; i < 2; ++i) {
                    if (currPixel < width) {
                        int tsrc  = src[i];
                    
                        _byte[dest]     = palette[tsrc].r;
                        _byte[dest + 1] = palette[tsrc].g;
                        _byte[dest + 2] = palette[tsrc].b;

                        ++currPixel;
                        dest += 4;
                    }
                }
            }
        }

	} else if (bitsPerPixel == 8) {
        
        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = width;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMPixel8 = input.readUInt8();

                if (currPixel < width) {
                    dest = 4 * ((h * width) + currPixel);
                    int src  = BMPixel8;
                    
                    _byte[dest]     = palette[src].r;
                    _byte[dest + 1] = palette[src].g;
                    _byte[dest + 2] = palette[src].b;
                    
                    ++currPixel;
                }
            }
        }
    }

	// Read the mask into the alpha channel
	int bitsPerRow  = width;
	int bytesPerRow = iCeil((double)bitsPerRow / 8);

    // For bitmaps, each scanline is dword-aligned.
    //BMScanWidth = (width + 1) >> 1;
    if (bytesPerRow & 3) {
        bytesPerRow += 4 - (bytesPerRow & 3);
    }
    
    for (int y = height - 1; y >= 0; --y) {
		int x = 0;
		// Read the row
		for (int i = 0; i < bytesPerRow; ++i) {
			uint8 byte = input.readUInt8();
			for (int j = 0; (j < 8) && (x < width); ++x, ++j) {
				int bit = (byte >> (7 - j)) & 0x01;
				pixel4(x, y).a = (1 - bit) * 0xFF;
			}
		}
	}

}


}
