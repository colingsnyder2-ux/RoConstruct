// from server: 100% by auto
// roc 2009-06 00784b90  unit: CXTColorDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00784b90
//
// 00784b90  8b442404             mov eax, dword ptr [esp + 4]
// 00784b94  85c0                 test eax, eax
// 00784b96  7415                 je 0x784bad
// 00784b98  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00784b9b  3b5020               cmp edx, dword ptr [eax + 0x20]
// 00784b9e  7508                 jne 0x784ba8
// 00784ba0  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00784ba3  3b4824               cmp ecx, dword ptr [eax + 0x24]
// 00784ba6  740b                 je 0x784bb3
// 00784ba8  33c0                 xor eax, eax
// 00784baa  c20400               ret 4
// 00784bad  83792000             cmp dword ptr [ecx + 0x20], 0
// 00784bb1  75f5                 jne 0x784ba8
// 00784bb3  b801000000           mov eax, 1
// 00784bb8  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?IsEqual@TOOLITEM@CXTPToolTipContextToolTip@@QAEHPAU12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
