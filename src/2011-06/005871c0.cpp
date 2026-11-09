// from server: 29% by atomic.potato
extern "C" float __cdecl sub_80bad0(float);

float sub_5871c0(const float* p)
{
    float value = p[0x214 / 4];
    return sub_80bad0(value);
}
