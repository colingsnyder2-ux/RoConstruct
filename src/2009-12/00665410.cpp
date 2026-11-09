// from server: 100% by atomic.potato
struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    *((unsigned char*)this + 0xbe8) = value;
}
