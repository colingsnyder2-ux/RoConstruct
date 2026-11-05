// from server: 100% by auto
// roc 2010-06 0081f760  unit: CXTPPropertyGridItemEnum  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081f760
//
// 0081f760  57                   push edi
// 0081f761  8bf9                 mov edi, ecx
// 0081f763  837f0800             cmp dword ptr [edi + 8], 0
// 0081f767  7434                 je 0x81f79d
// 0081f769  56                   push esi
// 0081f76a  68d442a600           push 0xa642d4
// 0081f76f  ff158ca39e00         call dword ptr [0x9ea38c]
// 0081f775  8bcf                 mov ecx, edi
// 0081f777  8bf0                 mov esi, eax
// 0081f779  e822ffffff           call 0x81f6a0
// 0081f77e  3bb0d0000000         cmp esi, dword ptr [eax + 0xd0]
// 0081f784  7416                 je 0x81f79c
// 0081f786  68d0000000           push 0xd0
// 0081f78b  6a00                 push 0
// 0081f78d  50                   push eax
// 0081f78e  89b0d0000000         mov dword ptr [eax + 0xd0], esi
// 0081f794  e84b94f8ff           call 0x7a8be4
// 0081f799  83c40c               add esp, 0xc
// 0081f79c  5e                   pop esi
// 0081f79d  5f                   pop edi
// 0081f79e  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ?ReloadLibrary@CXTPWinThemeWrapper@@ABEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPWinThemeWrapper.cpp
