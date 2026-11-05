// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" unsigned char __stdcall sub_83b7d0(int, int);

int S::f()
{
    if (*(int *)((char *)this + 16) == 1)
        if (sub_83b7d0(4, 10))
            return 1;
    return 0;
}
