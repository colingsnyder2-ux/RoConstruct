// from server: 100% by auto
// roc 2007-03 005c67e0  unit: seg_005c0000  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c67e0
//
// 005c67e0  83ec64               sub esp, 0x64
// 005c67e3  6a01                 push 1
// 005c67e5  56                   push esi
// 005c67e6  e85524ffff           call 0x5b8c40
// 005c67eb  83c408               add esp, 8
// 005c67ee  83f806               cmp eax, 6
// 005c67f1  750f                 jne 0x5c6802
// 005c67f3  6a01                 push 1
// 005c67f5  56                   push esi
// 005c67f6  e81524ffff           call 0x5b8c10
// 005c67fb  83c408               add esp, 8
// 005c67fe  83c464               add esp, 0x64
// 005c6801  c3                   ret 
// 005c6802  57                   push edi
// 005c6803  6a01                 push 1
// 005c6805  6a01                 push 1
// 005c6807  56                   push esi
// 005c6808  e8633fffff           call 0x5ba770
// 005c680d  8bf8                 mov edi, eax
// 005c680f  83c40c               add esp, 0xc
// 005c6812  85ff                 test edi, edi
// 005c6814  7d10                 jge 0x5c6826
// 005c6816  68cca37b00           push 0x7ba3cc
// 005c681b  6a01                 push 1
// 005c681d  56                   push esi
// 005c681e  e8cd3bffff           call 0x5ba3f0
// 005c6823  83c40c               add esp, 0xc
// 005c6826  8d442404             lea eax, [esp + 4]
// 005c682a  50                   push eax
// 005c682b  57                   push edi
// 005c682c  56                   push esi
// 005c682d  e88ebeffff           call 0x5c26c0
// 005c6832  83c40c               add esp, 0xc
// 005c6835  85c0                 test eax, eax
// 005c6837  7510                 jne 0x5c6849
// 005c6839  68bca37b00           push 0x7ba3bc
// 005c683e  6a01                 push 1
// 005c6840  56                   push esi
// 005c6841  e8aa3bffff           call 0x5ba3f0
// 005c6846  83c40c               add esp, 0xc
// 005c6849  8d4c2404             lea ecx, [esp + 4]
// 005c684d  51                   push ecx
// 005c684e  68b8a37b00           push 0x7ba3b8
// 005c6853  56                   push esi
// 005c6854  e8d7c9ffff           call 0x5c3230
// 005c6859  6aff                 push -1
// 005c685b  56                   push esi
// 005c685c  e8df23ffff           call 0x5b8c40
// 005c6861  83c414               add esp, 0x14
// 005c6864  85c0                 test eax, eax
// 005c6866  750f                 jne 0x5c6877
// 005c6868  57                   push edi
// 005c6869  6884a37b00           push 0x7ba384
// 005c686e  56                   push esi
// 005c686f  e8dc32ffff           call 0x5b9b50
// 005c6874  83c40c               add esp, 0xc
// 005c6877  5f                   pop edi
// 005c6878  83c464               add esp, 0x64
// 005c687b  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _getfunc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
