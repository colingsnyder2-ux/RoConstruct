// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = (int*)((char*)this + 4);
    int v = *p;
    if (v != 0 && v != (int)p)
        return 0;
    return 1;
}
