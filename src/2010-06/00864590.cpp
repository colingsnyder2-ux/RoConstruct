// from server: 100% by auto
// roc 2010-06 00864590  unit: CXTPDockingPaneMiniWnd  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864590
//
// 00864590  8b442404             mov eax, dword ptr [esp + 4]
// 00864594  56                   push esi
// 00864595  8bf1                 mov esi, ecx
// 00864597  c7401000000000       mov dword ptr [eax + 0x10], 0
// 0086459e  83be28ffffff00       cmp dword ptr [esi - 0xd8], 0
// 008645a5  c7463800000000       mov dword ptr [esi + 0x38], 0
// 008645ac  740d                 je 0x8645bb
// 008645ae  6a00                 push 0
// 008645b0  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 008645b6  e8cd36f4ff           call 0x7a7c88
// 008645bb  837e5000             cmp dword ptr [esi + 0x50], 0
// 008645bf  740b                 je 0x8645cc
// 008645c1  8d8e08ffffff         lea ecx, [esi - 0xf8]
// 008645c7  e854feffff           call 0x864420
// 008645cc  5e                   pop esi
// 008645cd  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?RemovePane@CXTPDockingPaneMiniWnd@@MAEXPAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
