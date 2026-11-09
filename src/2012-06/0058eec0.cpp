// from server: 91% by atomic.potato
struct S
{
    double value;
    void *f(void *, void *);
};

extern "C" void * __stdcall sub_00977d20(void *, void *, double);

void *S::f(void *a, void *b)
{
    sub_00977d20(a, b, *(double *)((char *)this + 0x220));
    return b;
}
