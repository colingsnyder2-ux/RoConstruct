// from server: 100% by auto
// roc 2010-06 0075de40  unit: RBX::MultiJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075de40
//
// 0075de40  56                   push esi
// 0075de41  8bf1                 mov esi, ecx
// 0075de43  c706a420a500         mov dword ptr [esi], 0xa520a4
// 0075de49  c746208420a500       mov dword ptr [esi + 0x20], 0xa52084
// 0075de50  e81bb4faff           call 0x709270
// 0075de55  f644240801           test byte ptr [esp + 8], 1
// 0075de5a  7409                 je 0x75de65
// 0075de5c  56                   push esi
// 0075de5d  e8389b0400           call 0x7a799a
// 0075de62  83c404               add esp, 4
// 0075de65  8bc6                 mov eax, esi
// 0075de67  5e                   pop esi
// 0075de68  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??_GCXTPControlButton@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
