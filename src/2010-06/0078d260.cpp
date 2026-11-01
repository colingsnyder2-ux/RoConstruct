// from server: 66% by atomic.potato
struct S
{
    void f(int);
};

extern "C" void sub760bf0(void *, int);
extern "C" void sub750ac0(void *, void *);

void S::f(int value)
{
    void *p = *(void **)((char *)this + 8);
    sub760bf0(p, value);
    sub750ac0((void *)value, this);
}
