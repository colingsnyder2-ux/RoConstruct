// from server: 71% by atomic.potato
struct S
{
    void *f(void *);
    void *g(void *);
};

void *f547610(void *, void *);
void f76a190(void *, void *);

void *S::f(void *p)
{
    void *a;
    void *b;
    a = f547610(this, (char *)p + 4);
    b = *(void **)a;
    f76a190(this, &b);
    return this;
}
