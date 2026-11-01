// from server: 100% by king_originala
extern const float lowerBound;
extern const float quantizationScale;

struct S {
    void writeBits(const unsigned char* data, int count, bool flag);
    void f(float value);
};

void S::f(float value)
{
    unsigned int encoded = (unsigned short)(
        ((lowerBound > value ? (double)lowerBound :
          (1.0 < value ? 1.0 : (double)value)) + 1.0) *
        quantizationScale);
    writeBits((const unsigned char*)&encoded, 16, true);
}
