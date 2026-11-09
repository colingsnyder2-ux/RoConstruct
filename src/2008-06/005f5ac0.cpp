// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    return (*(unsigned int*)((char*)this + 0xb0) >> 4) & 1;
}
