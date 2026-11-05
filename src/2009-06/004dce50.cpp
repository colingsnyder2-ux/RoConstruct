// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
namespace RakNet {
class BitStream {
public:
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool Read(bool& var)
    {
        if (readOffset + 1 > numberOfBitsUsed)
            return false;
        if (data[readOffset >> 3] & (0x80 >> (readOffset & 7)))
            var = true;
        else
            var = false;
        readOffset++;
        return true;
    }
    bool Read(unsigned short& var);
    template <class templateType>
    bool ReadNormQuat(templateType& w, templateType& x, templateType& y, templateType& z);
};
template <class templateType>
bool BitStream::ReadNormQuat(templateType& w, templateType& x, templateType& y, templateType& z)
{
    bool cwNeg, cxNeg, cyNeg, czNeg;
    unsigned short cx,cy,cz;
    Read(cwNeg);
    Read(cxNeg);
    Read(cyNeg);
    Read(czNeg);
    Read(cx);
    Read(cy);
    if (!Read(cz))
        return false;
    x=(templateType)(cx/65535.0);
    y=(templateType)(cy/65535.0);
    z=(templateType)(cz/65535.0);
    if (cxNeg) x=-x;
    if (cyNeg) y=-y;
    if (czNeg) z=-z;
    float difference = 1.0f - x*x - y*y - z*z;
    if (difference < 0.0f)
        difference=0.0f;
    w = (templateType)(sqrt(difference));
    if (cwNeg)
        w=-w;
    return true;
}
template bool BitStream::ReadNormQuat<float>(float&, float&, float&, float&);
}
