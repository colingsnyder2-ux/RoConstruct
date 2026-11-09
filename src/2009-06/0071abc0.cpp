// from server: 100% by EspClaude
// roc 2009-06 0071abc0  unit: ActiveDocView  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071abc0
//
// 0071abc0  8bff                 mov edi, edi
// 0071abc2  55                   push ebp
// 0071abc3  8bec                 mov ebp, esp
// 0071abc5  56                   push esi
// 0071abc6  8bf1                 mov esi, ecx
// 0071abc8  8b4608               mov eax, dword ptr [esi + 8]
// 0071abcb  c706a0128f00         mov dword ptr [esi], 0x8f12a0
// 0071abd1  85c0                 test eax, eax
// 0071abd3  7408                 je 0x71abdd
// 0071abd5  8b08                 mov ecx, dword ptr [eax]
// 0071abd7  8b5108               mov edx, dword ptr [ecx + 8]
// 0071abda  50                   push eax
// 0071abdb  ffd2                 call edx
// 0071abdd  837e0c00             cmp dword ptr [esi + 0xc], 0
// 0071abe1  7417                 je 0x71abfa
// 0071abe3  ff1530e28900         call dword ptr [0x89e230]
// 0071abe9  85c0                 test eax, eax
// 0071abeb  740d                 je 0x71abfa
// 0071abed  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0071abf0  51                   push ecx
// 0071abf1  6a00                 push 0
// 0071abf3  50                   push eax
// 0071abf4  ff1528e28900         call dword ptr [0x89e228]
// 0071abfa  f6450801             test byte ptr [ebp + 8], 1
// 0071abfe  7409                 je 0x71ac09
// 0071ac00  56                   push esi
// 0071ac01  e82cdeffff           call 0x718a32
// 0071ac06  83c404               add esp, 4
// 0071ac09  8bc6                 mov eax, esi
// 0071ac0b  5e                   pop esi
// 0071ac0c  5d                   pop ebp
// 0071ac0d  c20400               ret 4
// copied from an identical function in another client (function ??_G_com_error@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-comsupp-rtm comsupp.lib/f:/dd/vctools/compiler/cxxfe/sl/vccom/ANSI/objr/i386/comraise.obj