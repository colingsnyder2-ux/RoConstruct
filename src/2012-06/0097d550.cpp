// from server: 38% by atomic.potato
extern "C" int __cdecl sub_0064EAC0(int, int);

struct S
{
    int value;
    int f(int);
};

int S::f(int x)
{
    return sub_0064EAC0(value, x);
}
