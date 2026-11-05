// from server: 100% by atomic.potato
struct S
{
    int* f();
};

int* S::f()
{
    int* p = *(int**)((char*)this + 0x2688);
    if (p)
        return *(int**)((char*)p + 0x15c);
    return 0;
}
