// from server: 100% by auto
// roc 2009-12 008b55f0  unit: CXTPDockingPaneSplitterWnd  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b55f0
//
// 008b55f0  56                   push esi
// 008b55f1  57                   push edi
// 008b55f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008b55f6  8bf1                 mov esi, ecx
// 008b55f8  85ff                 test edi, edi
// 008b55fa  7429                 je 0x8b5625
// 008b55fc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b5600  8b442410             mov eax, dword ptr [esp + 0x10]
// 008b5604  6a01                 push 1
// 008b5606  6a00                 push 0
// 008b5608  894e34               mov dword ptr [esi + 0x34], ecx
// 008b560b  57                   push edi
// 008b560c  8bce                 mov ecx, esi
// 008b560e  898690000000         mov dword ptr [esi + 0x90], eax
// 008b5614  e887f6ffff           call 0x8b4ca0
// 008b5619  8b5704               mov edx, dword ptr [edi + 4]
// 008b561c  895624               mov dword ptr [esi + 0x24], edx
// 008b561f  8b4708               mov eax, dword ptr [edi + 8]
// 008b5622  894628               mov dword ptr [esi + 0x28], eax
// 008b5625  5f                   pop edi
// 008b5626  5e                   pop esi
// 008b5627  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?Init@CXTPDockingPaneSplitterContainer@@IAEXPAVCXTPDockingPaneBase@@HPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
