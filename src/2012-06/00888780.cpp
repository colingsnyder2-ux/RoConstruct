// from server: 72% by atomic.potato
struct FunctionalTest
{
    char padding_ac[172];
    int field_ac;
    int field_b0;

    void f(int value);
    void g();
};

void FunctionalTest::f(int value)
{
    if (value == field_ac)
    {
        if (--field_b0 == 0)
            g();
    }
}

void FunctionalTest::g()
{
}
