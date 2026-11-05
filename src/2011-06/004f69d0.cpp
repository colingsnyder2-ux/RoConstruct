// from server: 52% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

extern "C" void __cdecl sub_4f6970(void *, void *);
extern "C" void __cdecl sub_4f1950(void *, void *);

void S::f(void *arg)
{
    char local[12];
    sub_4f6970(local, arg);
    sub_4f1950(arg, local);
}
