// from server: 100% by tester
struct S_00401b70 {
    long __stdcall f(void* p);
};

long __stdcall S_00401b70::f(void* p)
{
    if (p == 0)
        return (long)0x80004003;
    *(unsigned long*)((char*)p + 0) = *(unsigned long*)0x784c04;
    *(unsigned long*)((char*)p + 4) = *(unsigned long*)0x784c08;
    *(unsigned long*)((char*)p + 8) = *(unsigned long*)0x784c0c;
    *(unsigned long*)((char*)p + 12) = *(unsigned long*)0x784c10;
    return 0;
}
