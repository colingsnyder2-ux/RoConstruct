// from server: 100% by auto
// roc 2010-06 00814290  unit: CXTPToolTipContext::CHTMLToolTip  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00814290
//
// 00814290  56                   push esi
// 00814291  57                   push edi
// 00814292  8bf1                 mov esi, ecx
// 00814294  ff1588c69e00         call dword ptr [0x9ec688]
// 0081429a  8b3de4ba9e00         mov edi, dword ptr [0x9ebae4]
// 008142a0  33c0                 xor eax, eax
// 008142a2  894608               mov dword ptr [esi + 8], eax
// 008142a5  894620               mov dword ptr [esi + 0x20], eax
// 008142a8  89461c               mov dword ptr [esi + 0x1c], eax
// 008142ab  8d460c               lea eax, [esi + 0xc]
// 008142ae  50                   push eax
// 008142af  c74624ffffffff       mov dword ptr [esi + 0x24], 0xffffffff
// 008142b6  ffd7                 call edi
// 008142b8  83c628               add esi, 0x28
// 008142bb  56                   push esi
// 008142bc  ffd7                 call edi
// 008142be  5f                   pop edi
// 008142bf  5e                   pop esi
// 008142c0  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ?Reset@TOOLITEM@CXTPToolTipContextToolTip@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
