// from server: 100% by auto
// roc 2009-12 007f8fa0  unit: CXTPEdit  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f8fa0
//
// 007f8fa0  56                   push esi
// 007f8fa1  8bf1                 mov esi, ecx
// 007f8fa3  6a00                 push 0
// 007f8fa5  c7465c01000000       mov dword ptr [esi + 0x5c], 1
// 007f8fac  e863acffff           call 0x7f3c14
// 007f8fb1  8b442408             mov eax, dword ptr [esp + 8]
// 007f8fb5  50                   push eax
// 007f8fb6  8bce                 mov ecx, esi
// 007f8fb8  c7465c00000000       mov dword ptr [esi + 0x5c], 0
// 007f8fbf  e850acffff           call 0x7f3c14
// 007f8fc4  5e                   pop esi
// 007f8fc5  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?SetWindowTextEx@CXTPCommandBarEditCtrl@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
