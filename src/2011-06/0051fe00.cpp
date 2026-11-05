// from server: 100% by atomic.potato
struct S {
    char pad0[0x87c];
    unsigned char value;
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    this->value = value;
}
