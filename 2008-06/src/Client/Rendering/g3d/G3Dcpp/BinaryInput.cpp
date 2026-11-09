/**
 @file BinaryInput.cpp
 
 @author Morgan McGuire, graphics3d.com
 
 @created 2001-08-09
 @edited  2005-02-24


  <PRE>
    {    
    BinaryOutput b("c:/tmp/test.b", BinaryOutput::LITTLE_ENDIAN);

    float f = 3.1415926;
    int i = 1027221;
    std::string s = "Hello World!";

    b.writeFloat32(f);
    b.writeInt32(i);
    b.writeString(s);
    b.commit();
    

    BinaryInput in("c:/tmp/test.b", BinaryInput::LITTLE_ENDIAN);

    debugAssert(f == in.readFloat32());
    int ii = in.readInt32();
    debugAssert(i == ii);
    debugAssert(s == in.readString());
    }
  </PRE>
 */

#include "G3D/platform.h"
#include "G3D/BinaryInput.h"
#include "G3D/Array.h"
#include "G3D/fileutils.h"
#ifdef G3D_WIN32
  #include "../zlib/zlib.h"
#else
  #include <zlib.h>
#endif

namespace G3D {

void BinaryInput::readBool8(std::vector<bool>& out, int n) {
    out.resize(n);
    // std::vector optimizes bool in a way that prevents fast reading
    for (int i = 0; i < n ; ++i) {
        out[i] = readBool8();
    }
}


void BinaryInput::readBool8(Array<bool>& out, int n) {
    out.resize(n);
    readBool8(out.begin(), n);
}


#define IMPLEMENT_READER(ucase, lcase)\
void BinaryInput::read##ucase(std::vector<lcase>& out, int n) {\
    out.resize(n);\
    read##ucase(&out[0], n);\
}\
\
\
void BinaryInput::read##ucase(Array<lcase>& out, int n) {\
    out.resize(n);\
    read##ucase(out.begin(), n);\
}


IMPLEMENT_READER(UInt8,   uint8)
IMPLEMENT_READER(Int8,    int8)
IMPLEMENT_READER(UInt16,  uint16)
IMPLEMENT_READER(Int16,   int16)
IMPLEMENT_READER(UInt32,  uint32)
IMPLEMENT_READER(Int32,   int32)
IMPLEMENT_READER(UInt64,  uint64)
IMPLEMENT_READER(Int64,   int64)
IMPLEMENT_READER(Float32, float32)
IMPLEMENT_READER(Float64, float64)    

#undef IMPLEMENT_READER

// Data structures that are one byte per element can be 
// directly copied, regardles of endian-ness.
#define IMPLEMENT_READER(ucase, lcase)\
void BinaryInput::read##ucase(lcase* out, int n) {\
    if (sizeof(lcase) == 1) {\
        readBytes(out, n);\
    } else {\
        for (int i = 0; i < n ; ++i) {\
            out[i] = read##ucase();\
        }\
    }\
}

IMPLEMENT_READER(Bool8,   bool)
IMPLEMENT_READER(UInt8,   uint8)
IMPLEMENT_READER(Int8,    int8)

#undef IMPLEMENT_READER


#define IMPLEMENT_READER(ucase, lcase)\
void BinaryInput::read##ucase(lcase* out, int n) {\
    if (swapBytes) {\
        for (int i = 0; i < n; ++i) {\
            out[i] = read##ucase();\
        }\
    } else {\
        readBytes(out, sizeof(lcase) * n);\
    }\
}


IMPLEMENT_READER(UInt16,  uint16)
IMPLEMENT_READER(Int16,   int16)
IMPLEMENT_READER(UInt32,  uint32)
IMPLEMENT_READER(Int32,   int32)
IMPLEMENT_READER(UInt64,  uint64)
IMPLEMENT_READER(Int64,   int64)
IMPLEMENT_READER(Float32, float32)
IMPLEMENT_READER(Float64, float64)    

#undef IMPLEMENT_READER

void BinaryInput::loadIntoMemory(int startPosition, int minLength) {
    // Load the next section of the file
    debugAssertM(filename != "<memory>", "Read past end of file.");

    int absPos = alreadyRead + pos;

    if (bufferLength < minLength) {
        // The current buffer isn't big enough to hold the chunk we want to read.
        // This happens if there was little memory available during the initial constructor
        // read but more memory has since been freed.
        bufferLength = minLength;
		debugAssert(freeBuffer);
        buffer = (uint8*)System::realloc(buffer, bufferLength);
        if (buffer == NULL) {
            throw "Tried to read a larger memory chunk than could fit in memory. (2)";
        }
    }

    alreadyRead = startPosition;

    FILE* file = fopen(filename.c_str(), "rb");
    debugAssert(file);

    int ret = fseek(file, alreadyRead, SEEK_SET);
    debugAssert(ret == 0);

    int toRead = iMin(bufferLength, length - alreadyRead);
    ret = fread(buffer, 1, toRead, file);
    debugAssert(ret == toRead);
    fclose(file);
    file = NULL;

    pos = absPos - alreadyRead;
    debugAssert(pos >= 0);
}



const bool BinaryInput::NO_COPY = false;
    
static bool needSwapBytes(G3DEndian fileEndian) {
    return (fileEndian != System::machineEndian());
}


/** Helper used by the constructors for decompression */
static uint32 readUInt32(const uint8* data, bool swapBytes) {
    if (swapBytes) {
        uint8 out[4];
        out[0] = data[3];
        out[1] = data[2];
        out[2] = data[1];
        out[3] = data[0];
        return *((uint32*)out);
    } else {
        return *((uint32*)data);
    }
}

BinaryInput::BinaryInput(
    const uint8*        data,
    int                 dataLen,
    G3DEndian           dataEndian,
    bool                compressed,
    bool                copyMemory) {

    debugAssert(! (compressed && !copyMemory));
    beginEndBits = 0;
    bitPos = 0;
    alreadyRead = 0;
    bufferLength = 0;

    freeBuffer = copyMemory || compressed;

    this->fileEndian = dataEndian;
    this->filename = "<memory>";
	pos = 0;
    swapBytes = needSwapBytes(fileEndian);

    if (compressed) {
        // Read the decompressed size from the first 4 bytes
        length = G3D::readUInt32(data, swapBytes);

		debugAssert(freeBuffer);
        buffer = (uint8*)System::malloc(length);

        uint32 L = length;
        // Decompress with zlib
        int result = uncompress(buffer, (unsigned long*)&L, data + 4, dataLen - 4);
        length = L;
        bufferLength = L;
        debugAssert(result == Z_OK); (void)result;

    } else {
	    length = dataLen;
        bufferLength = length;
        if (! copyMemory) {
 			debugAssert(!freeBuffer);
            buffer = const_cast<uint8*>(data);
        } else {
			debugAssert(freeBuffer);
            buffer = (uint8*)System::malloc(length);
            memcpy(buffer, data, dataLen);
        }
    }
}


BinaryInput::BinaryInput(
    const std::string&  filename,
    G3DEndian           fileEndian,
    bool                compressed) {

    alreadyRead = 0;
    freeBuffer = true;
    this->fileEndian = fileEndian;
    this->filename = filename;
	buffer = NULL;
    bufferLength = 0;
	length = 0;
	pos = 0;
    beginEndBits = 0;
    bitPos = 0;

    // Update global file tracker
    _internal::currentFilesUsed.append(filename);
    
    swapBytes = needSwapBytes(fileEndian);

    // Figure out how big the file is and verify that it exists.
    length = fileLength(filename);

    // Read the file into memory
    FILE* file = fopen(filename.c_str(), "rb");

	if (! file || (length == -1)) {
        throw format("File not found: \"%s\"", filename.c_str());
		return;
	}

    if (! compressed && (length > INITIAL_BUFFER_LENGTH)) {
        // Read only a subset of the file so we don't consume
        // all available memory.
        bufferLength = INITIAL_BUFFER_LENGTH;
    } else {
        // Either the length is fine or the file is compressed
        // and requires us to read the whole thing for zlib.
        bufferLength = length;
    }

	debugAssert(freeBuffer);
    buffer = (uint8*)System::malloc(bufferLength);
    if (buffer == NULL) {
        if (compressed) {
            throw "Not enough memory to load compressed file. (1)";
        }

        // Try to allocate a small array; not much memory is available.
        // Give up if we can't allocate even 1k.
        while ((buffer == NULL) && (bufferLength > 1024)) {
            bufferLength /= 2;
            buffer = (uint8*)System::malloc(bufferLength);
        }
    }
    debugAssert(buffer);
    
    fread(buffer, bufferLength, sizeof(int8), file);
    fclose(file);
    file = NULL;

    pos = 0;

    if (compressed) {
        if (bufferLength != length) {
            throw "Not enough memory to load compressed file. (2)";
        }

        // Decompress
        // Use the existing buffer as the source, allocate
        // a new buffer to use as the destination.

        int tempLength = length;
        length = G3D::readUInt32(buffer, swapBytes);

        uint8* tempBuffer = buffer;
        buffer = (uint8*)System::malloc(length);

        debugAssert(buffer);
        debugAssert(isValidHeapPointer(tempBuffer));
        debugAssert(isValidHeapPointer(buffer));

        unsigned long L = length;
        int result = uncompress(buffer, &L, tempBuffer + 4, tempLength - 4);
        length = L;
        bufferLength = length;

        debugAssert(result == Z_OK); (void)result;

        System::free(tempBuffer);
    }
}


BinaryInput::~BinaryInput() {

    if (freeBuffer) {
        System::free(buffer);
    }
    buffer = NULL;
}


void BinaryInput::readBytes(int n, void* bytes) {
    prepareToRead(n);
    debugAssert(isValidPointer(bytes));

    memcpy(bytes, buffer + pos, n);
    pos += n;
}


uint64 BinaryInput::readUInt64() {
    prepareToRead(8);
    uint8 out[8];

    if (swapBytes) {
        out[0] = buffer[pos + 7];
        out[1] = buffer[pos + 6];
        out[2] = buffer[pos + 5];
        out[3] = buffer[pos + 4];
        out[4] = buffer[pos + 3];
        out[5] = buffer[pos + 2];
        out[6] = buffer[pos + 1];
        out[7] = buffer[pos + 0];
    } else {
        *(uint64*)out = *(uint64*)(buffer + pos);
    }

    pos += 8;
    return *(uint64*)out;
}


std::string BinaryInput::readString(int n) {
    prepareToRead(n);
    debugAssertM((pos + n) <= length, "Read past end of file");
    
    char *s = (char*)System::malloc(n + 1);
    assert(s != NULL);

    memcpy(s, buffer + pos, n);
    // There may not be a null, so make sure
    // we add one.
    s[n] = '\0';

    std::string out = s;
    System::free(s);
    s = NULL;

    pos += n;

    return out;

}


std::string BinaryInput::readString() {
    int n = 0;

    if ((int)pos + (int)alreadyRead + n < (int)length - 1) {
        prepareToRead(1);
    }

    if (((int)pos + (int)alreadyRead + (int)n < length - 1) && (buffer[pos + n] != '\0')) {
        ++n;
        while (((int)pos + (int)alreadyRead + n < (int)length - 1) && (buffer[pos + n] != '\0')) {
            prepareToRead(1);
            ++n;
        }
    }

    // Consume NULL
    ++n;

    return readString(n);
}


std::string BinaryInput::readStringEven() {
    std::string x = readString();
    if (hasMore() && (G3D::isOdd(x.length() + 1))) {
        skip(1);
    }
    return x;
}


std::string BinaryInput::readString32() {
    int len = readUInt32();
    return readString(len);
}


Vector4 BinaryInput::readVector4() {
    double x = readFloat32();
    double y = readFloat32();
    double z = readFloat32();
    double w = readFloat32();
    return Vector4(x, y, z, w);
}


Vector3 BinaryInput::readVector3() {
    double x = readFloat32();
    double y = readFloat32();
    double z = readFloat32();
    return Vector3(x, y, z);
}


Vector2 BinaryInput::readVector2() {
    double x = readFloat32();
    double y = readFloat32();
    return Vector2(x, y);
}


Color4 BinaryInput::readColor4() {
    double r = readFloat32();
    double g = readFloat32();
    double b = readFloat32();
    double a = readFloat32();
    return Color4(r, g, b, a);
}


Color3 BinaryInput::readColor3() {
    double r = readFloat32();
    double g = readFloat32();
    double b = readFloat32();
    return Color3(r, g, b);
}


void BinaryInput::beginBits() {
    debugAssert(beginEndBits == 0);
    beginEndBits = 1;
    bitPos = 0;

    debugAssertM(hasMore(), "Can't call beginBits when at the end of a file");
    bitString = readUInt8();
}


uint32 BinaryInput::readBits(int numBits) {
    debugAssert(beginEndBits == 1);

    uint32 out = 0;

    const int total = numBits;
    while (numBits > 0) {
        if (bitPos > 7) {
            // Consume a new byte for reading.  We do this at the beginning
            // of the loop so that we don't try to read past the end of the file.
            bitPos = 0;
            bitString = readUInt8();
        }

        // Slide the lowest bit of the bitString into
        // the correct position.
        out |= (bitString & 1) << (total - numBits);

        // Shift over to the next bit
        bitString = bitString >> 1;
        ++bitPos;
        --numBits;
    }

    return out;
}


void BinaryInput::endBits() {
    debugAssert(beginEndBits == 1);
    if (bitPos == 0) {
        // Put back the last byte we read
        --pos;
    }
    beginEndBits = 0;
    bitPos = 0;
}

}
