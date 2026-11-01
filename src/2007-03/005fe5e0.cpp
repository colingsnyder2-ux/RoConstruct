// from server: 100% by auto
// roc 2007-03 005fe5e0  unit: seg_005f0000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fe5e0
//
// 005fe5e0  53                   push ebx
// 005fe5e1  56                   push esi
// 005fe5e2  8bf1                 mov esi, ecx
// 005fe5e4  8bd8                 mov ebx, eax
// 005fe5e6  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fe5e9  83f828               cmp eax, 0x28
// 005fe5ec  7422                 je 0x5fe610
// 005fe5ee  3d1d010000           cmp eax, 0x11d
// 005fe5f3  7411                 je 0x5fe606
// 005fe5f5  68b0057c00           push 0x7c05b0
// 005fe5fa  56                   push esi
// 005fe5fb  e870290000           call 0x600f70
// 005fe600  83c408               add esp, 8
// 005fe603  5e                   pop esi
// 005fe604  5b                   pop ebx
// 005fe605  c3                   ret 
// 005fe606  8bc6                 mov eax, esi
// 005fe608  e813f3ffff           call 0x5fd920
// 005fe60d  5e                   pop esi
// 005fe60e  5b                   pop ebx
// 005fe60f  c3                   ret 
// 005fe610  57                   push edi
// 005fe611  8b7e04               mov edi, dword ptr [esi + 4]
// 005fe614  56                   push esi
// 005fe615  e8863d0000           call 0x6023a0
// 005fe61a  6a00                 push 0
// 005fe61c  53                   push ebx
// 005fe61d  56                   push esi
// 005fe61e  e8ad060000           call 0x5fecd0
// 005fe623  8bc7                 mov eax, edi
// 005fe625  6a28                 push 0x28
// 005fe627  bf29000000           mov edi, 0x29
// 005fe62c  e89feeffff           call 0x5fd4d0
// 005fe631  8b4630               mov eax, dword ptr [esi + 0x30]
// 005fe634  53                   push ebx
// 005fe635  50                   push eax
// 005fe636  e8f5670100           call 0x614e30
// 005fe63b  83c41c               add esp, 0x1c
// 005fe63e  5f                   pop edi
// 005fe63f  5e                   pop esi
// 005fe640  5b                   pop ebx
// 005fe641  c3                   ret 
// library lua-5.1.1/lparser.c (function _prefixexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
