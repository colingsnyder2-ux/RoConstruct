// from server: 100% by auto
// roc 2009-12 008f2810  unit: CXTPControlRecentFileList  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2810
//
// 008f2810  e80913f0ff           call 0x7f3b1e
// 008f2815  8b4004               mov eax, dword ptr [eax + 4]
// 008f2818  8b8088000000         mov eax, dword ptr [eax + 0x88]
// 008f281e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ?GetRecentFileList@CXTPControlRecentFileList@@MAEPAVCRecentFileList@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
