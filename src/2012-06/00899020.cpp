// from server: 92% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0) = 0x00bdbe74;
    *(int *)((char *)this + 4) = 0x00bdbe6c;
    *(int *)((char *)this + 0x18) = 0x00bdbe60;
    *(int *)((char *)this + 0x1c) = 0x00bdbe54;
    *(int *)((char *)this + 0x80) = 0x00bdbe28;
}
