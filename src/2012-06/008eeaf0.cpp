// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0xbee164;
    *((int *)this + 1) = 0xbee15c;
    *((int *)this + 6) = 0xbee150;
    *((int *)this + 7) = 0xbee144;
}
