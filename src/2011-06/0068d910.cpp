// from server: 28% by atomic.potato
extern "C" void* __cdecl func_0080a05e(unsigned int);

struct T {
    void func_00732df0();
};

struct U {
    void func_0068d790(void*, void*);
};

struct S {
    void __cdecl f(void* a, void* b);
};

void S::f(void* a, void* b)
{
    void* p = func_0080a05e(0x98);
    void* q = 0;
    if (p) {
        ((T*)p)->func_00732df0();
        q = p;
    }
    ((U*)this)->func_0068d790(q, b);
}
