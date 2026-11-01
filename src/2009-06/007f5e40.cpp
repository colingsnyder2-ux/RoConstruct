// from server: 100% by auto
// roc 2009-06 007f5e40  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2003  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5e40
//
// 007f5e40  56                   push esi
// 007f5e41  8bf1                 mov esi, ecx
// 007f5e43  e8f83a0000           call 0x7f9940
// 007f5e48  6a00                 push 0
// 007f5e4a  6a00                 push 0
// 007f5e4c  6a01                 push 1
// 007f5e4e  6a04                 push 4
// 007f5e50  8d4604               lea eax, [esi + 4]
// 007f5e53  50                   push eax
// 007f5e54  c706b4a49000         mov dword ptr [esi], 0x90a4b4
// 007f5e5a  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f5e60  8bc6                 mov eax, esi
// 007f5e62  5e                   pop esi
// 007f5e63  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2007@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
