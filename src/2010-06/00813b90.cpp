// from server: 100% by auto
// roc 2010-06 00813b90  unit: CXTColorDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813b90
//
// 00813b90  8b442404             mov eax, dword ptr [esp + 4]
// 00813b94  85c0                 test eax, eax
// 00813b96  7415                 je 0x813bad
// 00813b98  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00813b9b  3b5020               cmp edx, dword ptr [eax + 0x20]
// 00813b9e  7508                 jne 0x813ba8
// 00813ba0  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00813ba3  3b4824               cmp ecx, dword ptr [eax + 0x24]
// 00813ba6  740b                 je 0x813bb3
// 00813ba8  33c0                 xor eax, eax
// 00813baa  c20400               ret 4
// 00813bad  83792000             cmp dword ptr [ecx + 0x20], 0
// 00813bb1  75f5                 jne 0x813ba8
// 00813bb3  b801000000           mov eax, 1
// 00813bb8  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?IsEqual@TOOLITEM@CXTPToolTipContextToolTip@@QAEHPAU12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
