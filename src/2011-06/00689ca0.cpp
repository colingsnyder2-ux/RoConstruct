// from server: 51% by atomic.potato
struct S
{
    void __cdecl f(char *a, char *b, char *c);
};

void S::f(char *a, char *b, char *c)
{
    while (b != c)
    {
        b -= 8;
        c -= 8;
        *(int *)c = *(int *)b;
        *(int *)(c + 4) = *(int *)(b + 4);
    }
}
