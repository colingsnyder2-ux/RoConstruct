// from server: 3% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_70b410();

void S::f()
{
    char buf[0x28];
    (void)buf;
    sub_70b410();
}
