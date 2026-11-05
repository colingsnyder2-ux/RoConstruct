// from server: 100% by auto
// roc 2010-06 008152f0  unit: CXTPToolTipContext::CHTMLToolTip::XDocHostUIHandler  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008152f0
//
// 008152f0  83ec10               sub esp, 0x10
// 008152f3  56                   push esi
// 008152f4  8b742418             mov esi, dword ptr [esp + 0x18]
// 008152f8  8b86e8feffff         mov eax, dword ptr [esi - 0x118]
// 008152fe  81c6ccfeffff         add esi, 0xfffffecc
// 00815304  50                   push eax
// 00815305  8d4c2408             lea ecx, [esp + 8]
// 00815309  e86229f9ff           call 0x7a7c70
// 0081530e  8bce                 mov ecx, esi
// 00815310  e8772ef9ff           call 0x7a818c
// 00815315  8bf0                 mov esi, eax
// 00815317  8b442408             mov eax, dword ptr [esp + 8]
// 0081531b  85c0                 test eax, eax
// 0081531d  7407                 je 0x815326
// 0081531f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00815323  894804               mov dword ptr [eax + 4], ecx
// 00815326  837c241000           cmp dword ptr [esp + 0x10], 0
// 0081532b  740c                 je 0x815339
// 0081532d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00815331  52                   push edx
// 00815332  6a00                 push 0
// 00815334  e82b29f9ff           call 0x7a7c64
// 00815339  8bc6                 mov eax, esi
// 0081533b  5e                   pop esi
// 0081533c  83c410               add esp, 0x10
// 0081533f  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?AddRef@XOleClientSite@CHTMLToolTip@CXTPToolTipContext@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
