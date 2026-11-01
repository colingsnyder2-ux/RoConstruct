// from server: 100% by atomic.potato
extern "C" int __stdcall ATL_CRegObject_405560(
    int,
    const char *,
    int,
    int);

int __stdcall VCWorkspace_456220(int a, int b, int c)
{
    return ATL_CRegObject_405560(a, (const char *)0x9ac220, b, c);
}
