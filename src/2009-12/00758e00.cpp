// from server: 80% by atomic.potato
extern "C" void Function_0040C080(void);

struct S
{
    unsigned char padding[0x2f0];
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (this->value == value)
        return;

    this->value = value;
    Function_0040C080();
}
