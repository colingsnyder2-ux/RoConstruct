// from server: 100% by auto
// roc 2009-06 00784c70  unit: CXTPToolTipContextToolTip  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00784c70
//
// 00784c70  8b442404             mov eax, dword ptr [esp + 4]
// 00784c74  83e801               sub eax, 1
// 00784c77  0fb7542408           movzx edx, word ptr [esp + 8]
// 00784c7c  740e                 je 0x784c8c
// 00784c7e  83e802               sub eax, 2
// 00784c81  750f                 jne 0x784c92
// 00784c83  899120010000         mov dword ptr [ecx + 0x120], edx
// 00784c89  c20800               ret 8
// 00784c8c  899124010000         mov dword ptr [ecx + 0x124], edx
// 00784c92  33c0                 xor eax, eax
// 00784c94  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetDelayTime@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
