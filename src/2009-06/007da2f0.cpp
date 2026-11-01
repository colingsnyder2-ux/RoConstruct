// from server: 100% by auto
// roc 2009-06 007da2f0  unit: CXTPDockingPaneSplitterContainer  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007da2f0
//
// 007da2f0  56                   push esi
// 007da2f1  57                   push edi
// 007da2f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007da2f6  8b4714               mov eax, dword ptr [edi + 0x14]
// 007da2f9  8bf1                 mov esi, ecx
// 007da2fb  8d4ee0               lea ecx, [esi - 0x20]
// 007da2fe  894614               mov dword ptr [esi + 0x14], eax
// 007da301  e81afdffff           call 0x7da020
// 007da306  8bce                 mov ecx, esi
// 007da308  e893aefaff           call 0x7851a0
// 007da30d  8944240c             mov dword ptr [esp + 0xc], eax
// 007da311  85c0                 test eax, eax
// 007da313  741d                 je 0x7da332
// 007da315  8d4c240c             lea ecx, [esp + 0xc]
// 007da319  51                   push ecx
// 007da31a  8bce                 mov ecx, esi
// 007da31c  e84fdf0300           call 0x818270
// 007da321  8b10                 mov edx, dword ptr [eax]
// 007da323  8bc8                 mov ecx, eax
// 007da325  8b423c               mov eax, dword ptr [edx + 0x3c]
// 007da328  57                   push edi
// 007da329  ffd0                 call eax
// 007da32b  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007da330  75e3                 jne 0x7da315
// 007da332  5f                   pop edi
// 007da333  5e                   pop esi
// 007da334  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?OnParentContainerChanged@CXTPDockingPaneSplitterContainer@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
