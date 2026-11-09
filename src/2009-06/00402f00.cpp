// from server: 100% by auto
// roc 2009-06 00402f00  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402f00
//
// 00402f00  8bc1                 mov eax, ecx
// 00402f02  33c9                 xor ecx, ecx
// 00402f04  8908                 mov dword ptr [eax], ecx
// 00402f06  894804               mov dword ptr [eax + 4], ecx
// 00402f09  894808               mov dword ptr [eax + 8], ecx
// 00402f0c  89480c               mov dword ptr [eax + 0xc], ecx
// 00402f0f  894810               mov dword ptr [eax + 0x10], ecx
// 00402f12  894814               mov dword ptr [eax + 0x14], ecx
// 00402f15  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
