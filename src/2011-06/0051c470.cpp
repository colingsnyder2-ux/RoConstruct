// from server: 100% by atomic.potato
extern "C" void __cdecl sub_0080A058(void *);

struct S
{
    int unused0;
    int unused1;
    int pad0;
    void *pad1;
    void *value;
    void f();
};

void S::f()
{
    if (pad0 != 0)
        sub_0080A058(pad1);
}
