// from server: 100% by auto
// roc 2007-03 00707a60  unit: seg_00700000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707a60
//
// 00707a60  56                   push esi
// 00707a61  6a00                 push 0
// 00707a63  6a00                 push 0
// 00707a65  8bf1                 mov esi, ecx
// 00707a67  6a00                 push 0
// 00707a69  6a00                 push 0
// 00707a6b  8d4604               lea eax, [esi + 4]
// 00707a6e  50                   push eax
// 00707a6f  c7067cde7d00         mov dword ptr [esi], 0x7dde7c
// 00707a75  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00707a7c  ff15b4ed7700         call dword ptr [0x77edb4]
// 00707a82  c74614feffffff       mov dword ptr [esi + 0x14], 0xfffffffe
// 00707a89  c7462000000000       mov dword ptr [esi + 0x20], 0
// 00707a90  8bc6                 mov eax, esi
// 00707a92  5e                   pop esi
// 00707a93  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ??0CXTPTabPaintManagerAppearanceSet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
