// from server: 52% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x28];
    Inner* p;
    void method(int a, int b);
};

extern "C" void* __cdecl sub_6c22c0();
extern "C" void __cdecl sub_577110(void*);

void Outer::method(int a, int b) {
    Inner* inner = p;
    void* vt = *(void**)inner;
    void (*fn)(void*, int, int) = *(void (**)(void*, int, int))((char*)vt + 8);
    int tmp;
    fn(inner, a, (int)&tmp);
    void* r = sub_6c22c0();
    *(void**)&tmp = r;
    sub_577110((char*)&tmp + 4);
}
