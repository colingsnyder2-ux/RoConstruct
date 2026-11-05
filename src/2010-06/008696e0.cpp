// from server: 100% by auto
// roc 2010-06 008696e0  unit: CXTPDockingPaneSplitterWnd  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008696e0
//
// 008696e0  56                   push esi
// 008696e1  57                   push edi
// 008696e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008696e6  8bf1                 mov esi, ecx
// 008696e8  85ff                 test edi, edi
// 008696ea  7429                 je 0x869715
// 008696ec  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008696f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008696f4  6a01                 push 1
// 008696f6  6a00                 push 0
// 008696f8  894e34               mov dword ptr [esi + 0x34], ecx
// 008696fb  57                   push edi
// 008696fc  8bce                 mov ecx, esi
// 008696fe  898690000000         mov dword ptr [esi + 0x90], eax
// 00869704  e887f6ffff           call 0x868d90
// 00869709  8b5704               mov edx, dword ptr [edi + 4]
// 0086970c  895624               mov dword ptr [esi + 0x24], edx
// 0086970f  8b4708               mov eax, dword ptr [edi + 8]
// 00869712  894628               mov dword ptr [esi + 0x28], eax
// 00869715  5f                   pop edi
// 00869716  5e                   pop esi
// 00869717  c20c00               ret 0xc
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?Init@CXTPDockingPaneSplitterContainer@@IAEXPAVCXTPDockingPaneBase@@HPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
