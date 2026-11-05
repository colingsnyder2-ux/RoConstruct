// from server: 100% by auto
// roc 2010-06 008a6fe0  unit: CXTPDockingPaneAutoHidePanel  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a6fe0
//
// 008a6fe0  53                   push ebx
// 008a6fe1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008a6fe5  3bd9                 cmp ebx, ecx
// 008a6fe7  7509                 jne 0x8a6ff2
// 008a6fe9  b801000000           mov eax, 1
// 008a6fee  5b                   pop ebx
// 008a6fef  c20400               ret 4
// 008a6ff2  56                   push esi
// 008a6ff3  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 008a6ff6  57                   push edi
// 008a6ff7  85f6                 test esi, esi
// 008a6ff9  741e                 je 0x8a7019
// 008a6ffb  eb03                 jmp 0x8a7000
// 008a6ffd  8d4900               lea ecx, [ecx]
// 008a7000  8bc6                 mov eax, esi
// 008a7002  8b4808               mov ecx, dword ptr [eax + 8]
// 008a7005  8b01                 mov eax, dword ptr [ecx]
// 008a7007  8b5008               mov edx, dword ptr [eax + 8]
// 008a700a  8bfe                 mov edi, esi
// 008a700c  8b36                 mov esi, dword ptr [esi]
// 008a700e  53                   push ebx
// 008a700f  ffd2                 call edx
// 008a7011  85c0                 test eax, eax
// 008a7013  750c                 jne 0x8a7021
// 008a7015  85f6                 test esi, esi
// 008a7017  75e7                 jne 0x8a7000
// 008a7019  5f                   pop edi
// 008a701a  5e                   pop esi
// 008a701b  33c0                 xor eax, eax
// 008a701d  5b                   pop ebx
// 008a701e  c20400               ret 4
// 008a7021  8bc7                 mov eax, edi
// 008a7023  5f                   pop edi
// 008a7024  5e                   pop esi
// 008a7025  5b                   pop ebx
// 008a7026  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?ContainPane@CXTPDockingPaneBaseContainer@@UBEPAU__POSITION@@PAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
