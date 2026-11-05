// from server: 100% by auto
// roc 2010-06 00402e90  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402e90
//
// 00402e90  56                   push esi
// 00402e91  8bf1                 mov esi, ecx
// 00402e93  8b0e                 mov ecx, dword ptr [esi]
// 00402e95  33c0                 xor eax, eax
// 00402e97  85c9                 test ecx, ecx
// 00402e99  7416                 je 0x402eb1
// 00402e9b  51                   push ecx
// 00402e9c  ff1510a09e00         call dword ptr [0x9ea010]
// 00402ea2  c70600000000         mov dword ptr [esi], 0
// 00402ea8  c7460400000000       mov dword ptr [esi + 4], 0
// 00402eaf  5e                   pop esi
// 00402eb0  c3                   ret 
// 00402eb1  894604               mov dword ptr [esi + 4], eax
// 00402eb4  5e                   pop esi
// 00402eb5  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
