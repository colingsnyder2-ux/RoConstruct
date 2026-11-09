// from server: 41% by atomic.potato
extern "C" void __stdcall sub_78b610(void *, void *);

struct S
{
    void __stdcall f(void *, void *);
};

void __stdcall S::f(void *a, void *b)
{
    char flag = 0;
    void *p = 0;
    sub_78b610((char *)a + 4, &p);
}
