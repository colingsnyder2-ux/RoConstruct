// from server: 100% by auto
// roc 2007-03 006e8060  unit: seg_006e0000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e8060
//
// 006e8060  56                   push esi
// 006e8061  8bf1                 mov esi, ecx
// 006e8063  e8f8f90100           call 0x707a60
// 006e8068  6a00                 push 0
// 006e806a  6a06                 push 6
// 006e806c  6a03                 push 3
// 006e806e  6a02                 push 2
// 006e8070  8d4604               lea eax, [esi + 4]
// 006e8073  50                   push eax
// 006e8074  c706649a7d00         mov dword ptr [esi], 0x7d9a64
// 006e807a  ff15b4ed7700         call dword ptr [0x77edb4]
// 006e8080  c706749c7d00         mov dword ptr [esi], 0x7d9c74
// 006e8086  8bc6                 mov eax, esi
// 006e8088  5e                   pop esi
// 006e8089  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPageSelected@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
