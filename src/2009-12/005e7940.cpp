// from server: 58% by atomic.potato
struct S
{
};

struct V
{
    float value30;
    unsigned char pad[0x30];
    unsigned int value34;
};

int __cdecl f(void *a, void *b)
{
    V *x = *(V **)a;
    V *y = *(V **)b;

    if (x->value34 < y->value34)
        return 1;
    if (x->value34 != y->value34)
        return 0;
    if (x->value30 > y->value30)
        return 1;
    return 0;
}
