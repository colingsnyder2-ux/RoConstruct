// from server: 100% by auto
// roc 2009-06 007f5d90  unit: CXTSplitterWnd  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5d90
//
// 007f5d90  56                   push esi
// 007f5d91  8bf1                 mov esi, ecx
// 007f5d93  e8a83b0000           call 0x7f9940
// 007f5d98  6a00                 push 0
// 007f5d9a  6a06                 push 6
// 007f5d9c  6a03                 push 3
// 007f5d9e  6a02                 push 2
// 007f5da0  8d4604               lea eax, [esi + 4]
// 007f5da3  50                   push eax
// 007f5da4  c70624a49000         mov dword ptr [esi], 0x90a424
// 007f5daa  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f5db0  8bc6                 mov eax, esi
// 007f5db2  5e                   pop esi
// 007f5db3  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
