// from server: 90% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __stdcall sub_0040dd60(S *, int);

int S::f(int value)
{
    return sub_0040dd60((S *)((char *)this + 16), value);
}
