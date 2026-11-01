// from server: 100% by auto
// roc 2007-03 0071b950  unit: seg_00710000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071b950
//
// 0071b950  f644240804           test byte ptr [esp + 8], 4
// 0071b955  56                   push esi
// 0071b956  8bf1                 mov esi, ecx
// 0071b958  7509                 jne 0x71b963
// 0071b95a  e8732df0ff           call 0x61e6d2
// 0071b95f  5e                   pop esi
// 0071b960  c20800               ret 8
// 0071b963  8b442408             mov eax, dword ptr [esp + 8]
// 0071b967  50                   push eax
// 0071b968  e821f20100           call 0x73ab8e
// 0071b96d  85c0                 test eax, eax
// 0071b96f  7408                 je 0x71b979
// 0071b971  50                   push eax
// 0071b972  8bce                 mov ecx, esi
// 0071b974  e807fdffff           call 0x71b680
// 0071b979  b801000000           mov eax, 1
// 0071b97e  5e                   pop esi
// 0071b97f  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?OnPrintClient@CXTPSkinObjectButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
