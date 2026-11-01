// from server: 89% by atomic.potato
struct S
{
    void f(void *);
    char padding[0x90];
    void *field_90;
};

void call_7f4496(void *, void *);

void S::f(void *p)
{
    call_7f4496(this, p);
    if (p == field_90)
        field_90 = 0;
}
