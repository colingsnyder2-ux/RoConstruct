// from server: 100% by auto
// roc 2007-08 00714a90  unit: CXTCaptionButton  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00714a90
//
// 00714a90  56                   push esi
// 00714a91  8bf1                 mov esi, ecx
// 00714a93  e83cb2f1ff           call 0x62fcd4
// 00714a98  807e7400             cmp byte ptr [esi + 0x74], 0
// 00714a9c  740d                 je 0x714aab
// 00714a9e  8b06                 mov eax, dword ptr [esi]
// 00714aa0  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 00714aa6  8bce                 mov ecx, esi
// 00714aa8  5e                   pop esi
// 00714aa9  ffe2                 jmp edx
// 00714aab  5e                   pop esi
// 00714aac  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?PreSubclassWindow@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
