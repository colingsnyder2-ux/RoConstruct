// from server: 94% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall sub_722dc0(int);

int S::f(int value)
{
    int *p = (int *)sub_722dc0(value);
    return ((int *)p[0x170 / 4])[0xa4 / 4];
}
