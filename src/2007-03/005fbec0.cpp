// from server: 100% by auto
// roc 2007-03 005fbec0  unit: seg_005f0000  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbec0
//
// 005fbec0  83ec08               sub esp, 8
// 005fbec3  57                   push edi
// 005fbec4  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005fbec8  8b4708               mov eax, dword ptr [edi + 8]
// 005fbecb  83e800               sub eax, 0
// 005fbece  0f8487000000         je 0x5fbf5b
// 005fbed4  83e803               sub eax, 3
// 005fbed7  7414                 je 0x5fbeed
// 005fbed9  83e801               sub eax, 1
// 005fbedc  7541                 jne 0x5fbf1f
// 005fbede  8b07                 mov eax, dword ptr [edi]
// 005fbee0  5f                   pop edi
// 005fbee1  83c408               add esp, 8
// 005fbee4  89442408             mov dword ptr [esp + 8], eax
// 005fbee8  e993ffffff           jmp 0x5fbe80
// 005fbeed  dd07                 fld qword ptr [edi]
// 005fbeef  dd5c2404             fstp qword ptr [esp + 4]
// 005fbef3  dd442404             fld qword ptr [esp + 4]
// 005fbef7  db5c2414             fistp dword ptr [esp + 0x14]
// 005fbefb  db442414             fild dword ptr [esp + 0x14]
// 005fbeff  dc1f                 fcomp qword ptr [edi]
// 005fbf01  dfe0                 fnstsw ax
// 005fbf03  f6c444               test ah, 0x44
// 005fbf06  7a17                 jp 0x5fbf1f
// 005fbf08  8b542414             mov edx, dword ptr [esp + 0x14]
// 005fbf0c  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fbf10  52                   push edx
// 005fbf11  50                   push eax
// 005fbf12  e8d9feffff           call 0x5fbdf0
// 005fbf17  83c408               add esp, 8
// 005fbf1a  5f                   pop edi
// 005fbf1b  83c408               add esp, 8
// 005fbf1e  c3                   ret 
// 005fbf1f  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fbf23  56                   push esi
// 005fbf24  8bd7                 mov edx, edi
// 005fbf26  e805f9ffff           call 0x5fb830
// 005fbf2b  8bf0                 mov esi, eax
// 005fbf2d  8d4900               lea ecx, [ecx]
// 005fbf30  8d4e10               lea ecx, [esi + 0x10]
// 005fbf33  57                   push edi
// 005fbf34  51                   push ecx
// 005fbf35  e8f6c4ffff           call 0x5f8430
// 005fbf3a  83c408               add esp, 8
// 005fbf3d  85c0                 test eax, eax
// 005fbf3f  7512                 jne 0x5fbf53
// 005fbf41  8b761c               mov esi, dword ptr [esi + 0x1c]
// 005fbf44  85f6                 test esi, esi
// 005fbf46  75e8                 jne 0x5fbf30
// 005fbf48  5e                   pop esi
// 005fbf49  b8a0007c00           mov eax, 0x7c00a0
// 005fbf4e  5f                   pop edi
// 005fbf4f  83c408               add esp, 8
// 005fbf52  c3                   ret 
// 005fbf53  8bc6                 mov eax, esi
// 005fbf55  5e                   pop esi
// 005fbf56  5f                   pop edi
// 005fbf57  83c408               add esp, 8
// 005fbf5a  c3                   ret 
// 005fbf5b  b8a0007c00           mov eax, 0x7c00a0
// 005fbf60  5f                   pop edi
// 005fbf61  83c408               add esp, 8
// 005fbf64  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_get)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
