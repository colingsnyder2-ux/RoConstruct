// from server: 100% by auto
// roc 2007-03 00615240  unit: seg_00610000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615240
//
// 00615240  56                   push esi
// 00615241  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00615245  57                   push edi
// 00615246  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0061524a  56                   push esi
// 0061524b  57                   push edi
// 0061524c  e8dffbffff           call 0x614e30
// 00615251  83c408               add esp, 8
// 00615254  833e0c               cmp dword ptr [esi], 0xc
// 00615257  7526                 jne 0x61527f
// 00615259  8b4610               mov eax, dword ptr [esi + 0x10]
// 0061525c  3b4614               cmp eax, dword ptr [esi + 0x14]
// 0061525f  8b4608               mov eax, dword ptr [esi + 8]
// 00615262  7428                 je 0x61528c
// 00615264  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 00615268  3bc1                 cmp eax, ecx
// 0061526a  7c13                 jl 0x61527f
// 0061526c  50                   push eax
// 0061526d  8bc6                 mov eax, esi
// 0061526f  8bcf                 mov ecx, edi
// 00615271  e82afeffff           call 0x6150a0
// 00615276  8b4608               mov eax, dword ptr [esi + 8]
// 00615279  83c404               add esp, 4
// 0061527c  5f                   pop edi
// 0061527d  5e                   pop esi
// 0061527e  c3                   ret 
// 0061527f  56                   push esi
// 00615280  57                   push edi
// 00615281  e83affffff           call 0x6151c0
// 00615286  8b4608               mov eax, dword ptr [esi + 8]
// 00615289  83c408               add esp, 8
// 0061528c  5f                   pop edi
// 0061528d  5e                   pop esi
// 0061528e  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_exp2anyreg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
