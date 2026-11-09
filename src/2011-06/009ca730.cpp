// from server: 37% by atomic.potato
struct S {
    unsigned char padding[0x41];
    unsigned char field_41;
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    field_41 = value;
}
