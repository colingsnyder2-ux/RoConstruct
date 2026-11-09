// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl sub_8726d0();

int S::f()
{
    sub_8726d0();
    *(int*)this = 0x00a0cc14;
    *(int*)((char*)this + 0x218) = 0;
    return (int)this;
}
