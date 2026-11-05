// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector {
    float x, y, z;
};

struct Stream {
    void writeBits(const unsigned char *, int, bool);
    void writeFloats(float, float, float);
};

extern float minimumXZ;
extern float minimumY;
extern float maximumXZ;
extern float maximumY;
extern float scale;

extern "C" Stream *__cdecl writeFlag(Stream *, bool);

void __cdecl writePosition(Stream *stream, const Vector &value, bool force)
{
    if (!force &&
        !(value.x > maximumXZ) && !(value.x < minimumXZ) &&
        !(value.y > maximumY) && !(value.y < minimumY) &&
        !(value.z > maximumXZ) && !(value.z < minimumXZ))
    {
        writeFlag(stream, true);

        unsigned int x = (unsigned short)((value.x - minimumXZ) * scale);
        unsigned int y = (unsigned short)((value.y - minimumY) * scale);
        unsigned int z = (unsigned short)((value.z - minimumXZ) * scale);

        if ((unsigned short)x >= 0x8000)
            x = 0xffff;
        if ((unsigned short)y >= 0x4000)
            y = 0xffff;
        if ((unsigned short)z >= 0x8000)
            z = 0xffff;

        stream->writeBits((const unsigned char *)&x, 15, true);
        stream->writeBits((const unsigned char *)&y, 14, true);
        stream->writeBits((const unsigned char *)&z, 15, true);
    }
    else
    {
        writeFlag(stream, false);
        stream->writeFloats(value.x, value.y, value.z);
    }
}
