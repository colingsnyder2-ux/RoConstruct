// from server: 100% by auto
// roc 2008-06 004bbf30  unit: ProfiledRakPeer  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbf30
//
// 004bbf30  83b92c02000000       cmp dword ptr [ecx + 0x22c], 0
// 004bbf37  744b                 je 0x4bbf84
// 004bbf39  8a4104               mov al, byte ptr [ecx + 4]
// 004bbf3c  3c01                 cmp al, 1
// 004bbf3e  7444                 je 0x4bbf84
// 004bbf40  0fb75108             movzx edx, word ptr [ecx + 8]
// 004bbf44  56                   push esi
// 004bbf45  33f6                 xor esi, esi
// 004bbf47  33c0                 xor eax, eax
// 004bbf49  663bf2               cmp si, dx
// 004bbf4c  7334                 jae 0x4bbf82
// 004bbf4e  8b892c020000         mov ecx, dword ptr [ecx + 0x22c]
// 004bbf54  0fb7d2               movzx edx, dx
// 004bbf57  8d7008               lea esi, [eax + 8]
// 004bbf5a  8d9b00000000         lea ebx, [ebx]
// 004bbf60  803900               cmp byte ptr [ecx], 0
// 004bbf63  7412                 je 0x4bbf77
// 004bbf65  80b9e007000000       cmp byte ptr [ecx + 0x7e0], 0
// 004bbf6c  7509                 jne 0x4bbf77
// 004bbf6e  39b148080000         cmp dword ptr [ecx + 0x848], esi
// 004bbf74  7501                 jne 0x4bbf77
// 004bbf76  40                   inc eax
// 004bbf77  81c150080000         add ecx, 0x850
// 004bbf7d  83ea01               sub edx, 1
// 004bbf80  75de                 jne 0x4bbf60
// 004bbf82  5e                   pop esi
// 004bbf83  c3                   ret 
// 004bbf84  33c0                 xor eax, eax
// 004bbf86  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?GetNumberOfRemoteInitiatedConnections@RakPeer@@IBEGXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
