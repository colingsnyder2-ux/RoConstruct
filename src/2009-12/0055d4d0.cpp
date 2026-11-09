// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = *(int**)((char*)this + 4);
    if (p == 0 || p == (int*)((char*)this + 4))
        return 1;
    return 0;
}
