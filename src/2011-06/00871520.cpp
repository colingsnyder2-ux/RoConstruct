// from server: 100% by auto
// roc 2011-06 00871520  unit: CXTPToolTipContextToolTip  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00871520
//
// 00871520  8b442404             mov eax, dword ptr [esp + 4]
// 00871524  83e801               sub eax, 1
// 00871527  0fb7542408           movzx edx, word ptr [esp + 8]
// 0087152c  740e                 je 0x87153c
// 0087152e  83e802               sub eax, 2
// 00871531  750f                 jne 0x871542
// 00871533  899120010000         mov dword ptr [ecx + 0x120], edx
// 00871539  c20800               ret 8
// 0087153c  899124010000         mov dword ptr [ecx + 0x124], edx
// 00871542  33c0                 xor eax, eax
// 00871544  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetDelayTime@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
