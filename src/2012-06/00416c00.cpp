// from server: 18% by atomic.potato
struct S {
    void f();
};

extern "C" void __cdecl sub_009826cc();

void S::f()
{
    *(int*)this = 0xb45f04;
    sub_009826cc();
}
