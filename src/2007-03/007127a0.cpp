// from server: 100% by auto
// roc 2007-03 007127a0  unit: seg_00710000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007127a0
//
// 007127a0  e8ebbbf0ff           call 0x61e390
// 007127a5  8b4004               mov eax, dword ptr [eax + 4]
// 007127a8  8b8088000000         mov eax, dword ptr [eax + 0x88]
// 007127ae  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ?GetRecentFileList@CXTPControlRecentFileList@@MAEPAVCRecentFileList@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
