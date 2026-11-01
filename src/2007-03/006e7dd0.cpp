// from server: 100% by auto
// roc 2007-03 006e7dd0  unit: seg_006e0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7dd0
//
// 006e7dd0  56                   push esi
// 006e7dd1  8bf1                 mov esi, ecx
// 006e7dd3  e888fc0100           call 0x707a60
// 006e7dd8  6a02                 push 2
// 006e7dda  6a04                 push 4
// 006e7ddc  6a02                 push 2
// 006e7dde  6a02                 push 2
// 006e7de0  8d4604               lea eax, [esi + 4]
// 006e7de3  50                   push eax
// 006e7de4  c706f49a7d00         mov dword ptr [esi], 0x7d9af4
// 006e7dea  ff15b4ed7700         call dword ptr [0x77edb4]
// 006e7df0  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006e7df7  8bc6                 mov eax, esi
// 006e7df9  5e                   pop esi
// 006e7dfa  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetStateButtons@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
