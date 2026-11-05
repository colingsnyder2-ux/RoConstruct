// from server: 42% by atomic.potato
extern "C" void __cdecl sub_0080A058(int);

struct S
{
    int value;
    int f();
};

int S::f()
{
    sub_0080A058(*(int *)((char *)this + 0x24));
    return 0;
}
