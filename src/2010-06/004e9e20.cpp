// from server: 45% by atomic.potato
extern "C" void __cdecl sub_4e1260(void *, void *, void *);
extern "C" void __cdecl sub_4e8740(void *);

struct S
{
    int pad;
    int value;
    void __cdecl f(void *, void *);
};

void S::f(void *a, void *b)
{
    char local;
    sub_4e1260(&local, b, a);
    if (value != 0)
        sub_4e8740(&local);
}
