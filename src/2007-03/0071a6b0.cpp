// from server: 100% by auto
// roc 2007-03 0071a6b0  unit: seg_00710000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071a6b0
//
// 0071a6b0  f644240804           test byte ptr [esp + 8], 4
// 0071a6b5  56                   push esi
// 0071a6b6  8bf1                 mov esi, ecx
// 0071a6b8  7509                 jne 0x71a6c3
// 0071a6ba  e81340f0ff           call 0x61e6d2
// 0071a6bf  5e                   pop esi
// 0071a6c0  c20800               ret 8
// 0071a6c3  8b442408             mov eax, dword ptr [esp + 8]
// 0071a6c7  50                   push eax
// 0071a6c8  e8c1040200           call 0x73ab8e
// 0071a6cd  85c0                 test eax, eax
// 0071a6cf  7408                 je 0x71a6d9
// 0071a6d1  50                   push eax
// 0071a6d2  8bce                 mov ecx, esi
// 0071a6d4  e8a7fdffff           call 0x71a480
// 0071a6d9  b801000000           mov eax, 1
// 0071a6de  5e                   pop esi
// 0071a6df  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?OnPrintClient@CXTPSkinObjectButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
