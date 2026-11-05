// from server: 46% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long *, long);

struct Inner {
    char pad0[8];
    char enabled;
    char pad1[0x12];
    char pad2[0x18];
};

struct Outer {
    char pad0[8];
    Inner inner;
    int field;
    void __cdecl method(float, int, float);
};

extern "C" void __stdcall sub_7e1e90(void *, void *);
extern "C" void __stdcall sub_7e1f00(void *);
extern "C" void __stdcall sub_74be20(void *, int, float, float);

void Outer::method(float a, int b, float c)
{
    char buf[8];
    sub_7e1e90(&inner, buf);
    field = 0;
    if (inner.enabled)
    {
        Inner *p = &inner;
        char *q = (char *)p + 0x18;
        sub_74be20(q, b, c, a);
    }
    field = -1;
    sub_7e1f00(buf);
}
