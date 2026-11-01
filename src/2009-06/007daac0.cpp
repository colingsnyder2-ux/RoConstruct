// from server: 100% by auto
// roc 2009-06 007daac0  unit: CXTPDockingPaneSplitterWnd  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007daac0
//
// 007daac0  56                   push esi
// 007daac1  57                   push edi
// 007daac2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007daac6  8bf1                 mov esi, ecx
// 007daac8  85ff                 test edi, edi
// 007daaca  7429                 je 0x7daaf5
// 007daacc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007daad0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007daad4  6a01                 push 1
// 007daad6  6a00                 push 0
// 007daad8  894e34               mov dword ptr [esi + 0x34], ecx
// 007daadb  57                   push edi
// 007daadc  8bce                 mov ecx, esi
// 007daade  898690000000         mov dword ptr [esi + 0x90], eax
// 007daae4  e887f6ffff           call 0x7da170
// 007daae9  8b5704               mov edx, dword ptr [edi + 4]
// 007daaec  895624               mov dword ptr [esi + 0x24], edx
// 007daaef  8b4708               mov eax, dword ptr [edi + 8]
// 007daaf2  894628               mov dword ptr [esi + 0x28], eax
// 007daaf5  5f                   pop edi
// 007daaf6  5e                   pop esi
// 007daaf7  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?Init@CXTPDockingPaneSplitterContainer@@IAEXPAVCXTPDockingPaneBase@@HPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
