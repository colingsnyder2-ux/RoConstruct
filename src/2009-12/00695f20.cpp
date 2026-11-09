// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7F4AAA(int, int, const void *, const void *, int);

int __stdcall f(int value)
{
    return sub_7F4AAA(value, 0, (const void *)0xAFFE40, (const void *)0xB1C3EC, 0) != 0;
}
