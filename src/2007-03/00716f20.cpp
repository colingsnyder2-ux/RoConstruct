// from server: 100% by auto
// roc 2007-03 00716f20  unit: seg_00710000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00716f20
//
// 00716f20  f644240804           test byte ptr [esp + 8], 4
// 00716f25  56                   push esi
// 00716f26  8bf1                 mov esi, ecx
// 00716f28  7509                 jne 0x716f33
// 00716f2a  e8a377f0ff           call 0x61e6d2
// 00716f2f  5e                   pop esi
// 00716f30  c20800               ret 8
// 00716f33  8b442408             mov eax, dword ptr [esp + 8]
// 00716f37  50                   push eax
// 00716f38  e8513c0200           call 0x73ab8e
// 00716f3d  85c0                 test eax, eax
// 00716f3f  7408                 je 0x716f49
// 00716f41  50                   push eax
// 00716f42  8bce                 mov ecx, esi
// 00716f44  e837f0ffff           call 0x715f80
// 00716f49  b801000000           mov eax, 1
// 00716f4e  5e                   pop esi
// 00716f4f  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?OnPrintClient@CXTPSkinObjectButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
