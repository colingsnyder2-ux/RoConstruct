// from server: 100% by auto
// roc 2007-03 006e7d20  unit: seg_006e0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7d20
//
// 006e7d20  56                   push esi
// 006e7d21  8bf1                 mov esi, ecx
// 006e7d23  e838fd0100           call 0x707a60
// 006e7d28  6a00                 push 0
// 006e7d2a  6a06                 push 6
// 006e7d2c  6a03                 push 3
// 006e7d2e  6a02                 push 2
// 006e7d30  8d4604               lea eax, [esi + 4]
// 006e7d33  50                   push eax
// 006e7d34  c706649a7d00         mov dword ptr [esi], 0x7d9a64
// 006e7d3a  ff15b4ed7700         call dword ptr [0x77edb4]
// 006e7d40  8bc6                 mov eax, esi
// 006e7d42  5e                   pop esi
// 006e7d43  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
