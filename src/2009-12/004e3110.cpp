// from server: 44% by atomic.potato
struct S {
    int f();
};

int S::f()
{
    int *p = *(int **)((char *)this + 0x14);
    return (int)((char *)p + 0x68);
}
