// from server: 29% by atomic.potato
extern "C" {
    int __cdecl func_00564c00(int, int);
    void __cdecl func_00565240(void*);
    int __cdecl func_00565290(void*, void*);
}

struct S {
    void* f(int a, int b, void* c);
};

void* S::f(int a, int b, void* c)
{
    char buf[0x38];
    void* p;
    int neg;
    int total;
    void* str;

    total = a + b;
    neg = a;
    if (neg < 0)
        neg = -neg;
    p = (void*)func_00564c00(neg, total);
    if (a < 0) {
        p = (char*)p - 1;
        *(char*)p = '-';
    }
    func_00565240(buf);
    if (func_00565290(buf, c)) {
        func_00565240(buf);
        return p;
    }
    func_00565240(buf);
    return p;
}
