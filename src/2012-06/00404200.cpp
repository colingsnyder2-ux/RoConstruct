// from server: 100% by auto
// roc 2012-06 00404200  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404200
//
// 00404200  8bc1                 mov eax, ecx
// 00404202  33c9                 xor ecx, ecx
// 00404204  8908                 mov dword ptr [eax], ecx
// 00404206  894804               mov dword ptr [eax + 4], ecx
// 00404209  894808               mov dword ptr [eax + 8], ecx
// 0040420c  89480c               mov dword ptr [eax + 0xc], ecx
// 0040420f  894810               mov dword ptr [eax + 0x10], ecx
// 00404212  894814               mov dword ptr [eax + 0x14], ecx
// 00404215  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
