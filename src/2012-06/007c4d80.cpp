// from server: 21% by atomic.potato
struct S
{
    unsigned char Get(unsigned char);
    void Set(unsigned char, unsigned char);
};

unsigned char S::Get(unsigned char value)
{
    return value;
}

void S::Set(unsigned char value, unsigned char result)
{
    (void)value;
    (void)result;
}

struct T : S
{
    void f(unsigned char);
};

void T::f(unsigned char value)
{
    unsigned char result = Get(value);
    Set(value, result);
}
