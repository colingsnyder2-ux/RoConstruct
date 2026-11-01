// from server: 100% by auto
// roc 2009-12 008d0990  unit: RBX::SleepStage  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0990
//
// 008d0990  56                   push esi
// 008d0991  8bf1                 mov esi, ecx
// 008d0993  e8483b0000           call 0x8d44e0
// 008d0998  6a00                 push 0
// 008d099a  6a06                 push 6
// 008d099c  6a03                 push 3
// 008d099e  6a02                 push 2
// 008d09a0  8d4604               lea eax, [esi + 4]
// 008d09a3  50                   push eax
// 008d09a4  c706dca8a000         mov dword ptr [esi], 0xa0a8dc
// 008d09aa  ff1538ca9800         call dword ptr [0x98ca38]
// 008d09b0  c7462400000000       mov dword ptr [esi + 0x24], 0
// 008d09b7  8bc6                 mov eax, esi
// 008d09b9  5e                   pop esi
// 008d09ba  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
