// from server: 100% by auto
// roc 2009-12 00833550  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833550
//
// 00833550  53                   push ebx
// 00833551  8bd9                 mov ebx, ecx
// 00833553  837b0400             cmp dword ptr [ebx + 4], 0
// 00833557  7458                 je 0x8335b1
// 00833559  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083355d  57                   push edi
// 0083355e  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00833562  c70000000000         mov dword ptr [eax], 0
// 00833568  8b470c               mov eax, dword ptr [edi + 0xc]
// 0083356b  83f801               cmp eax, 1
// 0083356e  7407                 je 0x833577
// 00833570  3d00800000           cmp eax, 0x8000
// 00833575  7539                 jne 0x8335b0
// 00833577  8b473c               mov eax, dword ptr [edi + 0x3c]
// 0083357a  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 0083357d  56                   push esi
// 0083357e  6a02                 push 2
// 00833580  50                   push eax
// 00833581  e880310f00           call 0x926706
// 00833586  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 00833589  6a01                 push 1
// 0083358b  8bf0                 mov esi, eax
// 0083358d  6a00                 push 0
// 0083358f  51                   push ecx
// 00833590  d1ee                 shr esi, 1
// 00833592  8bcb                 mov ecx, ebx
// 00833594  83e601               and esi, 1
// 00833597  e8d4f6ffff           call 0x832c70
// 0083359c  85c0                 test eax, eax
// 0083359e  740f                 je 0x8335af
// 008335a0  85f6                 test esi, esi
// 008335a2  750b                 jne 0x8335af
// 008335a4  8b573c               mov edx, dword ptr [edi + 0x3c]
// 008335a7  52                   push edx
// 008335a8  8bcb                 mov ecx, ebx
// 008335aa  e861efffff           call 0x832510
// 008335af  5e                   pop esi
// 008335b0  5f                   pop edi
// 008335b1  33c0                 xor eax, eax
// 008335b3  5b                   pop ebx
// 008335b4  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnItemExpanding@CXTPTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
