// from server: 42% by atomic.potato
extern "C" int __cdecl target_751870();

struct S
{
    int value;
    int f();
};

int S::f()
{
    static volatile unsigned char flag = 0;
    if (flag)
        return 1;
    return target_751870();
}
