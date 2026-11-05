// from server: 70% by atomic.potato
struct S
{
    S* f(void*);
};

extern "C" void g(void*);

S* S::f(void* p)
{
    S* r = this;
    g(p);
    *(int*)((char*)r + 0x28) = 0xA5BEE8;
    *(int*)r = 0xA911BC;
    *(int*)((char*)r + 0x14) = 0xA911B4;
    *(int*)((char*)r + 0x28) = 0xA911A4;
    return r;
}
