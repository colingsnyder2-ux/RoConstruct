// from server: 100% by auto
// roc 2009-12 008afba0  unit: CXTPDockingPaneMiniWnd  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008afba0
//
// 008afba0  8b542404             mov edx, dword ptr [esp + 4]
// 008afba4  8b4214               mov eax, dword ptr [edx + 0x14]
// 008afba7  3df1240000           cmp eax, 0x24f1
// 008afbac  7506                 jne 0x8afbb4
// 008afbae  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 008afbb1  c20400               ret 4
// 008afbb4  3df0240000           cmp eax, 0x24f0
// 008afbb9  7515                 jne 0x8afbd0
// 008afbbb  8b4150               mov eax, dword ptr [ecx + 0x50]
// 008afbbe  f7d8                 neg eax
// 008afbc0  1bc0                 sbb eax, eax
// 008afbc2  83e002               and eax, 2
// 008afbc5  894220               mov dword ptr [edx + 0x20], eax
// 008afbc8  a1c091b600           mov eax, dword ptr [0xb691c0]
// 008afbcd  c20400               ret 4
// 008afbd0  3df4240000           cmp eax, 0x24f4
// 008afbd5  751f                 jne 0x8afbf6
// 008afbd7  81c108ffffff         add ecx, 0xffffff08
// 008afbdd  e8defeffff           call 0x8afac0
// 008afbe2  85c0                 test eax, eax
// 008afbe4  740b                 je 0x8afbf1
// 008afbe6  8bc8                 mov ecx, eax
// 008afbe8  e893cffaff           call 0x85cb80
// 008afbed  a810                 test al, 0x10
// 008afbef  7505                 jne 0x8afbf6
// 008afbf1  33c0                 xor eax, eax
// 008afbf3  c20400               ret 4
// 008afbf6  b801000000           mov eax, 1
// 008afbfb  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?IsCaptionButtonVisible@CXTPDockingPaneMiniWnd@@MAEHPAVCXTPDockingPaneCaptionButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
