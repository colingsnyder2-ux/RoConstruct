// from server: 100% by auto
// roc 2009-06 007d5980  unit: CXTPDockingPaneMiniWnd  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5980
//
// 007d5980  8b442404             mov eax, dword ptr [esp + 4]
// 007d5984  56                   push esi
// 007d5985  8bf1                 mov esi, ecx
// 007d5987  c7401000000000       mov dword ptr [eax + 0x10], 0
// 007d598e  83be28ffffff00       cmp dword ptr [esi - 0xd8], 0
// 007d5995  c7463800000000       mov dword ptr [esi + 0x38], 0
// 007d599c  740d                 je 0x7d59ab
// 007d599e  6a00                 push 0
// 007d59a0  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 007d59a6  e87533f4ff           call 0x718d20
// 007d59ab  837e5000             cmp dword ptr [esi + 0x50], 0
// 007d59af  740b                 je 0x7d59bc
// 007d59b1  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 007d59b7  e854feffff           call 0x7d5810
// 007d59bc  5e                   pop esi
// 007d59bd  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?RemovePane@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
