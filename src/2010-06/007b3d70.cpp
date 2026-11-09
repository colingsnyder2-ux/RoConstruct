// from server: 100% by auto
// roc 2010-06 007b3d70  unit: CXTPEdit  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3d70
//
// 007b3d70  56                   push esi
// 007b3d71  8bf1                 mov esi, ecx
// 007b3d73  6a00                 push 0
// 007b3d75  c7465c01000000       mov dword ptr [esi + 0x5c], 1
// 007b3d7c  e8d33fffff           call 0x7a7d54
// 007b3d81  8b442408             mov eax, dword ptr [esp + 8]
// 007b3d85  50                   push eax
// 007b3d86  8bce                 mov ecx, esi
// 007b3d88  c7465c00000000       mov dword ptr [esi + 0x5c], 0
// 007b3d8f  e8c03fffff           call 0x7a7d54
// 007b3d94  5e                   pop esi
// 007b3d95  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?SetWindowTextEx@CXTPCommandBarEditCtrl@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
