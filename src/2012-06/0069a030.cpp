// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0xb93adc;
    *(int *)((char *)this + 4) = 0xb93ad0;
    *(int *)((char *)this + 0x18) = 0xb93ac4;
    *(int *)((char *)this + 0x1c) = 0xb93ab8;
}
