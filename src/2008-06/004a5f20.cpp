// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2008-06 004a5f20  unit: RBX::VHint::?$FactoryProduct::Creator  size: 466 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a5f20


extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct S
{
    int bitCount;
    int capacity;
    int readOffset;
    unsigned char* data;

    bool readBits(unsigned char* output, int count, bool rightAligned);
    bool readQuaternion(float& w, float& x, float& y, float& z);
    inline bool Read(bool& var)
    {
        if (readOffset + 1 > bitCount)
            return false;
        if (data[readOffset >> 3] & (0x80 >> (readOffset & 7)))
            var = true;
        else
            var = false;
        readOffset++;
        return true;
    }
};

bool S::readQuaternion(float& w, float& x, float& y, float& z)
{
    bool negativeW, negativeX, negativeY, negativeZ;
    unsigned short encodedX, encodedY, encodedZ;

    Read(negativeW);
    Read(negativeX);
    Read(negativeY);
    Read(negativeZ);

    readBits((unsigned char*)&encodedX, 16, true);
    readBits((unsigned char*)&encodedY, 16, true);
    if (!readBits((unsigned char*)&encodedZ, 16, true))
        return false;

    x = negativeX ? -(encodedX * (1.0 / 65535.0))
                  : encodedX * (1.0 / 65535.0);
    y = negativeY ? -(encodedY * (1.0 / 65535.0))
                  : encodedY * (1.0 / 65535.0);
    z = negativeZ ? -(encodedZ * (1.0 / 65535.0))
                  : encodedZ * (1.0 / 65535.0);

    float remainder = 1.0f - x * x - y * y - z * z;
    if (remainder <= 0.0f)
        w = 0.0f;
    else
        w = (float)(negativeW ? -sqrt(remainder) : sqrt(remainder));
    return true;
}
