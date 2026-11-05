// from server: 70% by atomic.potato
struct S
{
    void f();
    unsigned char padding[0x1dc];
    unsigned char value;
};

void S::f()
{
    value = 0;
}
