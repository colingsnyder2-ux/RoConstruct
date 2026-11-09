// from server: 91% by atomic.potato
extern "C" int __cdecl sub_80B2EA(int, const void *, const void *, int, int);

int __stdcall f(unsigned int value)
{
    return !sub_80B2EA(value, (const void *)0xC071F8, (const void *)0xC52794, 0, 0);
}
