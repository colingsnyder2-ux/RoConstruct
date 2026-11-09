// from server: 100% by auto
// roc 2009-12 00402e40  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402e40
//
// 00402e40  56                   push esi
// 00402e41  8bf1                 mov esi, ecx
// 00402e43  8b0e                 mov ecx, dword ptr [esi]
// 00402e45  33c0                 xor eax, eax
// 00402e47  85c9                 test ecx, ecx
// 00402e49  7416                 je 0x402e61
// 00402e4b  51                   push ecx
// 00402e4c  ff1508b09800         call dword ptr [0x98b008]
// 00402e52  c70600000000         mov dword ptr [esi], 0
// 00402e58  c7460400000000       mov dword ptr [esi + 4], 0
// 00402e5f  5e                   pop esi
// 00402e60  c3                   ret 
// 00402e61  894604               mov dword ptr [esi + 4], eax
// 00402e64  5e                   pop esi
// 00402e65  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
