// from server: 0% by atomic.potato
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);

struct CXTPPropertyGridItemEnum
{
    void sub_86b760();
    void sub_86b7a0();
    void* sub_86b6a0();
    void sub_86bd00(int, int);
};

void CXTPPropertyGridItemEnum::sub_86bd00(int a, int b)
{
    sub_86b760();
    sub_86b7a0();
    void* p = sub_86b6a0();
    char* s = (char*)p;
    void* q = *(void**)(s + 0xd0);
    if (q != 0 && *(int*)(s + 0x10) == 0)
    {
        *(void**)(s + 0x10) = GetProcAddress(q, (const char*)0x9ffea4);
    }
    void* fn = *(void**)(s + 0x10);
    if (fn != 0)
    {
        int r = ((int(__stdcall*)(int, int))fn)(a, b);
        *(int*)((char*)this + 4) = r;
    }
}
