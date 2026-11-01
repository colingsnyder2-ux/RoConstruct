// from server: 100% by auto
// roc 2007-03 0071aca0  unit: seg_00710000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071aca0
//
// 0071aca0  f644240804           test byte ptr [esp + 8], 4
// 0071aca5  56                   push esi
// 0071aca6  8bf1                 mov esi, ecx
// 0071aca8  7509                 jne 0x71acb3
// 0071acaa  e8233af0ff           call 0x61e6d2
// 0071acaf  5e                   pop esi
// 0071acb0  c20800               ret 8
// 0071acb3  8b442408             mov eax, dword ptr [esp + 8]
// 0071acb7  50                   push eax
// 0071acb8  e8d1fe0100           call 0x73ab8e
// 0071acbd  85c0                 test eax, eax
// 0071acbf  7408                 je 0x71acc9
// 0071acc1  50                   push eax
// 0071acc2  8bce                 mov ecx, esi
// 0071acc4  e827fdffff           call 0x71a9f0
// 0071acc9  b801000000           mov eax, 1
// 0071acce  5e                   pop esi
// 0071accf  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?OnPrintClient@CXTPSkinObjectButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
