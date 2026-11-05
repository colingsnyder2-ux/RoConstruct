// from server: 92% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this) = 0x00BBFC2C;
    *(int *)((char *)this + 4) = 0x00BBFC24;
    *(int *)((char *)this + 0x18) = 0x00BBFC18;
    *(int *)((char *)this + 0x1C) = 0x00BBFC0C;
    *(int *)((char *)this + 0x80) = 0x00BBFC04;
}
