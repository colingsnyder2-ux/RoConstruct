// from server: 13% by atomic.potato
struct Inner;

struct Outer {
    char pad0[0x28];
    Inner* inner;
    char pad1[0x10];
    void* vtbl4;
    void construct();
};

struct Inner {
    char pad0[0x28];
    void* vtbl;
    char pad1[0x14];
    void* vtbl2;
    char pad2[0x10];
    void* vtbl3;
    void init(Outer* owner);
};

extern "C" void* __cdecl sub_98211a(unsigned int);

void Inner::init(Outer* owner)
{
    *(void**)((char*)this + 0x28) = (void*)0xb43c34;
    *(void**)this = (void*)0xb9902c;
    *(void**)((char*)this + 0x14) = (void*)0xb99024;
    *(void**)((char*)this + 0x28) = (void*)0xb99014;
}

void Outer::construct()
{
    Inner* p = (Inner*)sub_98211a(0x2c);
    if (p != 0) {
        p->init((Outer*)((char*)this - 0x28));
    }
}
