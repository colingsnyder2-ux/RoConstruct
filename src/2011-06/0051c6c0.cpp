// from server: 92% by atomic.potato
extern "C" void __cdecl sub_0080B1D8(void *, int, int, const char *);
extern "C" void __cdecl sub_0080A058(void *);

void f(void *value)
{
    if (value != 0)
    {
        sub_0080B1D8((char *)value + 8, 0x28, 0x28, "96t\"");
        sub_0080A058(value);
    }
}
