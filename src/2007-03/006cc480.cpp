// from server: 100% by auto
// roc 2007-03 006cc480  unit: seg_006c0000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006cc480
//
// 006cc480  56                   push esi
// 006cc481  8bf1                 mov esi, ecx
// 006cc483  e8e625f5ff           call 0x61ea6e
// 006cc488  33c0                 xor eax, eax
// 006cc48a  894664               mov dword ptr [esi + 0x64], eax
// 006cc48d  894658               mov dword ptr [esi + 0x58], eax
// 006cc490  89465c               mov dword ptr [esi + 0x5c], eax
// 006cc493  894654               mov dword ptr [esi + 0x54], eax
// 006cc496  894660               mov dword ptr [esi + 0x60], eax
// 006cc499  894668               mov dword ptr [esi + 0x68], eax
// 006cc49c  c7061c6e7d00         mov dword ptr [esi], 0x7d6e1c
// 006cc4a2  8bc6                 mov eax, esi
// 006cc4a4  5e                   pop esi
// 006cc4a5  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ??0CXTPDockingPaneSplitterWnd@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
