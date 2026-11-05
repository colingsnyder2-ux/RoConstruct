// from server: 91% by atomic.potato
extern "C" int __cdecl sub_00983448(int, const void *, const void *, int, int);

int __stdcall Function007d48f0(int value)
{
    int result = sub_00983448(value, (const void *)0x00d601e8,
                              (const void *)0x00d820a8, 0, 0);
    return !result;
}
