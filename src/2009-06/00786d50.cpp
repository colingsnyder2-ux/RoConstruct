// from server: 100% by auto
// roc 2009-06 00786d50  unit: CXTPToolTipContext::CStandardToolTip  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00786d50
//
// 00786d50  8b4160               mov eax, dword ptr [ecx + 0x60]
// 00786d53  85c0                 test eax, eax
// 00786d55  7419                 je 0x786d70
// 00786d57  83782000             cmp dword ptr [eax + 0x20], 0
// 00786d5b  7413                 je 0x786d70
// 00786d5d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00786d60  6a00                 push 0
// 00786d62  6a00                 push 0
// 00786d64  6801040000           push 0x401
// 00786d69  50                   push eax
// 00786d6a  ff1590ee8900         call dword ptr [0x89ee90]
// 00786d70  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?CancelToolTips@CXTPToolTipContext@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
