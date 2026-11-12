// from server: 100% by auto
// roc 2008-06 004bc960  unit: ProfiledRakPeer  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc960
//
// 004bc960  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bc964  56                   push esi
// 004bc965  57                   push edi
// 004bc966  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004bc96a  be0f000000           mov esi, 0xf
// 004bc96f  8d413c               lea eax, [ecx + 0x3c]
// 004bc972  2bf9                 sub edi, ecx
// 004bc974  8b0c07               mov ecx, dword ptr [edi + eax]
// 004bc977  8b10                 mov edx, dword ptr [eax]
// 004bc979  3bca                 cmp ecx, edx
// 004bc97b  770f                 ja 0x4bc98c
// 004bc97d  7208                 jb 0x4bc987
// 004bc97f  4e                   dec esi
// 004bc980  83e804               sub eax, 4
// 004bc983  85f6                 test esi, esi
// 004bc985  7ded                 jge 0x4bc974
// 004bc987  5f                   pop edi
// 004bc988  32c0                 xor al, al
// 004bc98a  5e                   pop esi
// 004bc98b  c3                   ret 
// 004bc98c  5f                   pop edi
// 004bc98d  b001                 mov al, 1
// 004bc98f  5e                   pop esi
// 004bc990  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$ugreater@$$BY0BA@I@big@@YA_NAAY0BA@I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
