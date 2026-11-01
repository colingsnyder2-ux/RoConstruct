// from server: 100% by auto
// roc 2007-03 005fd920  unit: seg_005f0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd920
//
// 005fd920  56                   push esi
// 005fd921  8bf0                 mov esi, eax
// 005fd923  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 005fd92a  57                   push edi
// 005fd92b  7424                 je 0x5fd951
// 005fd92d  681d010000           push 0x11d
// 005fd932  56                   push esi
// 005fd933  e838350000           call 0x600e70
// 005fd938  50                   push eax
// 005fd939  8b4634               mov eax, dword ptr [esi + 0x34]
// 005fd93c  6828047c00           push 0x7c0428
// 005fd941  50                   push eax
// 005fd942  e8f9aeffff           call 0x5f8840
// 005fd947  50                   push eax
// 005fd948  56                   push esi
// 005fd949  e822360000           call 0x600f70
// 005fd94e  83c41c               add esp, 0x1c
// 005fd951  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005fd954  56                   push esi
// 005fd955  e8464a0000           call 0x6023a0
// 005fd95a  8b7630               mov esi, dword ptr [esi + 0x30]
// 005fd95d  6a01                 push 1
// 005fd95f  53                   push ebx
// 005fd960  57                   push edi
// 005fd961  56                   push esi
// 005fd962  e8d9feffff           call 0x5fd840
// 005fd967  83c414               add esp, 0x14
// 005fd96a  83f808               cmp eax, 8
// 005fd96d  750d                 jne 0x5fd97c
// 005fd96f  57                   push edi
// 005fd970  56                   push esi
// 005fd971  e8aa6e0100           call 0x614820
// 005fd976  83c408               add esp, 8
// 005fd979  894308               mov dword ptr [ebx + 8], eax
// 005fd97c  5f                   pop edi
// 005fd97d  5e                   pop esi
// 005fd97e  c3                   ret 
// library lua-5.1.1/lparser.c (function _singlevar)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
