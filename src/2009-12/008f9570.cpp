// from server: 27% by atomic.potato
extern "C" int __cdecl func_008f5ef1(float, float);

void __stdcall func_008f9570(float* out, float* a, float* m)
{
    float x = a[0] * m[0] + a[1] * m[4];
    float y = a[0] * m[1] + a[1] * m[5];
    float z = a[0] * m[3] + a[1] * m[7];
    x += m[12];
    y += m[13];
    z += m[15];
    out[0] = x;
    out[1] = y;
    if (func_008f5ef1(1.0f, z) == 0)
    {
        float inv = 1.0f / z;
        out[0] = out[0] * inv;
        out[1] = out[1] * inv;
    }
}
