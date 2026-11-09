// from server: 69% by atomic.potato
struct S
{
    int f(int, int);
};

extern "C" int __stdcall call1(S *, int, int);
extern "C" void __stdcall call2(S *, int);

int S::f(int a, int b)
{
    int value = call1(this, a, b);
    if (value != -1)
        call2(this, value);
    return value;
}
