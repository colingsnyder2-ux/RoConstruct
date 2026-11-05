// from server: 70% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int*)((char*)this + 0x34) = -2;
}
