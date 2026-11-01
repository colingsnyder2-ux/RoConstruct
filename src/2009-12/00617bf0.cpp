// from server: 100% by auto
// roc 2009-12 00617bf0  unit: seg_00610000  size: 664 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00617bf0
//
// 00617bf0  83ec10               sub esp, 0x10
// 00617bf3  57                   push edi
// 00617bf4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00617bf8  8b4768               mov eax, dword ptr [edi + 0x68]
// 00617bfb  a801                 test al, 1
// 00617bfd  7572                 jne 0x617c71
// 00617bff  68f8959c00           push 0x9c95f8
// 00617c04  57                   push edi
// 00617c05  e88685ffff           call 0x610190
// 00617c0a  83c408               add esp, 8
// 00617c0d  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00617c13  53                   push ebx
// 00617c14  55                   push ebp
// 00617c15  56                   push esi
// 00617c16  51                   push ecx
// 00617c17  57                   push edi
// 00617c18  e8c390ffff           call 0x610ce0
// 00617c1d  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00617c21  8d5501               lea edx, [ebp + 1]
// 00617c24  52                   push edx
// 00617c25  57                   push edi
// 00617c26  e85590ffff           call 0x610c80
// 00617c2b  8bf0                 mov esi, eax
// 00617c2d  55                   push ebp
// 00617c2e  56                   push esi
// 00617c2f  57                   push edi
// 00617c30  89b788020000         mov dword ptr [edi + 0x288], esi
// 00617c36  e8552effff           call 0x60aa90
// 00617c3b  55                   push ebp
// 00617c3c  56                   push esi
// 00617c3d  57                   push edi
// 00617c3e  e82dbafeff           call 0x603670
// 00617c43  33db                 xor ebx, ebx
// 00617c45  53                   push ebx
// 00617c46  57                   push edi
// 00617c47  e8a4efffff           call 0x616bf0
// 00617c4c  83c430               add esp, 0x30
// 00617c4f  85c0                 test eax, eax
// 00617c51  7440                 je 0x617c93
// 00617c53  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 00617c59  50                   push eax
// 00617c5a  57                   push edi
// 00617c5b  e88090ffff           call 0x610ce0
// 00617c60  83c408               add esp, 8
// 00617c63  5e                   pop esi
// 00617c64  5d                   pop ebp
// 00617c65  899f88020000         mov dword ptr [edi + 0x288], ebx
// 00617c6b  5b                   pop ebx
// 00617c6c  5f                   pop edi
// 00617c6d  83c410               add esp, 0x10
// 00617c70  c3                   ret 
// 00617c71  a804                 test al, 4
// 00617c73  7498                 je 0x617c0d
// 00617c75  68e0959c00           push 0x9c95e0
// 00617c7a  57                   push edi
// 00617c7b  e8c085ffff           call 0x610240
// 00617c80  8b442428             mov eax, dword ptr [esp + 0x28]
// 00617c84  50                   push eax
// 00617c85  57                   push edi
// 00617c86  e865efffff           call 0x616bf0
// 00617c8b  83c410               add esp, 0x10
// 00617c8e  5f                   pop edi
// 00617c8f  83c410               add esp, 0x10
// 00617c92  c3                   ret 
// 00617c93  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00617c99  881c29               mov byte ptr [ecx + ebp], bl
// 00617c9c  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00617ca2  8bf1                 mov esi, ecx
// 00617ca4  381e                 cmp byte ptr [esi], bl
// 00617ca6  7405                 je 0x617cad
// 00617ca8  46                   inc esi
// 00617ca9  381e                 cmp byte ptr [esi], bl
// 00617cab  75fb                 jne 0x617ca8
// 00617cad  46                   inc esi
// 00617cae  8d5429fe             lea edx, [ecx + ebp - 2]
// 00617cb2  3bf2                 cmp esi, edx
// 00617cb4  7623                 jbe 0x617cd9
// 00617cb6  51                   push ecx
// 00617cb7  57                   push edi
// 00617cb8  e82390ffff           call 0x610ce0
// 00617cbd  68c8959c00           push 0x9c95c8
// 00617cc2  57                   push edi
// 00617cc3  899f88020000         mov dword ptr [edi + 0x288], ebx
// 00617cc9  e87285ffff           call 0x610240
// 00617cce  83c410               add esp, 0x10
// 00617cd1  5e                   pop esi
// 00617cd2  5d                   pop ebp
// 00617cd3  5b                   pop ebx
// 00617cd4  5f                   pop edi
// 00617cd5  83c410               add esp, 0x10
// 00617cd8  c3                   ret 
// 00617cd9  8a06                 mov al, byte ptr [esi]
// 00617cdb  33db                 xor ebx, ebx
// 00617cdd  46                   inc esi
// 00617cde  3c08                 cmp al, 8
// 00617ce0  88442414             mov byte ptr [esp + 0x14], al
// 00617ce4  0f95c3               setne bl
// 00617ce7  8bc1                 mov eax, ecx
// 00617ce9  2bc6                 sub eax, esi
// 00617ceb  03c5                 add eax, ebp
// 00617ced  99                   cdq 
// 00617cee  8d1c9d06000000       lea ebx, [ebx*4 + 6]
// 00617cf5  f7fb                 idiv ebx
// 00617cf7  85d2                 test edx, edx
// 00617cf9  7427                 je 0x617d22
// 00617cfb  51                   push ecx
// 00617cfc  57                   push edi
// 00617cfd  e8de8fffff           call 0x610ce0
// 00617d02  68ac959c00           push 0x9c95ac
// 00617d07  57                   push edi
// 00617d08  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00617d12  e82985ffff           call 0x610240
// 00617d17  83c410               add esp, 0x10
// 00617d1a  5e                   pop esi
// 00617d1b  5d                   pop ebp
// 00617d1c  5b                   pop ebx
// 00617d1d  5f                   pop edi
// 00617d1e  83c410               add esp, 0x10
// 00617d21  c3                   ret 
// 00617d22  8944241c             mov dword ptr [esp + 0x1c], eax
// 00617d26  3d99999919           cmp eax, 0x19999999
// 00617d2b  7616                 jbe 0x617d43
// 00617d2d  6898959c00           push 0x9c9598
// 00617d32  57                   push edi
// 00617d33  e80885ffff           call 0x610240
// 00617d38  83c408               add esp, 8
// 00617d3b  5e                   pop esi
// 00617d3c  5d                   pop ebp
// 00617d3d  5b                   pop ebx
// 00617d3e  5f                   pop edi
// 00617d3f  83c410               add esp, 0x10
// 00617d42  c3                   ret 
// 00617d43  8d0480               lea eax, [eax + eax*4]
// 00617d46  03c0                 add eax, eax
// 00617d48  50                   push eax
// 00617d49  57                   push edi
// 00617d4a  e8c18fffff           call 0x610d10
// 00617d4f  83c408               add esp, 8
// 00617d52  89442418             mov dword ptr [esp + 0x18], eax
// 00617d56  85c0                 test eax, eax
// 00617d58  7516                 jne 0x617d70
// 00617d5a  6874959c00           push 0x9c9574
// 00617d5f  57                   push edi
// 00617d60  e8db84ffff           call 0x610240
// 00617d65  83c408               add esp, 8
// 00617d68  5e                   pop esi
// 00617d69  5d                   pop ebp
// 00617d6a  5b                   pop ebx
// 00617d6b  5f                   pop edi
// 00617d6c  83c410               add esp, 0x10
// 00617d6f  c3                   ret 
// 00617d70  33c9                 xor ecx, ecx
// 00617d72  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 00617d76  0f8ec3000000         jle 0x617e3f
// 00617d7c  33d2                 xor edx, edx
// 00617d7e  eb04                 jmp 0x617d84
// 00617d80  8b442418             mov eax, dword ptr [esp + 0x18]
// 00617d84  0fb61e               movzx ebx, byte ptr [esi]
// 00617d87  03c2                 add eax, edx
// 00617d89  807c241408           cmp byte ptr [esp + 0x14], 8
// 00617d8e  751a                 jne 0x617daa
// 00617d90  46                   inc esi
// 00617d91  668918               mov word ptr [eax], bx
// 00617d94  0fb61e               movzx ebx, byte ptr [esi]
// 00617d97  46                   inc esi
// 00617d98  66895802             mov word ptr [eax + 2], bx
// 00617d9c  0fb61e               movzx ebx, byte ptr [esi]
// 00617d9f  46                   inc esi
// 00617da0  66895804             mov word ptr [eax + 4], bx
// 00617da4  0fb61e               movzx ebx, byte ptr [esi]
// 00617da7  46                   inc esi
// 00617da8  eb67                 jmp 0x617e11
// 00617daa  bd00010000           mov ebp, 0x100
// 00617daf  660fafdd             imul bx, bp
// 00617db3  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00617db8  6603dd               add bx, bp
// 00617dbb  668918               mov word ptr [eax], bx
// 00617dbe  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00617dc2  83c602               add esi, 2
// 00617dc5  bd00010000           mov ebp, 0x100
// 00617dca  660fafdd             imul bx, bp
// 00617dce  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00617dd3  6603dd               add bx, bp
// 00617dd6  66895802             mov word ptr [eax + 2], bx
// 00617dda  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00617dde  83c602               add esi, 2
// 00617de1  bd00010000           mov ebp, 0x100
// 00617de6  660fafdd             imul bx, bp
// 00617dea  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00617def  6603dd               add bx, bp
// 00617df2  66895804             mov word ptr [eax + 4], bx
// 00617df6  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00617dfa  83c602               add esi, 2
// 00617dfd  bd00010000           mov ebp, 0x100
// 00617e02  660fafdd             imul bx, bp
// 00617e06  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00617e0b  6603dd               add bx, bp
// 00617e0e  83c602               add esi, 2
// 00617e11  66895806             mov word ptr [eax + 6], bx
// 00617e15  660fb61e             movzx bx, byte ptr [esi]
// 00617e19  bd00010000           mov ebp, 0x100
// 00617e1e  660fafdd             imul bx, bp
// 00617e22  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00617e27  6603dd               add bx, bp
// 00617e2a  41                   inc ecx
// 00617e2b  66895808             mov word ptr [eax + 8], bx
// 00617e2f  83c602               add esi, 2
// 00617e32  83c20a               add edx, 0xa
// 00617e35  3b4c241c             cmp ecx, dword ptr [esp + 0x1c]
// 00617e39  0f8c41ffffff         jl 0x617d80
// 00617e3f  8b442428             mov eax, dword ptr [esp + 0x28]
// 00617e43  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00617e49  6a01                 push 1
// 00617e4b  8d542414             lea edx, [esp + 0x14]
// 00617e4f  52                   push edx
// 00617e50  50                   push eax
// 00617e51  57                   push edi
// 00617e52  894c2420             mov dword ptr [esp + 0x20], ecx
// 00617e56  e855b2feff           call 0x6030b0
// 00617e5b  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00617e61  51                   push ecx
// 00617e62  57                   push edi
// 00617e63  e8788effff           call 0x610ce0
// 00617e68  8b542430             mov edx, dword ptr [esp + 0x30]
// 00617e6c  52                   push edx
// 00617e6d  57                   push edi
// 00617e6e  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00617e78  e8638effff           call 0x610ce0
// 00617e7d  83c420               add esp, 0x20
// 00617e80  5e                   pop esi
// 00617e81  5d                   pop ebp
// 00617e82  5b                   pop ebx
// 00617e83  5f                   pop edi
// 00617e84  83c410               add esp, 0x10
// 00617e87  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
