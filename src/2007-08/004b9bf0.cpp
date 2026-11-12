// from server: 100% by colin
// roc 2007-08 004b9bf0  unit: RakPeer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b9bf0
//
// 004b9bf0  56                   push esi
// 004b9bf1  8b742408             mov esi, dword ptr [esp + 8]
// 004b9bf5  57                   push edi
// 004b9bf6  33d2                 xor edx, edx
// 004b9bf8  b90f000000           mov ecx, 0xf
// 004b9bfd  8d4900               lea ecx, [ecx]
// 004b9c00  8b048e               mov eax, dword ptr [esi + ecx*4]
// 004b9c03  8bf8                 mov edi, eax
// 004b9c05  d1ef                 shr edi, 1
// 004b9c07  0bfa                 or edi, edx
// 004b9c09  c1e01f               shl eax, 0x1f
// 004b9c0c  83e901               sub ecx, 1
// 004b9c0f  897c8e04             mov dword ptr [esi + ecx*4 + 4], edi
// 004b9c13  8bd0                 mov edx, eax
// 004b9c15  79e9                 jns 0x4b9c00
// 004b9c17  5f                   pop edi
// 004b9c18  5e                   pop esi
// 004b9c19  c3                   ret 
// copied from an identical function in another client (function ??$ushiftRight1@$$BY0BA@I@big@@YAXAAY0BA@I@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp