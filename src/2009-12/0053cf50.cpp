// from server: 66% by atomic.potato
struct S
{
    void __cdecl f(int, int);
};

extern "C" int __cdecl sub_53bc40(int);
extern "C" void __cdecl sub_5337e0(int, int);

void S::f(int a, int b)
{
    int t = 0;
    int v = sub_53bc40(a);
    sub_5337e0(b, v);
}
