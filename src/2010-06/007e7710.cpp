// from server: 100% by auto
// roc 2010-06 007e7710  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7710
//
// 007e7710  53                   push ebx
// 007e7711  8bd9                 mov ebx, ecx
// 007e7713  837b0400             cmp dword ptr [ebx + 4], 0
// 007e7717  7458                 je 0x7e7771
// 007e7719  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e771d  57                   push edi
// 007e771e  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007e7722  c70000000000         mov dword ptr [eax], 0
// 007e7728  8b470c               mov eax, dword ptr [edi + 0xc]
// 007e772b  83f801               cmp eax, 1
// 007e772e  7407                 je 0x7e7737
// 007e7730  3d00800000           cmp eax, 0x8000
// 007e7735  7539                 jne 0x7e7770
// 007e7737  8b473c               mov eax, dword ptr [edi + 0x3c]
// 007e773a  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 007e773d  56                   push esi
// 007e773e  6a02                 push 2
// 007e7740  50                   push eax
// 007e7741  e8fc581900           call 0x97d042
// 007e7746  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 007e7749  6a01                 push 1
// 007e774b  8bf0                 mov esi, eax
// 007e774d  6a00                 push 0
// 007e774f  51                   push ecx
// 007e7750  d1ee                 shr esi, 1
// 007e7752  8bcb                 mov ecx, ebx
// 007e7754  83e601               and esi, 1
// 007e7757  e8d4f6ffff           call 0x7e6e30
// 007e775c  85c0                 test eax, eax
// 007e775e  740f                 je 0x7e776f
// 007e7760  85f6                 test esi, esi
// 007e7762  750b                 jne 0x7e776f
// 007e7764  8b573c               mov edx, dword ptr [edi + 0x3c]
// 007e7767  52                   push edx
// 007e7768  8bcb                 mov ecx, ebx
// 007e776a  e861efffff           call 0x7e66d0
// 007e776f  5e                   pop esi
// 007e7770  5f                   pop edi
// 007e7771  33c0                 xor eax, eax
// 007e7773  5b                   pop ebx
// 007e7774  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnItemExpanding@CXTTreeBase@@IAEHPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
