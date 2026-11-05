// from server: 46% by atomic.potato
struct Str_004430f0 { int words[8]; };

struct X_004430f0 {
    char pad[0xa4];
    Str_004430f0 value;
    Str_004430f0* copy(Str_004430f0* out);
};

extern "C" void* __stdcall get_thing_0xa42dc8();
extern "C" void* __stdcall get_thing_0xa42e08();
extern "C" void __stdcall str_ctor_0xa404c4(void*, const char*);
extern "C" void __stdcall str_dtor_0xa404d0(void*);
extern "C" int __stdcall compare_0x6515b0(void*, void*);

struct UDim2ComponentItem {
    char pad0[0x128];
    int mode;
    int a0;
    int a1;
    int a2;
    int a3;
    void func(int* out);
};

void UDim2ComponentItem::func(int* out)
{
    Str_004430f0 tmp;
    ((X_004430f0*)this)->copy(&tmp);

    char strbuf[0x18];
    void* p = get_thing_0xa42dc8();
    str_ctor_0xa404c4(strbuf, (const char*)p);

    int* src;
    if (mode - 1 == 0)
        src = &a0;
    else
        src = (int*)&tmp;

    char ok = (char)compare_0x6515b0(strbuf, src);

    str_dtor_0xa404d0(strbuf);
    get_thing_0xa42e08();

    if (ok) {
        out[0] = ((int*)&tmp)[0];
        out[1] = ((int*)&tmp)[1];
        out[2] = ((int*)&tmp)[2];
        out[3] = ((int*)&tmp)[3];
    } else {
        out[0] = a0;
        out[1] = a1;
        out[2] = a2;
        out[3] = a3;
    }
}
