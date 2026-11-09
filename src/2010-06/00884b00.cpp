// from server: 100% by auto
// roc 2010-06 00884b00  unit: CXTPTabPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884b00
//
// 00884b00  56                   push esi
// 00884b01  8bf1                 mov esi, ecx
// 00884b03  e8883b0000           call 0x888690
// 00884b08  6a00                 push 0
// 00884b0a  6a06                 push 6
// 00884b0c  6a03                 push 3
// 00884b0e  6a02                 push 2
// 00884b10  8d4604               lea eax, [esi + 4]
// 00884b13  50                   push eax
// 00884b14  c7068ceba600         mov dword ptr [esi], 0xa6eb8c
// 00884b1a  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 00884b20  8bc6                 mov eax, esi
// 00884b22  5e                   pop esi
// 00884b23  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
