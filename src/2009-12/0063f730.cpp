// from server: 66% by atomic.potato
extern "C" void* __stdcall FindResourceA(void*, const char*, const char*);
extern "C" int __stdcall WideCharToMultiByte(unsigned int, unsigned int, const wchar_t*, int, char*, int, const char*, int*);
extern void G1_func_00402b80(unsigned int);
extern void G1_func_00404c40();
extern void* G1_func_0063ebc0(void*, void*, unsigned int);

struct S {
    void* field0;
    int f(void* a, unsigned int b);
};

int S::f(void* a, unsigned int b)
{
    void* h = FindResourceA(a, (const char*)((b >> 4) + 1), (const char*)6);
    if (h == 0)
        return 0;
    unsigned short* p = (unsigned short*)G1_func_0063ebc0(a, h, b);
    if (p == 0)
        return 0;
    int n = WideCharToMultiByte(3, 0, (const wchar_t*)(p + 1), *p, 0, 0, 0, 0);
    int* q = (int*)field0;
    int cap = *(int*)((char*)q - 8);
    int len = *(int*)((char*)q - 12);
    if (n > cap || n < 0) {
        G1_func_00404c40();
    }
    WideCharToMultiByte(3, 0, (const wchar_t*)(p + 1), *p, (char*)field0, n, 0, 0);
    if (n >= 0 && n <= *(int*)((char*)field0 - 8)) {
        *(int*)((char*)field0 - 12) = n;
        ((char*)field0)[n] = 0;
        return 1;
    }
    G1_func_00402b80(0x80070057);
    return 0;
}
