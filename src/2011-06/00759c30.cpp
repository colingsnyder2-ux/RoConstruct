// from server: 100% by auto
// roc 2011-06 00759c30  unit: RBX::Network::Replicator::PingItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00759c30
//
// 00759c30  f644240401           test byte ptr [esp + 4], 1
// 00759c35  56                   push esi
// 00759c36  8bf1                 mov esi, ecx
// 00759c38  7409                 je 0x759c43
// 00759c3a  56                   push esi
// 00759c3b  e818040b00           call 0x80a058
// 00759c40  83c404               add esp, 4
// 00759c43  8bc6                 mov eax, esi
// 00759c45  5e                   pop esi
// 00759c46  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ??_GCCellObj@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
