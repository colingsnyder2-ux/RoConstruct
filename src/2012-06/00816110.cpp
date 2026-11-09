// from server: 48% by atomic.potato
struct S
{
    void * __cdecl f(void *, int);
};

void *S::f(void *a, int b)
{
    void *result = 0;
    ((S *)a)->f(this, 0);
    return a;
}
