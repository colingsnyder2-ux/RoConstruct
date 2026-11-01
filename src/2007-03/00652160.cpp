// from server: 100% by auto
// roc 2007-03 00652160  unit: seg_00650000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652160
//
// 00652160  33c0                 xor eax, eax
// 00652162  39442404             cmp dword ptr [esp + 4], eax
// 00652166  53                   push ebx
// 00652167  0f95c0               setne al
// 0065216a  55                   push ebp
// 0065216b  56                   push esi
// 0065216c  8b742414             mov esi, dword ptr [esp + 0x14]
// 00652170  57                   push edi
// 00652171  8bf9                 mov edi, ecx
// 00652173  8be8                 mov ebp, eax
// 00652175  8bdd                 mov ebx, ebp
// 00652177  f7db                 neg ebx
// 00652179  1bdb                 sbb ebx, ebx
// 0065217b  83e302               and ebx, 2
// 0065217e  85f6                 test esi, esi
// 00652180  751e                 jne 0x6521a0
// 00652182  8b4734               mov eax, dword ptr [edi + 0x34]
// 00652185  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00652188  56                   push esi
// 00652189  56                   push esi
// 0065218a  680a110000           push 0x110a
// 0065218f  51                   push ecx
// 00652190  ff1550ee7700         call dword ptr [0x77ee50]
// 00652196  8bf0                 mov esi, eax
// 00652198  85f6                 test esi, esi
// 0065219a  743e                 je 0x6521da
// 0065219c  8d642400             lea esp, [esp]
// 006521a0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 006521a3  6a02                 push 2
// 006521a5  56                   push esi
// 006521a6  e8db8b0e00           call 0x73ad86
// 006521ab  d1e8                 shr eax, 1
// 006521ad  83e001               and eax, 1
// 006521b0  3bc5                 cmp eax, ebp
// 006521b2  740b                 je 0x6521bf
// 006521b4  6a02                 push 2
// 006521b6  53                   push ebx
// 006521b7  56                   push esi
// 006521b8  8bcf                 mov ecx, edi
// 006521ba  e841fbffff           call 0x651d00
// 006521bf  8b4734               mov eax, dword ptr [edi + 0x34]
// 006521c2  8b5020               mov edx, dword ptr [eax + 0x20]
// 006521c5  56                   push esi
// 006521c6  6a06                 push 6
// 006521c8  680a110000           push 0x110a
// 006521cd  52                   push edx
// 006521ce  ff1550ee7700         call dword ptr [0x77ee50]
// 006521d4  8bf0                 mov esi, eax
// 006521d6  85f6                 test esi, esi
// 006521d8  75c6                 jne 0x6521a0
// 006521da  5f                   pop edi
// 006521db  5e                   pop esi
// 006521dc  5d                   pop ebp
// 006521dd  5b                   pop ebx
// 006521de  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectAll@CXTPTreeBase@@QAEXHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
