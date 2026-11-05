// from server: 44% by atomic.potato
extern "C" void __cdecl sub_5dc450(void *, void *, void *, unsigned int);

struct S
{
    S * __cdecl f(void *);
};

S *S::f(void *arg)
{
    unsigned char local[20];
    *(unsigned int *)(local + 8) = 0;
    sub_5dc450(this, *(void **)this, local, 20);
    return (S *)arg;
}
