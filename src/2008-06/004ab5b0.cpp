// from server: 100% by auto
// roc 2008-06 004ab5b0  unit: RBX::Network::Replicator::MarkerItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ab5b0
//
// 004ab5b0  f644240401           test byte ptr [esp + 4], 1
// 004ab5b5  56                   push esi
// 004ab5b6  8bf1                 mov esi, ecx
// 004ab5b8  7409                 je 0x4ab5c3
// 004ab5ba  56                   push esi
// 004ab5bb  e8ba501f00           call 0x6a067a
// 004ab5c0  83c404               add esp, 4
// 004ab5c3  8bc6                 mov eax, esi
// 004ab5c5  5e                   pop esi
// 004ab5c6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ??_GCCellObj@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
