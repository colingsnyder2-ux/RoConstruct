// from server: 100% by auto
// roc 2010-06 00815290  unit: CXTPToolTipContext::CHTMLToolTip::XDocHostUIHandler  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00815290
//
// 00815290  83ec10               sub esp, 0x10
// 00815293  56                   push esi
// 00815294  8b742418             mov esi, dword ptr [esp + 0x18]
// 00815298  8b86e8feffff         mov eax, dword ptr [esi - 0x118]
// 0081529e  81c6ccfeffff         add esi, 0xfffffecc
// 008152a4  50                   push eax
// 008152a5  8d4c2408             lea ecx, [esp + 8]
// 008152a9  e8c229f9ff           call 0x7a7c70
// 008152ae  8bce                 mov ecx, esi
// 008152b0  e8d12ef9ff           call 0x7a8186
// 008152b5  8bf0                 mov esi, eax
// 008152b7  8b442408             mov eax, dword ptr [esp + 8]
// 008152bb  85c0                 test eax, eax
// 008152bd  7407                 je 0x8152c6
// 008152bf  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008152c3  894804               mov dword ptr [eax + 4], ecx
// 008152c6  837c241000           cmp dword ptr [esp + 0x10], 0
// 008152cb  740c                 je 0x8152d9
// 008152cd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008152d1  52                   push edx
// 008152d2  6a00                 push 0
// 008152d4  e88b29f9ff           call 0x7a7c64
// 008152d9  8bc6                 mov eax, esi
// 008152db  5e                   pop esi
// 008152dc  83c410               add esp, 0x10
// 008152df  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?AddRef@XOleClientSite@CHTMLToolTip@CXTPToolTipContext@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
