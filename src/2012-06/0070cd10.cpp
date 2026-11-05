// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl G_0070ca70();

void S::f()
{
    *(int *)this = 0x00ba031c;
    *(int *)((char *)this + 4) = 0x00ba0314;
    *(int *)((char *)this + 0x18) = 0x00ba0308;
    *(int *)((char *)this + 0x1c) = 0x00ba02fc;
    *(int *)((char *)this + 0x80) = 0x00ba02f4;
    G_0070ca70();
}
