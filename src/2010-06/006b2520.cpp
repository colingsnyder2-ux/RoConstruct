// from server: 53% by atomic.potato
struct Inner {
    char pad0[0x38];
    int* field38;
};

struct Outer {
    char pad0[0xc];
    int* begin;
    char pad10[4];
    int* end;
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" float* __cdecl sub_4b4d50(int* p);
extern "C" void __fastcall sub_6ae830(int* p, void* unused, void* arg);

struct V {
    int f(int* a, Outer* b);
};

int V::f(int* a, Outer* b)
{
    int* p = a ? (int*)((char*)a - 0x1c) : 0;
    Inner* inner = (Inner*)((char*)this + 0x38);
    int* s = (int*)((char*)inner->field38 + (int)p);

    int n = (int)((char*)b->end - (char*)b->begin) >> 2;
    if (n <= 0)
        _invalid_parameter_noinfo();

    float* v = sub_4b4d50(b->begin);
    float x = v[0];
    float y = v[1];
    float z = v[2];

    if (*s != 0) {
        struct Arg {
            void* vt;
            float x, y, z;
        } arg;
        arg.vt = (void*)0x6adb00;
        arg.x = x;
        arg.y = y;
        arg.z = z;
        sub_6ae830(s, 0, &arg);
    }
    return 0;
}
