// from server: 58% by atomic.potato
struct S
{
};

extern "C" void *__cdecl sub_004ed710(void *);

void * __cdecl f(void *p)
{
    unsigned long *src = (unsigned long *)sub_004ed710(p);
    unsigned long *dst = (unsigned long *)p;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    return p;
}
