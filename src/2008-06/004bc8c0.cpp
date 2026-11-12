// from server: 100% by auto
// roc 2008-06 004bc8c0  unit: ProfiledRakPeer  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc8c0
//
// 004bc8c0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bc8c4  56                   push esi
// 004bc8c5  57                   push edi
// 004bc8c6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004bc8ca  be07000000           mov esi, 7
// 004bc8cf  8d411c               lea eax, [ecx + 0x1c]
// 004bc8d2  2bf9                 sub edi, ecx
// 004bc8d4  8b0c07               mov ecx, dword ptr [edi + eax]
// 004bc8d7  8b10                 mov edx, dword ptr [eax]
// 004bc8d9  3bca                 cmp ecx, edx
// 004bc8db  770f                 ja 0x4bc8ec
// 004bc8dd  7208                 jb 0x4bc8e7
// 004bc8df  4e                   dec esi
// 004bc8e0  83e804               sub eax, 4
// 004bc8e3  85f6                 test esi, esi
// 004bc8e5  7ded                 jge 0x4bc8d4
// 004bc8e7  5f                   pop edi
// 004bc8e8  32c0                 xor al, al
// 004bc8ea  5e                   pop esi
// 004bc8eb  c3                   ret 
// 004bc8ec  5f                   pop edi
// 004bc8ed  b001                 mov al, 1
// 004bc8ef  5e                   pop esi
// 004bc8f0  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$ugreater@$$BY07I@big@@YA_NAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
