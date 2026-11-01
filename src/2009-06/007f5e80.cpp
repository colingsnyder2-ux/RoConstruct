// from server: 100% by auto
// roc 2009-06 007f5e80  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2007  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5e80
//
// 007f5e80  56                   push esi
// 007f5e81  8bf1                 mov esi, ecx
// 007f5e83  e8b83a0000           call 0x7f9940
// 007f5e88  6a02                 push 2
// 007f5e8a  6a04                 push 4
// 007f5e8c  6a02                 push 2
// 007f5e8e  6a02                 push 2
// 007f5e90  8d4604               lea eax, [esi + 4]
// 007f5e93  50                   push eax
// 007f5e94  c706fca49000         mov dword ptr [esi], 0x90a4fc
// 007f5e9a  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f5ea0  c7461400000000       mov dword ptr [esi + 0x14], 0
// 007f5ea7  8bc6                 mov eax, esi
// 007f5ea9  5e                   pop esi
// 007f5eaa  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetStateButtons@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
