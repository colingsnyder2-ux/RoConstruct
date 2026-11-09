// from server: 100% by colin
extern "C" int __cdecl sub_00630D36(int, int, int, int, int);

struct Members {
    int func_00442A90(int);
};

int Members::func_00442A90(int a)
{
    int r = sub_00630D36(a, 0, (int)0x881F4C, (int)0x886328, 0);
    return r != 0;
}
