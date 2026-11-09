// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x00bb0bc4;
    *((int *)this + 1) = 0x00bb0bb8;
    *((int *)this + 6) = 0x00bb0bac;
    *((int *)this + 7) = 0x00bb0ba0;
}
