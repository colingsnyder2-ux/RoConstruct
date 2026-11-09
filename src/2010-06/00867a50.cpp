// from server: 100% by auto
// roc 2010-06 00867a50  unit: CXTPDockingPaneTabbedContainer  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867a50
//
// 00867a50  56                   push esi
// 00867a51  8bf1                 mov esi, ecx
// 00867a53  e83008f4ff           call 0x7a8288
// 00867a58  33c0                 xor eax, eax
// 00867a5a  894664               mov dword ptr [esi + 0x64], eax
// 00867a5d  894658               mov dword ptr [esi + 0x58], eax
// 00867a60  89465c               mov dword ptr [esi + 0x5c], eax
// 00867a63  894654               mov dword ptr [esi + 0x54], eax
// 00867a66  894660               mov dword ptr [esi + 0x60], eax
// 00867a69  894668               mov dword ptr [esi + 0x68], eax
// 00867a6c  c7066cbba600         mov dword ptr [esi], 0xa6bb6c
// 00867a72  8bc6                 mov eax, esi
// 00867a74  5e                   pop esi
// 00867a75  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ??0CXTPDockingPaneSplitterWnd@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
