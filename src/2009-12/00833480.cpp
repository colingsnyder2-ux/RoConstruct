// from server: 100% by auto
// roc 2009-12 00833480  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833480
//
// 00833480  83ec10               sub esp, 0x10
// 00833483  57                   push edi
// 00833484  8bf9                 mov edi, ecx
// 00833486  837f0400             cmp dword ptr [edi + 4], 0
// 0083348a  7444                 je 0x8334d0
// 0083348c  56                   push esi
// 0083348d  e8cef0ffff           call 0x832560
// 00833492  8bf0                 mov esi, eax
// 00833494  85f6                 test esi, esi
// 00833496  7437                 je 0x8334cf
// 00833498  53                   push ebx
// 00833499  8b1de8cb9800         mov ebx, dword ptr [0x98cbe8]
// 0083349f  90                   nop 
// 008334a0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008334a3  6a01                 push 1
// 008334a5  8d442410             lea eax, [esp + 0x10]
// 008334a9  50                   push eax
// 008334aa  56                   push esi
// 008334ab  e8460dfcff           call 0x7f41f6
// 008334b0  8b5734               mov edx, dword ptr [edi + 0x34]
// 008334b3  8b4220               mov eax, dword ptr [edx + 0x20]
// 008334b6  6a01                 push 1
// 008334b8  8d4c2410             lea ecx, [esp + 0x10]
// 008334bc  51                   push ecx
// 008334bd  50                   push eax
// 008334be  ffd3                 call ebx
// 008334c0  56                   push esi
// 008334c1  8bcf                 mov ecx, edi
// 008334c3  e8e8f0ffff           call 0x8325b0
// 008334c8  8bf0                 mov esi, eax
// 008334ca  85f6                 test esi, esi
// 008334cc  75d2                 jne 0x8334a0
// 008334ce  5b                   pop ebx
// 008334cf  5e                   pop esi
// 008334d0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 008334d3  e85809fcff           call 0x7f3e30
// 008334d8  5f                   pop edi
// 008334d9  83c410               add esp, 0x10
// 008334dc  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnSetFocus@CXTPTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
