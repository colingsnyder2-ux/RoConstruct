// from server: 100% by auto
// roc 2011-06 00871ad0  unit: CXTPToolTipContext::CHTMLToolTip  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00871ad0
//
// 00871ad0  56                   push esi
// 00871ad1  57                   push edi
// 00871ad2  8bf1                 mov esi, ecx
// 00871ad4  ff155c27a400         call dword ptr [0xa4275c]
// 00871ada  8b3dac19a400         mov edi, dword ptr [0xa419ac]
// 00871ae0  33c0                 xor eax, eax
// 00871ae2  894608               mov dword ptr [esi + 8], eax
// 00871ae5  894620               mov dword ptr [esi + 0x20], eax
// 00871ae8  89461c               mov dword ptr [esi + 0x1c], eax
// 00871aeb  8d460c               lea eax, [esi + 0xc]
// 00871aee  50                   push eax
// 00871aef  c74624ffffffff       mov dword ptr [esi + 0x24], 0xffffffff
// 00871af6  ffd7                 call edi
// 00871af8  83c628               add esi, 0x28
// 00871afb  56                   push esi
// 00871afc  ffd7                 call edi
// 00871afe  5f                   pop edi
// 00871aff  5e                   pop esi
// 00871b00  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?Reset@TOOLITEM@CXTPToolTipContextToolTip@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
