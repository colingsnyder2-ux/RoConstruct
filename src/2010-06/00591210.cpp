// from server: 23% by atomic.potato
extern "C" void* __stdcall make_desc_00590e10(const char*, int);
extern "C" void* __stdcall alloc_0058e8d0(int, int, int, int, int, int, int);
extern "C" void __stdcall free_007a799a(void*);
extern "C" void* __stdcall func_00590e10();

struct Descriptor {
    void* field0;
    void attach(void*);
};

struct Base {
    void* vtable;
    void method_00443800(void*);
};

struct S : Base {
    S(int, int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f, int g)
{
    void* p = alloc_0058e8d0(a, b, c, d, e, f, g);
    void* q = *(void**)p;
    *(void**)p = 0;
    void* r = &q;
    void* s = func_00590e10();
    this->method_00443800(s);
    free_007a799a(q);
    this->vtable = (void*)0xa28fbc;
}
