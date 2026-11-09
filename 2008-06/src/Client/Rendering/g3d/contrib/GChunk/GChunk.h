/**
 @file GChunk.h
 @maintainer Morgan McGuire, morgan@graphics3d.com
 @created 2005-06-07
 @edite   2005-06-07
 */
#ifndef G3D_GCHUNK_H
#define G3D_GCHUNK_H

namespace G3D {
/** 
  Helper for writing files with extensible and discoverable formats.

  <B>Writing a Chunk:</B>

  <PRE>
    BinaryOutput b(...);
    enum MyFormat {HEIGHTS, POSITION};
    Array<int32> heights;
    ...

    Chunk c(b, HEIGHTS, Chunk::INT32, heights.size());
    for (int i = 0; i < heights.size(); ++i) {
        b.writeInt32(heights[i]);
    }
    c.finish();
   </PRE>

  <B>Reading a Chunk:</B>

  <HR NOSHADE>
  Chunks have the following binary format:

  <PRE>
  uint16            name (application defined code)
  uint16            format (Chunk::BinaryFormat)
  int32             size (not including these 8 header bytes)
  format[num]       ...data...
  </PRE>

  The number of data elements is <CODE>num = size / Chunk::byteSize(format)</CODE>.

 */
class GChunk {
private:

    enum {HEADER_SIZE = 8};

    /** Keeps track of whether this chunk is for reading or writing */
    enum {WRITE = 0, READ = 1, UNINITIALIZED}  mode;
    
    bool                        finished;

    /** Start of the header relative to the beginning of the file. Data 
        payload is HEADER_SIZE bytes later. */
    int32                       startPos;


    void readInit(G3D::BinaryInput& b) {
        mode    = READ;
        finished = false;

        startPos = b.getPosition();

        name   = b.readUInt16();
        format = (BinaryFormat)b.readUInt16();

        debugAssertM((format > FIRST_BINFMT) && (format < LAST_BINFMT), 
            "GChunk file is corrupted-- format tag is invalid.");

        size   = b.readInt32();
        debugAssertM(size < b.getLength(), 
            "GChunk file is corrupted-- chunk is larger than file!");

        if (format != CUSTOM_BINFMT) {
            int32 s = byteSize(format);
            if (s != -1) {
                count  = size / s;
            } else {
                count = -1;
            }
        } else {
            count  = -1;
        }
    }

public:

    /** Application-defined code for this chunk. */
    uint16                      name;

    /** BinaryFormat of the data payload. */
    BinaryFormat                format;

    /** Size of the data payload in bytes, excluding the 8 header bytes. */
    int32                       size;

    /** Number of elements in the data payload. -1 if unknown because the format is CUSTOM or string.*/
    int32                       count;

    GChunk() : mode(UNINITIALIZED), finished(true) {}

    /** Begin a read chunk.  After the constructor finishes
        you can access the member fields to discover the chunk
        type.  Use GChunk::finish() to jump to the end of the chunk.
      */
    GChunk(G3D::BinaryInput& b) {
        readInit(b);
    }

    /** Shortcut for:
      <PRE>
       GChunk c(b);
       alwaysAssertM(c.name == name);
      </PRE>
      */
    GChunk(G3D::BinaryInput& b, uint16 _name) {
        readInit(b);
        alwaysAssertM(name == _name, "File does not match format.");
    }

    GChunk(G3D::BinaryInput& b, uint16 _name, BinaryFormat _format) {
        readInit(b);
        alwaysAssertM(name == _name, "File does not match format.");
        alwaysAssertM(format == _format, "File does not match format.");
    }

    GChunk(G3D::BinaryInput& b, uint16 _name, BinaryFormat _format, int32 _count) {
        readInit(b);
        alwaysAssertM(name == _name, "File does not match format.");
        alwaysAssertM(format == _format, "File does not match format.");        
        alwaysAssertM(count == _count, "File does not match format.");
    }

    /** Begin a write chunk.  Use GChunk::finish() when done.*/
    GChunk(G3D::BinaryOutput& b, uint16 name, BinaryFormat format = CUSTOM_BINFMT) :
        startPos(b.getPosition()), name(name), format(format), count(count), finished(false), mode(WRITE) {

        b.writeUInt16(name);
        b.writeUInt16(format);

        // Leave space for the payload size
        b.skip(sizeof(int32));
    }

    ~GChunk() {
        debugAssertM(finished, "GChunk went out of scope or destroyed without being finished or aborted.");
    }

    /** Stop writing to a chunk abruptly.  Avoids the assertion failure that will
        occur in the destructor if a chunk is destroyed without being finished. */
    void abort() {
        debugAssertM(! finished, "Aborted a chunk that was already finished.");
        finished = true;
    }

    /** End writing to the chunk and write the header. */
    void finish(G3D::BinaryInput& b) {
        debugAssertM(mode == READ, "Called finish with a binary input on a write chunk.");
        debugAssertM(! finished, "Called finish on the same chunk twice.");

        b.setPosition(startPos + size + HEADER_SIZE);

        finished = true;
    }

    // Not called commit because we perform it on input as well
    /** End writing to the chunk and write the header. Only call when at the end of the chunk.
        Leaves the file pointer at the end of the chunk. */
    void finish(G3D::BinaryOutput& b) {
        debugAssertM(mode == WRITE, "Called finish with a binary output on a read chunk.");
        debugAssertM(! finished, "Called finish on the same chunk twice.");

        // Write the size into the header
        int32 currentPos = b.position();
        b.setPosition(startPos + HEADER_SIZE - 4);
        b.writeInt32(currentPos - startPos - HEADER_SIZE);
        b.setPosition(currentPos);

        finished = true;
    }
};

}

#endif

