// from server: 100% by auto
// roc 2009-12 00402b10  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402b10
//
// 00402b10  56                   push esi
// 00402b11  8b742408             mov esi, dword ptr [esp + 8]
// 00402b15  85f6                 test esi, esi
// 00402b17  742f                 je 0x402b48
// 00402b19  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402b1d  85c0                 test eax, eax
// 00402b1f  7427                 je 0x402b48
// 00402b21  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00402b25  8b542414             mov edx, dword ptr [esp + 0x14]
// 00402b29  6a00                 push 0
// 00402b2b  6a00                 push 0
// 00402b2d  51                   push ecx
// 00402b2e  56                   push esi
// 00402b2f  6aff                 push -1
// 00402b31  50                   push eax
// 00402b32  6a00                 push 0
// 00402b34  52                   push edx
// 00402b35  c60600               mov byte ptr [esi], 0
// 00402b38  ff153cb29800         call dword ptr [0x98b23c]
// 00402b3e  f7d8                 neg eax
// 00402b40  1bc0                 sbb eax, eax
// 00402b42  23c6                 and eax, esi
// 00402b44  5e                   pop esi
// 00402b45  c21000               ret 0x10
// 00402b48  33c0                 xor eax, eax
// 00402b4a  5e                   pop esi
// 00402b4b  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
