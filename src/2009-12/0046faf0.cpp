// from server: 61% by atomic.potato
struct S_0046faf0
{
    struct V
    {
        void (__thiscall *f4)(V *);
        void (__thiscall *f8)(V *);
    };

    char pad[0xf0];
    V *member_f0;
    unsigned char f(unsigned char value);
};

unsigned char S_0046faf0::f(unsigned char value)
{
    V *p = member_f0;
    unsigned char result = (p == (V *)value);
    if (p)
        p->f4(p);
    if (p)
        p->f8(p);
    return result;
}
