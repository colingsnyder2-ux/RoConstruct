// from server: 36% by colin
struct ReportAbuseVerb {
    void sub_452270(int);
    void f();
};

extern "C" {
    void __stdcall sub_77ddac(void*);
    void __stdcall sub_77d59c(void*, unsigned int);
    void __stdcall sub_77dd98(void*);
    void __stdcall sub_77ddbc(void*);
    void __stdcall sub_77e698(void*, const char*);
    void __cdecl sub_6303f4(void*, int, int, const char*, int, void*);
    int  __cdecl sub_6303ee(void*);
    void __cdecl sub_6303e8(void*, void*);
    void __cdecl sub_6303dc(void*);
    void __cdecl sub_630a1e(void);
}

void ReportAbuseVerb::f()
{
    char buf[0x1d8];
    (void)buf;
    sub_77ddac(buf);
    sub_77d59c(buf, 0xd0);
    sub_77dd98(buf);
    sub_6303f4(buf, 1, 0x7919f8, 0, 6, buf);
    if (sub_6303ee(buf) == 1) {
        sub_6303e8(buf, buf);
        sub_77dd98(buf);
        sub_77e698(buf, 0);
        sub_452270(0);
    }
    sub_6303dc(buf);
    sub_77ddbc(buf);
    sub_77ddbc(buf);
}
