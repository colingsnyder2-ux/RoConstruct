// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_5980D0();

void S::f()
{
    *(int*)this = 0x00A8FF34;
    *((int*)this + 1) = 0x00A8FF28;
    *((int*)this + 6) = 0x00A8FF1C;
    *((int*)this + 7) = 0x00A8FF10;
    sub_5980D0();
}
