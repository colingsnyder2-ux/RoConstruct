// from server: 100% by auto
// roc 2012-06 0065bf30  unit: seg_00650000  size: 664 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065bf30
//
// 0065bf30  83ec10               sub esp, 0x10
// 0065bf33  57                   push edi
// 0065bf34  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0065bf38  8b4768               mov eax, dword ptr [edi + 0x68]
// 0065bf3b  a801                 test al, 1
// 0065bf3d  7572                 jne 0x65bfb1
// 0065bf3f  6840a8b800           push 0xb8a840
// 0065bf44  57                   push edi
// 0065bf45  e86622ffff           call 0x64e1b0
// 0065bf4a  83c408               add esp, 8
// 0065bf4d  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 0065bf53  53                   push ebx
// 0065bf54  55                   push ebp
// 0065bf55  56                   push esi
// 0065bf56  51                   push ecx
// 0065bf57  57                   push edi
// 0065bf58  e8c325ffff           call 0x64e520
// 0065bf5d  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0065bf61  8d5501               lea edx, [ebp + 1]
// 0065bf64  52                   push edx
// 0065bf65  57                   push edi
// 0065bf66  e85525ffff           call 0x64e4c0
// 0065bf6b  8bf0                 mov esi, eax
// 0065bf6d  55                   push ebp
// 0065bf6e  56                   push esi
// 0065bf6f  57                   push edi
// 0065bf70  89b788020000         mov dword ptr [edi + 0x288], esi
// 0065bf76  e8751effff           call 0x64ddf0
// 0065bf7b  55                   push ebp
// 0065bf7c  56                   push esi
// 0065bf7d  57                   push edi
// 0065bf7e  e80d1ffeff           call 0x63de90
// 0065bf83  33db                 xor ebx, ebx
// 0065bf85  53                   push ebx
// 0065bf86  57                   push edi
// 0065bf87  e8c4efffff           call 0x65af50
// 0065bf8c  83c430               add esp, 0x30
// 0065bf8f  85c0                 test eax, eax
// 0065bf91  7440                 je 0x65bfd3
// 0065bf93  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 0065bf99  50                   push eax
// 0065bf9a  57                   push edi
// 0065bf9b  e88025ffff           call 0x64e520
// 0065bfa0  83c408               add esp, 8
// 0065bfa3  5e                   pop esi
// 0065bfa4  5d                   pop ebp
// 0065bfa5  899f88020000         mov dword ptr [edi + 0x288], ebx
// 0065bfab  5b                   pop ebx
// 0065bfac  5f                   pop edi
// 0065bfad  83c410               add esp, 0x10
// 0065bfb0  c3                   ret 
// 0065bfb1  a804                 test al, 4
// 0065bfb3  7498                 je 0x65bf4d
// 0065bfb5  6828a8b800           push 0xb8a828
// 0065bfba  57                   push edi
// 0065bfbb  e8a022ffff           call 0x64e260
// 0065bfc0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065bfc4  50                   push eax
// 0065bfc5  57                   push edi
// 0065bfc6  e885efffff           call 0x65af50
// 0065bfcb  83c410               add esp, 0x10
// 0065bfce  5f                   pop edi
// 0065bfcf  83c410               add esp, 0x10
// 0065bfd2  c3                   ret 
// 0065bfd3  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 0065bfd9  881c29               mov byte ptr [ecx + ebp], bl
// 0065bfdc  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 0065bfe2  8bf1                 mov esi, ecx
// 0065bfe4  381e                 cmp byte ptr [esi], bl
// 0065bfe6  7405                 je 0x65bfed
// 0065bfe8  46                   inc esi
// 0065bfe9  381e                 cmp byte ptr [esi], bl
// 0065bfeb  75fb                 jne 0x65bfe8
// 0065bfed  46                   inc esi
// 0065bfee  8d5429fe             lea edx, [ecx + ebp - 2]
// 0065bff2  3bf2                 cmp esi, edx
// 0065bff4  7623                 jbe 0x65c019
// 0065bff6  51                   push ecx
// 0065bff7  57                   push edi
// 0065bff8  e82325ffff           call 0x64e520
// 0065bffd  6810a8b800           push 0xb8a810
// 0065c002  57                   push edi
// 0065c003  899f88020000         mov dword ptr [edi + 0x288], ebx
// 0065c009  e85222ffff           call 0x64e260
// 0065c00e  83c410               add esp, 0x10
// 0065c011  5e                   pop esi
// 0065c012  5d                   pop ebp
// 0065c013  5b                   pop ebx
// 0065c014  5f                   pop edi
// 0065c015  83c410               add esp, 0x10
// 0065c018  c3                   ret 
// 0065c019  8a06                 mov al, byte ptr [esi]
// 0065c01b  33db                 xor ebx, ebx
// 0065c01d  46                   inc esi
// 0065c01e  3c08                 cmp al, 8
// 0065c020  88442414             mov byte ptr [esp + 0x14], al
// 0065c024  0f95c3               setne bl
// 0065c027  8bc1                 mov eax, ecx
// 0065c029  2bc6                 sub eax, esi
// 0065c02b  03c5                 add eax, ebp
// 0065c02d  99                   cdq 
// 0065c02e  8d1c9d06000000       lea ebx, [ebx*4 + 6]
// 0065c035  f7fb                 idiv ebx
// 0065c037  85d2                 test edx, edx
// 0065c039  7427                 je 0x65c062
// 0065c03b  51                   push ecx
// 0065c03c  57                   push edi
// 0065c03d  e8de24ffff           call 0x64e520
// 0065c042  68f4a7b800           push 0xb8a7f4
// 0065c047  57                   push edi
// 0065c048  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 0065c052  e80922ffff           call 0x64e260
// 0065c057  83c410               add esp, 0x10
// 0065c05a  5e                   pop esi
// 0065c05b  5d                   pop ebp
// 0065c05c  5b                   pop ebx
// 0065c05d  5f                   pop edi
// 0065c05e  83c410               add esp, 0x10
// 0065c061  c3                   ret 
// 0065c062  8944241c             mov dword ptr [esp + 0x1c], eax
// 0065c066  3d99999919           cmp eax, 0x19999999
// 0065c06b  7616                 jbe 0x65c083
// 0065c06d  68e0a7b800           push 0xb8a7e0
// 0065c072  57                   push edi
// 0065c073  e8e821ffff           call 0x64e260
// 0065c078  83c408               add esp, 8
// 0065c07b  5e                   pop esi
// 0065c07c  5d                   pop ebp
// 0065c07d  5b                   pop ebx
// 0065c07e  5f                   pop edi
// 0065c07f  83c410               add esp, 0x10
// 0065c082  c3                   ret 
// 0065c083  8d0480               lea eax, [eax + eax*4]
// 0065c086  03c0                 add eax, eax
// 0065c088  50                   push eax
// 0065c089  57                   push edi
// 0065c08a  e8c124ffff           call 0x64e550
// 0065c08f  83c408               add esp, 8
// 0065c092  89442418             mov dword ptr [esp + 0x18], eax
// 0065c096  85c0                 test eax, eax
// 0065c098  7516                 jne 0x65c0b0
// 0065c09a  68bca7b800           push 0xb8a7bc
// 0065c09f  57                   push edi
// 0065c0a0  e8bb21ffff           call 0x64e260
// 0065c0a5  83c408               add esp, 8
// 0065c0a8  5e                   pop esi
// 0065c0a9  5d                   pop ebp
// 0065c0aa  5b                   pop ebx
// 0065c0ab  5f                   pop edi
// 0065c0ac  83c410               add esp, 0x10
// 0065c0af  c3                   ret 
// 0065c0b0  33c9                 xor ecx, ecx
// 0065c0b2  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 0065c0b6  0f8ec3000000         jle 0x65c17f
// 0065c0bc  33d2                 xor edx, edx
// 0065c0be  eb04                 jmp 0x65c0c4
// 0065c0c0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065c0c4  0fb61e               movzx ebx, byte ptr [esi]
// 0065c0c7  03c2                 add eax, edx
// 0065c0c9  807c241408           cmp byte ptr [esp + 0x14], 8
// 0065c0ce  751a                 jne 0x65c0ea
// 0065c0d0  46                   inc esi
// 0065c0d1  668918               mov word ptr [eax], bx
// 0065c0d4  0fb61e               movzx ebx, byte ptr [esi]
// 0065c0d7  46                   inc esi
// 0065c0d8  66895802             mov word ptr [eax + 2], bx
// 0065c0dc  0fb61e               movzx ebx, byte ptr [esi]
// 0065c0df  46                   inc esi
// 0065c0e0  66895804             mov word ptr [eax + 4], bx
// 0065c0e4  0fb61e               movzx ebx, byte ptr [esi]
// 0065c0e7  46                   inc esi
// 0065c0e8  eb67                 jmp 0x65c151
// 0065c0ea  bd00010000           mov ebp, 0x100
// 0065c0ef  660fafdd             imul bx, bp
// 0065c0f3  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0065c0f8  6603dd               add bx, bp
// 0065c0fb  668918               mov word ptr [eax], bx
// 0065c0fe  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 0065c102  83c602               add esi, 2
// 0065c105  bd00010000           mov ebp, 0x100
// 0065c10a  660fafdd             imul bx, bp
// 0065c10e  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0065c113  6603dd               add bx, bp
// 0065c116  66895802             mov word ptr [eax + 2], bx
// 0065c11a  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 0065c11e  83c602               add esi, 2
// 0065c121  bd00010000           mov ebp, 0x100
// 0065c126  660fafdd             imul bx, bp
// 0065c12a  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0065c12f  6603dd               add bx, bp
// 0065c132  66895804             mov word ptr [eax + 4], bx
// 0065c136  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 0065c13a  83c602               add esi, 2
// 0065c13d  bd00010000           mov ebp, 0x100
// 0065c142  660fafdd             imul bx, bp
// 0065c146  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0065c14b  6603dd               add bx, bp
// 0065c14e  83c602               add esi, 2
// 0065c151  66895806             mov word ptr [eax + 6], bx
// 0065c155  660fb61e             movzx bx, byte ptr [esi]
// 0065c159  bd00010000           mov ebp, 0x100
// 0065c15e  660fafdd             imul bx, bp
// 0065c162  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0065c167  6603dd               add bx, bp
// 0065c16a  41                   inc ecx
// 0065c16b  66895808             mov word ptr [eax + 8], bx
// 0065c16f  83c602               add esi, 2
// 0065c172  83c20a               add edx, 0xa
// 0065c175  3b4c241c             cmp ecx, dword ptr [esp + 0x1c]
// 0065c179  0f8c41ffffff         jl 0x65c0c0
// 0065c17f  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065c183  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 0065c189  6a01                 push 1
// 0065c18b  8d542414             lea edx, [esp + 0x14]
// 0065c18f  52                   push edx
// 0065c190  50                   push eax
// 0065c191  57                   push edi
// 0065c192  894c2420             mov dword ptr [esp + 0x20], ecx
// 0065c196  e845b2feff           call 0x6473e0
// 0065c19b  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 0065c1a1  51                   push ecx
// 0065c1a2  57                   push edi
// 0065c1a3  e87823ffff           call 0x64e520
// 0065c1a8  8b542430             mov edx, dword ptr [esp + 0x30]
// 0065c1ac  52                   push edx
// 0065c1ad  57                   push edi
// 0065c1ae  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 0065c1b8  e86323ffff           call 0x64e520
// 0065c1bd  83c420               add esp, 0x20
// 0065c1c0  5e                   pop esi
// 0065c1c1  5d                   pop ebp
// 0065c1c2  5b                   pop ebx
// 0065c1c3  5f                   pop edi
// 0065c1c4  83c410               add esp, 0x10
// 0065c1c7  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
