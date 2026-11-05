// from server: 88% by atomic.potato
struct S
{
    void f(unsigned int value);
    char pad[88];
    int field58;
};

void S::f(unsigned int value)
{
    field58 = (field58 & ~4) | (value ? 0 : 4);
}
