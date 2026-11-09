// from server: 60% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall target(int, int);

int S::f(int value)
{
    return target(*(int *)((char *)this + 0x38) + value, 0);
}
