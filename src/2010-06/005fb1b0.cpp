// from server: 56% by atomic.potato
struct S
{
    int f(void *, void *);
    int *member;
};

extern "C" int G1_func_005faf80(void *, void *);

int S::f(void *a, void *b)
{
    int local[3];
    int *p = (int *)member[0];
    p += 4;
    int value = G1_func_005faf80(b, &local[0]);
    return ((int (__thiscall *)(int *, void *, int))(*p))(p, a, value);
}
