// from server: 52% by atomic.potato
extern "C" void __cdecl sub_4e83b0(void *, void *);
extern "C" void __cdecl sub_4e16e0(void *, void *);

struct S
{
    void __cdecl f(void *);
};

void S::f(void *arg)
{
    char buffer[12];
    sub_4e83b0(buffer, arg);
    sub_4e16e0(arg, buffer);
}
