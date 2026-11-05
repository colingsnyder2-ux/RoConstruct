// from server: 100% by auto
// roc 2010-06 008142d0  unit: CXTPToolTipContext::CHTMLToolTip  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008142d0
//
// 008142d0  8b442404             mov eax, dword ptr [esp + 4]
// 008142d4  56                   push esi
// 008142d5  57                   push edi
// 008142d6  33ff                 xor edi, edi
// 008142d8  8bf1                 mov esi, ecx
// 008142da  3bc7                 cmp eax, edi
// 008142dc  740b                 je 0x8142e9
// 008142de  50                   push eax
// 008142df  e8dcf8ffff           call 0x813bc0
// 008142e4  5f                   pop edi
// 008142e5  5e                   pop esi
// 008142e6  c20400               ret 4
// 008142e9  ff1588c69e00         call dword ptr [0x9ec688]
// 008142ef  8d460c               lea eax, [esi + 0xc]
// 008142f2  897e08               mov dword ptr [esi + 8], edi
// 008142f5  897e20               mov dword ptr [esi + 0x20], edi
// 008142f8  897e1c               mov dword ptr [esi + 0x1c], edi
// 008142fb  8b3de4ba9e00         mov edi, dword ptr [0x9ebae4]
// 00814301  50                   push eax
// 00814302  c74624ffffffff       mov dword ptr [esi + 0x24], 0xffffffff
// 00814309  ffd7                 call edi
// 0081430b  83c628               add esi, 0x28
// 0081430e  56                   push esi
// 0081430f  ffd7                 call edi
// 00814311  5f                   pop edi
// 00814312  5e                   pop esi
// 00814313  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?Assign@TOOLITEM@CXTPToolTipContextToolTip@@QAEXPAU12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
