// from server: 100% by auto
// roc 2008-06 004bc630  unit: ProfiledRakPeer  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc630
//
// 004bc630  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bc634  56                   push esi
// 004bc635  57                   push edi
// 004bc636  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004bc63a  be03000000           mov esi, 3
// 004bc63f  8d410c               lea eax, [ecx + 0xc]
// 004bc642  2bf9                 sub edi, ecx
// 004bc644  8b0c07               mov ecx, dword ptr [edi + eax]
// 004bc647  8b10                 mov edx, dword ptr [eax]
// 004bc649  3bca                 cmp ecx, edx
// 004bc64b  770f                 ja 0x4bc65c
// 004bc64d  7208                 jb 0x4bc657
// 004bc64f  4e                   dec esi
// 004bc650  83e804               sub eax, 4
// 004bc653  85f6                 test esi, esi
// 004bc655  7ded                 jge 0x4bc644
// 004bc657  5f                   pop edi
// 004bc658  32c0                 xor al, al
// 004bc65a  5e                   pop esi
// 004bc65b  c3                   ret 
// 004bc65c  5f                   pop edi
// 004bc65d  b001                 mov al, 1
// 004bc65f  5e                   pop esi
// 004bc660  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$ugreater@$$BY03I@big@@YA_NAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
