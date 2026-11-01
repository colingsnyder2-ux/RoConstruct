// from server: 100% by auto
// roc 2009-06 0071ad90  unit: CXTPEdit  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071ad90
//
// 0071ad90  56                   push esi
// 0071ad91  8bf1                 mov esi, ecx
// 0071ad93  6a00                 push 0
// 0071ad95  c7465c01000000       mov dword ptr [esi + 0x5c], 1
// 0071ad9c  e84be0ffff           call 0x718dec
// 0071ada1  8b442408             mov eax, dword ptr [esp + 8]
// 0071ada5  50                   push eax
// 0071ada6  8bce                 mov ecx, esi
// 0071ada8  c7465c00000000       mov dword ptr [esi + 0x5c], 0
// 0071adaf  e838e0ffff           call 0x718dec
// 0071adb4  5e                   pop esi
// 0071adb5  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?SetWindowTextEx@CXTPCommandBarEditCtrl@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
