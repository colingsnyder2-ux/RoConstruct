// from server: 100% by auto
// roc 2010-06 00884ba0  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2003  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884ba0
//
// 00884ba0  56                   push esi
// 00884ba1  8bf1                 mov esi, ecx
// 00884ba3  e8e83a0000           call 0x888690
// 00884ba8  6a00                 push 0
// 00884baa  6a00                 push 0
// 00884bac  6a01                 push 1
// 00884bae  6a04                 push 4
// 00884bb0  8d4604               lea eax, [esi + 4]
// 00884bb3  50                   push eax
// 00884bb4  c7061ceca600         mov dword ptr [esi], 0xa6ec1c
// 00884bba  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 00884bc0  8bc6                 mov eax, esi
// 00884bc2  5e                   pop esi
// 00884bc3  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2007@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
