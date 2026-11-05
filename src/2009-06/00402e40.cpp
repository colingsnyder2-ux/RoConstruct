// from server: 100% by auto
// roc 2009-06 00402e40  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402e40
//
// 00402e40  56                   push esi
// 00402e41  8b742408             mov esi, dword ptr [esp + 8]
// 00402e45  85f6                 test esi, esi
// 00402e47  742f                 je 0x402e78
// 00402e49  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402e4d  85c0                 test eax, eax
// 00402e4f  7427                 je 0x402e78
// 00402e51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00402e55  8b542414             mov edx, dword ptr [esp + 0x14]
// 00402e59  6a00                 push 0
// 00402e5b  6a00                 push 0
// 00402e5d  51                   push ecx
// 00402e5e  56                   push esi
// 00402e5f  6aff                 push -1
// 00402e61  50                   push eax
// 00402e62  6a00                 push 0
// 00402e64  52                   push edx
// 00402e65  c60600               mov byte ptr [esi], 0
// 00402e68  ff153ce28900         call dword ptr [0x89e23c]
// 00402e6e  f7d8                 neg eax
// 00402e70  1bc0                 sbb eax, eax
// 00402e72  23c6                 and eax, esi
// 00402e74  5e                   pop esi
// 00402e75  c21000               ret 0x10
// 00402e78  33c0                 xor eax, eax
// 00402e7a  5e                   pop esi
// 00402e7b  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\olemisc.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olemisc.cpp
