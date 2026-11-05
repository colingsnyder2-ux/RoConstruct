// from server: 100% by auto
// roc 2010-06 0074bb30  unit: RBX::Network::Replicator::PingItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0074bb30
//
// 0074bb30  f644240401           test byte ptr [esp + 4], 1
// 0074bb35  56                   push esi
// 0074bb36  8bf1                 mov esi, ecx
// 0074bb38  7409                 je 0x74bb43
// 0074bb3a  56                   push esi
// 0074bb3b  e85abe0500           call 0x7a799a
// 0074bb40  83c404               add esp, 4
// 0074bb43  8bc6                 mov eax, esi
// 0074bb45  5e                   pop esi
// 0074bb46  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ??_GCCellObj@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
