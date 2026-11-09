// from server: 100% by auto
// roc 2010-06 008a6960  unit: CXTPControlRecentFileList  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a6960
//
// 008a6960  e8f912f0ff           call 0x7a7c5e
// 008a6965  8b4004               mov eax, dword ptr [eax + 4]
// 008a6968  8b8088000000         mov eax, dword ptr [eax + 0x88]
// 008a696e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ?GetRecentFileList@CXTPControlRecentFileList@@MAEPAVCRecentFileList@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
