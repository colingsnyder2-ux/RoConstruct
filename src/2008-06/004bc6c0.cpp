// from server: 100% by auto
// roc 2008-06 004bc6c0  unit: ProfiledRakPeer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc6c0
//
// 004bc6c0  55                   push ebp
// 004bc6c1  8bec                 mov ebp, esp
// 004bc6c3  51                   push ecx
// 004bc6c4  56                   push esi
// 004bc6c5  57                   push edi
// 004bc6c6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004bc6cd  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004bc6d0  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bc6d3  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004bc6d6  8b06                 mov eax, dword ptr [esi]
// 004bc6d8  33d2                 xor edx, edx
// 004bc6da  2907                 sub dword ptr [edi], eax
// 004bc6dc  8b4604               mov eax, dword ptr [esi + 4]
// 004bc6df  194704               sbb dword ptr [edi + 4], eax
// 004bc6e2  8b4608               mov eax, dword ptr [esi + 8]
// 004bc6e5  194708               sbb dword ptr [edi + 8], eax
// 004bc6e8  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc6eb  19470c               sbb dword ptr [edi + 0xc], eax
// 004bc6ee  e322                 jecxz 0x4bc712
// 004bc6f0  42                   inc edx
// 004bc6f1  42                   inc edx
// 004bc6f2  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bc6f5  1904d7               sbb dword ptr [edi + edx*8], eax
// 004bc6f8  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bc6fc  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004bc700  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bc704  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004bc708  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bc70c  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004bc710  e2de                 loop 0x4bc6f0
// 004bc712  5f                   pop edi
// 004bc713  5e                   pop esi
// 004bc714  8be5                 mov esp, ebp
// 004bc716  5d                   pop ebp
// 004bc717  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$subtract@$$BY03I@big@@YAXAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
