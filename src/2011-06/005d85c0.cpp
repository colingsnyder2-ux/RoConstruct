// from server: 28% by atomic.potato
extern "C" void* __cdecl sub_80A05E(unsigned int);
extern "C" void __cdecl sub_713C40(void*);

struct Inner {
    void ctor();
};

struct Outer {
    void __cdecl method(Inner*, int);
    void method2(Inner*, int);
};

void Outer::method(Inner* p, int flag)
{
    void* mem = sub_80A05E(0xb0);
    Inner* obj;
    if (mem) {
        sub_713C40(mem);
        obj = (Inner*)mem;
    } else {
        obj = 0;
    }
    Inner* tmp = obj;
    int zero = 0;
    this->method2(tmp, zero);
}
