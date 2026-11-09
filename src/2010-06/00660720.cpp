// from server: 77% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* a = *(int**)((char*)this);
    return ((int (__thiscall *)(int, int))a[0])(a[1] + a[2], a[3]);
}
