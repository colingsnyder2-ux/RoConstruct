/**
 
 @author Morgan McGuire, matrix@graphics3d.com
 */

#ifndef VIDEO_SERIALIZER_H
#define VIDEO_SERIALIZER_H

#include <G3DAll.h>

/**
 Losslessly encodes images and video streams at about 1.6:1 compression with
 fast compression and decompression, ideal for streaming over a network or
 playing from disk.
 */
class VideoSerializer {
public:

    /**
     ENCODING_RAW       
       Frames are serialized as:
                  
            uint32      encoding (will be ENCODING_RAW)
            uint32      format
            uint32      width
            uint32      height
            uint32      numBytes (will be width*height*bytesPerPixel(format))
            uint8[numBytes] uint8's that are the frame data

     <P>
     ENCODING_TIME_DIFF1 
            The maximum compression is 8:3, the minimum is 8:11.  Compression is
            best when frames resemble the previous one.  Generally gives 1:5 : 1
            compression.

            uint32      encoding (will be ENCODING_TIME_DIFF1)
            uint32      format
            uint32      width
            uint32      height
            uint32      numBytes
            uint8[numBytes] Frame data as deltas from previous frame.
                        Data is packed into 4-bit chunks that are deltas
                        from the previous frame.  If the chunk is 1111,
                        it is immediately followed by an absolute 8-bit
                        number that is the value.  Otherwise, the value
                        is the previous frame's value + the chunk - 7.

     ENCODING_SPACE_DIFF1
            Same as time diff except: (1) the first PStride elements
            are 8-bit numbers representing absolute values and (2) each
            delta is relative to the current byte minus PStride instead
            of the previous frame.  Gives about 1:6 : 1 compression.
     */ 
    // Design note:  I tried many other schemes, including a single 
    // compression bit for all three channels, 3-bit schemes, and
    // a single escape for all three channels.  In each case, compression
    // was worse.  The FELICS system claims 2:1 lossless compression for images,
    // however it is much more complicated.
    enum Encoding {
        ENCODING_RAW,
        ENCODING_TIME_DIFF1,
        ENCODING_SPACE_DIFF1
    };

    /**
     R8G8B8             Every pixel contains 8 bits of red, 8 bits of green, and 8 bits of blue.
     <P>
     BAYER_R8G8_G8B8    Pixels are interpreted based on their position.  Even rows, starting with row 0,
                        alternate between red and green values.  Odd rows alternate between green and blue.
                        The width and height of the frame describes the total number of pixels, regardless of 
                        their color.
    <P>
     L8                 8-bit monochrome.
     */
    enum Format {
        FORMAT_R8G8B8,
        FORMAT_L8,
        FORMAT_BAYER_R8G8_G8B8,
    };

    /** Number of bytes in a pixel.  Note that Bayer pixels are monochrome pixels that
        alternate in interpretation.*/
    static int bytesPerPixel(Format f) {
        switch (f) {
        case FORMAT_R8G8B8:
            return 3;
        default:
            return 1;
        }
    }

private:

    void serializeRaw(BinaryOutput& b) const;
    void deserializeRaw(BinaryInput& b);

    /** Called after the width, height, and format have been read. */
    void serializeTimeDiff1(BinaryOutput& b) const;
    void deserializeTimeDiff1(BinaryInput& b);

    void serializeSpaceDiff1(BinaryOutput& b) const;
    void deserializeSpaceDiff1(BinaryInput& b);

    // Bytes between elements that should correspond for diffing purposes.
    // 1 for monochrome, 2 for Bayer, 3 for RGB
    int prevStride;
    inline static int channelStride(Format f) {
        switch (f) {
        case FORMAT_R8G8B8:
            return 3;
        case FORMAT_L8:
            return 1;
        case FORMAT_BAYER_R8G8_G8B8:
            return 2;
        }
        debugAssert(false);
        return 0;
    }

public:

    void serialize(BinaryOutput& b) const;
    void deserialize(BinaryInput& b);

    /** Pointer to the bytes of the current frame.  Set this before invoking serialize 
        or deserialize.*/
    uint8*              currentFrame;

    /** May be NULL when not using time-based encoding. */
    uint8*              previousFrame;

    /** Number of pixel columns, not necessarily the number of bytes in that row.*/
    int                 width;
    int                 height;

    /** The encoding that the system will attempt to use first when sending data.
        Not guaranteed to be followed. */
    Encoding            preferredEncoding;

    /* If true, the data is compressed by BinaryOutput's internal Lempel-Ziv
       compressor after being encoded.  Can give better compression ratios
       at the cost of slower compression/decompression times. For noisy images
	   this may only improve compression a few percent. */
    bool                zip;

    /** Format of currentFrame and previousFrame */
    Format              frameFormat;


    VideoSerializer() :
        zip(false), 
        preferredEncoding(ENCODING_SPACE_DIFF1),
        width(0), height(0), 
        frameFormat(FORMAT_R8G8B8),
        currentFrame(NULL),
        previousFrame(NULL) {}
};

#endif

