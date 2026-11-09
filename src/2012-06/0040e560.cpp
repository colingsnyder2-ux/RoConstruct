// from server: 61% by atomic.potato
struct S
{
    int field;
    S *value(int x);
};

extern "C" void f(void *, int);

S *S::value(int x)
{
    f(this, x);
    field = 0x00b4426c;
    return this;
}
