// from server: 100% by auto
// roc 2007-08 00693d00  unit: CXTPStatusBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00693d00
//
// 00693d00  8b442404             mov eax, dword ptr [esp + 4]
// 00693d04  83e801               sub eax, 1
// 00693d07  0fb7542408           movzx edx, word ptr [esp + 8]
// 00693d0c  740e                 je 0x693d1c
// 00693d0e  83e802               sub eax, 2
// 00693d11  750f                 jne 0x693d22
// 00693d13  899120010000         mov dword ptr [ecx + 0x120], edx
// 00693d19  c20800               ret 8
// 00693d1c  899124010000         mov dword ptr [ecx + 0x124], edx
// 00693d22  33c0                 xor eax, eax
// 00693d24  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetDelayTime@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
