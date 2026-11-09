// from server: 69% by atomic.potato
struct Inner
{
    char pad[4];
    void *p;
};

struct S
{
    char pad[0x24];
    char *base;
    void method(void *a, Inner *b);
};

extern "C" void __stdcall sub_4B3050(void *dst, void *src);
extern "C" void __stdcall sub_4C04A0(void *self, void *arg);

void S::method(void *a, Inner *b)
{
    char *p = (char *)a;
    if (p)
        p -= 0x1c;
    else
        p = 0;
    char *q = base + (int)p;
    void *tmp;
    sub_4B3050(&tmp, b->p);
    sub_4C04A0(q, &tmp);
}
