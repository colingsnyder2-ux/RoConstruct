// from server: 100% by auto
// roc 2009-06 004e5d70  unit: RBX::Network::Replicator::PingItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5d70
//
// 004e5d70  f644240401           test byte ptr [esp + 4], 1
// 004e5d75  56                   push esi
// 004e5d76  8bf1                 mov esi, ecx
// 004e5d78  7409                 je 0x4e5d83
// 004e5d7a  56                   push esi
// 004e5d7b  e8b22c2300           call 0x718a32
// 004e5d80  83c404               add esp, 4
// 004e5d83  8bc6                 mov eax, esi
// 004e5d85  5e                   pop esi
// 004e5d86  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ??_GCCellObj@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
