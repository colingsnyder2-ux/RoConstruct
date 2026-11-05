// from server: 100% by auto
// roc 2010-06 00564730  unit: seg_00560000  size: 459 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564730
//
// 00564730  83ec08               sub esp, 8
// 00564733  55                   push ebp
// 00564734  57                   push edi
// 00564735  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00564739  85ff                 test edi, edi
// 0056473b  0f84b2010000         je 0x5648f3
// 00564741  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00564745  85ed                 test ebp, ebp
// 00564747  0f84a6010000         je 0x5648f3
// 0056474d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00564751  85c9                 test ecx, ecx
// 00564753  0f849a010000         je 0x5648f3
// 00564759  8b4530               mov eax, dword ptr [ebp + 0x30]
// 0056475c  53                   push ebx
// 0056475d  56                   push esi
// 0056475e  8b7534               mov esi, dword ptr [ebp + 0x34]
// 00564761  03c1                 add eax, ecx
// 00564763  3bc6                 cmp eax, esi
// 00564765  7e7a                 jle 0x5647e1
// 00564767  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 0056476a  85db                 test ebx, ebx
// 0056476c  7448                 je 0x5647b6
// 0056476e  83c008               add eax, 8
// 00564771  894534               mov dword ptr [ebp + 0x34], eax
// 00564774  c1e004               shl eax, 4
// 00564777  50                   push eax
// 00564778  57                   push edi
// 00564779  e8b2de0000           call 0x572630
// 0056477e  83c408               add esp, 8
// 00564781  894538               mov dword ptr [ebp + 0x38], eax
// 00564784  85c0                 test eax, eax
// 00564786  7517                 jne 0x56479f
// 00564788  53                   push ebx
// 00564789  57                   push edi
// 0056478a  e871de0000           call 0x572600
// 0056478f  83c408               add esp, 8
// 00564792  5e                   pop esi
// 00564793  5b                   pop ebx
// 00564794  5f                   pop edi
// 00564795  b801000000           mov eax, 1
// 0056479a  5d                   pop ebp
// 0056479b  83c408               add esp, 8
// 0056479e  c3                   ret 
// 0056479f  c1e604               shl esi, 4
// 005647a2  56                   push esi
// 005647a3  53                   push ebx
// 005647a4  50                   push eax
// 005647a5  e87c462400           call 0x7a8e26
// 005647aa  53                   push ebx
// 005647ab  57                   push edi
// 005647ac  e84fde0000           call 0x572600
// 005647b1  83c414               add esp, 0x14
// 005647b4  eb2b                 jmp 0x5647e1
// 005647b6  83c108               add ecx, 8
// 005647b9  894d34               mov dword ptr [ebp + 0x34], ecx
// 005647bc  c1e104               shl ecx, 4
// 005647bf  51                   push ecx
// 005647c0  57                   push edi
// 005647c1  c7453000000000       mov dword ptr [ebp + 0x30], 0
// 005647c8  e863de0000           call 0x572630
// 005647cd  83c408               add esp, 8
// 005647d0  894538               mov dword ptr [ebp + 0x38], eax
// 005647d3  85c0                 test eax, eax
// 005647d5  74bb                 je 0x564792
// 005647d7  818db800000000400000 or dword ptr [ebp + 0xb8], 0x4000
// 005647e1  837c242800           cmp dword ptr [esp + 0x28], 0
// 005647e6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005647ee  0f8ef5000000         jle 0x5648e9
// 005647f4  8b542424             mov edx, dword ptr [esp + 0x24]
// 005647f8  83c208               add edx, 8
// 005647fb  89542410             mov dword ptr [esp + 0x10], edx
// 005647ff  90                   nop 
// 00564800  8b7530               mov esi, dword ptr [ebp + 0x30]
// 00564803  8b42fc               mov eax, dword ptr [edx - 4]
// 00564806  c1e604               shl esi, 4
// 00564809  037538               add esi, dword ptr [ebp + 0x38]
// 0056480c  85c0                 test eax, eax
// 0056480e  0f84bb000000         je 0x5648cf
// 00564814  8d5801               lea ebx, [eax + 1]
// 00564817  8a08                 mov cl, byte ptr [eax]
// 00564819  40                   inc eax
// 0056481a  84c9                 test cl, cl
// 0056481c  75f9                 jne 0x564817
// 0056481e  8b4af8               mov ecx, dword ptr [edx - 8]
// 00564821  2bc3                 sub eax, ebx
// 00564823  8bd8                 mov ebx, eax
// 00564825  85c9                 test ecx, ecx
// 00564827  0f8f90000000         jg 0x5648bd
// 0056482d  8b3a                 mov edi, dword ptr [edx]
// 0056482f  85ff                 test edi, edi
// 00564831  741a                 je 0x56484d
// 00564833  803f00               cmp byte ptr [edi], 0
// 00564836  7415                 je 0x56484d
// 00564838  8d5701               lea edx, [edi + 1]
// 0056483b  eb03                 jmp 0x564840
// 0056483d  8d4900               lea ecx, [ecx]
// 00564840  8a07                 mov al, byte ptr [edi]
// 00564842  47                   inc edi
// 00564843  84c0                 test al, al
// 00564845  75f9                 jne 0x564840
// 00564847  2bfa                 sub edi, edx
// 00564849  890e                 mov dword ptr [esi], ecx
// 0056484b  eb08                 jmp 0x564855
// 0056484d  33ff                 xor edi, edi
// 0056484f  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 00564855  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00564859  8d541f04             lea edx, [edi + ebx + 4]
// 0056485d  52                   push edx
// 0056485e  50                   push eax
// 0056485f  e8ccdd0000           call 0x572630
// 00564864  83c408               add esp, 8
// 00564867  894604               mov dword ptr [esi + 4], eax
// 0056486a  85c0                 test eax, eax
// 0056486c  0f8420ffffff         je 0x564792
// 00564872  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00564876  8b51fc               mov edx, dword ptr [ecx - 4]
// 00564879  53                   push ebx
// 0056487a  52                   push edx
// 0056487b  50                   push eax
// 0056487c  e8a5452400           call 0x7a8e26
// 00564881  8b4604               mov eax, dword ptr [esi + 4]
// 00564884  c6040300             mov byte ptr [ebx + eax], 0
// 00564888  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056488b  83c40c               add esp, 0xc
// 0056488e  8d5c0b01             lea ebx, [ebx + ecx + 1]
// 00564892  895e08               mov dword ptr [esi + 8], ebx
// 00564895  85ff                 test edi, edi
// 00564897  7411                 je 0x5648aa
// 00564899  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056489d  8b02                 mov eax, dword ptr [edx]
// 0056489f  57                   push edi
// 005648a0  50                   push eax
// 005648a1  53                   push ebx
// 005648a2  e87f452400           call 0x7a8e26
// 005648a7  83c40c               add esp, 0xc
// 005648aa  8b4e08               mov ecx, dword ptr [esi + 8]
// 005648ad  c6040f00             mov byte ptr [edi + ecx], 0
// 005648b1  897e0c               mov dword ptr [esi + 0xc], edi
// 005648b4  ff4530               inc dword ptr [ebp + 0x30]
// 005648b7  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005648bb  eb0e                 jmp 0x5648cb
// 005648bd  684c14a200           push 0xa2144c
// 005648c2  57                   push edi
// 005648c3  e898d20000           call 0x571b60
// 005648c8  83c408               add esp, 8
// 005648cb  8b542410             mov edx, dword ptr [esp + 0x10]
// 005648cf  8b442414             mov eax, dword ptr [esp + 0x14]
// 005648d3  40                   inc eax
// 005648d4  83c210               add edx, 0x10
// 005648d7  3b442428             cmp eax, dword ptr [esp + 0x28]
// 005648db  89442414             mov dword ptr [esp + 0x14], eax
// 005648df  89542410             mov dword ptr [esp + 0x10], edx
// 005648e3  0f8c17ffffff         jl 0x564800
// 005648e9  5e                   pop esi
// 005648ea  5b                   pop ebx
// 005648eb  5f                   pop edi
// 005648ec  33c0                 xor eax, eax
// 005648ee  5d                   pop ebp
// 005648ef  83c408               add esp, 8
// 005648f2  c3                   ret 
// 005648f3  5f                   pop edi
// 005648f4  33c0                 xor eax, eax
// 005648f6  5d                   pop ebp
// 005648f7  83c408               add esp, 8
// 005648fa  c3                   ret 
// library libpng-1.2.18/pngset.c (function _png_set_text_2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngset.c
