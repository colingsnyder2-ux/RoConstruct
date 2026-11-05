// from server: 100% by atomic.potato
struct S
{
    unsigned char padding0[12];
    unsigned int count;
    void f();
};

extern "C" void __cdecl sub_0080A304(void *);

void S::f()
{
    if (count > 0)
        sub_0080A304(*(void **)this);
}
