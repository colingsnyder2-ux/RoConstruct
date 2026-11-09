// from server: 88% by atomic.potato
struct S
{
    int (**vtable)(int, int);
    int f();
};

extern "C" void __cdecl sub_47d070(int);

int S::f()
{
    int x = vtable[1](0, 0);
    sub_47d070(x);
    return 0x44ce1a;
}
