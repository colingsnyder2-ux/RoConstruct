// from server: 100% by auto
// roc 2008-06 006621e0  unit: RBX::FilterStairs  size: 297 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006621e0
//
// 006621e0  83ec38               sub esp, 0x38
// 006621e3  53                   push ebx
// 006621e4  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 006621e8  8b4308               mov eax, dword ptr [ebx + 8]
// 006621eb  83f806               cmp eax, 6
// 006621ee  55                   push ebp
// 006621ef  8d6b08               lea ebp, [ebx + 8]
// 006621f2  56                   push esi
// 006621f3  8b742448             mov esi, dword ptr [esp + 0x48]
// 006621f7  57                   push edi
// 006621f8  7c05                 jl 0x6621ff
// 006621fa  83f809               cmp eax, 9
// 006621fd  7e0e                 jle 0x66220d
// 006621ff  6888c68400           push 0x84c688
// 00662204  56                   push esi
// 00662205  e806200000           call 0x664210
// 0066220a  83c408               add esp, 8
// 0066220d  8b4610               mov eax, dword ptr [esi + 0x10]
// 00662210  83f82c               cmp eax, 0x2c
// 00662213  753c                 jne 0x662251
// 00662215  56                   push esi
// 00662216  e8e5330000           call 0x665600
// 0066221b  83c404               add esp, 4
// 0066221e  8d7c2430             lea edi, [esp + 0x30]
// 00662222  895c2428             mov dword ptr [esp + 0x28], ebx
// 00662226  e845f7ffff           call 0x661970
// 0066222b  837c243006           cmp dword ptr [esp + 0x30], 6
// 00662230  7509                 jne 0x66223b
// 00662232  8bc3                 mov eax, ebx
// 00662234  8bce                 mov ecx, esi
// 00662236  e845ffffff           call 0x662180
// 0066223b  8b442454             mov eax, dword ptr [esp + 0x54]
// 0066223f  40                   inc eax
// 00662240  50                   push eax
// 00662241  8d4c242c             lea ecx, [esp + 0x2c]
// 00662245  51                   push ecx
// 00662246  56                   push esi
// 00662247  e894ffffff           call 0x6621e0
// 0066224c  83c40c               add esp, 0xc
// 0066224f  eb5f                 jmp 0x6622b0
// 00662251  83f83d               cmp eax, 0x3d
// 00662254  7421                 je 0x662277
// 00662256  6a3d                 push 0x3d
// 00662258  56                   push esi
// 00662259  e8b21e0000           call 0x664110
// 0066225e  8b5634               mov edx, dword ptr [esi + 0x34]
// 00662261  50                   push eax
// 00662262  68c0c48400           push 0x84c4c0
// 00662267  52                   push edx
// 00662268  e85308fcff           call 0x622ac0
// 0066226d  50                   push eax
// 0066226e  56                   push esi
// 0066226f  e89c1f0000           call 0x664210
// 00662274  83c41c               add esp, 0x1c
// 00662277  56                   push esi
// 00662278  e883330000           call 0x665600
// 0066227d  83c404               add esp, 4
// 00662280  8d7c2410             lea edi, [esp + 0x10]
// 00662284  e8f7f4ffff           call 0x661780
// 00662289  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 0066228d  8bd8                 mov ebx, eax
// 0066228f  8d4c2410             lea ecx, [esp + 0x10]
// 00662293  3bdf                 cmp ebx, edi
// 00662295  744e                 je 0x6622e5
// 00662297  53                   push ebx
// 00662298  8bd7                 mov edx, edi
// 0066229a  8bc6                 mov eax, esi
// 0066229c  e80feaffff           call 0x660cb0
// 006622a1  83c404               add esp, 4
// 006622a4  3bdf                 cmp ebx, edi
// 006622a6  7e08                 jle 0x6622b0
// 006622a8  8b4630               mov eax, dword ptr [esi + 0x30]
// 006622ab  2bfb                 sub edi, ebx
// 006622ad  017824               add dword ptr [eax + 0x24], edi
// 006622b0  8b7630               mov esi, dword ptr [esi + 0x30]
// 006622b3  8b4624               mov eax, dword ptr [esi + 0x24]
// 006622b6  48                   dec eax
// 006622b7  89442418             mov dword ptr [esp + 0x18], eax
// 006622bb  8d442410             lea eax, [esp + 0x10]
// 006622bf  50                   push eax
// 006622c0  83c9ff               or ecx, 0xffffffff
// 006622c3  55                   push ebp
// 006622c4  56                   push esi
// 006622c5  894c242c             mov dword ptr [esp + 0x2c], ecx
// 006622c9  894c2430             mov dword ptr [esp + 0x30], ecx
// 006622cd  c744241c0c000000     mov dword ptr [esp + 0x1c], 0xc
// 006622d5  e846970000           call 0x66ba20
// 006622da  83c40c               add esp, 0xc
// 006622dd  5f                   pop edi
// 006622de  5e                   pop esi
// 006622df  5d                   pop ebp
// 006622e0  5b                   pop ebx
// 006622e1  83c438               add esp, 0x38
// 006622e4  c3                   ret 
// 006622e5  8b5630               mov edx, dword ptr [esi + 0x30]
// 006622e8  51                   push ecx
// 006622e9  52                   push edx
// 006622ea  e8e18c0000           call 0x66afd0
// 006622ef  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 006622f2  8d442418             lea eax, [esp + 0x18]
// 006622f6  50                   push eax
// 006622f7  55                   push ebp
// 006622f8  51                   push ecx
// 006622f9  e822970000           call 0x66ba20
// 006622fe  83c414               add esp, 0x14
// 00662301  5f                   pop edi
// 00662302  5e                   pop esi
// 00662303  5d                   pop ebp
// 00662304  5b                   pop ebx
// 00662305  83c438               add esp, 0x38
// 00662308  c3                   ret 
// library lua-5.1.2/lparser.c (function _assignment)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lparser.c
