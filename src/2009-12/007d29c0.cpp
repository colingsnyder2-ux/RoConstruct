// from server: 100% by auto
// roc 2009-12 007d29c0  unit: seg_007d0000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d29c0
//
// 007d29c0  53                   push ebx
// 007d29c1  56                   push esi
// 007d29c2  8bf1                 mov esi, ecx
// 007d29c4  8bd8                 mov ebx, eax
// 007d29c6  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d29c9  83f828               cmp eax, 0x28
// 007d29cc  7422                 je 0x7d29f0
// 007d29ce  3d1d010000           cmp eax, 0x11d
// 007d29d3  7411                 je 0x7d29e6
// 007d29d5  6858ef9e00           push 0x9eef58
// 007d29da  56                   push esi
// 007d29db  e860290000           call 0x7d5340
// 007d29e0  83c408               add esp, 8
// 007d29e3  5e                   pop esi
// 007d29e4  5b                   pop ebx
// 007d29e5  c3                   ret 
// 007d29e6  8bc6                 mov eax, esi
// 007d29e8  e823f3ffff           call 0x7d1d10
// 007d29ed  5e                   pop esi
// 007d29ee  5b                   pop ebx
// 007d29ef  c3                   ret 
// 007d29f0  57                   push edi
// 007d29f1  8b7e04               mov edi, dword ptr [esi + 4]
// 007d29f4  56                   push esi
// 007d29f5  e8363d0000           call 0x7d6730
// 007d29fa  6a00                 push 0
// 007d29fc  53                   push ebx
// 007d29fd  56                   push esi
// 007d29fe  e8ad060000           call 0x7d30b0
// 007d2a03  8bc7                 mov eax, edi
// 007d2a05  6a28                 push 0x28
// 007d2a07  bf29000000           mov edi, 0x29
// 007d2a0c  e8cfeeffff           call 0x7d18e0
// 007d2a11  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d2a14  53                   push ebx
// 007d2a15  50                   push eax
// 007d2a16  e8659e0000           call 0x7dc880
// 007d2a1b  83c41c               add esp, 0x1c
// 007d2a1e  5f                   pop edi
// 007d2a1f  5e                   pop esi
// 007d2a20  5b                   pop ebx
// 007d2a21  c3                   ret 
// library lua-5.1/lparser.c (function _prefixexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
