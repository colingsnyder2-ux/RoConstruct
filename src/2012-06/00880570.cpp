// from server: 88% by atomic.potato
extern "C" int __cdecl sub_00983448(void *, void *, const char *, int);

int __stdcall TestService(void *value)
{
    return sub_00983448(value, (void *)0x00d601e8, (const char *)0x00d6a11c, 0) == 0;
}
