// from server: 100% by auto
// roc 2009-12 0085fc90  unit: CXTPToolTipContextToolTip  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085fc90
//
// 0085fc90  8b442404             mov eax, dword ptr [esp + 4]
// 0085fc94  83e801               sub eax, 1
// 0085fc97  0fb7542408           movzx edx, word ptr [esp + 8]
// 0085fc9c  740e                 je 0x85fcac
// 0085fc9e  83e802               sub eax, 2
// 0085fca1  750f                 jne 0x85fcb2
// 0085fca3  899120010000         mov dword ptr [ecx + 0x120], edx
// 0085fca9  c20800               ret 8
// 0085fcac  899124010000         mov dword ptr [ecx + 0x124], edx
// 0085fcb2  33c0                 xor eax, eax
// 0085fcb4  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?OnSetDelayTime@CXTPToolTipContextToolTip@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
