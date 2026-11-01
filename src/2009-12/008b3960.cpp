// from server: 100% by auto
// roc 2009-12 008b3960  unit: CXTPDockingPaneTabbedContainer  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b3960
//
// 008b3960  56                   push esi
// 008b3961  8bf1                 mov esi, ecx
// 008b3963  e8e007f4ff           call 0x7f4148
// 008b3968  33c0                 xor eax, eax
// 008b396a  894664               mov dword ptr [esi + 0x64], eax
// 008b396d  894658               mov dword ptr [esi + 0x58], eax
// 008b3970  89465c               mov dword ptr [esi + 0x5c], eax
// 008b3973  894654               mov dword ptr [esi + 0x54], eax
// 008b3976  894660               mov dword ptr [esi + 0x60], eax
// 008b3979  894668               mov dword ptr [esi + 0x68], eax
// 008b397c  c7068478a000         mov dword ptr [esi], 0xa07884
// 008b3982  8bc6                 mov eax, esi
// 008b3984  5e                   pop esi
// 008b3985  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ??0CXTPDockingPaneSplitterWnd@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
