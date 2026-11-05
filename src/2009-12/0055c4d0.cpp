// from server: 100% by atomic.potato
struct S
{
    char padding[20];
    int value;
};

int __cdecl f(S *p)
{
    return p->value == 0;
}
