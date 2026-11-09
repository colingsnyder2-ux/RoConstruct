// from server: 100% by atomic.potato
extern "C" int __cdecl sub_79d5c0();

extern int dword_c24250;

int sub_79d6b0(int value)
{
    if (dword_c24250 > 0)
    {
        if (sub_79d5c0() + value > dword_c24250)
            return 0;
    }
    return 1;
}
