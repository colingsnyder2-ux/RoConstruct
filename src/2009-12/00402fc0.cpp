// from server: 100% by auto
// roc 2009-12 00402fc0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402fc0
//
// 00402fc0  8b4108               mov eax, dword ptr [ecx + 8]
// 00402fc3  50                   push eax
// 00402fc4  ff15a0e09800         call dword ptr [0x98e0a0]
// 00402fca  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?GetBkColor@CDC@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
