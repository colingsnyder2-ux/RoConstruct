// from server: 100% by atomic.potato
extern "C" int __cdecl _atexit(void (__cdecl *)());
extern "C" void __cdecl _initterm(void (__cdecl **)(), void (__cdecl **)());

void __cdecl sub_463ac0();
void __cdecl sub_97ead0();

extern unsigned int dword_B7B9B8;
extern int dword_B7B9B0;
extern int dword_B7B9B4;

int __cdecl sub_464120()
{
    _initterm((void (__cdecl **)())0xB7B9E8, (void (__cdecl **)())0x463AC0);
    if (!(dword_B7B9B8 & 1))
    {
        dword_B7B9B8 |= 1;
        dword_B7B9B0 = 0;
        dword_B7B9B4 = 0;
        _atexit(sub_97ead0);
    }
    return (int)&dword_B7B9B0;
}
