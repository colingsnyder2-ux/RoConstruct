// from server: 100% by auto
// roc 2009-12 008b4e20  unit: CXTPDockingPaneSplitterContainer  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b4e20
//
// 008b4e20  56                   push esi
// 008b4e21  57                   push edi
// 008b4e22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008b4e26  8b4714               mov eax, dword ptr [edi + 0x14]
// 008b4e29  8bf1                 mov esi, ecx
// 008b4e2b  8d4ee0               lea ecx, [esi - 0x20]
// 008b4e2e  894614               mov dword ptr [esi + 0x14], eax
// 008b4e31  e81afdffff           call 0x8b4b50
// 008b4e36  8bce                 mov ecx, esi
// 008b4e38  e85359faff           call 0x85a790
// 008b4e3d  8944240c             mov dword ptr [esp + 0xc], eax
// 008b4e41  85c0                 test eax, eax
// 008b4e43  741d                 je 0x8b4e62
// 008b4e45  8d4c240c             lea ecx, [esp + 0xc]
// 008b4e49  51                   push ecx
// 008b4e4a  8bce                 mov ecx, esi
// 008b4e4c  e8bfe00300           call 0x8f2f10
// 008b4e51  8b10                 mov edx, dword ptr [eax]
// 008b4e53  8bc8                 mov ecx, eax
// 008b4e55  8b423c               mov eax, dword ptr [edx + 0x3c]
// 008b4e58  57                   push edi
// 008b4e59  ffd0                 call eax
// 008b4e5b  837c240c00           cmp dword ptr [esp + 0xc], 0
// 008b4e60  75e3                 jne 0x8b4e45
// 008b4e62  5f                   pop edi
// 008b4e63  5e                   pop esi
// 008b4e64  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?OnParentContainerChanged@CXTPDockingPaneSplitterContainer@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
