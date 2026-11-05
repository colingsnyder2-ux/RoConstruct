// from server: 42% by colin
extern "C" {
extern double G_double_0079d420;
extern double G_double_00793198;
}

struct Replicator {
    bool readBitStream(void* bitStream, unsigned int bits, void* out);
    bool readVector3(void* bitStream, float* out);
};

bool Replicator::readVector3(void* bitStream, float* out)
{
    unsigned short raw;
    float x, y, z;
    float scale;

    if (!readBitStream(bitStream, 0x20, &x))
        return false;

    if (x == 0.0f) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
        return true;
    }

    if (readBitStream(bitStream, 0x10, &raw)) {
        x = (float)(int)raw / G_double_0079d420 - G_double_00793198;
    }

    if (readBitStream(bitStream, 0x10, &raw)) {
        y = (float)(int)raw / G_double_0079d420 - G_double_00793198;
    }

    if (!readBitStream(bitStream, 0x10, &raw))
        return false;

    z = (float)(int)raw / G_double_0079d420 - G_double_00793198;

    scale = x;
    out[0] = x * scale;
    out[1] = y * scale;
    out[2] = z * scale;
    return true;
}
