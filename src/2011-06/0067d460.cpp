// from server: 61% by atomic.potato
extern "C" int __cdecl sub_40c7e0(int *, int);

struct S
{
    struct VTable
    {
        int (__thiscall *f38)(int);
    };

    VTable **vtable;
    int f(int);
};

int S::f(int value)
{
    int result = (*vtable)->f38(value);
    return sub_40c7e0(&value, result);
}
