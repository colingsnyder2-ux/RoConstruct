// from server: 100% by auto
// roc 2009-12 00861d60  unit: CXTPToolTipContext::CStandardToolTip  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00861d60
//
// 00861d60  8b4160               mov eax, dword ptr [ecx + 0x60]
// 00861d63  85c0                 test eax, eax
// 00861d65  7419                 je 0x861d80
// 00861d67  83782000             cmp dword ptr [eax + 0x20], 0
// 00861d6b  7413                 je 0x861d80
// 00861d6d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00861d70  6a00                 push 0
// 00861d72  6a00                 push 0
// 00861d74  6801040000           push 0x401
// 00861d79  50                   push eax
// 00861d7a  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00861d80  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?CancelToolTips@CXTPToolTipContext@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
