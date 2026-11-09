// from server: 34% by atomic.potato
struct S
{
    typedef void (__thiscall *Call)(S *, void *, void *, void *, void *, int);

    void f();
};

void S::f()
{
    void *a;
    void *b;
    void *c;
    void *d;
    Call p = *(Call *)*(void **)((char *)this + 20);
    p(this, &a, &b, &c, &d, *(int *)((char *)this + 20 + 4) +
      *(int *)((char *)this + 20 + 8));
}
