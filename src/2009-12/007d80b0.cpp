// from server: 64% by atomic.potato
extern "C" void sub_7dd790(void *, void *);

struct S
{
    S(void *, void *);
};

S::S(void *a, void *b)
{
    sub_7dd790(this, b);
    *(void **)this = (void *)0x9ef7cc;
    *((void **)this + 1) = (void *)0x9ef7c4;
}
