// from server: 100% by auto
// roc 2010-06 00815d40  unit: CXTPToolTipContext::CStandardToolTip  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00815d40
//
// 00815d40  8b4160               mov eax, dword ptr [ecx + 0x60]
// 00815d43  85c0                 test eax, eax
// 00815d45  7419                 je 0x815d60
// 00815d47  83782000             cmp dword ptr [eax + 0x20], 0
// 00815d4b  7413                 je 0x815d60
// 00815d4d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00815d50  6a00                 push 0
// 00815d52  6a00                 push 0
// 00815d54  6801040000           push 0x401
// 00815d59  50                   push eax
// 00815d5a  ff1554ba9e00         call dword ptr [0x9eba54]
// 00815d60  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?CancelToolTips@CXTPToolTipContext@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
