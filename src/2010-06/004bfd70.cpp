// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    return *(int*)((char*)this + 0xc8) != 0;
}
