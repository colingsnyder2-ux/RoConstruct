// from server: 43% by atomic.potato
typedef int (__cdecl *Fn)(int, int, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int count = *(int *)((char *)this + 4);
    if (count <= 0)
        return 0;

    Fn fn = (Fn)0x7ee920;
    return fn(value, count, 0) != -1;
}
