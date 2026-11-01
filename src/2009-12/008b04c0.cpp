// from server: 100% by auto
// roc 2009-12 008b04c0  unit: CXTPDockingPaneMiniWnd  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b04c0
//
// 008b04c0  8b442404             mov eax, dword ptr [esp + 4]
// 008b04c4  56                   push esi
// 008b04c5  8bf1                 mov esi, ecx
// 008b04c7  c7401000000000       mov dword ptr [eax + 0x10], 0
// 008b04ce  83be28ffffff00       cmp dword ptr [esi - 0xd8], 0
// 008b04d5  c7463800000000       mov dword ptr [esi + 0x38], 0
// 008b04dc  740d                 je 0x8b04eb
// 008b04de  6a00                 push 0
// 008b04e0  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 008b04e6  e85d36f4ff           call 0x7f3b48
// 008b04eb  837e5000             cmp dword ptr [esi + 0x50], 0
// 008b04ef  740b                 je 0x8b04fc
// 008b04f1  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 008b04f7  e854feffff           call 0x8b0350
// 008b04fc  5e                   pop esi
// 008b04fd  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?RemovePane@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
