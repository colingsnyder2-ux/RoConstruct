// from server: 100% by auto
// roc 2009-06 007586d0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007586d0
//
// 007586d0  53                   push ebx
// 007586d1  8bd9                 mov ebx, ecx
// 007586d3  837b0400             cmp dword ptr [ebx + 4], 0
// 007586d7  7458                 je 0x758731
// 007586d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007586dd  57                   push edi
// 007586de  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007586e2  c70000000000         mov dword ptr [eax], 0
// 007586e8  8b470c               mov eax, dword ptr [edi + 0xc]
// 007586eb  83f801               cmp eax, 1
// 007586ee  7407                 je 0x7586f7
// 007586f0  3d00800000           cmp eax, 0x8000
// 007586f5  7539                 jne 0x758730
// 007586f7  8b473c               mov eax, dword ptr [edi + 0x3c]
// 007586fa  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 007586fd  56                   push esi
// 007586fe  6a02                 push 2
// 00758700  50                   push eax
// 00758701  e8943a0f00           call 0x84c19a
// 00758706  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 00758709  6a01                 push 1
// 0075870b  8bf0                 mov esi, eax
// 0075870d  6a00                 push 0
// 0075870f  51                   push ecx
// 00758710  d1ee                 shr esi, 1
// 00758712  8bcb                 mov ecx, ebx
// 00758714  83e601               and esi, 1
// 00758717  e8d4f6ffff           call 0x757df0
// 0075871c  85c0                 test eax, eax
// 0075871e  740f                 je 0x75872f
// 00758720  85f6                 test esi, esi
// 00758722  750b                 jne 0x75872f
// 00758724  8b573c               mov edx, dword ptr [edi + 0x3c]
// 00758727  52                   push edx
// 00758728  8bcb                 mov ecx, ebx
// 0075872a  e861efffff           call 0x757690
// 0075872f  5e                   pop esi
// 00758730  5f                   pop edi
// 00758731  33c0                 xor eax, eax
// 00758733  5b                   pop ebx
// 00758734  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnItemExpanding@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
