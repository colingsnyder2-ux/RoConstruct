// from server: 100% by auto
// roc 2009-06 00790740  unit: CXTPPropertyGridItemEnum  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790740
//
// 00790740  57                   push edi
// 00790741  8bf9                 mov edi, ecx
// 00790743  837f0800             cmp dword ptr [edi + 8], 0
// 00790747  7434                 je 0x79077d
// 00790749  56                   push esi
// 0079074a  6854fb8f00           push 0x8ffb54
// 0079074f  ff15e4e18900         call dword ptr [0x89e1e4]
// 00790755  8bcf                 mov ecx, edi
// 00790757  8bf0                 mov esi, eax
// 00790759  e822ffffff           call 0x790680
// 0079075e  3bb0d0000000         cmp esi, dword ptr [eax + 0xd0]
// 00790764  7416                 je 0x79077c
// 00790766  68d0000000           push 0xd0
// 0079076b  6a00                 push 0
// 0079076d  50                   push eax
// 0079076e  89b0d0000000         mov dword ptr [eax + 0xd0], esi
// 00790774  e8fb94f8ff           call 0x719c74
// 00790779  83c40c               add esp, 0xc
// 0079077c  5e                   pop esi
// 0079077d  5f                   pop edi
// 0079077e  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ?ReloadLibrary@CXTPWinThemeWrapper@@ABEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
