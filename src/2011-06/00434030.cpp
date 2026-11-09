// from server: 69% by colin
extern "C" void __cdecl _initterm(void (__cdecl **first)(void), void (__cdecl **last)(void));
extern "C" void __cdecl _atexit(void (__cdecl *func)(void));

void __cdecl sub_433AB0(void);
void __cdecl sub_A30C30(void);

int *g_434030()
{
    _initterm((void (__cdecl **)(void))0x433ab0, (void (__cdecl **)(void))0xcb2724);
    if ((*(unsigned char *)0xcb2700 & 1) == 0)
    {
        *(unsigned int *)0xcb2700 |= 1;
        *(int *)0xcb26f8 = 0;
        *(int *)0xcb26fc = 0;
        _atexit(sub_A30C30);
    }
    return (int *)0xcb26f8;
}
