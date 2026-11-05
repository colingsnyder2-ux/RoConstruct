// from server: 100% by auto
// roc 2010-06 00579510  unit: seg_00570000  size: 664 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00579510
//
// 00579510  83ec10               sub esp, 0x10
// 00579513  57                   push edi
// 00579514  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00579518  8b4768               mov eax, dword ptr [edi + 0x68]
// 0057951b  a801                 test al, 1
// 0057951d  7572                 jne 0x579591
// 0057951f  687073a200           push 0xa27370
// 00579524  57                   push edi
// 00579525  e88685ffff           call 0x571ab0
// 0057952a  83c408               add esp, 8
// 0057952d  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00579533  53                   push ebx
// 00579534  55                   push ebp
// 00579535  56                   push esi
// 00579536  51                   push ecx
// 00579537  57                   push edi
// 00579538  e8c390ffff           call 0x572600
// 0057953d  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00579541  8d5501               lea edx, [ebp + 1]
// 00579544  52                   push edx
// 00579545  57                   push edi
// 00579546  e85590ffff           call 0x5725a0
// 0057954b  8bf0                 mov esi, eax
// 0057954d  55                   push ebp
// 0057954e  56                   push esi
// 0057954f  57                   push edi
// 00579550  89b788020000         mov dword ptr [edi + 0x288], esi
// 00579556  e8b52effff           call 0x56c410
// 0057955b  55                   push ebp
// 0057955c  56                   push esi
// 0057955d  57                   push edi
// 0057955e  e87dbafeff           call 0x564fe0
// 00579563  33db                 xor ebx, ebx
// 00579565  53                   push ebx
// 00579566  57                   push edi
// 00579567  e8a4efffff           call 0x578510
// 0057956c  83c430               add esp, 0x30
// 0057956f  85c0                 test eax, eax
// 00579571  7440                 je 0x5795b3
// 00579573  8b8788020000         mov eax, dword ptr [edi + 0x288]
// 00579579  50                   push eax
// 0057957a  57                   push edi
// 0057957b  e88090ffff           call 0x572600
// 00579580  83c408               add esp, 8
// 00579583  5e                   pop esi
// 00579584  5d                   pop ebp
// 00579585  899f88020000         mov dword ptr [edi + 0x288], ebx
// 0057958b  5b                   pop ebx
// 0057958c  5f                   pop edi
// 0057958d  83c410               add esp, 0x10
// 00579590  c3                   ret 
// 00579591  a804                 test al, 4
// 00579593  7498                 je 0x57952d
// 00579595  685873a200           push 0xa27358
// 0057959a  57                   push edi
// 0057959b  e8c085ffff           call 0x571b60
// 005795a0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005795a4  50                   push eax
// 005795a5  57                   push edi
// 005795a6  e865efffff           call 0x578510
// 005795ab  83c410               add esp, 0x10
// 005795ae  5f                   pop edi
// 005795af  83c410               add esp, 0x10
// 005795b2  c3                   ret 
// 005795b3  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 005795b9  881c29               mov byte ptr [ecx + ebp], bl
// 005795bc  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 005795c2  8bf1                 mov esi, ecx
// 005795c4  381e                 cmp byte ptr [esi], bl
// 005795c6  7405                 je 0x5795cd
// 005795c8  46                   inc esi
// 005795c9  381e                 cmp byte ptr [esi], bl
// 005795cb  75fb                 jne 0x5795c8
// 005795cd  46                   inc esi
// 005795ce  8d5429fe             lea edx, [ecx + ebp - 2]
// 005795d2  3bf2                 cmp esi, edx
// 005795d4  7623                 jbe 0x5795f9
// 005795d6  51                   push ecx
// 005795d7  57                   push edi
// 005795d8  e82390ffff           call 0x572600
// 005795dd  684073a200           push 0xa27340
// 005795e2  57                   push edi
// 005795e3  899f88020000         mov dword ptr [edi + 0x288], ebx
// 005795e9  e87285ffff           call 0x571b60
// 005795ee  83c410               add esp, 0x10
// 005795f1  5e                   pop esi
// 005795f2  5d                   pop ebp
// 005795f3  5b                   pop ebx
// 005795f4  5f                   pop edi
// 005795f5  83c410               add esp, 0x10
// 005795f8  c3                   ret 
// 005795f9  8a06                 mov al, byte ptr [esi]
// 005795fb  33db                 xor ebx, ebx
// 005795fd  46                   inc esi
// 005795fe  3c08                 cmp al, 8
// 00579600  88442414             mov byte ptr [esp + 0x14], al
// 00579604  0f95c3               setne bl
// 00579607  8bc1                 mov eax, ecx
// 00579609  2bc6                 sub eax, esi
// 0057960b  03c5                 add eax, ebp
// 0057960d  99                   cdq 
// 0057960e  8d1c9d06000000       lea ebx, [ebx*4 + 6]
// 00579615  f7fb                 idiv ebx
// 00579617  85d2                 test edx, edx
// 00579619  7427                 je 0x579642
// 0057961b  51                   push ecx
// 0057961c  57                   push edi
// 0057961d  e8de8fffff           call 0x572600
// 00579622  682473a200           push 0xa27324
// 00579627  57                   push edi
// 00579628  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00579632  e82985ffff           call 0x571b60
// 00579637  83c410               add esp, 0x10
// 0057963a  5e                   pop esi
// 0057963b  5d                   pop ebp
// 0057963c  5b                   pop ebx
// 0057963d  5f                   pop edi
// 0057963e  83c410               add esp, 0x10
// 00579641  c3                   ret 
// 00579642  8944241c             mov dword ptr [esp + 0x1c], eax
// 00579646  3d99999919           cmp eax, 0x19999999
// 0057964b  7616                 jbe 0x579663
// 0057964d  681073a200           push 0xa27310
// 00579652  57                   push edi
// 00579653  e80885ffff           call 0x571b60
// 00579658  83c408               add esp, 8
// 0057965b  5e                   pop esi
// 0057965c  5d                   pop ebp
// 0057965d  5b                   pop ebx
// 0057965e  5f                   pop edi
// 0057965f  83c410               add esp, 0x10
// 00579662  c3                   ret 
// 00579663  8d0480               lea eax, [eax + eax*4]
// 00579666  03c0                 add eax, eax
// 00579668  50                   push eax
// 00579669  57                   push edi
// 0057966a  e8c18fffff           call 0x572630
// 0057966f  83c408               add esp, 8
// 00579672  89442418             mov dword ptr [esp + 0x18], eax
// 00579676  85c0                 test eax, eax
// 00579678  7516                 jne 0x579690
// 0057967a  68ec72a200           push 0xa272ec
// 0057967f  57                   push edi
// 00579680  e8db84ffff           call 0x571b60
// 00579685  83c408               add esp, 8
// 00579688  5e                   pop esi
// 00579689  5d                   pop ebp
// 0057968a  5b                   pop ebx
// 0057968b  5f                   pop edi
// 0057968c  83c410               add esp, 0x10
// 0057968f  c3                   ret 
// 00579690  33c9                 xor ecx, ecx
// 00579692  394c241c             cmp dword ptr [esp + 0x1c], ecx
// 00579696  0f8ec3000000         jle 0x57975f
// 0057969c  33d2                 xor edx, edx
// 0057969e  eb04                 jmp 0x5796a4
// 005796a0  8b442418             mov eax, dword ptr [esp + 0x18]
// 005796a4  0fb61e               movzx ebx, byte ptr [esi]
// 005796a7  03c2                 add eax, edx
// 005796a9  807c241408           cmp byte ptr [esp + 0x14], 8
// 005796ae  751a                 jne 0x5796ca
// 005796b0  46                   inc esi
// 005796b1  668918               mov word ptr [eax], bx
// 005796b4  0fb61e               movzx ebx, byte ptr [esi]
// 005796b7  46                   inc esi
// 005796b8  66895802             mov word ptr [eax + 2], bx
// 005796bc  0fb61e               movzx ebx, byte ptr [esi]
// 005796bf  46                   inc esi
// 005796c0  66895804             mov word ptr [eax + 4], bx
// 005796c4  0fb61e               movzx ebx, byte ptr [esi]
// 005796c7  46                   inc esi
// 005796c8  eb67                 jmp 0x579731
// 005796ca  bd00010000           mov ebp, 0x100
// 005796cf  660fafdd             imul bx, bp
// 005796d3  660fb66e01           movzx bp, byte ptr [esi + 1]
// 005796d8  6603dd               add bx, bp
// 005796db  668918               mov word ptr [eax], bx
// 005796de  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 005796e2  83c602               add esi, 2
// 005796e5  bd00010000           mov ebp, 0x100
// 005796ea  660fafdd             imul bx, bp
// 005796ee  660fb66e01           movzx bp, byte ptr [esi + 1]
// 005796f3  6603dd               add bx, bp
// 005796f6  66895802             mov word ptr [eax + 2], bx
// 005796fa  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 005796fe  83c602               add esi, 2
// 00579701  bd00010000           mov ebp, 0x100
// 00579706  660fafdd             imul bx, bp
// 0057970a  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0057970f  6603dd               add bx, bp
// 00579712  66895804             mov word ptr [eax + 4], bx
// 00579716  0fb65e02             movzx ebx, byte ptr [esi + 2]
// 0057971a  83c602               add esi, 2
// 0057971d  bd00010000           mov ebp, 0x100
// 00579722  660fafdd             imul bx, bp
// 00579726  660fb66e01           movzx bp, byte ptr [esi + 1]
// 0057972b  6603dd               add bx, bp
// 0057972e  83c602               add esi, 2
// 00579731  66895806             mov word ptr [eax + 6], bx
// 00579735  660fb61e             movzx bx, byte ptr [esi]
// 00579739  bd00010000           mov ebp, 0x100
// 0057973e  660fafdd             imul bx, bp
// 00579742  660fb66e01           movzx bp, byte ptr [esi + 1]
// 00579747  6603dd               add bx, bp
// 0057974a  41                   inc ecx
// 0057974b  66895808             mov word ptr [eax + 8], bx
// 0057974f  83c602               add esi, 2
// 00579752  83c20a               add edx, 0xa
// 00579755  3b4c241c             cmp ecx, dword ptr [esp + 0x1c]
// 00579759  0f8c41ffffff         jl 0x5796a0
// 0057975f  8b442428             mov eax, dword ptr [esp + 0x28]
// 00579763  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00579769  6a01                 push 1
// 0057976b  8d542414             lea edx, [esp + 0x14]
// 0057976f  52                   push edx
// 00579770  50                   push eax
// 00579771  57                   push edi
// 00579772  894c2420             mov dword ptr [esp + 0x20], ecx
// 00579776  e8a5b2feff           call 0x564a20
// 0057977b  8b8f88020000         mov ecx, dword ptr [edi + 0x288]
// 00579781  51                   push ecx
// 00579782  57                   push edi
// 00579783  e8788effff           call 0x572600
// 00579788  8b542430             mov edx, dword ptr [esp + 0x30]
// 0057978c  52                   push edx
// 0057978d  57                   push edi
// 0057978e  c7878802000000000000 mov dword ptr [edi + 0x288], 0
// 00579798  e8638effff           call 0x572600
// 0057979d  83c420               add esp, 0x20
// 005797a0  5e                   pop esi
// 005797a1  5d                   pop ebp
// 005797a2  5b                   pop ebx
// 005797a3  5f                   pop edi
// 005797a4  83c410               add esp, 0x10
// 005797a7  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
