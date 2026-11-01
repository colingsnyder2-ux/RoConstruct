// from server: 89% by atomic.potato
extern "C" void* __stdcall func_0080a31c();
extern "C" void* __stdcall func_0080b2ea(void*, void*, void*, void*, void*);

struct T {
    void __thiscall func_00430c00();
};

struct S {
    int f(int);
};

int S::f(int)
{
    char* p = (char*)func_0080a31c();
    p = *(char**)(p + 4);
    p = *(char**)(p + 0x20);
    void* r = func_0080b2ea(p, 0, (void*)0xc06080, (void*)0xc0e110, 0);
    ((T*)r)->func_00430c00();
    return 0;
}
