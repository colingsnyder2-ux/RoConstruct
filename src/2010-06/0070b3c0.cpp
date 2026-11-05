// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int* p = *(int**)((char*)this + 0x18);
    return p[0x28 / 4] + p[1] * 6;
}
