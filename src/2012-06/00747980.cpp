// from server: 92% by atomic.potato
struct S {
    void f();
};

void S::f()
{
    *(int *)this = 0xBAAE54;
    *((int *)this + 1) = 0xBAAE4C;
    *((int *)this + 6) = 0xBAAE40;
    *((int *)this + 7) = 0xBAAE34;
    *((int *)this + 32) = 0xBAAE08;
}
