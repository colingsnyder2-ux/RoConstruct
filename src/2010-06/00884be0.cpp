// from server: 100% by auto
// roc 2010-06 00884be0  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2007  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884be0
//
// 00884be0  56                   push esi
// 00884be1  8bf1                 mov esi, ecx
// 00884be3  e8a83a0000           call 0x888690
// 00884be8  6a02                 push 2
// 00884bea  6a04                 push 4
// 00884bec  6a02                 push 2
// 00884bee  6a02                 push 2
// 00884bf0  8d4604               lea eax, [esi + 4]
// 00884bf3  50                   push eax
// 00884bf4  c70664eca600         mov dword ptr [esi], 0xa6ec64
// 00884bfa  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 00884c00  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00884c07  8bc6                 mov eax, esi
// 00884c09  5e                   pop esi
// 00884c0a  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetStateButtons@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
