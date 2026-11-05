// from server: 76% by atomic.potato
struct S {
    unsigned char pad[0xf8];
    unsigned char value;
    void f(unsigned char value);
};

extern "C" void sub_0040C080();

void S::f(unsigned char value)
{
    if (value != this->value)
        return;
    this->value = value;
    sub_0040C080();
}
