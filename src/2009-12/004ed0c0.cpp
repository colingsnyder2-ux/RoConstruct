// from server: 26% by atomic.potato
struct S
{
    int __cdecl f(int *, int);
};

int S::f(int *p, int value)
{
    int state = 0;
    *p = value;
    state |= 1;
    return *p;
}
