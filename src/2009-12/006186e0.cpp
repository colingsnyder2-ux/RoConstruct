// from server: 100% by auto
// roc 2009-12 006186e0  unit: seg_00610000  size: 767 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006186e0
//
// 006186e0  83ec10               sub esp, 0x10
// 006186e3  56                   push esi
// 006186e4  8b742418             mov esi, dword ptr [esp + 0x18]
// 006186e8  8b4668               mov eax, dword ptr [esi + 0x68]
// 006186eb  57                   push edi
// 006186ec  a801                 test al, 1
// 006186ee  7552                 jne 0x618742
// 006186f0  6880999c00           push 0x9c9980
// 006186f5  56                   push esi
// 006186f6  e8957affff           call 0x610190
// 006186fb  83c408               add esp, 8
// 006186fe  33ff                 xor edi, edi
// 00618700  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00618706  53                   push ebx
// 00618707  55                   push ebp
// 00618708  52                   push edx
// 00618709  56                   push esi
// 0061870a  e8d185ffff           call 0x610ce0
// 0061870f  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00618713  8d4501               lea eax, [ebp + 1]
// 00618716  50                   push eax
// 00618717  56                   push esi
// 00618718  e8f385ffff           call 0x610d10
// 0061871d  8bd8                 mov ebx, eax
// 0061871f  83c410               add esp, 0x10
// 00618722  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00618728  3bdf                 cmp ebx, edi
// 0061872a  756b                 jne 0x618797
// 0061872c  6864999c00           push 0x9c9964
// 00618731  56                   push esi
// 00618732  e8097bffff           call 0x610240
// 00618737  83c408               add esp, 8
// 0061873a  5d                   pop ebp
// 0061873b  5b                   pop ebx
// 0061873c  5f                   pop edi
// 0061873d  5e                   pop esi
// 0061873e  83c410               add esp, 0x10
// 00618741  c3                   ret 
// 00618742  a804                 test al, 4
// 00618744  741f                 je 0x618765
// 00618746  684c999c00           push 0x9c994c
// 0061874b  56                   push esi
// 0061874c  e8ef7affff           call 0x610240
// 00618751  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00618755  50                   push eax
// 00618756  56                   push esi
// 00618757  e894e4ffff           call 0x616bf0
// 0061875c  83c410               add esp, 0x10
// 0061875f  5f                   pop edi
// 00618760  5e                   pop esi
// 00618761  83c410               add esp, 0x10
// 00618764  c3                   ret 
// 00618765  8b442420             mov eax, dword ptr [esp + 0x20]
// 00618769  33ff                 xor edi, edi
// 0061876b  3bc7                 cmp eax, edi
// 0061876d  7491                 je 0x618700
// 0061876f  f7400800040000       test dword ptr [eax + 8], 0x400
// 00618776  7488                 je 0x618700
// 00618778  6834999c00           push 0x9c9934
// 0061877d  56                   push esi
// 0061877e  e8bd7affff           call 0x610240
// 00618783  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00618787  51                   push ecx
// 00618788  56                   push esi
// 00618789  e862e4ffff           call 0x616bf0
// 0061878e  83c410               add esp, 0x10
// 00618791  5f                   pop edi
// 00618792  5e                   pop esi
// 00618793  83c410               add esp, 0x10
// 00618796  c3                   ret 
// 00618797  55                   push ebp
// 00618798  53                   push ebx
// 00618799  56                   push esi
// 0061879a  e8f122ffff           call 0x60aa90
// 0061879f  55                   push ebp
// 006187a0  53                   push ebx
// 006187a1  56                   push esi
// 006187a2  e8c9aefeff           call 0x603670
// 006187a7  57                   push edi
// 006187a8  56                   push esi
// 006187a9  e842e4ffff           call 0x616bf0
// 006187ae  83c420               add esp, 0x20
// 006187b1  85c0                 test eax, eax
// 006187b3  741e                 je 0x6187d3
// 006187b5  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 006187bb  51                   push ecx
// 006187bc  56                   push esi
// 006187bd  e81e85ffff           call 0x610ce0
// 006187c2  83c408               add esp, 8
// 006187c5  5d                   pop ebp
// 006187c6  5b                   pop ebx
// 006187c7  89be88020000         mov dword ptr [esi + 0x288], edi
// 006187cd  5f                   pop edi
// 006187ce  5e                   pop esi
// 006187cf  83c410               add esp, 0x10
// 006187d2  c3                   ret 
// 006187d3  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 006187d9  c6042a00             mov byte ptr [edx + ebp], 0
// 006187dd  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 006187e3  8bc1                 mov eax, ecx
// 006187e5  803800               cmp byte ptr [eax], 0
// 006187e8  740c                 je 0x6187f6
// 006187ea  8d9b00000000         lea ebx, [ebx]
// 006187f0  40                   inc eax
// 006187f1  803800               cmp byte ptr [eax], 0
// 006187f4  75fa                 jne 0x6187f0
// 006187f6  03cd                 add ecx, ebp
// 006187f8  8d500c               lea edx, [eax + 0xc]
// 006187fb  894c241c             mov dword ptr [esp + 0x1c], ecx
// 006187ff  3bca                 cmp ecx, edx
// 00618801  770a                 ja 0x61880d
// 00618803  6820999c00           push 0x9c9920
// 00618808  e985000000           jmp 0x618892
// 0061880d  0fb66801             movzx ebp, byte ptr [eax + 1]
// 00618811  0fb64802             movzx ecx, byte ptr [eax + 2]
// 00618815  0fb65003             movzx edx, byte ptr [eax + 3]
// 00618819  0fb65805             movzx ebx, byte ptr [eax + 5]
// 0061881d  c1e508               shl ebp, 8
// 00618820  03e9                 add ebp, ecx
// 00618822  0fb64804             movzx ecx, byte ptr [eax + 4]
// 00618826  c1e508               shl ebp, 8
// 00618829  03ea                 add ebp, edx
// 0061882b  0fb65006             movzx edx, byte ptr [eax + 6]
// 0061882f  c1e308               shl ebx, 8
// 00618832  03da                 add ebx, edx
// 00618834  0fb65008             movzx edx, byte ptr [eax + 8]
// 00618838  c1e508               shl ebp, 8
// 0061883b  03e9                 add ebp, ecx
// 0061883d  0fb64807             movzx ecx, byte ptr [eax + 7]
// 00618841  c1e308               shl ebx, 8
// 00618844  03d9                 add ebx, ecx
// 00618846  8a4809               mov cl, byte ptr [eax + 9]
// 00618849  c1e308               shl ebx, 8
// 0061884c  03da                 add ebx, edx
// 0061884e  8a500a               mov dl, byte ptr [eax + 0xa]
// 00618851  83c00b               add eax, 0xb
// 00618854  884c2413             mov byte ptr [esp + 0x13], cl
// 00618858  88542424             mov byte ptr [esp + 0x24], dl
// 0061885c  89442414             mov dword ptr [esp + 0x14], eax
// 00618860  84c9                 test cl, cl
// 00618862  7507                 jne 0x61886b
// 00618864  80fa02               cmp dl, 2
// 00618867  7524                 jne 0x61888d
// 00618869  eb66                 jmp 0x6188d1
// 0061886b  80f901               cmp cl, 1
// 0061886e  7507                 jne 0x618877
// 00618870  80fa03               cmp dl, 3
// 00618873  7518                 jne 0x61888d
// 00618875  eb5a                 jmp 0x6188d1
// 00618877  80f902               cmp cl, 2
// 0061887a  7507                 jne 0x618883
// 0061887c  80fa03               cmp dl, 3
// 0061887f  750c                 jne 0x61888d
// 00618881  eb4e                 jmp 0x6188d1
// 00618883  80f903               cmp cl, 3
// 00618886  752e                 jne 0x6188b6
// 00618888  80fa04               cmp dl, 4
// 0061888b  7444                 je 0x6188d1
// 0061888d  68f4989c00           push 0x9c98f4
// 00618892  56                   push esi
// 00618893  e8a879ffff           call 0x610240
// 00618898  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0061889e  50                   push eax
// 0061889f  56                   push esi
// 006188a0  e83b84ffff           call 0x610ce0
// 006188a5  83c410               add esp, 0x10
// 006188a8  5d                   pop ebp
// 006188a9  5b                   pop ebx
// 006188aa  89be88020000         mov dword ptr [esi + 0x288], edi
// 006188b0  5f                   pop edi
// 006188b1  5e                   pop esi
// 006188b2  83c410               add esp, 0x10
// 006188b5  c3                   ret 
// 006188b6  80f904               cmp cl, 4
// 006188b9  7216                 jb 0x6188d1
// 006188bb  68a85b9c00           push 0x9c5ba8
// 006188c0  56                   push esi
// 006188c1  e87a79ffff           call 0x610240
// 006188c6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006188ca  8a54242c             mov dl, byte ptr [esp + 0x2c]
// 006188ce  83c408               add esp, 8
// 006188d1  803800               cmp byte ptr [eax], 0
// 006188d4  8bf8                 mov edi, eax
// 006188d6  7406                 je 0x6188de
// 006188d8  47                   inc edi
// 006188d9  803f00               cmp byte ptr [edi], 0
// 006188dc  75fa                 jne 0x6188d8
// 006188de  0fb6c2               movzx eax, dl
// 006188e1  8d0c8500000000       lea ecx, [eax*4]
// 006188e8  51                   push ecx
// 006188e9  56                   push esi
// 006188ea  8944242c             mov dword ptr [esp + 0x2c], eax
// 006188ee  e81d84ffff           call 0x610d10
// 006188f3  83c408               add esp, 8
// 006188f6  89442418             mov dword ptr [esp + 0x18], eax
// 006188fa  85c0                 test eax, eax
// 006188fc  752d                 jne 0x61892b
// 006188fe  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00618904  52                   push edx
// 00618905  56                   push esi
// 00618906  e8d583ffff           call 0x610ce0
// 0061890b  68d8989c00           push 0x9c98d8
// 00618910  56                   push esi
// 00618911  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 0061891b  e82079ffff           call 0x610240
// 00618920  83c410               add esp, 0x10
// 00618923  5d                   pop ebp
// 00618924  5b                   pop ebx
// 00618925  5f                   pop edi
// 00618926  5e                   pop esi
// 00618927  83c410               add esp, 0x10
// 0061892a  c3                   ret 
// 0061892b  33d2                 xor edx, edx
// 0061892d  39542424             cmp dword ptr [esp + 0x24], edx
// 00618931  7e5a                 jle 0x61898d
// 00618933  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00618937  47                   inc edi
// 00618938  893c90               mov dword ptr [eax + edx*4], edi
// 0061893b  3bf9                 cmp edi, ecx
// 0061893d  770b                 ja 0x61894a
// 0061893f  90                   nop 
// 00618940  803f00               cmp byte ptr [edi], 0
// 00618943  743d                 je 0x618982
// 00618945  47                   inc edi
// 00618946  3bf9                 cmp edi, ecx
// 00618948  76f6                 jbe 0x618940
// 0061894a  6820999c00           push 0x9c9920
// 0061894f  56                   push esi
// 00618950  e8eb78ffff           call 0x610240
// 00618955  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0061895b  50                   push eax
// 0061895c  56                   push esi
// 0061895d  e87e83ffff           call 0x610ce0
// 00618962  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00618966  51                   push ecx
// 00618967  56                   push esi
// 00618968  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00618972  e86983ffff           call 0x610ce0
// 00618977  83c418               add esp, 0x18
// 0061897a  5d                   pop ebp
// 0061897b  5b                   pop ebx
// 0061897c  5f                   pop edi
// 0061897d  5e                   pop esi
// 0061897e  83c410               add esp, 0x10
// 00618981  c3                   ret 
// 00618982  3bf9                 cmp edi, ecx
// 00618984  77c4                 ja 0x61894a
// 00618986  42                   inc edx
// 00618987  3b542424             cmp edx, dword ptr [esp + 0x24]
// 0061898b  7ca6                 jl 0x618933
// 0061898d  8b542414             mov edx, dword ptr [esp + 0x14]
// 00618991  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 00618996  50                   push eax
// 00618997  8b442428             mov eax, dword ptr [esp + 0x28]
// 0061899b  52                   push edx
// 0061899c  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 006189a2  50                   push eax
// 006189a3  8b442434             mov eax, dword ptr [esp + 0x34]
// 006189a7  51                   push ecx
// 006189a8  53                   push ebx
// 006189a9  55                   push ebp
// 006189aa  52                   push edx
// 006189ab  50                   push eax
// 006189ac  56                   push esi
// 006189ad  e83e9ffeff           call 0x6028f0
// 006189b2  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 006189b8  51                   push ecx
// 006189b9  56                   push esi
// 006189ba  e82183ffff           call 0x610ce0
// 006189bf  8b542444             mov edx, dword ptr [esp + 0x44]
// 006189c3  52                   push edx
// 006189c4  56                   push esi
// 006189c5  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 006189cf  e80c83ffff           call 0x610ce0
// 006189d4  83c434               add esp, 0x34
// 006189d7  5d                   pop ebp
// 006189d8  5b                   pop ebx
// 006189d9  5f                   pop edi
// 006189da  5e                   pop esi
// 006189db  83c410               add esp, 0x10
// 006189de  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
