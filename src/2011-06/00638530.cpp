// from server: 66% by atomic.potato
extern "C" void __cdecl sub_5D3420(void *, int);

struct S
{
};

void * __cdecl f(void *p, void *q)
{
    sub_5D3420(q, 0);
    return q;
}
