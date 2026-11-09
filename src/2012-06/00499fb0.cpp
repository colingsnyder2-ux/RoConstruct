// from server: 5% by atomic.potato
struct S
{
    unsigned char GetValue();
    void Process(bool* value);

    void f();
};

void S::Process(bool* value)
{
}

unsigned char S::GetValue()
{
    return 0;
}

void S::f()
{
    unsigned char value = GetValue();
    Process((bool*)&value);
}
