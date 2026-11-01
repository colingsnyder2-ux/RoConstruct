// from server: 100% by auto
// roc 2011-06 008bfe10  unit: CXTPDockingPaneMiniWnd  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bfe10
//
// 008bfe10  56                   push esi
// 008bfe11  8bf1                 mov esi, ecx
// 008bfe13  83be28ffffff00       cmp dword ptr [esi - 0xd8], 0
// 008bfe1a  7445                 je 0x8bfe61
// 008bfe1c  8b4638               mov eax, dword ptr [esi + 0x38]
// 008bfe1f  85c0                 test eax, eax
// 008bfe21  742d                 je 0x8bfe50
// 008bfe23  8d4820               lea ecx, [eax + 0x20]
// 008bfe26  8b01                 mov eax, dword ptr [ecx]
// 008bfe28  8b5014               mov edx, dword ptr [eax + 0x14]
// 008bfe2b  ffd2                 call edx
// 008bfe2d  85c0                 test eax, eax
// 008bfe2f  751f                 jne 0x8bfe50
// 008bfe31  50                   push eax
// 008bfe32  50                   push eax
// 008bfe33  8b8628ffffff         mov eax, dword ptr [esi - 0xd8]
// 008bfe39  6863030000           push 0x363
// 008bfe3e  50                   push eax
// 008bfe3f  c7465c01000000       mov dword ptr [esi + 0x5c], 1
// 008bfe46  ff15b419a400         call dword ptr [0xa419b4]
// 008bfe4c  5e                   pop esi
// 008bfe4d  c20400               ret 4
// 008bfe50  8b9608ffffff         mov edx, dword ptr [esi - 0xf8]
// 008bfe56  8b4268               mov eax, dword ptr [edx + 0x68]
// 008bfe59  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 008bfe5f  ffd0                 call eax
// 008bfe61  5e                   pop esi
// 008bfe62  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnChildContainerChanged@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneMiniWnd.cpp
