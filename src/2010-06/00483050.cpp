// from server: 100% by auto
// roc 2010-06 00483050  unit: RBX::LDraw2Lua::LDrawParser  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00483050
//
// 00483050  56                   push esi
// 00483051  8bf1                 mov esi, ecx
// 00483053  8d4e04               lea ecx, [esi + 4]
// 00483056  c7060c31a100         mov dword ptr [esi], 0xa1310c
// 0048305c  ff1500a49e00         call dword ptr [0x9ea400]
// 00483062  f644240801           test byte ptr [esp + 8], 1
// 00483067  7409                 je 0x483072
// 00483069  56                   push esi
// 0048306a  e82b493200           call 0x7a799a
// 0048306f  83c404               add esp, 4
// 00483072  8bc6                 mov eax, esi
// 00483074  5e                   pop esi
// 00483075  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\SyntaxEdit\XTPSyntaxEditUndoManager.cpp (function ??_GCXTPSyntaxEditCommand@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/SyntaxEdit/XTPSyntaxEditUndoManager.cpp
