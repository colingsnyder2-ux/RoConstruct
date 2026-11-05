// from server: 92% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0) = 0xbc63d4;
    *(int *)((char *)this + 4) = 0xbc63c8;
    *(int *)((char *)this + 0x18) = 0xbc63bc;
    *(int *)((char *)this + 0x1c) = 0xbc63b0;
    *(int *)((char *)this + 0x80) = 0xbc6384;
}
