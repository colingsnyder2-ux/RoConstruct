// from server: 40% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl call_419c60(int);
extern "C" unsigned int __cdecl call_419490(int);

int S::f()
{
    int value = *(int *)((char *)this + 0x20);
    if (value == 0)
        return 0;

    value = call_419c60(value);
    if (value == 0)
        return 0;

    if (call_419490(value) == 0)
        return 0;

    return 1;
}
