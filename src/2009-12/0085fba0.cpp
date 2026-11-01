// from server: 100% by auto
// roc 2009-12 0085fba0  unit: CXTColorDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085fba0
//
// 0085fba0  8b442404             mov eax, dword ptr [esp + 4]
// 0085fba4  85c0                 test eax, eax
// 0085fba6  7415                 je 0x85fbbd
// 0085fba8  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0085fbab  3b5020               cmp edx, dword ptr [eax + 0x20]
// 0085fbae  7508                 jne 0x85fbb8
// 0085fbb0  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0085fbb3  3b4824               cmp ecx, dword ptr [eax + 0x24]
// 0085fbb6  740b                 je 0x85fbc3
// 0085fbb8  33c0                 xor eax, eax
// 0085fbba  c20400               ret 4
// 0085fbbd  83792000             cmp dword ptr [ecx + 0x20], 0
// 0085fbc1  75f5                 jne 0x85fbb8
// 0085fbc3  b801000000           mov eax, 1
// 0085fbc8  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?IsEqual@TOOLITEM@CXTPToolTipContextToolTip@@QAEHPAU12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
