// from server: 68% by atomic.potato
struct S
{
    unsigned char pad0[8];
    unsigned char value;
    unsigned char flag;
    unsigned char pad10[10];
    unsigned char enabled;
    void f();
};

extern "C" void __stdcall sub_936300(S *);

void S::f()
{
    if (enabled != 0 && flag == 0 && value == *(unsigned char *)((char *)this + 8))
    {
        sub_936300(this);
        enabled = 0;
    }
}
