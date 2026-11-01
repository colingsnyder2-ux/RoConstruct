// from server: 76% by atomic.potato
struct S_func_0067e670 {
    char pad0[0x24];
    int a;
    int b;
    int c;

    void* f(void* arg);
};

struct S_func_0066cae0 {
    char pad[360];
    void* m_p;
    void* g();
};

extern "C" void __stdcall f_00540050(void*, void*);
extern "C" void __stdcall f_00541890(void*);
extern "C" void* __stdcall f_0067e1d0(void*);

void* S_func_0067e670::f(void* arg)
{
    S_func_0067e670* p = (S_func_0067e670*)((char*)this - 0x2b8);
    S_func_0066cae0* r = (S_func_0066cae0*)f_0067e1d0(p);
    if (r)
    {
        void* src = r->g();
        f_00540050(arg, src);
        S_func_0067e670* d = (S_func_0067e670*)arg;
        d->a = *(int*)((char*)src + 0x24);
        d->b = *(int*)((char*)src + 0x28);
        d->c = *(int*)((char*)src + 0x2c);
        return arg;
    }
    f_00541890(arg);
    return arg;
}
