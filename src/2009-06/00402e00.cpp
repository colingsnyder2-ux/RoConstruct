// from server: 100% by auto
// roc 2009-06 00402e00  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402e00
//
// 00402e00  56                   push esi
// 00402e01  8b742408             mov esi, dword ptr [esp + 8]
// 00402e05  85f6                 test esi, esi
// 00402e07  742c                 je 0x402e35
// 00402e09  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402e0d  85c0                 test eax, eax
// 00402e0f  7424                 je 0x402e35
// 00402e11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00402e15  52                   push edx
// 00402e16  56                   push esi
// 00402e17  6aff                 push -1
// 00402e19  50                   push eax
// 00402e1a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00402e1e  33c9                 xor ecx, ecx
// 00402e20  51                   push ecx
// 00402e21  50                   push eax
// 00402e22  66890e               mov word ptr [esi], cx
// 00402e25  ff1538e38900         call dword ptr [0x89e338]
// 00402e2b  f7d8                 neg eax
// 00402e2d  1bc0                 sbb eax, eax
// 00402e2f  23c6                 and eax, esi
// 00402e31  5e                   pop esi
// 00402e32  c21000               ret 0x10
// 00402e35  33c0                 xor eax, eax
// 00402e37  5e                   pop esi
// 00402e38  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
