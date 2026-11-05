// from server: 69% by atomic.potato
struct S
{
    char padding[0x14];
    int* field14;
    void __cdecl f(double a, double b);
};

extern "C" void* __stdcall malloc(unsigned int);
extern "C" void __cdecl exit(int);
extern "C" void* __cdecl __iob_func();
extern "C" int __cdecl fprintf(void*, const char*, const char*);

void S::f(double a, double b)
{
    char* p = (char*)malloc(0x18);
    if (p == 0)
    {
        fprintf((char*)__iob_func() + 0x40, "gpc malloc failure: %s", "vertex node creation");
        exit(0);
    }
    *(double*)p = a;
    *(double*)(p + 8) = b;
    int* q = (int*)field14;
    *(int*)(p + 0x10) = q[2];
    int* r = (int*)field14;
    r[2] = (int)p;
}
