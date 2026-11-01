// from server: 100% by auto
// roc 2009-12 008334e0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008334e0
//
// 008334e0  83ec10               sub esp, 0x10
// 008334e3  57                   push edi
// 008334e4  8bf9                 mov edi, ecx
// 008334e6  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008334e9  e84209fcff           call 0x7f3e30
// 008334ee  837f0400             cmp dword ptr [edi + 4], 0
// 008334f2  744c                 je 0x833540
// 008334f4  56                   push esi
// 008334f5  8bcf                 mov ecx, edi
// 008334f7  e864f0ffff           call 0x832560
// 008334fc  8bf0                 mov esi, eax
// 008334fe  85f6                 test esi, esi
// 00833500  743d                 je 0x83353f
// 00833502  53                   push ebx
// 00833503  8b1de8cb9800         mov ebx, dword ptr [0x98cbe8]
// 00833509  8da42400000000       lea esp, [esp]
// 00833510  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00833513  6a01                 push 1
// 00833515  8d442410             lea eax, [esp + 0x10]
// 00833519  50                   push eax
// 0083351a  56                   push esi
// 0083351b  e8d60cfcff           call 0x7f41f6
// 00833520  8b5734               mov edx, dword ptr [edi + 0x34]
// 00833523  8b4220               mov eax, dword ptr [edx + 0x20]
// 00833526  6a01                 push 1
// 00833528  8d4c2410             lea ecx, [esp + 0x10]
// 0083352c  51                   push ecx
// 0083352d  50                   push eax
// 0083352e  ffd3                 call ebx
// 00833530  56                   push esi
// 00833531  8bcf                 mov ecx, edi
// 00833533  e878f0ffff           call 0x8325b0
// 00833538  8bf0                 mov esi, eax
// 0083353a  85f6                 test esi, esi
// 0083353c  75d2                 jne 0x833510
// 0083353e  5b                   pop ebx
// 0083353f  5e                   pop esi
// 00833540  5f                   pop edi
// 00833541  83c410               add esp, 0x10
// 00833544  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnKillFocus@CXTPTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
