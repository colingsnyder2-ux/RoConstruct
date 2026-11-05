// from server: 100% by auto
// roc 2009-12 00402ad0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402ad0
//
// 00402ad0  56                   push esi
// 00402ad1  8b742408             mov esi, dword ptr [esp + 8]
// 00402ad5  85f6                 test esi, esi
// 00402ad7  742c                 je 0x402b05
// 00402ad9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402add  85c0                 test eax, eax
// 00402adf  7424                 je 0x402b05
// 00402ae1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00402ae5  52                   push edx
// 00402ae6  56                   push esi
// 00402ae7  6aff                 push -1
// 00402ae9  50                   push eax
// 00402aea  8b442424             mov eax, dword ptr [esp + 0x24]
// 00402aee  33c9                 xor ecx, ecx
// 00402af0  51                   push ecx
// 00402af1  50                   push eax
// 00402af2  66890e               mov word ptr [esi], cx
// 00402af5  ff1540b29800         call dword ptr [0x98b240]
// 00402afb  f7d8                 neg eax
// 00402afd  1bc0                 sbb eax, eax
// 00402aff  23c6                 and eax, esi
// 00402b01  5e                   pop esi
// 00402b02  c21000               ret 0x10
// 00402b05  33c0                 xor eax, eax
// 00402b07  5e                   pop esi
// 00402b08  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
