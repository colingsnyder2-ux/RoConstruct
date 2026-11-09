// from server: 100% by auto
// roc 2010-06 00868f10  unit: CXTPDockingPaneSplitterContainer  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00868f10
//
// 00868f10  56                   push esi
// 00868f11  57                   push edi
// 00868f12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00868f16  8b4714               mov eax, dword ptr [edi + 0x14]
// 00868f19  8bf1                 mov esi, ecx
// 00868f1b  8d4ee0               lea ecx, [esi - 0x20]
// 00868f1e  894614               mov dword ptr [esi + 0x14], eax
// 00868f21  e81afdffff           call 0x868c40
// 00868f26  8bce                 mov ecx, esi
// 00868f28  e89362f9ff           call 0x7ff1c0
// 00868f2d  8944240c             mov dword ptr [esp + 0xc], eax
// 00868f31  85c0                 test eax, eax
// 00868f33  741d                 je 0x868f52
// 00868f35  8d4c240c             lea ecx, [esp + 0xc]
// 00868f39  51                   push ecx
// 00868f3a  8bce                 mov ecx, esi
// 00868f3c  e81fe10300           call 0x8a7060
// 00868f41  8b10                 mov edx, dword ptr [eax]
// 00868f43  8bc8                 mov ecx, eax
// 00868f45  8b423c               mov eax, dword ptr [edx + 0x3c]
// 00868f48  57                   push edi
// 00868f49  ffd0                 call eax
// 00868f4b  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00868f50  75e3                 jne 0x868f35
// 00868f52  5f                   pop edi
// 00868f53  5e                   pop esi
// 00868f54  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?OnParentContainerChanged@CXTPDockingPaneSplitterContainer@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
