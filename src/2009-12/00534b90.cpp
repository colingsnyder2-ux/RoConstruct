// from server: 59% by atomic.potato
extern "C" int __cdecl sub_005346c0(int *);
extern "C" void __cdecl sub_00533330(int, int);

void __cdecl function_00534b90(int value)
{
    int local;
    int result = sub_005346c0(&local);
    sub_00533330(value, result);
}
