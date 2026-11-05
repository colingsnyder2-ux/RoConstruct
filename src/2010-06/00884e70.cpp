// from server: 100% by auto
// roc 2010-06 00884e70  unit: CXTPTabPaintManager::CColorSetWinXP  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884e70
//
// 00884e70  56                   push esi
// 00884e71  8bf1                 mov esi, ecx
// 00884e73  e818380000           call 0x888690
// 00884e78  6a00                 push 0
// 00884e7a  6a06                 push 6
// 00884e7c  6a03                 push 3
// 00884e7e  6a02                 push 2
// 00884e80  8d4604               lea eax, [esi + 4]
// 00884e83  50                   push eax
// 00884e84  c7068ceba600         mov dword ptr [esi], 0xa6eb8c
// 00884e8a  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 00884e90  c706e4eda600         mov dword ptr [esi], 0xa6ede4
// 00884e96  8bc6                 mov eax, esi
// 00884e98  5e                   pop esi
// 00884e99  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPageSelected@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
