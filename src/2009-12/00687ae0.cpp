// from server: 70% by atomic.potato
struct S
{
    int f(int, int);
    int field;
};

extern "C" void sub_006b1700(S *, int);

int S::f(int value, int unused)
{
    sub_006b1700(this, value);
    field = value;
    return (int)this;
}
