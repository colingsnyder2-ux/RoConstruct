// from server: 54% by pitbull
struct S {
    void __cdecl f(int a, int b, int c);
};

extern "C" {
    void __stdcall sub_77ddac(void*);
    void __stdcall sub_77dd94(void*, const char*, ...);
    void* __stdcall sub_77d678(void*, int);
    void __stdcall sub_77dd98(void*, void*);
    void __stdcall sub_77ddbc(void*);
    int __fastcall sub_42f770(void*, int, int);
}

void S::f(int a, int b, int c)
{
    char buf1[16];
    char buf2[16];
    char buf3[16];

    sub_77ddac(buf1);
    sub_77dd94(buf1, "%s_%d", (const char*)0x78ab5c, a);
    void* p1 = sub_77d678(buf1, 0);
    sub_77dd98(p1, buf1);
    if (sub_42f770(p1, b, c)) {
        sub_77dd94(buf2, "%s_%d", (const char*)0x78ab50, a);
        void* p2 = sub_77d678(buf2, 1);
        sub_77dd98(p2, buf2);
        sub_42f770(p2, b, c);
        sub_77dd94(buf3, "%s_%d_D", (const char*)0x78ab44, a);
        void* p3 = sub_77d678(buf3, 2);
        sub_77dd98(p3, buf3);
        sub_42f770(p3, b, c);
    }
    sub_77ddbc(buf1);
}
