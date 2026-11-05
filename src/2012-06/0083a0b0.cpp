// from server: 100% by atomic.potato
extern "C" int __cdecl sub_831ef0(int, int, int);

struct S
{
};

int __cdecl f(int a, int b)
{
    int r = sub_831ef0(a, b, 0);
    if (!r)
        r = *(int*)0x00de13ec;
    return r;
}
