// from server: 100% by auto
// roc 2007-03 006e7d60  unit: seg_006e0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7d60
//
// 006e7d60  56                   push esi
// 006e7d61  8bf1                 mov esi, ecx
// 006e7d63  e8f8fc0100           call 0x707a60
// 006e7d68  6a00                 push 0
// 006e7d6a  6a06                 push 6
// 006e7d6c  6a03                 push 3
// 006e7d6e  6a02                 push 2
// 006e7d70  8d4604               lea eax, [esi + 4]
// 006e7d73  50                   push eax
// 006e7d74  c706ac9a7d00         mov dword ptr [esi], 0x7d9aac
// 006e7d7a  ff15b4ed7700         call dword ptr [0x77edb4]
// 006e7d80  c7462400000000       mov dword ptr [esi + 0x24], 0
// 006e7d87  8bc6                 mov eax, esi
// 006e7d89  5e                   pop esi
// 006e7d8a  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
