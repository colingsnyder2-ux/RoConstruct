// from server: 100% by auto
// roc 2009-06 00595bb0  unit: seg_00590000  size: 664 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00595bb0
//
// 00595bb0  83ec10               sub esp, 0x10
// 00595bb3  57                   push edi
// 00595bb4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00595bb8  8b4768               mov eax, dword ptr [edi + 0x68]
// 00595bbb  a801                 test al, 1
// 00595bbd  7572                 jne 0x595c31
// 00595bbf  6868278d00           push 0x8d2768
// 00595bc4  57                   push edi
// 00595bc5  e89685ffff           call 0x58e160
// 00595bca  83c408               add esp, 8
// 00595bcd  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00595bd3  53                   push ebx
// 00595bd4  55                   push ebp
// 00595bd5  56                   push esi
// 00595bd6  51                   push ecx
// 00595bd7  57                   push edi
// 00595bd8  e8d390ffff           call 0x58ecb0
// 00595bdd  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00595be1  8d5501               lea edx, [ebp + 1]
// 00595be4  52                   push edx
// 00595be5  57                   push edi
// 00595be6  e86590ffff           call 0x58ec50
// 00595beb  8bf0                 mov esi, eax
// 00595bed  55                   push ebp
// 00595bee  56                   push esi
// 00595bef  57                   push edi
// 00595bf0  89b788020000         mov dword ptr [edi + 0x288], esi
// 00595bf6  e80531ffff           call 0x588d00
// 00595bfb  55                   push ebp
// 00595bfc  56                   push esi
// 00595bfd  57                   push edi
// 00595bfe  e8bdbcfeff           call 0x5818c0
// 00595c03  33db                 xor ebx, ebx
// 00595c05  53                   push ebx
// 00595c06  57                   push edi
// 00595c07  e8d4efffff           call 0x594be0
// 00595c0c  83c430               add esp, 0x30
// 00595c0f  85c0                 test eax, eax
// 00595c11  7440                 je 0x595c53
// 00595c13  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 00595c19  50                   push eax
// 00595c1a  57                   push edi
// 00595c1b  e89090ffff           call 0x58ecb0
// 00595c20  83c408               add esp, 8
// 00595c23  5e                   pop esi
// 00595c24  5d                   pop ebp
// 00595c25  899f88020000         mov dword ptr [edi + 0x288], ebx
// 00595c2b  5b                   pop ebx
// 00595c2c  5f                   pop edi
// 00595c2d  83c410               add esp, 0x10
// 00595c30  c3                   ret 
// 00595c31  a804                 test al, 4
// 00595c33  7498                 je 0x595bcd
// 00595c35  6850278d00           push 0x8d2750
// 00595c3a  57                   push edi
// 00595c3b  e8d085ffff           call 0x58e210
// 00595c40  8b442428             mov eax, dword ptr [esp + 0x28]
// 00595c44  50                   push eax
// 00595c45  57                   push edi
// 00595c46  e895efffff           call 0x594be0
// 00595c4b  83c410               add esp, 0x10
// 00595c4e  5f                   pop edi
// 00595c4f  83c410               add esp, 0x10
// 00595c52  c3                   ret 
// 00595c53  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00595c59  881c29               mov byte ptr [ecx + ebp], bl
// 00595c5c  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00595c62  8bf1                 mov esi, ecx
// 00595c64  381e                 cmp byte ptr [esi], bl
// 00595c66  7405                 je 0x595c6d
// 00595c68  46                   inc esi
// 00595c69  381e                 cmp byte ptr [esi], bl
// 00595c6b  75fb                 jne 0x595c68
// 00595c6d  46                   inc esi
// 00595c6e  8d5429fe             lea edx, [ecx + ebp - 2]
// 00595c72  3bf2                 cmp esi, edx
// 00595c74  7623                 jbe 0x595c99
// 00595c76  51                   push ecx
// 00595c77  57                   push edi
// 00595c78  e83390ffff           call 0x58ecb0
// 00595c7d  6838278d00           push 0x8d2738
// 00595c82  57                   push edi
// 00595c83  899f88020000         mov dword ptr [edi + 0x288], ebx
// 00595c89  e88285ffff           call 0x58e210
// 00595c8e  83c410               add esp, 0x10
// 00595c91  5e                   pop esi
// 00595c92  5d                   pop ebp
// 00595c93  5b                   pop ebx
// 00595c94  5f                   pop edi
// 00595c95  83c410               add esp, 0x10
// 00595c98  c3                   ret 
// 00595c99  8a06                 mov al, byte ptr [esi]
// 00595c9b  33db                 xor ebx, ebx
// 00595c9d  46                   inc esi
// 00595c9e  3c08                 cmp al, 8
// 00595ca0  88442414             mov byte ptr [esp + 0x14], al
// 00595ca4  0f95c3               setne bl
// 00595ca7  8bc1                 mov eax, ecx
// 00595ca9  2bc6                 sub eax, esi
// 00595cab  03c5                 add eax, ebp
// 00595cad  99                   cdq 
// 00595cae  8d1c9d06000000       lea ebx, [ebx*4 + 6]
// 00595cb5  f7fb                 idiv ebx
// 00595cb7  85d2                 test edx, edx
// 00595cb9  7427                 je 0x595ce2
// 00595cbb  51                   push ecx
// 00595cbc  57                   push edi
// 00595cbd  e8ee8fffff           call 0x58ecb0
// 00595cc2  681c278d00           push 0x8d271c
// 00595cc7  57                   push edi
// 00595cc8  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00595cd2  e83985ffff           call 0x58e210
// 00595cd7  83c410               add esp, 0x10
// 00595cda  5e                   pop esi
// 00595cdb  5d                   pop ebp
// 00595cdc  5b                   pop ebx
// 00595cdd  5f                   pop edi
// 00595cde  83c410               add esp, 0x10
// 00595ce1  c3                   ret 
// 00595ce2  8944241c             mov dword ptr [esp + 0x1c], eax
// 00595ce6  3d99999919           cmp eax, 0x19999999
// 00595ceb  7616                 jbe 0x595d03
// 00595ced  6808278d00           push 0x8d2708
// 00595cf2  57                   push edi
// 00595cf3  e81885ffff           call 0x58e210
// 00595cf8  83c408               add esp, 8
// 00595cfb  5e                   pop esi
// 00595cfc  5d                   pop ebp
// 00595cfd  5b                   pop ebx
// 00595cfe  5f                   pop edi
// 00595cff  83c410               add esp, 0x10
// 00595d02  c3                   ret 
// 00595d03  8d0480               lea eax, [eax + eax*4]
// 00595d06  03c0                 add eax, eax
// 00595d08  50                   push eax
// 00595d09  57                   push edi
// 00595d0a  e8d18fffff           call 0x58ece0
// 00595d0f  83c408               add esp, 8
// 00595d12  89442418             mov dword ptr [esp + 0x18], eax
// 00595d16  85c0                 test eax, eax
// 00595d18  7516                 jne 0x595d30
// 00595d1a  68e4268d00           push 0x8d26e4
// 00595d1f  57                   push edi
// 00595d20  e8eb84ffff           call 0x58e210
// 00595d25  83c408               add esp, 8
// 00595d28  5e                   pop esi
// 00595d29  5d                   pop ebp
// 00595d2a  5b                   pop ebx
// 00595d2b  5f                   pop edi
// 00595d2c  83c410               add esp, 0x10
// 00595d2f  c3                   ret 
// 00595d30  33c9                 xor ecx, ecx
// 00595d32  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 00595d36  0f8ec3000000         jle 0x595dff
// 00595d3c  33d2                 xor edx, edx
// 00595d3e  eb04                 jmp 0x595d44
// 00595d40  8b442418             mov eax, dword ptr [esp + 0x18]
// 00595d44  0fb61e               movzx ebx, byte ptr [esi]
// 00595d47  03c2                 add eax, edx
// 00595d49  807c241408           cmp byte ptr [esp + 0x14], 8
// 00595d4e  751a                 jne 0x595d6a
// 00595d50  46                   inc esi
// 00595d51  668918               mov word ptr [eax], bx
// 00595d54  0fb61e               movzx ebx, byte ptr [esi]
// 00595d57  46                   inc esi
// 00595d58  66895802             mov word ptr [eax + 2], bx
// 00595d5c  0fb61e               movzx ebx, byte ptr [esi]
// 00595d5f  46                   inc esi
// 00595d60  66895804             mov word ptr [eax + 4], bx
// 00595d64  0fb61e               movzx ebx, byte ptr [esi]
// 00595d67  46                   inc esi
// 00595d68  eb67                 jmp 0x595dd1
// 00595d6a  bd00010000           mov ebp, 0x100
// 00595d6f  660fafdd             imul bx, bp
// 00595d73  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00595d78  6603dd               add bx, bp
// 00595d7b  668918               mov word ptr [eax], bx
// 00595d7e  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00595d82  83c602               add esi, 2
// 00595d85  bd00010000           mov ebp, 0x100
// 00595d8a  660fafdd             imul bx, bp
// 00595d8e  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00595d93  6603dd               add bx, bp
// 00595d96  66895802             mov word ptr [eax + 2], bx
// 00595d9a  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00595d9e  83c602               add esi, 2
// 00595da1  bd00010000           mov ebp, 0x100
// 00595da6  660fafdd             imul bx, bp
// 00595daa  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00595daf  6603dd               add bx, bp
// 00595db2  66895804             mov word ptr [eax + 4], bx
// 00595db6  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00595dba  83c602               add esi, 2
// 00595dbd  bd00010000           mov ebp, 0x100
// 00595dc2  660fafdd             imul bx, bp
// 00595dc6  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00595dcb  6603dd               add bx, bp
// 00595dce  83c602               add esi, 2
// 00595dd1  66895806             mov word ptr [eax + 6], bx
// 00595dd5  660fb61e             movzx bx, byte ptr [esi]
// 00595dd9  bd00010000           mov ebp, 0x100
// 00595dde  660fafdd             imul bx, bp
// 00595de2  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00595de7  6603dd               add bx, bp
// 00595dea  41                   inc ecx
// 00595deb  66895808             mov word ptr [eax + 8], bx
// 00595def  83c602               add esi, 2
// 00595df2  83c20a               add edx, 0xa
// 00595df5  3b4c241c             cmp ecx, dword ptr [esp + 0x1c]
// 00595df9  0f8c41ffffff         jl 0x595d40
// 00595dff  8b442428             mov eax, dword ptr [esp + 0x28]
// 00595e03  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00595e09  6a01                 push 1
// 00595e0b  8d542414             lea edx, [esp + 0x14]
// 00595e0f  52                   push edx
// 00595e10  50                   push eax
// 00595e11  57                   push edi
// 00595e12  894c2420             mov dword ptr [esp + 0x20], ecx
// 00595e16  e8e5b4feff           call 0x581300
// 00595e1b  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00595e21  51                   push ecx
// 00595e22  57                   push edi
// 00595e23  e8888effff           call 0x58ecb0
// 00595e28  8b542430             mov edx, dword ptr [esp + 0x30]
// 00595e2c  52                   push edx
// 00595e2d  57                   push edi
// 00595e2e  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00595e38  e8738effff           call 0x58ecb0
// 00595e3d  83c420               add esp, 0x20
// 00595e40  5e                   pop esi
// 00595e41  5d                   pop ebp
// 00595e42  5b                   pop ebx
// 00595e43  5f                   pop edi
// 00595e44  83c410               add esp, 0x10
// 00595e47  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
