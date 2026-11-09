// from server: 100% by auto
// roc 2010-06 00884b30  unit: CXTPTabPaintManager  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884b30
//
// 00884b30  56                   push esi
// 00884b31  8bf1                 mov esi, ecx
// 00884b33  e8583b0000           call 0x888690
// 00884b38  6a00                 push 0
// 00884b3a  6a06                 push 6
// 00884b3c  6a03                 push 3
// 00884b3e  6a02                 push 2
// 00884b40  8d4604               lea eax, [esi + 4]
// 00884b43  50                   push eax
// 00884b44  c706d4eba600         mov dword ptr [esi], 0xa6ebd4
// 00884b4a  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 00884b50  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00884b57  8bc6                 mov eax, esi
// 00884b59  5e                   pop esi
// 00884b5a  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
