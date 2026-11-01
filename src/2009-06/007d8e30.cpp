// from server: 100% by auto
// roc 2009-06 007d8e30  unit: CXTPDockingPaneTabbedContainer  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d8e30
//
// 007d8e30  56                   push esi
// 007d8e31  8bf1                 mov esi, ecx
// 007d8e33  e8e804f4ff           call 0x719320
// 007d8e38  33c0                 xor eax, eax
// 007d8e3a  894664               mov dword ptr [esi + 0x64], eax
// 007d8e3d  894658               mov dword ptr [esi + 0x58], eax
// 007d8e40  89465c               mov dword ptr [esi + 0x5c], eax
// 007d8e43  894654               mov dword ptr [esi + 0x54], eax
// 007d8e46  894660               mov dword ptr [esi + 0x60], eax
// 007d8e49  894668               mov dword ptr [esi + 0x68], eax
// 007d8e4c  c70614749000         mov dword ptr [esi], 0x907414
// 007d8e52  8bc6                 mov eax, esi
// 007d8e54  5e                   pop esi
// 007d8e55  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ??0CXTPDockingPaneSplitterWnd@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
