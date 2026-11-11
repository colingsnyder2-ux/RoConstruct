// from server: 97% by EspClaude
// from server: 82% by EspClaude
// roc 2007-08 00630c84  unit: std::bad_alloc  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00630c84
//
// 00630c84  6a14                 push 0x14
// 00630c86  68f09a8600           push 0x869af0
// 00630c8b  e890090000           call 0x631620
// 00630c90  ff35049c8c00         push dword ptr [0x8c9c04]
// 00630c96  8b35b8e77700         mov esi, dword ptr [0x77e7b8]
// 00630c9c  ffd6                 call esi
// 00630c9e  59                   pop ecx
// 00630c9f  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00630ca2  83f8ff               cmp eax, -1
// 00630ca5  750c                 jne 0x630cb3
// 00630ca7  ff7508               push dword ptr [ebp + 8]
// 00630caa  ff15bce77700         call dword ptr [0x77e7bc]
// 00630cb0  59                   pop ecx
// 00630cb1  eb61                 jmp 0x630d14
// 00630cb3  6a08                 push 8
// 00630cb5  e8cc090000           call 0x631686
// 00630cba  59                   pop ecx
// 00630cbb  8365fc00             and dword ptr [ebp - 4], 0
// 00630cbf  ff35049c8c00         push dword ptr [0x8c9c04]
// 00630cc5  ffd6                 call esi
// 00630cc7  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00630cca  ff35009c8c00         push dword ptr [0x8c9c00]
// 00630cd0  ffd6                 call esi
// 00630cd2  8945e0               mov dword ptr [ebp - 0x20], eax
// 00630cd5  8d45e0               lea eax, [ebp - 0x20]
// 00630cd8  50                   push eax
// 00630cd9  8d45e4               lea eax, [ebp - 0x1c]
// 00630cdc  50                   push eax
// 00630cdd  ff7508               push dword ptr [ebp + 8]
// 00630ce0  e89b090000           call 0x631680
// 00630ce5  8945dc               mov dword ptr [ebp - 0x24], eax
// 00630ce8  ff75e4               push dword ptr [ebp - 0x1c]
// 00630ceb  8b35c8e77700         mov esi, dword ptr [0x77e7c8]
// 00630cf1  ffd6                 call esi
// 00630cf3  a3049c8c00           mov dword ptr [0x8c9c04], eax
// 00630cf8  ff75e0               push dword ptr [ebp - 0x20]
// 00630cfb  ffd6                 call esi
// 00630cfd  83c41c               add esp, 0x1c
// 00630d00  a3009c8c00           mov dword ptr [0x8c9c00], eax
// 00630d05  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 00630d0c  e809000000           call 0x630d1a
// 00630d11  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 00630d14  e84c090000           call 0x631665
// 00630d19  c3                   ret 

// from server: 100% by colin
// roc 2008-06 006a170a  unit: ActiveDocView  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a170a
//
// 006a170a  6a14                 push 0x14
// 006a170c  68200b9000           push 0x900b20
// 006a1711  e8a6080000           call 0x6a1fbc
// 006a1716  ff350cf79700         push dword ptr [0x97f70c]
// 006a171c  8b3590268000         mov esi, dword ptr [0x802690]
// 006a1722  ffd6                 call esi
// 006a1724  59                   pop ecx
// 006a1725  8945e4               mov dword ptr [ebp - 0x1c], eax
// 006a1728  83f8ff               cmp eax, -1
// 006a172b  750c                 jne 0x6a1739
// 006a172d  ff7508               push dword ptr [ebp + 8]
// 006a1730  ff1594268000         call dword ptr [0x802694]
// 006a1736  59                   pop ecx
// 006a1737  eb67                 jmp 0x6a17a0
// 006a1739  6a08                 push 8
// 006a173b  e80c090000           call 0x6a204c
// 006a1740  59                   pop ecx
// 006a1741  8365fc00             and dword ptr [ebp - 4], 0
// 006a1745  ff350cf79700         push dword ptr [0x97f70c]
// 006a174b  ffd6                 call esi
// 006a174d  8945e4               mov dword ptr [ebp - 0x1c], eax
// 006a1750  ff3508f79700         push dword ptr [0x97f708]
// 006a1756  ffd6                 call esi
// 006a1758  59                   pop ecx
// 006a1759  59                   pop ecx
// 006a175a  8945e0               mov dword ptr [ebp - 0x20], eax
// 006a175d  8d45e0               lea eax, [ebp - 0x20]
// 006a1760  50                   push eax
// 006a1761  8d45e4               lea eax, [ebp - 0x1c]
// 006a1764  50                   push eax
// 006a1765  ff7508               push dword ptr [ebp + 8]
// 006a1768  8b359c268000         mov esi, dword ptr [0x80269c]
// 006a176e  ffd6                 call esi
// 006a1770  59                   pop ecx
// 006a1771  50                   push eax
// 006a1772  e8cf080000           call 0x6a2046
// 006a1777  8945dc               mov dword ptr [ebp - 0x24], eax
// 006a177a  ff75e4               push dword ptr [ebp - 0x1c]
// 006a177d  ffd6                 call esi
// 006a177f  a30cf79700           mov dword ptr [0x97f70c], eax
// 006a1784  ff75e0               push dword ptr [ebp - 0x20]
// 006a1787  ffd6                 call esi
// 006a1789  83c414               add esp, 0x14
// 006a178c  a308f79700           mov dword ptr [0x97f708], eax
// 006a1791  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 006a1798  e809000000           call 0x6a17a6
// 006a179d  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 006a17a0  e85c080000           call 0x6a2001
// 006a17a5  c3                   ret 

// from server: 97% by EspClaude
// from server: 63% by colin
// roc 2008-06 006a170a  unit: ActiveDocView  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a170a
// 006a170a  6a14                 push 0x14
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O1 /GS /MD
typedef void (__cdecl *_PVFV)(void);
typedef int (__cdecl *_onexit_t)(void);

extern "C" __declspec(dllimport) void * __cdecl _decode_pointer(void *);
extern "C" __declspec(dllimport) void * __cdecl _encode_pointer(void *);
extern "C" __declspec(dllimport) _onexit_t __cdecl _onexit(_onexit_t);
extern "C" _onexit_t __cdecl __dllonexit(_onexit_t, _PVFV **, _PVFV **);
extern "C" void __cdecl _lock(int);
extern "C" void __cdecl _unlock(int);
extern "C" _PVFV *__onexitbegin;
extern "C" _PVFV *__onexitend;

extern "C" _onexit_t __cdecl roc_onexit(_onexit_t func)
{
    _PVFV *onexitbegin;
    _PVFV *onexitend;
    _onexit_t retval;

    onexitbegin = (_PVFV *)_decode_pointer(__onexitbegin);

    if (onexitbegin == (_PVFV *)-1)
    {
        return _onexit(func);
    }

    _lock(8);

    __try
    {
        onexitbegin = (_PVFV *)_decode_pointer(__onexitbegin);
        onexitend = (_PVFV *)_decode_pointer(__onexitend);

        retval = __dllonexit(func, &onexitbegin, &onexitend);

        __onexitbegin = (_PVFV *)_encode_pointer(onexitbegin);
        __onexitend = (_PVFV *)_encode_pointer(onexitend);
    }
    __finally
    {
        _unlock(8);
    }

    return retval;
}
