// from server: 18% by atomic.potato
struct S {
    void f();
};

extern "C" void __cdecl sub_007f3e1e();

void S::f()
{
    *(int*)this = 0x9a17a8;
    sub_007f3e1e();
}
