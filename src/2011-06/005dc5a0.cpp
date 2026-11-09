// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_5980d0();

void S::f()
{
    ((int*)this)[0] = 0xa8ffd4;
    ((int*)this)[1] = 0xa8ffc8;
    ((int*)this)[6] = 0xa8ffbc;
    ((int*)this)[7] = 0xa8ffb0;
    sub_5980d0();
}
