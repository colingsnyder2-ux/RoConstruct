// from server: 100% by auto
// roc 2010-06 00402b20  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402b20
//
// 00402b20  56                   push esi
// 00402b21  8b742408             mov esi, dword ptr [esp + 8]
// 00402b25  85f6                 test esi, esi
// 00402b27  742c                 je 0x402b55
// 00402b29  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402b2d  85c0                 test eax, eax
// 00402b2f  7424                 je 0x402b55
// 00402b31  8b542410             mov edx, dword ptr [esp + 0x10]
// 00402b35  52                   push edx
// 00402b36  56                   push esi
// 00402b37  6aff                 push -1
// 00402b39  50                   push eax
// 00402b3a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00402b3e  33c9                 xor ecx, ecx
// 00402b40  51                   push ecx
// 00402b41  50                   push eax
// 00402b42  66890e               mov word ptr [esi], cx
// 00402b45  ff15b0a39e00         call dword ptr [0x9ea3b0]
// 00402b4b  f7d8                 neg eax
// 00402b4d  1bc0                 sbb eax, eax
// 00402b4f  23c6                 and eax, esi
// 00402b51  5e                   pop esi
// 00402b52  c21000               ret 0x10
// 00402b55  33c0                 xor eax, eax
// 00402b57  5e                   pop esi
// 00402b58  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
