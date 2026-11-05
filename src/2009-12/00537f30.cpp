// from server: 83% by atomic.potato
extern "C" void __cdecl sub_6379c0(void *);

struct S
{
    void f();
    char pad[12];
    void *p;
};

void S::f()
{
    void *v = p;
    sub_6379c0(v);
    if (v)
    {
        void (**q)(int) = (void (**)(int))(*(void ***)((char *)v + 0x18));
        q[0](1);
    }
}
