// from server: 100% by auto
// roc 2007-03 00653090  unit: seg_00650000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00653090
//
// 00653090  53                   push ebx
// 00653091  8bd9                 mov ebx, ecx
// 00653093  837b0400             cmp dword ptr [ebx + 4], 0
// 00653097  7458                 je 0x6530f1
// 00653099  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065309d  57                   push edi
// 0065309e  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006530a2  c70000000000         mov dword ptr [eax], 0
// 006530a8  8b470c               mov eax, dword ptr [edi + 0xc]
// 006530ab  83f801               cmp eax, 1
// 006530ae  7407                 je 0x6530b7
// 006530b0  3d00800000           cmp eax, 0x8000
// 006530b5  7539                 jne 0x6530f0
// 006530b7  8b473c               mov eax, dword ptr [edi + 0x3c]
// 006530ba  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 006530bd  56                   push esi
// 006530be  6a02                 push 2
// 006530c0  50                   push eax
// 006530c1  e8c07c0e00           call 0x73ad86
// 006530c6  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 006530c9  6a01                 push 1
// 006530cb  8bf0                 mov esi, eax
// 006530cd  6a00                 push 0
// 006530cf  51                   push ecx
// 006530d0  d1ee                 shr esi, 1
// 006530d2  8bcb                 mov ecx, ebx
// 006530d4  83e601               and esi, 1
// 006530d7  e8d4f6ffff           call 0x6527b0
// 006530dc  85c0                 test eax, eax
// 006530de  740f                 je 0x6530ef
// 006530e0  85f6                 test esi, esi
// 006530e2  750b                 jne 0x6530ef
// 006530e4  8b573c               mov edx, dword ptr [edi + 0x3c]
// 006530e7  52                   push edx
// 006530e8  8bcb                 mov ecx, ebx
// 006530ea  e871efffff           call 0x652060
// 006530ef  5e                   pop esi
// 006530f0  5f                   pop edi
// 006530f1  33c0                 xor eax, eax
// 006530f3  5b                   pop ebx
// 006530f4  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnItemExpanding@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
