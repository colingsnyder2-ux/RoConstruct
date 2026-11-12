// from server: 100% by auto
// roc 2008-06 004bb6a0  unit: ProfiledRakPeer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb6a0
//
// 004bb6a0  0fb75108             movzx edx, word ptr [ecx + 8]
// 004bb6a4  56                   push esi
// 004bb6a5  33f6                 xor esi, esi
// 004bb6a7  33c0                 xor eax, eax
// 004bb6a9  663bf2               cmp si, dx
// 004bb6ac  5e                   pop esi
// 004bb6ad  731a                 jae 0x4bb6c9
// 004bb6af  8b892c020000         mov ecx, dword ptr [ecx + 0x22c]
// 004bb6b5  0fb7d2               movzx edx, dx
// 004bb6b8  803900               cmp byte ptr [ecx], 0
// 004bb6bb  7401                 je 0x4bb6be
// 004bb6bd  40                   inc eax
// 004bb6be  81c150080000         add ecx, 0x850
// 004bb6c4  83ea01               sub edx, 1
// 004bb6c7  75ef                 jne 0x4bb6b8
// 004bb6c9  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?NumberOfConnections@RakPeer@@UBEGXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
