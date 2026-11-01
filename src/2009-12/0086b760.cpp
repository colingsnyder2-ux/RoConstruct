// from server: 100% by auto
// roc 2009-12 0086b760  unit: CXTPPropertyGridItemEnum  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086b760
//
// 0086b760  57                   push edi
// 0086b761  8bf9                 mov edi, ecx
// 0086b763  837f0800             cmp dword ptr [edi + 8], 0
// 0086b767  7434                 je 0x86b79d
// 0086b769  56                   push esi
// 0086b76a  68dcff9f00           push 0x9fffdc
// 0086b76f  ff151cb29800         call dword ptr [0x98b21c]
// 0086b775  8bcf                 mov ecx, edi
// 0086b777  8bf0                 mov esi, eax
// 0086b779  e822ffffff           call 0x86b6a0
// 0086b77e  3bb0d0000000         cmp esi, dword ptr [eax + 0xd0]
// 0086b784  7416                 je 0x86b79c
// 0086b786  68d0000000           push 0xd0
// 0086b78b  6a00                 push 0
// 0086b78d  50                   push eax
// 0086b78e  89b0d0000000         mov dword ptr [eax + 0xd0], esi
// 0086b794  e80b93f8ff           call 0x7f4aa4
// 0086b799  83c40c               add esp, 0xc
// 0086b79c  5e                   pop esi
// 0086b79d  5f                   pop edi
// 0086b79e  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ?ReloadLibrary@CXTPWinThemeWrapper@@ABEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
