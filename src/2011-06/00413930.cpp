// from server: 18% by atomic.potato
struct S {
    void f();
};

extern "C" void __cdecl sub_80A61C();

void S::f()
{
    *(int*)this = 0xA5DEDC;
    sub_80A61C();
}
