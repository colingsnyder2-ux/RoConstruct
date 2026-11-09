// from server: 8% by atomic.potato
struct S {
    int __stdcall f();
};

int __stdcall S::f()
{
    return 0;
}
