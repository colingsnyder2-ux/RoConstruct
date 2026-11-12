// from server: 100% by auto
// roc 2008-06 004bc900  unit: ProfiledRakPeer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc900
//
// 004bc900  55                   push ebp
// 004bc901  8bec                 mov ebp, esp
// 004bc903  51                   push ecx
// 004bc904  56                   push esi
// 004bc905  57                   push edi
// 004bc906  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004bc90d  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004bc910  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bc913  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004bc916  8b06                 mov eax, dword ptr [esi]
// 004bc918  33d2                 xor edx, edx
// 004bc91a  2907                 sub dword ptr [edi], eax
// 004bc91c  8b4604               mov eax, dword ptr [esi + 4]
// 004bc91f  194704               sbb dword ptr [edi + 4], eax
// 004bc922  8b4608               mov eax, dword ptr [esi + 8]
// 004bc925  194708               sbb dword ptr [edi + 8], eax
// 004bc928  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc92b  19470c               sbb dword ptr [edi + 0xc], eax
// 004bc92e  e322                 jecxz 0x4bc952
// 004bc930  42                   inc edx
// 004bc931  42                   inc edx
// 004bc932  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bc935  1904d7               sbb dword ptr [edi + edx*8], eax
// 004bc938  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bc93c  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004bc940  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bc944  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004bc948  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bc94c  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004bc950  e2de                 loop 0x4bc930
// 004bc952  5f                   pop edi
// 004bc953  5e                   pop esi
// 004bc954  8be5                 mov esp, ebp
// 004bc956  5d                   pop ebp
// 004bc957  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$subtract@$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
