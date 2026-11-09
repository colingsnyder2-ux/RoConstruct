// from server: 100% by atomic.potato
struct S
{
    char value;
    void f(char);
};

void S::f(char value)
{
    *((char*)this + 0x119) = value;
}
