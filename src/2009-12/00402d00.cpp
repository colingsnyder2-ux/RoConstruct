// from server: 100% by auto
// roc 2009-12 00402d00  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402d00
//
// 00402d00  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00402d03  50                   push eax
// 00402d04  ff15bccb9800         call dword ptr [0x98cbbc]
// 00402d0a  50                   push eax
// 00402d0b  e81a0e3f00           call 0x7f3b2a
// 00402d10  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
