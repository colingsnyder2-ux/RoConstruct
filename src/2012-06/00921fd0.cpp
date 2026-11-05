// from server: 78% by atomic.potato
extern "C" void __stdcall sub_9172a0(void *, void *);
extern "C" void __stdcall sub_9623e0(void *, void *);

struct S
{
    void *field8;
    void *f(unsigned int);
};

void *S::f(unsigned int value)
{
    sub_9172a0((void *)value, this);
    sub_9623e0(field8, (void *)value);
    return 0;
}
