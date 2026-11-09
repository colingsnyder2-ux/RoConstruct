// from server: 88% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_006d98b0(int);
extern "C" int __stdcall sub_0076a190(S *, int *);

int S::f(int value)
{
    int *p = (int *)sub_006d98b0(value + 4);
    int v = *p;
    return sub_0076a190(this, &v);
}
