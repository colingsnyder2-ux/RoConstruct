// from server: 71% by atomic.potato
extern "C" void * __cdecl sub_0054A7A0(void *, void *, void *, int *);
extern "C" void sub_00549410(void *);

struct ParseError
{
    void *f(void *, void *);
};

void *ParseError::f(void *a, void *b)
{
    int x = 0;
    sub_00549410(sub_0054A7A0(this, a, b, &x));
    return a;
}
