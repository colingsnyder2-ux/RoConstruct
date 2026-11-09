// from server: 75% by colin
extern "C" void __cdecl sub_00630a1e(int);

struct S_func_00402fd0 {
    int f(int, int, int);
};

int S_func_00402fd0::f(int, int, int)
{
    sub_00630a1e(0x80004003);
    return 0x80004003;
}
