// from server: 100% by atomic.potato
extern "C" int __cdecl sub_007A8BEA(int, int, int, int, int);

int __stdcall f0065A650(int value)
{
    int result = sub_007A8BEA(value, 0, 0x00B78E40, 0x00BBA00C, 0);
    return result != 0;
}
