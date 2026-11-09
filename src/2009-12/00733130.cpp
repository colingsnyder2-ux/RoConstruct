// from server: 32% by atomic.potato
extern "C" void __stdcall sub_5064C0(void *, const void *, unsigned char);

struct S
{
    unsigned char pad[0x94];
    unsigned char flag;
    void *value;
    void f();
};

void S::f()
{
    unsigned char value = flag;
    void *p = this->value;
    if (p)
        sub_5064C0(p, (const void *)0x71AAD0, value);
}
