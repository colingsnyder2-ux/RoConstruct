// from server: 54% by Intel
struct TextureProxyBase {
    float __cdecl func_004cfed0(const float* v);
};

float TextureProxyBase::func_004cfed0(const float* v)
{
    float a = v[0];
    float b = v[1];
    float c = v[2];

    if (a >= 0.0f) a = -a;
    if (b < 0.0f) b = -b;
    if (c < 0.0f) c = -c;

    float max_val = a;
    if (b > max_val) max_val = b;
    if (c > max_val) max_val = c;

    return max_val;
}
