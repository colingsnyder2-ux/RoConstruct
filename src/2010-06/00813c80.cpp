// from server: 100% by auto
// roc 2010-06 00813c80  unit: CXTPToolTipContextToolTip  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813c80
//
// 00813c80  8b442404             mov eax, dword ptr [esp + 4]
// 00813c84  83e801               sub eax, 1
// 00813c87  0fb7542408           movzx edx, word ptr [esp + 8]
// 00813c8c  740e                 je 0x813c9c
// 00813c8e  83e802               sub eax, 2
// 00813c91  750f                 jne 0x813ca2
// 00813c93  899120010000         mov dword ptr [ecx + 0x120], edx
// 00813c99  c20800               ret 8
// 00813c9c  899124010000         mov dword ptr [ecx + 0x124], edx
// 00813ca2  33c0                 xor eax, eax
// 00813ca4  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetDelayTime@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
