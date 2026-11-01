// from server: 100% by auto
// roc 2007-03 00509eb0  unit: seg_00500000  size: 495 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509eb0
//
// 00509eb0  83ec08               sub esp, 8
// 00509eb3  53                   push ebx
// 00509eb4  57                   push edi
// 00509eb5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00509eb9  85ff                 test edi, edi
// 00509ebb  0f84d6010000         je 0x50a097
// 00509ec1  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00509ec5  85db                 test ebx, ebx
// 00509ec7  0f84ca010000         je 0x50a097
// 00509ecd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00509ed1  85c9                 test ecx, ecx
// 00509ed3  0f84be010000         je 0x50a097
// 00509ed9  8b4330               mov eax, dword ptr [ebx + 0x30]
// 00509edc  55                   push ebp
// 00509edd  56                   push esi
// 00509ede  8b7334               mov esi, dword ptr [ebx + 0x34]
// 00509ee1  03c1                 add eax, ecx
// 00509ee3  3bc6                 cmp eax, esi
// 00509ee5  7e7a                 jle 0x509f61
// 00509ee7  8b6b38               mov ebp, dword ptr [ebx + 0x38]
// 00509eea  85ed                 test ebp, ebp
// 00509eec  7448                 je 0x509f36
// 00509eee  83c008               add eax, 8
// 00509ef1  894334               mov dword ptr [ebx + 0x34], eax
// 00509ef4  c1e004               shl eax, 4
// 00509ef7  50                   push eax
// 00509ef8  57                   push edi
// 00509ef9  e822f10000           call 0x519020
// 00509efe  83c408               add esp, 8
// 00509f01  85c0                 test eax, eax
// 00509f03  894338               mov dword ptr [ebx + 0x38], eax
// 00509f06  7517                 jne 0x509f1f
// 00509f08  55                   push ebp
// 00509f09  57                   push edi
// 00509f0a  e8e1f00000           call 0x518ff0
// 00509f0f  83c408               add esp, 8
// 00509f12  5e                   pop esi
// 00509f13  5d                   pop ebp
// 00509f14  5f                   pop edi
// 00509f15  b801000000           mov eax, 1
// 00509f1a  5b                   pop ebx
// 00509f1b  83c408               add esp, 8
// 00509f1e  c3                   ret 
// 00509f1f  c1e604               shl esi, 4
// 00509f22  56                   push esi
// 00509f23  55                   push ebp
// 00509f24  50                   push eax
// 00509f25  e8b8521100           call 0x61f1e2
// 00509f2a  55                   push ebp
// 00509f2b  57                   push edi
// 00509f2c  e8bff00000           call 0x518ff0
// 00509f31  83c414               add esp, 0x14
// 00509f34  eb2b                 jmp 0x509f61
// 00509f36  83c108               add ecx, 8
// 00509f39  894b34               mov dword ptr [ebx + 0x34], ecx
// 00509f3c  c1e104               shl ecx, 4
// 00509f3f  51                   push ecx
// 00509f40  57                   push edi
// 00509f41  c7433000000000       mov dword ptr [ebx + 0x30], 0
// 00509f48  e8d3f00000           call 0x519020
// 00509f4d  83c408               add esp, 8
// 00509f50  85c0                 test eax, eax
// 00509f52  894338               mov dword ptr [ebx + 0x38], eax
// 00509f55  74bb                 je 0x509f12
// 00509f57  818bb800000000400000 or dword ptr [ebx + 0xb8], 0x4000
// 00509f61  837c242800           cmp dword ptr [esp + 0x28], 0
// 00509f66  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00509f6e  0f8e19010000         jle 0x50a08d
// 00509f74  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00509f78  83c708               add edi, 8
// 00509f7b  897c2410             mov dword ptr [esp + 0x10], edi
// 00509f7f  90                   nop 
// 00509f80  8b7330               mov esi, dword ptr [ebx + 0x30]
// 00509f83  8b47fc               mov eax, dword ptr [edi - 4]
// 00509f86  c1e604               shl esi, 4
// 00509f89  037338               add esi, dword ptr [ebx + 0x38]
// 00509f8c  85c0                 test eax, eax
// 00509f8e  0f84dd000000         je 0x50a071
// 00509f94  8d5001               lea edx, [eax + 1]
// 00509f97  8a08                 mov cl, byte ptr [eax]
// 00509f99  83c001               add eax, 1
// 00509f9c  84c9                 test cl, cl
// 00509f9e  75f7                 jne 0x509f97
// 00509fa0  8b4ff8               mov ecx, dword ptr [edi - 8]
// 00509fa3  2bc2                 sub eax, edx
// 00509fa5  85c9                 test ecx, ecx
// 00509fa7  8be8                 mov ebp, eax
// 00509fa9  0f8fb0000000         jg 0x50a05f
// 00509faf  8b3f                 mov edi, dword ptr [edi]
// 00509fb1  85ff                 test edi, edi
// 00509fb3  741a                 je 0x509fcf
// 00509fb5  803f00               cmp byte ptr [edi], 0
// 00509fb8  7415                 je 0x509fcf
// 00509fba  8d5701               lea edx, [edi + 1]
// 00509fbd  8d4900               lea ecx, [ecx]
// 00509fc0  8a07                 mov al, byte ptr [edi]
// 00509fc2  83c701               add edi, 1
// 00509fc5  84c0                 test al, al
// 00509fc7  75f7                 jne 0x509fc0
// 00509fc9  2bfa                 sub edi, edx
// 00509fcb  890e                 mov dword ptr [esi], ecx
// 00509fcd  eb08                 jmp 0x509fd7
// 00509fcf  33ff                 xor edi, edi
// 00509fd1  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 00509fd7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00509fdb  8d542f04             lea edx, [edi + ebp + 4]
// 00509fdf  52                   push edx
// 00509fe0  50                   push eax
// 00509fe1  e83af00000           call 0x519020
// 00509fe6  83c408               add esp, 8
// 00509fe9  85c0                 test eax, eax
// 00509feb  894604               mov dword ptr [esi + 4], eax
// 00509fee  0f841effffff         je 0x509f12
// 00509ff4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00509ff8  8b51fc               mov edx, dword ptr [ecx - 4]
// 00509ffb  55                   push ebp
// 00509ffc  52                   push edx
// 00509ffd  50                   push eax
// 00509ffe  e8df511100           call 0x61f1e2
// 0050a003  8b4604               mov eax, dword ptr [esi + 4]
// 0050a006  c6042800             mov byte ptr [eax + ebp], 0
// 0050a00a  8b4e04               mov ecx, dword ptr [esi + 4]
// 0050a00d  83c40c               add esp, 0xc
// 0050a010  85ff                 test edi, edi
// 0050a012  8d442901             lea eax, [ecx + ebp + 1]
// 0050a016  894608               mov dword ptr [esi + 8], eax
// 0050a019  7411                 je 0x50a02c
// 0050a01b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0050a01f  8b0a                 mov ecx, dword ptr [edx]
// 0050a021  57                   push edi
// 0050a022  51                   push ecx
// 0050a023  50                   push eax
// 0050a024  e8b9511100           call 0x61f1e2
// 0050a029  83c40c               add esp, 0xc
// 0050a02c  8b5608               mov edx, dword ptr [esi + 8]
// 0050a02f  c6041700             mov byte ptr [edi + edx], 0
// 0050a033  897e0c               mov dword ptr [esi + 0xc], edi
// 0050a036  8b4330               mov eax, dword ptr [ebx + 0x30]
// 0050a039  8b0e                 mov ecx, dword ptr [esi]
// 0050a03b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0050a03f  c1e004               shl eax, 4
// 0050a042  034338               add eax, dword ptr [ebx + 0x38]
// 0050a045  8908                 mov dword ptr [eax], ecx
// 0050a047  8b5604               mov edx, dword ptr [esi + 4]
// 0050a04a  895004               mov dword ptr [eax + 4], edx
// 0050a04d  8b4e08               mov ecx, dword ptr [esi + 8]
// 0050a050  894808               mov dword ptr [eax + 8], ecx
// 0050a053  8b560c               mov edx, dword ptr [esi + 0xc]
// 0050a056  89500c               mov dword ptr [eax + 0xc], edx
// 0050a059  83433001             add dword ptr [ebx + 0x30], 1
// 0050a05d  eb12                 jmp 0x50a071
// 0050a05f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050a063  68540d7a00           push 0x7a0d54
// 0050a068  50                   push eax
// 0050a069  e862e30000           call 0x5183d0
// 0050a06e  83c408               add esp, 8
// 0050a071  8b442414             mov eax, dword ptr [esp + 0x14]
// 0050a075  83c001               add eax, 1
// 0050a078  83c710               add edi, 0x10
// 0050a07b  3b442428             cmp eax, dword ptr [esp + 0x28]
// 0050a07f  89442414             mov dword ptr [esp + 0x14], eax
// 0050a083  897c2410             mov dword ptr [esp + 0x10], edi
// 0050a087  0f8cf3feffff         jl 0x509f80
// 0050a08d  5e                   pop esi
// 0050a08e  5d                   pop ebp
// 0050a08f  5f                   pop edi
// 0050a090  33c0                 xor eax, eax
// 0050a092  5b                   pop ebx
// 0050a093  83c408               add esp, 8
// 0050a096  c3                   ret 
// 0050a097  5f                   pop edi
// 0050a098  33c0                 xor eax, eax
// 0050a09a  5b                   pop ebx
// 0050a09b  83c408               add esp, 8
// 0050a09e  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_text_2)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
