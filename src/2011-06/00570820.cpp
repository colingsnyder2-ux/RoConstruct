// from server: 100% by auto
// roc 2011-06 00570820  unit: seg_00570000  size: 664 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00570820
//
// 00570820  83ec10               sub esp, 0x10
// 00570823  57                   push edi
// 00570824  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00570828  8b4768               mov eax, dword ptr [edi + 0x68]
// 0057082b  a801                 test al, 1
// 0057082d  7572                 jne 0x5708a1
// 0057082f  68f069a800           push 0xa869f0
// 00570834  57                   push edi
// 00570835  e8f60affff           call 0x561330
// 0057083a  83c408               add esp, 8
// 0057083d  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00570843  53                   push ebx
// 00570844  55                   push ebp
// 00570845  56                   push esi
// 00570846  51                   push ecx
// 00570847  57                   push edi
// 00570848  e8530effff           call 0x5616a0
// 0057084d  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00570851  8d5501               lea edx, [ebp + 1]
// 00570854  52                   push edx
// 00570855  57                   push edi
// 00570856  e8e50dffff           call 0x561640
// 0057085b  8bf0                 mov esi, eax
// 0057085d  55                   push ebp
// 0057085e  56                   push esi
// 0057085f  57                   push edi
// 00570860  89b788020000         mov dword ptr [edi + 0x288], esi
// 00570866  e80507ffff           call 0x560f70
// 0057086b  55                   push ebp
// 0057086c  56                   push esi
// 0057086d  57                   push edi
// 0057086e  e8ddfffdff           call 0x550850
// 00570873  33db                 xor ebx, ebx
// 00570875  53                   push ebx
// 00570876  57                   push edi
// 00570877  e8c4efffff           call 0x56f840
// 0057087c  83c430               add esp, 0x30
// 0057087f  85c0                 test eax, eax
// 00570881  7440                 je 0x5708c3
// 00570883  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 00570889  50                   push eax
// 0057088a  57                   push edi
// 0057088b  e8100effff           call 0x5616a0
// 00570890  83c408               add esp, 8
// 00570893  5e                   pop esi
// 00570894  5d                   pop ebp
// 00570895  899f88020000         mov dword ptr [edi + 0x288], ebx
// 0057089b  5b                   pop ebx
// 0057089c  5f                   pop edi
// 0057089d  83c410               add esp, 0x10
// 005708a0  c3                   ret 
// 005708a1  a804                 test al, 4
// 005708a3  7498                 je 0x57083d
// 005708a5  68d869a800           push 0xa869d8
// 005708aa  57                   push edi
// 005708ab  e8300bffff           call 0x5613e0
// 005708b0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005708b4  50                   push eax
// 005708b5  57                   push edi
// 005708b6  e885efffff           call 0x56f840
// 005708bb  83c410               add esp, 0x10
// 005708be  5f                   pop edi
// 005708bf  83c410               add esp, 0x10
// 005708c2  c3                   ret 
// 005708c3  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 005708c9  881c29               mov byte ptr [ecx + ebp], bl
// 005708cc  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 005708d2  8bf1                 mov esi, ecx
// 005708d4  381e                 cmp byte ptr [esi], bl
// 005708d6  7405                 je 0x5708dd
// 005708d8  46                   inc esi
// 005708d9  381e                 cmp byte ptr [esi], bl
// 005708db  75fb                 jne 0x5708d8
// 005708dd  46                   inc esi
// 005708de  8d5429fe             lea edx, [ecx + ebp - 2]
// 005708e2  3bf2                 cmp esi, edx
// 005708e4  7623                 jbe 0x570909
// 005708e6  51                   push ecx
// 005708e7  57                   push edi
// 005708e8  e8b30dffff           call 0x5616a0
// 005708ed  68c069a800           push 0xa869c0
// 005708f2  57                   push edi
// 005708f3  899f88020000         mov dword ptr [edi + 0x288], ebx
// 005708f9  e8e20affff           call 0x5613e0
// 005708fe  83c410               add esp, 0x10
// 00570901  5e                   pop esi
// 00570902  5d                   pop ebp
// 00570903  5b                   pop ebx
// 00570904  5f                   pop edi
// 00570905  83c410               add esp, 0x10
// 00570908  c3                   ret 
// 00570909  8a06                 mov al, byte ptr [esi]
// 0057090b  33db                 xor ebx, ebx
// 0057090d  46                   inc esi
// 0057090e  3c08                 cmp al, 8
// 00570910  88442414             mov byte ptr [esp + 0x14], al
// 00570914  0f95c3               setne bl
// 00570917  8bc1                 mov eax, ecx
// 00570919  2bc6                 sub eax, esi
// 0057091b  03c5                 add eax, ebp
// 0057091d  99                   cdq 
// 0057091e  8d1c9d06000000       lea ebx, [ebx*4 + 6]
// 00570925  f7fb                 idiv ebx
// 00570927  85d2                 test edx, edx
// 00570929  7427                 je 0x570952
// 0057092b  51                   push ecx
// 0057092c  57                   push edi
// 0057092d  e86e0dffff           call 0x5616a0
// 00570932  68a469a800           push 0xa869a4
// 00570937  57                   push edi
// 00570938  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00570942  e8990affff           call 0x5613e0
// 00570947  83c410               add esp, 0x10
// 0057094a  5e                   pop esi
// 0057094b  5d                   pop ebp
// 0057094c  5b                   pop ebx
// 0057094d  5f                   pop edi
// 0057094e  83c410               add esp, 0x10
// 00570951  c3                   ret 
// 00570952  8944241c             mov dword ptr [esp + 0x1c], eax
// 00570956  3d99999919           cmp eax, 0x19999999
// 0057095b  7616                 jbe 0x570973
// 0057095d  689069a800           push 0xa86990
// 00570962  57                   push edi
// 00570963  e8780affff           call 0x5613e0
// 00570968  83c408               add esp, 8
// 0057096b  5e                   pop esi
// 0057096c  5d                   pop ebp
// 0057096d  5b                   pop ebx
// 0057096e  5f                   pop edi
// 0057096f  83c410               add esp, 0x10
// 00570972  c3                   ret 
// 00570973  8d0480               lea eax, [eax + eax*4]
// 00570976  03c0                 add eax, eax
// 00570978  50                   push eax
// 00570979  57                   push edi
// 0057097a  e8510dffff           call 0x5616d0
// 0057097f  83c408               add esp, 8
// 00570982  89442418             mov dword ptr [esp + 0x18], eax
// 00570986  85c0                 test eax, eax
// 00570988  7516                 jne 0x5709a0
// 0057098a  686c69a800           push 0xa8696c
// 0057098f  57                   push edi
// 00570990  e84b0affff           call 0x5613e0
// 00570995  83c408               add esp, 8
// 00570998  5e                   pop esi
// 00570999  5d                   pop ebp
// 0057099a  5b                   pop ebx
// 0057099b  5f                   pop edi
// 0057099c  83c410               add esp, 0x10
// 0057099f  c3                   ret 
// 005709a0  33c9                 xor ecx, ecx
// 005709a2  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 005709a6  0f8ec3000000         jle 0x570a6f
// 005709ac  33d2                 xor edx, edx
// 005709ae  eb04                 jmp 0x5709b4
// 005709b0  8b442418             mov eax, dword ptr [esp + 0x18]
// 005709b4  0fb61e               movzx ebx, byte ptr [esi]
// 005709b7  03c2                 add eax, edx
// 005709b9  807c241408           cmp byte ptr [esp + 0x14], 8
// 005709be  751a                 jne 0x5709da
// 005709c0  46                   inc esi
// 005709c1  668918               mov word ptr [eax], bx
// 005709c4  0fb61e               movzx ebx, byte ptr [esi]
// 005709c7  46                   inc esi
// 005709c8  66895802             mov word ptr [eax + 2], bx
// 005709cc  0fb61e               movzx ebx, byte ptr [esi]
// 005709cf  46                   inc esi
// 005709d0  66895804             mov word ptr [eax + 4], bx
// 005709d4  0fb61e               movzx ebx, byte ptr [esi]
// 005709d7  46                   inc esi
// 005709d8  eb67                 jmp 0x570a41
// 005709da  bd00010000           mov ebp, 0x100
// 005709df  660fafdd             imul bx, bp
// 005709e3  660fb66e01           movzx bp, byte ptr [esi + 1]
// 005709e8  6603dd               add bx, bp
// 005709eb  668918               mov word ptr [eax], bx
// 005709ee  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 005709f2  83c602               add esi, 2
// 005709f5  bd00010000           mov ebp, 0x100
// 005709fa  660fafdd             imul bx, bp
// 005709fe  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00570a03  6603dd               add bx, bp
// 00570a06  66895802             mov word ptr [eax + 2], bx
// 00570a0a  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00570a0e  83c602               add esi, 2
// 00570a11  bd00010000           mov ebp, 0x100
// 00570a16  660fafdd             imul bx, bp
// 00570a1a  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00570a1f  6603dd               add bx, bp
// 00570a22  66895804             mov word ptr [eax + 4], bx
// 00570a26  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 00570a2a  83c602               add esi, 2
// 00570a2d  bd00010000           mov ebp, 0x100
// 00570a32  660fafdd             imul bx, bp
// 00570a36  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00570a3b  6603dd               add bx, bp
// 00570a3e  83c602               add esi, 2
// 00570a41  66895806             mov word ptr [eax + 6], bx
// 00570a45  660fb61e             movzx bx, byte ptr [esi]
// 00570a49  bd00010000           mov ebp, 0x100
// 00570a4e  660fafdd             imul bx, bp
// 00570a52  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00570a57  6603dd               add bx, bp
// 00570a5a  41                   inc ecx
// 00570a5b  66895808             mov word ptr [eax + 8], bx
// 00570a5f  83c602               add esi, 2
// 00570a62  83c20a               add edx, 0xa
// 00570a65  3b4c241c             cmp ecx, dword ptr [esp + 0x1c]
// 00570a69  0f8c41ffffff         jl 0x5709b0
// 00570a6f  8b442428             mov eax, dword ptr [esp + 0x28]
// 00570a73  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00570a79  6a01                 push 1
// 00570a7b  8d542414             lea edx, [esp + 0x14]
// 00570a7f  52                   push edx
// 00570a80  50                   push eax
// 00570a81  57                   push edi
// 00570a82  894c2420             mov dword ptr [esp + 0x20], ecx
// 00570a86  e8d59afeff           call 0x55a560
// 00570a8b  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00570a91  51                   push ecx
// 00570a92  57                   push edi
// 00570a93  e8080cffff           call 0x5616a0
// 00570a98  8b542430             mov edx, dword ptr [esp + 0x30]
// 00570a9c  52                   push edx
// 00570a9d  57                   push edi
// 00570a9e  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00570aa8  e8f30bffff           call 0x5616a0
// 00570aad  83c420               add esp, 0x20
// 00570ab0  5e                   pop esi
// 00570ab1  5d                   pop ebp
// 00570ab2  5b                   pop ebx
// 00570ab3  5f                   pop edi
// 00570ab4  83c410               add esp, 0x10
// 00570ab7  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
