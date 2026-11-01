// from server: 100% by auto
// roc 2010-06 00815350  unit: CXTPToolTipContext::CHTMLToolTip::XDocHostUIHandler  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00815350
//
// 00815350  83ec10               sub esp, 0x10
// 00815353  56                   push esi
// 00815354  8b742418             mov esi, dword ptr [esp + 0x18]
// 00815358  8b86e8feffff         mov eax, dword ptr [esi - 0x118]
// 0081535e  81c6ccfeffff         add esi, 0xfffffecc
// 00815364  50                   push eax
// 00815365  8d4c2408             lea ecx, [esp + 8]
// 00815369  e80229f9ff           call 0x7a7c70
// 0081536e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00815372  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00815376  51                   push ecx
// 00815377  52                   push edx
// 00815378  8bce                 mov ecx, esi
// 0081537a  e8132ef9ff           call 0x7a8192
// 0081537f  8bf0                 mov esi, eax
// 00815381  8b442408             mov eax, dword ptr [esp + 8]
// 00815385  85c0                 test eax, eax
// 00815387  7407                 je 0x815390
// 00815389  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0081538d  894804               mov dword ptr [eax + 4], ecx
// 00815390  837c241000           cmp dword ptr [esp + 0x10], 0
// 00815395  740c                 je 0x8153a3
// 00815397  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0081539b  52                   push edx
// 0081539c  6a00                 push 0
// 0081539e  e8c128f9ff           call 0x7a7c64
// 008153a3  8bc6                 mov eax, esi
// 008153a5  5e                   pop esi
// 008153a6  83c410               add esp, 0x10
// 008153a9  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?QueryInterface@XOleClientSite@CHTMLToolTip@CXTPToolTipContext@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
