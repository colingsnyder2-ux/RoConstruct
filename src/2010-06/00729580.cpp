// from server: 40% by atomic.potato
extern "C" int __cdecl sub_722E10(void *a, int b, int c);
extern "C" void *__cdecl sub_721FA0(void *a, int b);
extern "C" void __cdecl sub_7217A0(void *a, int b, int c);
extern "C" void __cdecl sub_721B30(void *a, int b);

extern int dword_BE2A4C;
extern int dword_BE2A50;

struct LuaArguments
{
};

int __cdecl method(void *arg)
{
    void *v1 = (void *)sub_722E10(arg, 1, dword_BE2A4C);
    void *v2 = (void *)sub_722E10(arg, 2, dword_BE2A50);

    float dx = *(float *)((char *)v2 + 4) - *(float *)((char *)v1 + 8);
    float dz = *(float *)((char *)v2 + 8) - *(float *)((char *)v1 + 0xc);
    float dy = *(float *)((char *)v2 + 0) - *(float *)((char *)v1 + 4);

    float dot = *(float *)((char *)v1 + 0x14) * dx
              + *(float *)((char *)v1 + 0x18) * dz
              + *(float *)((char *)v1 + 0x10) * dy;

    float px, py, pz;
    if (dot < 0.0f)
    {
        px = *(float *)((char *)v1 + 4);
        py = *(float *)((char *)v1 + 8);
        pz = *(float *)((char *)v1 + 0xc);
    }
    else
    {
        px = *(float *)((char *)v1 + 4) + *(float *)((char *)v1 + 0x10) * dot;
        py = *(float *)((char *)v1 + 8) + *(float *)((char *)v1 + 0x14) * dot;
        pz = *(float *)((char *)v1 + 0xc) + *(float *)((char *)v1 + 0x18) * dot;
    }

    float *out = (float *)sub_721FA0(arg, 0xc);
    if (out)
    {
        out[0] = px;
        out[1] = py;
        out[2] = pz;
    }

    sub_7217A0(arg, -10000, dword_BE2A50);
    sub_721B30(arg, -2);
    return 1;
}
