// from server: 100% by auto
// roc 2010-06 00402b60  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402b60
//
// 00402b60  56                   push esi
// 00402b61  8b742408             mov esi, dword ptr [esp + 8]
// 00402b65  85f6                 test esi, esi
// 00402b67  742f                 je 0x402b98
// 00402b69  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402b6d  85c0                 test eax, eax
// 00402b6f  7427                 je 0x402b98
// 00402b71  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00402b75  8b542414             mov edx, dword ptr [esp + 0x14]
// 00402b79  6a00                 push 0
// 00402b7b  6a00                 push 0
// 00402b7d  51                   push ecx
// 00402b7e  56                   push esi
// 00402b7f  6aff                 push -1
// 00402b81  50                   push eax
// 00402b82  6a00                 push 0
// 00402b84  52                   push edx
// 00402b85  c60600               mov byte ptr [esi], 0
// 00402b88  ff15aca39e00         call dword ptr [0x9ea3ac]
// 00402b8e  f7d8                 neg eax
// 00402b90  1bc0                 sbb eax, eax
// 00402b92  23c6                 and eax, esi
// 00402b94  5e                   pop esi
// 00402b95  c21000               ret 0x10
// 00402b98  33c0                 xor eax, eax
// 00402b9a  5e                   pop esi
// 00402b9b  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\olemisc.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olemisc.cpp
