// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void S_f_tail();

void S::f()
{
    *(int *)this = 0xbc68fc;
    *(int *)((char *)this + 4) = 0xbc68f0;
    *(int *)((char *)this + 0x18) = 0xbc68e4;
    *(int *)((char *)this + 0x1c) = 0xbc68d8;
    *(int *)((char *)this + 0x80) = 0xbc68ac;
    S_f_tail();
}
