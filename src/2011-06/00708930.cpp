// from server: 43% by atomic.potato
struct S
{
    int pad[7];

    int f(int *a, int *b);
};

extern "C" int __cdecl sub_708870(int *value, int *out);
typedef int (__cdecl *Callback)(int *, int *);

int S::f(int *a, int *b)
{
    int *p = *(int **)((char *)this + 0x1c);
    int value = *b;
    sub_708870(&value, &value);
    Callback fn = *(Callback *)(*(int **)p + 0x0c);
    return fn(p, a);
}
