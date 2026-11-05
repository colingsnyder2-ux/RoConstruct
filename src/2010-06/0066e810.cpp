// from server: 84% by atomic.potato
extern "C" int __cdecl sub_007A8BEA(int, int, int, int, int);
extern "C" int __cdecl sub_0066E470(int);

struct S
{
};

int __cdecl f(int value)
{
    if (value)
    {
        int result = sub_007A8BEA(value, 0, 0x00B78E40, 0x00B84678, 0);
        if (result)
            return sub_0066E470(result);
    }
    return 0;
}
