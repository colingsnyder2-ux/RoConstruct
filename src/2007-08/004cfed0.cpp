// from server: 55% by Intel
struct TextureProxyBase {
    float __cdecl func_004cfed0(const float* src);
};

float TextureProxyBase::func_004cfed0(const float* src)
{
    float v0 = src[0];
    float v1 = src[1];
    float v2 = src[2];

    if (v0 < 0.0f) v0 = -v0;
    if (v1 < 0.0f) v1 = -v1;
    if (v2 < 0.0f) v2 = -v2;

    float max01 = (v0 > v1) ? v0 : v1;
    float result = (max01 > v2) ? max01 : v2;

    return result;
}
