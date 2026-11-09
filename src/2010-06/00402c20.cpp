// from server: 100% by auto
// roc 2010-06 00402c20  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402c20
//
// 00402c20  8bc1                 mov eax, ecx
// 00402c22  33c9                 xor ecx, ecx
// 00402c24  8908                 mov dword ptr [eax], ecx
// 00402c26  894804               mov dword ptr [eax + 4], ecx
// 00402c29  894808               mov dword ptr [eax + 8], ecx
// 00402c2c  89480c               mov dword ptr [eax + 0xc], ecx
// 00402c2f  894810               mov dword ptr [eax + 0x10], ecx
// 00402c32  894814               mov dword ptr [eax + 0x14], ecx
// 00402c35  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
