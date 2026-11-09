// from server: 59% by atomic.potato
extern "C" int __cdecl sub_983a37(int);

struct S
{
    int f(void *, void *);
};

int S::f(void *, void *b)
{
    int x = *(int *)((char *)b - 4) ^ (int)b;
    return sub_983a37(x);
}
