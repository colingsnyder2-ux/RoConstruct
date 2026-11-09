// from server: 92% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x00bbfd3c;
    *((int *)this + 1) = 0x00bbfd34;
    *((int *)this + 6) = 0x00bbfd28;
    *((int *)this + 7) = 0x00bbfd1c;
    *((int *)this + 32) = 0x00bbfd14;
}
