// from server: 13% by atomic.potato
struct S
{
    void *field;
    void *f();
};

void *S::f()
{
    return field;
}
