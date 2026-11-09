// from server: 29% by atomic.potato
extern "C" void* __cdecl sub_80A05E(unsigned int);
extern "C" void __cdecl sub_713120(void*);

struct Inner {
    void ctor();
};

struct Outer {
    void method(Inner*);
};

void Outer::method(Inner* p)
{
    void* mem = sub_80A05E(0xD8);
    Inner* obj = 0;
    if (mem) {
        sub_713120(mem);
        obj = (Inner*)mem;
    }
    this->method(obj);
}
