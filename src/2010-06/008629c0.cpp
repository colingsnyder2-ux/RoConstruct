// from server: 100% by auto
// roc 2010-06 008629c0  unit: CXTPDockingPaneMiniWnd  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008629c0
//
// 008629c0  56                   push esi
// 008629c1  8bf1                 mov esi, ecx
// 008629c3  83be28ffffff00       cmp dword ptr [esi - 0xd8], 0
// 008629ca  7445                 je 0x862a11
// 008629cc  8b4638               mov eax, dword ptr [esi + 0x38]
// 008629cf  85c0                 test eax, eax
// 008629d1  742d                 je 0x862a00
// 008629d3  8d4820               lea ecx, [eax + 0x20]
// 008629d6  8b01                 mov eax, dword ptr [ecx]
// 008629d8  8b5014               mov edx, dword ptr [eax + 0x14]
// 008629db  ffd2                 call edx
// 008629dd  85c0                 test eax, eax
// 008629df  751f                 jne 0x862a00
// 008629e1  50                   push eax
// 008629e2  50                   push eax
// 008629e3  8b8628ffffff         mov eax, dword ptr [esi - 0xd8]
// 008629e9  6863030000           push 0x363
// 008629ee  50                   push eax
// 008629ef  c7465c01000000       mov dword ptr [esi + 0x5c], 1
// 008629f6  ff1548ba9e00         call dword ptr [0x9eba48]
// 008629fc  5e                   pop esi
// 008629fd  c20400               ret 4
// 00862a00  8b9608ffffff         mov edx, dword ptr [esi - 0xf8]
// 00862a06  8b4268               mov eax, dword ptr [edx + 0x68]
// 00862a09  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 00862a0f  ffd0                 call eax
// 00862a11  5e                   pop esi
// 00862a12  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnChildContainerChanged@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneMiniWnd.cpp
