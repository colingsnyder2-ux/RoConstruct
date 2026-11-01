// from server: 100% by auto
// roc 2011-06 00871b10  unit: CXTPToolTipContext::CHTMLToolTip  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00871b10
//
// 00871b10  8b442404             mov eax, dword ptr [esp + 4]
// 00871b14  56                   push esi
// 00871b15  57                   push edi
// 00871b16  33ff                 xor edi, edi
// 00871b18  8bf1                 mov esi, ecx
// 00871b1a  3bc7                 cmp eax, edi
// 00871b1c  740b                 je 0x871b29
// 00871b1e  50                   push eax
// 00871b1f  e83cf9ffff           call 0x871460
// 00871b24  5f                   pop edi
// 00871b25  5e                   pop esi
// 00871b26  c20400               ret 4
// 00871b29  ff155c27a400         call dword ptr [0xa4275c]
// 00871b2f  8d460c               lea eax, [esi + 0xc]
// 00871b32  897e08               mov dword ptr [esi + 8], edi
// 00871b35  897e20               mov dword ptr [esi + 0x20], edi
// 00871b38  897e1c               mov dword ptr [esi + 0x1c], edi
// 00871b3b  8b3dac19a400         mov edi, dword ptr [0xa419ac]
// 00871b41  50                   push eax
// 00871b42  c74624ffffffff       mov dword ptr [esi + 0x24], 0xffffffff
// 00871b49  ffd7                 call edi
// 00871b4b  83c628               add esi, 0x28
// 00871b4e  56                   push esi
// 00871b4f  ffd7                 call edi
// 00871b51  5f                   pop edi
// 00871b52  5e                   pop esi
// 00871b53  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?Assign@TOOLITEM@CXTPToolTipContextToolTip@@QAEXPAU12@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
