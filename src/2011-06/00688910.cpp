// from server: 62% by atomic.potato
struct S_func_00688910
{
    int f(int);
};

extern "C" int __cdecl sub_00688180();

struct S_arg_00688a80
{
    int sub_00688a80();
};

int S_arg_00688a80::sub_00688a80()
{
    return 0;
}

int S_func_00688910::f(int)
{
    int value = sub_00688180();
    if (value != 0)
        ((S_arg_00688a80*)value)->sub_00688a80();
    return 0;
}
