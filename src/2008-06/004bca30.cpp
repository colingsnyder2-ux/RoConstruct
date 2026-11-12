// from server: 100% by auto
// roc 2008-06 004bca30  unit: ProfiledRakPeer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bca30
//
// 004bca30  56                   push esi
// 004bca31  8b742408             mov esi, dword ptr [esp + 8]
// 004bca35  57                   push edi
// 004bca36  33d2                 xor edx, edx
// 004bca38  b90f000000           mov ecx, 0xf
// 004bca3d  8d4900               lea ecx, [ecx]
// 004bca40  8b048e               mov eax, dword ptr [esi + ecx*4]
// 004bca43  8bf8                 mov edi, eax
// 004bca45  d1ef                 shr edi, 1
// 004bca47  0bfa                 or edi, edx
// 004bca49  c1e01f               shl eax, 0x1f
// 004bca4c  83e901               sub ecx, 1
// 004bca4f  897c8e04             mov dword ptr [esi + ecx*4 + 4], edi
// 004bca53  8bd0                 mov edx, eax
// 004bca55  79e9                 jns 0x4bca40
// 004bca57  5f                   pop edi
// 004bca58  5e                   pop esi
// 004bca59  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$ushiftRight1@$$BY0BA@I@big@@YAXAAY0BA@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
