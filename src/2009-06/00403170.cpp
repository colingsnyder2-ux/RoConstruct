// from server: 100% by auto
// roc 2009-06 00403170  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403170
//
// 00403170  56                   push esi
// 00403171  8bf1                 mov esi, ecx
// 00403173  8b0e                 mov ecx, dword ptr [esi]
// 00403175  33c0                 xor eax, eax
// 00403177  85c9                 test ecx, ecx
// 00403179  7416                 je 0x403191
// 0040317b  51                   push ecx
// 0040317c  ff1508e08900         call dword ptr [0x89e008]
// 00403182  c70600000000         mov dword ptr [esi], 0
// 00403188  c7460400000000       mov dword ptr [esi + 4], 0
// 0040318f  5e                   pop esi
// 00403190  c3                   ret 
// 00403191  894604               mov dword ptr [esi + 4], eax
// 00403194  5e                   pop esi
// 00403195  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
