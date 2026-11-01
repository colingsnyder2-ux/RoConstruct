// from server: 100% by auto
// roc 2007-03 005fda40  unit: seg_005f0000  size: 261 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fda40
//
// 005fda40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005fda44  53                   push ebx
// 005fda45  55                   push ebp
// 005fda46  56                   push esi
// 005fda47  8b7130               mov esi, dword ptr [ecx + 0x30]
// 005fda4a  8b1e                 mov ebx, dword ptr [esi]
// 005fda4c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005fda4f  8d6b34               lea ebp, [ebx + 0x34]
// 005fda52  57                   push edi
// 005fda53  8b7d00               mov edi, dword ptr [ebp]
// 005fda56  83c001               add eax, 1
// 005fda59  3bc7                 cmp eax, edi
// 005fda5b  7e24                 jle 0x5fda81
// 005fda5d  8b5310               mov edx, dword ptr [ebx + 0x10]
// 005fda60  8b4134               mov eax, dword ptr [ecx + 0x34]
// 005fda63  680c057c00           push 0x7c050c
// 005fda68  68ffff0300           push 0x3ffff
// 005fda6d  6a04                 push 4
// 005fda6f  55                   push ebp
// 005fda70  52                   push edx
// 005fda71  50                   push eax
// 005fda72  e879f9ffff           call 0x5fd3f0
// 005fda77  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005fda7b  83c418               add esp, 0x18
// 005fda7e  894310               mov dword ptr [ebx + 0x10], eax
// 005fda81  3b7d00               cmp edi, dword ptr [ebp]
// 005fda84  7d1c                 jge 0x5fdaa2
// 005fda86  eb08                 jmp 0x5fda90
// 005fda88  8da42400000000       lea esp, [esp]
// 005fda8f  90                   nop 
// 005fda90  8b5310               mov edx, dword ptr [ebx + 0x10]
// 005fda93  c704ba00000000       mov dword ptr [edx + edi*4], 0
// 005fda9a  83c701               add edi, 1
// 005fda9d  3b7d00               cmp edi, dword ptr [ebp]
// 005fdaa0  7cee                 jl 0x5fda90
// 005fdaa2  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005fdaa6  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005fdaa9  8b5310               mov edx, dword ptr [ebx + 0x10]
// 005fdaac  8b7d00               mov edi, dword ptr [ebp]
// 005fdaaf  893c82               mov dword ptr [edx + eax*4], edi
// 005fdab2  83462c01             add dword ptr [esi + 0x2c], 1
// 005fdab6  8b4500               mov eax, dword ptr [ebp]
// 005fdab9  f6400503             test byte ptr [eax + 5], 3
// 005fdabd  7414                 je 0x5fdad3
// 005fdabf  f6430504             test byte ptr [ebx + 5], 4
// 005fdac3  740e                 je 0x5fdad3
// 005fdac5  50                   push eax
// 005fdac6  8b4134               mov eax, dword ptr [ecx + 0x34]
// 005fdac9  53                   push ebx
// 005fdaca  50                   push eax
// 005fdacb  e8d0bdffff           call 0x5f98a0
// 005fdad0  83c40c               add esp, 0xc
// 005fdad3  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 005fdad6  83e901               sub ecx, 1
// 005fdad9  51                   push ecx
// 005fdada  6a00                 push 0
// 005fdadc  6a24                 push 0x24
// 005fdade  56                   push esi
// 005fdadf  e8fc700100           call 0x614be0
// 005fdae4  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005fdae8  83caff               or edx, 0xffffffff
// 005fdaeb  895110               mov dword ptr [ecx + 0x10], edx
// 005fdaee  895114               mov dword ptr [ecx + 0x14], edx
// 005fdaf1  c7010b000000         mov dword ptr [ecx], 0xb
// 005fdaf7  894108               mov dword ptr [ecx + 8], eax
// 005fdafa  8b5500               mov edx, dword ptr [ebp]
// 005fdafd  33db                 xor ebx, ebx
// 005fdaff  83c410               add esp, 0x10
// 005fdb02  385a48               cmp byte ptr [edx + 0x48], bl
// 005fdb05  7639                 jbe 0x5fdb40
// 005fdb07  8d7d33               lea edi, [ebp + 0x33]
// 005fdb0a  8d9b00000000         lea ebx, [ebx]
// 005fdb10  8a0f                 mov cl, byte ptr [edi]
// 005fdb12  0fb64701             movzx eax, byte ptr [edi + 1]
// 005fdb16  80e906               sub cl, 6
// 005fdb19  f6d9                 neg cl
// 005fdb1b  6a00                 push 0
// 005fdb1d  50                   push eax
// 005fdb1e  6a00                 push 0
// 005fdb20  1bc9                 sbb ecx, ecx
// 005fdb22  83e104               and ecx, 4
// 005fdb25  51                   push ecx
// 005fdb26  56                   push esi
// 005fdb27  e884700100           call 0x614bb0
// 005fdb2c  8b5500               mov edx, dword ptr [ebp]
// 005fdb2f  0fb64248             movzx eax, byte ptr [edx + 0x48]
// 005fdb33  83c301               add ebx, 1
// 005fdb36  83c414               add esp, 0x14
// 005fdb39  83c702               add edi, 2
// 005fdb3c  3bd8                 cmp ebx, eax
// 005fdb3e  7cd0                 jl 0x5fdb10
// 005fdb40  5f                   pop edi
// 005fdb41  5e                   pop esi
// 005fdb42  5d                   pop ebp
// 005fdb43  5b                   pop ebx
// 005fdb44  c3                   ret 
// library lua-5.1.1/lparser.c (function _pushclosure)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
