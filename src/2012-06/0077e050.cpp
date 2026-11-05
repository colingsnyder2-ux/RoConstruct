// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x00bb0d8c;
    *((int *)this + 1) = 0x00bb0d80;
    *((int *)this + 6) = 0x00bb0d74;
    *((int *)this + 7) = 0x00bb0d68;
}
