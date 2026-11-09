// from server: 66% by atomic.potato
extern "C" int __stdcall sub_006b0da0(int);

struct S
{
    int f();
};

extern "C" void __stdcall sub_0052f040(S*, int*, int, int);

int S::f()
{
    int v = sub_006b0da0(0);
    sub_0052f040(this, &v, 6, 1);
    return 0;
}
