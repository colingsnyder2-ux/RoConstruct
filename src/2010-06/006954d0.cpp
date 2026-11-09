// from server: 100% by auto
// roc 2010-06 006954d0  unit: RBX::RigidJoint  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006954d0
//
// 006954d0  56                   push esi
// 006954d1  8bf1                 mov esi, ecx
// 006954d3  c706fce1a300         mov dword ptr [esi], 0xa3e1fc
// 006954d9  c74620dce1a300       mov dword ptr [esi + 0x20], 0xa3e1dc
// 006954e0  e88b3d0700           call 0x709270
// 006954e5  f644240801           test byte ptr [esp + 8], 1
// 006954ea  7409                 je 0x6954f5
// 006954ec  56                   push esi
// 006954ed  e8a8241100           call 0x7a799a
// 006954f2  83c404               add esp, 4
// 006954f5  8bc6                 mov eax, esi
// 006954f7  5e                   pop esi
// 006954f8  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlButton.cpp (function ??_GCXTPControlButton@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlButton.cpp
