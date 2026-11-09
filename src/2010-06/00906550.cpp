// from server: 34% by atomic.potato
struct S
{
    int f(int);
    int (*vtable)(S *, int);
    int field;
};

int S::f(int value)
{
    return vtable(this, value);
}
