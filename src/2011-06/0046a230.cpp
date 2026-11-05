// from server: 5% by atomic.potato
struct S
{
    unsigned char GetValue();
    void SetValue(unsigned char *);

    void f();
};

unsigned char S::GetValue()
{
    return 0;
}

void S::SetValue(unsigned char *)
{
}

void S::f()
{
    unsigned char value = GetValue();
    SetValue(&value);
}
