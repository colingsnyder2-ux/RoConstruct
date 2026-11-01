// from server: 100% by auto
// roc 2009-06 0076e6c0  unit: CXTPControlRecentFileList  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076e6c0
//
// 0076e6c0  e831a6faff           call 0x718cf6
// 0076e6c5  8b4004               mov eax, dword ptr [eax + 4]
// 0076e6c8  8b8088000000         mov eax, dword ptr [eax + 0x88]
// 0076e6ce  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ?GetRecentFileList@CXTPControlRecentFileList@@MAEPAVCRecentFileList@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
