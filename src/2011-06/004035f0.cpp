// from server: 100% by auto
// roc 2011-06 004035f0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004035f0
//
// 004035f0  8bc1                 mov eax, ecx
// 004035f2  33c9                 xor ecx, ecx
// 004035f4  8908                 mov dword ptr [eax], ecx
// 004035f6  894804               mov dword ptr [eax + 4], ecx
// 004035f9  894808               mov dword ptr [eax + 8], ecx
// 004035fc  89480c               mov dword ptr [eax + 0xc], ecx
// 004035ff  894810               mov dword ptr [eax + 0x10], ecx
// 00403602  894814               mov dword ptr [eax + 0x14], ecx
// 00403605  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
