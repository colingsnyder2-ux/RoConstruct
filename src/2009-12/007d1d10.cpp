// from server: 100% by auto
// roc 2009-12 007d1d10  unit: seg_007d0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1d10
//
// 007d1d10  56                   push esi
// 007d1d11  8bf0                 mov esi, eax
// 007d1d13  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d1d1a  57                   push edi
// 007d1d1b  7424                 je 0x7d1d41
// 007d1d1d  681d010000           push 0x11d
// 007d1d22  56                   push esi
// 007d1d23  e818350000           call 0x7d5240
// 007d1d28  50                   push eax
// 007d1d29  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d1d2c  68d0ed9e00           push 0x9eedd0
// 007d1d31  50                   push eax
// 007d1d32  e84988fcff           call 0x79a580
// 007d1d37  50                   push eax
// 007d1d38  56                   push esi
// 007d1d39  e802360000           call 0x7d5340
// 007d1d3e  83c41c               add esp, 0x1c
// 007d1d41  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007d1d44  56                   push esi
// 007d1d45  e8e6490000           call 0x7d6730
// 007d1d4a  8b7630               mov esi, dword ptr [esi + 0x30]
// 007d1d4d  6a01                 push 1
// 007d1d4f  53                   push ebx
// 007d1d50  57                   push edi
// 007d1d51  56                   push esi
// 007d1d52  e8d9feffff           call 0x7d1c30
// 007d1d57  83c414               add esp, 0x14
// 007d1d5a  83f808               cmp eax, 8
// 007d1d5d  750d                 jne 0x7d1d6c
// 007d1d5f  57                   push edi
// 007d1d60  56                   push esi
// 007d1d61  e83aa50000           call 0x7dc2a0
// 007d1d66  83c408               add esp, 8
// 007d1d69  894308               mov dword ptr [ebx + 8], eax
// 007d1d6c  5f                   pop edi
// 007d1d6d  5e                   pop esi
// 007d1d6e  c3                   ret 
// library lua-5.1/lparser.c (function _singlevar)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
