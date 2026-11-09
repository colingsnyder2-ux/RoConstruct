// from server: 53% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    ((void**)((char*)this + 0x200))[1] = 0;
}
