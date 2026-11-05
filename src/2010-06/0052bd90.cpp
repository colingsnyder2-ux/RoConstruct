// from server: 56% by atomic.potato
struct S
{
    void *vtable;
};

extern "C" void __cdecl sub_52bc90(void *, void *, void *, unsigned int);

S * __cdecl sub_52bd90(S *a, void *b, void *c)
{
    S *p;
    p = a;
    sub_52bc90(a, *(void **)a, &p, 0x14);
    return a;
}
