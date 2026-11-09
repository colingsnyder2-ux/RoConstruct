// from server: 100% by auto
// roc 2010-06 0075ce30  unit: RBX::RotateJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075ce30
//
// 0075ce30  56                   push esi
// 0075ce31  8bf1                 mov esi, ecx
// 0075ce33  c7063420a500         mov dword ptr [esi], 0xa52034
// 0075ce39  c746201420a500       mov dword ptr [esi + 0x20], 0xa52014
// 0075ce40  e89b0e0000           call 0x75dce0
// 0075ce45  f644240801           test byte ptr [esp + 8], 1
// 0075ce4a  7409                 je 0x75ce55
// 0075ce4c  56                   push esi
// 0075ce4d  e848ab0400           call 0x7a799a
// 0075ce52  83c404               add esp, 4
// 0075ce55  8bc6                 mov eax, esi
// 0075ce57  5e                   pop esi
// 0075ce58  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??_GCXTPControlButton@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
