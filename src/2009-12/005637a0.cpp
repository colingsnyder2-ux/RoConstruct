// from server: 61% by atomic.potato
struct S
{
    char pad_0[88];
    int value_58;
    char pad_5c[4];
    double value_60;
    char pad_68[104];
    int value_d8;
    void f(int value);
};

double g_9a44d0 = 4294967296.0;

void S::f(int value)
{
    if (value > value_d8)
        value_d8 = value;
    ++value_58;
    value_60 += (double)value + (value < 0 ? g_9a44d0 : 0.0);
}
