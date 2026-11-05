// from server: 66% by atomic.potato
extern "C" void __cdecl sub_004ae5d0(int, int);

struct S_func_004dcfd0 {
    int __cdecl f(int);
};

int S_func_004dcfd0::f(int value)
{
    sub_004ae5d0(0, value);
    return value;
}
