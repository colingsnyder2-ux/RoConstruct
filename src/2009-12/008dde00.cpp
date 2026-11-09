// from server: 100% by atomic.potato
struct S {
    void* Init();
};

struct Base {
    static void* Init();
};

void* S::Init()
{
    Base::Init();
    *(unsigned long *)this = 0x00a0b44c;
    *(unsigned long *)((char *)this + 0x74) = 0;

    return this;
}
