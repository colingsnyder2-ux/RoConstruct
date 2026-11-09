// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern DWORD g_00CD310C;
extern DWORD g_00CD3104;
extern DWORD g_00CD3108;

extern void __cdecl Function_0080B15D(const void *);

void Function_00708460()
{
    if ((g_00CD310C & 1) != 0)
        return;

    g_00CD310C |= 1;
    g_00CD3104 = 0;
    g_00CD3108 = 0;
    Function_0080B15D((const void *)0x00A3E140);
}
