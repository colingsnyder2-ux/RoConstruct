// from server: 23% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void __cdecl sub_53e4a0();

struct Inner {
    void ctor();
};

struct Outer {
    void __cdecl method(Inner* p, int a);
    void method2(Inner* p, int a);
};

void Outer::method(Inner* p, int a) {
    void* mem = sub_98211a(0x180);
    Inner* obj = 0;
    if (mem) {
        obj = (Inner*)mem;
        sub_53e4a0();
    }
    method2(obj, a);
}
