// from server: 100% by atomic.potato
struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    *(unsigned char*)((char*)this + 0xbf8) = value;
}
