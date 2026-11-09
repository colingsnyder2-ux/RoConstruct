// from server: 81% by tajop
extern "C" double __cdecl sqrt(double);

struct BitStream
{
    void WriteBits(const unsigned char* input, int numberOfBitsToWrite, bool rightAlignedBits);
    void WriteCompressed(float var);
    inline void Write(float var)
    {
        WriteBits((unsigned char*)&var, sizeof(var) * 8, true);
    }
    void WriteVector(float x, float y, float z);
};

void BitStream::WriteVector(float x, float y, float z)
{
    float magnitude = (float)sqrt((float)(x * x + y * y + z * z));
    Write(magnitude);
    if (magnitude > 0.0f)
    {
        WriteCompressed((float)(x / magnitude));
        WriteCompressed((float)(y / magnitude));
        WriteCompressed((float)(z / magnitude));
    }
}
