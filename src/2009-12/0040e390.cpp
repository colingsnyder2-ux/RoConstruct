// from server: 93% by atomic.potato
struct S
{
    int __stdcall f();
};

int __stdcall S::f()
{
    int* p = *(int**)this;
    p[4] = p[2];
    return 0;
}
