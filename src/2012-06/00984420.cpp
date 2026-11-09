// from server: 51% by atomic.potato
struct S
{
    void __cdecl f(void *, void *);
};

extern "C" void __cdecl sub_983144(void *, const char *);

void S::f(void *a, void *b)
{
    struct T
    {
        int x;
        void *a;
        void *b;
        int z;
    } t;

    t.x = 0x00c0cd98;
    t.a = a;
    t.b = b;
    t.z = 0;
    sub_983144(&t, "CXTPControl");
}
