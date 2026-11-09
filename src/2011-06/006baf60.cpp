// from server: 38% by atomic.potato
extern "C" void __stdcall func_006b3a70(void*, void*);
extern "C" void __stdcall func_006b3020(void*);

struct S {
    void func_006b8c60(void*);
    void f(void*, int, int, int, int, int, int, int, int, int, int, int, int);
};

void S::f(void* a, int, int, int, int, int, int, int, int, int, int, int, int) {
    char buf[0x30];
    void* p = a;
    func_006b3a70(buf, &p);
    this->func_006b8c60(a);
    func_006b3020(buf);
}
