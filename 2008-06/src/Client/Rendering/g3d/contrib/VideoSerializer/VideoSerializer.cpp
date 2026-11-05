#include "VideoSerializer.h"

void VideoSerializer::serialize(BinaryOutput& b) const {
    Encoding encoding = preferredEncoding;

    if ((encoding == ENCODING_TIME_DIFF1) && (previousFrame == NULL)) {
        // There was no previous frame, so switch to a different encoding.
        encoding = ENCODING_RAW;
    }
    b.writeUInt32(encoding);
    b.writeBool8(zip);
    b.writeUInt32(frameFormat);
    b.writeUInt32(width);
    b.writeUInt32(height);

    BinaryOutput* b2 = &b;

    if (zip) {
        // Hand a new BinaryOutput to the serializers so that
        // we can compress the data.
        b2 = new BinaryOutput("<memory>", G3D_LITTLE_ENDIAN);
    }

    switch (encoding) {
    case ENCODING_RAW:
        serializeRaw(*b2);
        break;

    case ENCODING_TIME_DIFF1:
        serializeTimeDiff1(*b2);
        break;

    case ENCODING_SPACE_DIFF1:
        serializeSpaceDiff1(*b2);
        break;

    default:
        debugAssert(false);
    }

    if (zip) {
        // Compress
        b2->compress();

        // Copy data to the original BinaryOutput
        b.writeBytes(b2->getCArray(), b2->length());

        // Free the BinaryOutput we created.  No need 
        // to commit it, since we already pulled the data out.
        delete b2;
    }

    b2 = NULL;
}


void VideoSerializer::deserialize(BinaryInput& b)  {
    Encoding encoding = (Encoding)b.readUInt32();
    zip = b.readBool8();
    frameFormat = (Format)b.readUInt32();
    width = b.readUInt32();
    height = b.readUInt32();

    BinaryInput* b2 = &b;

    if (zip) {
        // Hand a new BinarInput to the deserializers
        b2 = new BinaryInput(b.getCArray() + b.getPosition(), 
                             b.getLength() - b.getPosition(), 
                             G3D_LITTLE_ENDIAN, true, true);
    }

    switch (encoding) {
    case ENCODING_RAW:
        deserializeRaw(*b2);
        break;

    case ENCODING_TIME_DIFF1:
        deserializeTimeDiff1(*b2);
        break;

    case ENCODING_SPACE_DIFF1:
        deserializeSpaceDiff1(*b2);
        break;

    default:
        debugAssert(false);
    }

    if (zip) {
        delete b2;
    }
    b2 = NULL;
}


void VideoSerializer::serializeRaw(BinaryOutput& b) const {
    uint32 n = width * height * bytesPerPixel(frameFormat);
    b.writeUInt32(n);
    b.writeBytes(currentFrame, n);
}


void VideoSerializer::deserializeRaw(BinaryInput& b) {
    uint32 n = width * height * bytesPerPixel(frameFormat);
    int x = b.readUInt32();
    debugAssert(x == n);
    b.readBytes(currentFrame, n);
}


void VideoSerializer::serializeTimeDiff1(BinaryOutput& b) const {
    static const int BITS = 4, MAXDELTA = 7, ESCAPE = 15;

    uint32 n = width * height * bytesPerPixel(frameFormat);
    
    // Reserve space for the size header
    int sizePos = b.getPosition();
    b.writeUInt32(0);

    b.beginBits();

    // Iterate over the bytes in the frames
    for (size_t i = 0; i < n; ++i) {
        int P = previousFrame[i];
        int C = currentFrame[i];

        int delta = C - P;

        if (iAbs(delta) > MAXDELTA) {
            // Escape
            b.writeBits(ESCAPE, BITS);
            b.writeBits(C, 8);
        } else {
            // Send delta
            b.writeBits(MAXDELTA + delta, BITS);
        }
    }

    b.endBits();

    int endPos = b.getPosition();
    b.setPosition(sizePos);
    b.writeUInt32(endPos - sizePos - 4);
    b.setPosition(endPos);
}


void VideoSerializer::deserializeTimeDiff1(BinaryInput& b) {
    static const int BITS = 4, MAXDELTA = 7, ESCAPE = 15;

    uint32 n = width * height * bytesPerPixel(frameFormat);

    debugAssert(currentFrame != NULL);
    debugAssert(previousFrame != NULL);

    // Read the byte size (although we won't use it).
    int size = b.readUInt32();

    b.beginBits();

    for (size_t i = 0; i < n; ++i) {
        int a = b.readBits(BITS);

        if (a < ESCAPE) {
            int delta = a - MAXDELTA;
            currentFrame[i] = previousFrame[i] + delta;
        } else {
            // Escape; the following 8 bits are the real value.
            // We can't read a uint8 because the 8 bits will
            // rarely be aligned on a byte boundary.
            currentFrame[i] = b.readBits(8);
        }
    }

    b.endBits();
}


void VideoSerializer::serializeSpaceDiff1(BinaryOutput& b) const {
    static const int BITS = 4, MAXDELTA = 7, MAXSHIFTDELTA = 14;
    static const int ESCAPE = 15;

    uint32 n = width * height * bytesPerPixel(frameFormat);

    // Reserve space for the size header
    int sizePos = b.getPosition();
    b.writeUInt32(0);

    int PStride = channelStride(frameFormat);

    // Write out the first Pstride bytes, since we have
    // no values against which to compute a delta.
    for (int i = 0; i < PStride; ++i) {
        b.writeUInt8(currentFrame[i]);
    }

    b.beginBits();

    // Iterate over the bytes in the frame.
    for (size_t i = PStride; i < n; ++i) {
        int P = currentFrame[i - PStride];
        int C = currentFrame[i];
        int delta = C - P + MAXDELTA;

        if ((delta >= 0) && (delta <= MAXSHIFTDELTA)) {
            b.writeBits(delta, BITS);
        } else {
            // Escape and then write 8 components
            b.writeBits(ESCAPE, BITS);
            b.writeBits(C, 8);
        }
    }

    b.endBits();

    int endPos = b.getPosition();
    b.setPosition(sizePos);
    b.writeUInt32(endPos - sizePos - 4);
    b.setPosition(endPos);
}



void VideoSerializer::deserializeSpaceDiff1(BinaryInput& b) {
    static const int BITS = 4, MAXDELTA = 7, MAXSHIFTDELTA = 14;
    static const int ESCAPE = 15;

    // Optimization note: since we're using 4 bit numbers,
    // we could obtain them faster by readin bytes and masking
    // the top and bottom halves.

    uint32 n = width * height * bytesPerPixel(frameFormat);

    debugAssert(currentFrame != NULL);

    // Read the byte size (although we won't use it).
    int size = b.readUInt32();
    
    int PStride = channelStride(frameFormat);

    // Read the first Pstride bytes, since we have
    // no values against which to compute a delta.
    for (int i = 0; i < PStride; ++i) {
        currentFrame[i] = b.readUInt8();
    }

    b.beginBits();

    for (size_t i = PStride; i < n; ++i) {
        int delta = b.readBits(BITS);

        if (delta >= ESCAPE) {
            currentFrame[i] = b.readBits(8);
        } else {
            currentFrame[i] = currentFrame[i - PStride] + (delta - MAXDELTA);
        }
    }
    b.endBits();
}
