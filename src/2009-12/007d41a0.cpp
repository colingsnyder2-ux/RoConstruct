// from server: 100% by auto
// roc 2009-12 007d41a0  unit: seg_007d0000  size: 218 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d41a0
//
// 007d41a0  83ec18               sub esp, 0x18
// 007d41a3  53                   push ebx
// 007d41a4  55                   push ebp
// 007d41a5  56                   push esi
// 007d41a6  8bf1                 mov esi, ecx
// 007d41a8  8bd8                 mov ebx, eax
// 007d41aa  57                   push edi
// 007d41ab  8bc6                 mov eax, esi
// 007d41ad  e85edbffff           call 0x7d1d10
// 007d41b2  837e102e             cmp dword ptr [esi + 0x10], 0x2e
// 007d41b6  757f                 jne 0x7d4237
// 007d41b8  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 007d41bb  53                   push ebx
// 007d41bc  55                   push ebp
// 007d41bd  e8ce8a0000           call 0x7dcc90
// 007d41c2  56                   push esi
// 007d41c3  e868250000           call 0x7d6730
// 007d41c8  83c40c               add esp, 0xc
// 007d41cb  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d41d2  7424                 je 0x7d41f8
// 007d41d4  681d010000           push 0x11d
// 007d41d9  56                   push esi
// 007d41da  e861100000           call 0x7d5240
// 007d41df  50                   push eax
// 007d41e0  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d41e3  68d0ed9e00           push 0x9eedd0
// 007d41e8  50                   push eax
// 007d41e9  e89263fcff           call 0x79a580
// 007d41ee  50                   push eax
// 007d41ef  56                   push esi
// 007d41f0  e84b110000           call 0x7d5340
// 007d41f5  83c41c               add esp, 0x1c
// 007d41f8  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007d41fb  56                   push esi
// 007d41fc  e82f250000           call 0x7d6730
// 007d4201  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 007d4204  57                   push edi
// 007d4205  51                   push ecx
// 007d4206  e895800000           call 0x7dc2a0
// 007d420b  8d54241c             lea edx, [esp + 0x1c]
// 007d420f  52                   push edx
// 007d4210  83c9ff               or ecx, 0xffffffff
// 007d4213  53                   push ebx
// 007d4214  55                   push ebp
// 007d4215  894c2438             mov dword ptr [esp + 0x38], ecx
// 007d4219  894c243c             mov dword ptr [esp + 0x3c], ecx
// 007d421d  c744242804000000     mov dword ptr [esp + 0x28], 4
// 007d4225  89442430             mov dword ptr [esp + 0x30], eax
// 007d4229  e8f28f0000           call 0x7dd220
// 007d422e  83c418               add esp, 0x18
// 007d4231  837e102e             cmp dword ptr [esi + 0x10], 0x2e
// 007d4235  7481                 je 0x7d41b8
// 007d4237  837e103a             cmp dword ptr [esi + 0x10], 0x3a
// 007d423b  7533                 jne 0x7d4270
// 007d423d  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 007d4240  53                   push ebx
// 007d4241  55                   push ebp
// 007d4242  e8498a0000           call 0x7dcc90
// 007d4247  56                   push esi
// 007d4248  e8e3240000           call 0x7d6730
// 007d424d  8d7c241c             lea edi, [esp + 0x1c]
// 007d4251  e81ad7ffff           call 0x7d1970
// 007d4256  8bc7                 mov eax, edi
// 007d4258  50                   push eax
// 007d4259  53                   push ebx
// 007d425a  55                   push ebp
// 007d425b  e8c08f0000           call 0x7dd220
// 007d4260  83c418               add esp, 0x18
// 007d4263  5f                   pop edi
// 007d4264  5e                   pop esi
// 007d4265  5d                   pop ebp
// 007d4266  b801000000           mov eax, 1
// 007d426b  5b                   pop ebx
// 007d426c  83c418               add esp, 0x18
// 007d426f  c3                   ret 
// 007d4270  5f                   pop edi
// 007d4271  5e                   pop esi
// 007d4272  5d                   pop ebp
// 007d4273  33c0                 xor eax, eax
// 007d4275  5b                   pop ebx
// 007d4276  83c418               add esp, 0x18
// 007d4279  c3                   ret 
// library lua-5.1/lparser.c (function _funcname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
