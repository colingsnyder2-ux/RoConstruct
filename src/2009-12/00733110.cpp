// from server: 43% by atomic.potato
extern "C" void __stdcall sub_7B6970(const void *, void *);

struct S
{
    int f();
    unsigned char pad[0x94];
    void *value94;
    void *value98;
};

int S::f()
{
    void *a = value94;
    void *b = value98;
    if (b)
        sub_7B6970((const void *)0x71AAD0, a);
    return 0;
}
