// from server: 100% by auto
// roc 2009-06 005959b0  unit: seg_00590000  size: 502 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005959b0
//
// 005959b0  56                   push esi
// 005959b1  8b742408             mov esi, dword ptr [esp + 8]
// 005959b5  8b4668               mov eax, dword ptr [esi + 0x68]
// 005959b8  a801                 test al, 1
// 005959ba  750d                 jne 0x5959c9
// 005959bc  68c8268d00           push 0x8d26c8
// 005959c1  56                   push esi
// 005959c2  e89987ffff           call 0x58e160
// 005959c7  eb2e                 jmp 0x5959f7
// 005959c9  a804                 test al, 4
// 005959cb  741b                 je 0x5959e8
// 005959cd  68b0268d00           push 0x8d26b0
// 005959d2  56                   push esi
// 005959d3  e83888ffff           call 0x58e210
// 005959d8  8b442418             mov eax, dword ptr [esp + 0x18]
// 005959dc  50                   push eax
// 005959dd  56                   push esi
// 005959de  e8fdf1ffff           call 0x594be0
// 005959e3  83c410               add esp, 0x10
// 005959e6  5e                   pop esi
// 005959e7  c3                   ret 
// 005959e8  a802                 test al, 2
// 005959ea  740e                 je 0x5959fa
// 005959ec  6898268d00           push 0x8d2698
// 005959f1  56                   push esi
// 005959f2  e81988ffff           call 0x58e210
// 005959f7  83c408               add esp, 8
// 005959fa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005959fe  53                   push ebx
// 005959ff  33db                 xor ebx, ebx
// 00595a01  3bc3                 cmp eax, ebx
// 00595a03  7425                 je 0x595a2a
// 00595a05  f7400800100000       test dword ptr [eax + 8], 0x1000
// 00595a0c  741c                 je 0x595a2a
// 00595a0e  6880268d00           push 0x8d2680
// 00595a13  56                   push esi
// 00595a14  e8f787ffff           call 0x58e210
// 00595a19  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00595a1d  51                   push ecx
// 00595a1e  56                   push esi
// 00595a1f  e8bcf1ffff           call 0x594be0
// 00595a24  83c410               add esp, 0x10
// 00595a27  5b                   pop ebx
// 00595a28  5e                   pop esi
// 00595a29  c3                   ret 
// 00595a2a  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00595a30  55                   push ebp
// 00595a31  57                   push edi
// 00595a32  52                   push edx
// 00595a33  56                   push esi
// 00595a34  e87792ffff           call 0x58ecb0
// 00595a39  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00595a3d  8d4501               lea eax, [ebp + 1]
// 00595a40  50                   push eax
// 00595a41  56                   push esi
// 00595a42  e80992ffff           call 0x58ec50
// 00595a47  8bf8                 mov edi, eax
// 00595a49  55                   push ebp
// 00595a4a  57                   push edi
// 00595a4b  56                   push esi
// 00595a4c  89be88020000         mov dword ptr [esi + 0x288], edi
// 00595a52  e8a932ffff           call 0x588d00
// 00595a57  55                   push ebp
// 00595a58  57                   push edi
// 00595a59  56                   push esi
// 00595a5a  e861befeff           call 0x5818c0
// 00595a5f  53                   push ebx
// 00595a60  56                   push esi
// 00595a61  e87af1ffff           call 0x594be0
// 00595a66  83c430               add esp, 0x30
// 00595a69  85c0                 test eax, eax
// 00595a6b  741b                 je 0x595a88
// 00595a6d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00595a73  51                   push ecx
// 00595a74  56                   push esi
// 00595a75  e83692ffff           call 0x58ecb0
// 00595a7a  83c408               add esp, 8
// 00595a7d  5f                   pop edi
// 00595a7e  5d                   pop ebp
// 00595a7f  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00595a85  5b                   pop ebx
// 00595a86  5e                   pop esi
// 00595a87  c3                   ret 
// 00595a88  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00595a8e  881c2a               mov byte ptr [edx + ebp], bl
// 00595a91  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00595a97  8bf8                 mov edi, eax
// 00595a99  381f                 cmp byte ptr [edi], bl
// 00595a9b  7408                 je 0x595aa5
// 00595a9d  8d4900               lea ecx, [ecx]
// 00595aa0  47                   inc edi
// 00595aa1  381f                 cmp byte ptr [edi], bl
// 00595aa3  75fb                 jne 0x595aa0
// 00595aa5  47                   inc edi
// 00595aa6  8d4c28ff             lea ecx, [eax + ebp - 1]
// 00595aaa  3bf9                 cmp edi, ecx
// 00595aac  7220                 jb 0x595ace
// 00595aae  50                   push eax
// 00595aaf  56                   push esi
// 00595ab0  e8fb91ffff           call 0x58ecb0
// 00595ab5  6868268d00           push 0x8d2668
// 00595aba  56                   push esi
// 00595abb  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00595ac1  e84a87ffff           call 0x58e210
// 00595ac6  83c410               add esp, 0x10
// 00595ac9  5f                   pop edi
// 00595aca  5d                   pop ebp
// 00595acb  5b                   pop ebx
// 00595acc  5e                   pop esi
// 00595acd  c3                   ret 
// 00595ace  8a07                 mov al, byte ptr [edi]
// 00595ad0  47                   inc edi
// 00595ad1  84c0                 test al, al
// 00595ad3  7410                 je 0x595ae5
// 00595ad5  6838268d00           push 0x8d2638
// 00595ada  56                   push esi
// 00595adb  e83087ffff           call 0x58e210
// 00595ae0  83c408               add esp, 8
// 00595ae3  32c0                 xor al, al
// 00595ae5  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 00595aeb  8d542414             lea edx, [esp + 0x14]
// 00595aef  52                   push edx
// 00595af0  57                   push edi
// 00595af1  0fb6d8               movzx ebx, al
// 00595af4  55                   push ebp
// 00595af5  53                   push ebx
// 00595af6  56                   push esi
// 00595af7  e834e0ffff           call 0x593b30
// 00595afc  8b442428             mov eax, dword ptr [esp + 0x28]
// 00595b00  8bc8                 mov ecx, eax
// 00595b02  83c414               add esp, 0x14
// 00595b05  2bcf                 sub ecx, edi
// 00595b07  3bf8                 cmp edi, eax
// 00595b09  7771                 ja 0x595b7c
// 00595b0b  83f904               cmp ecx, 4
// 00595b0e  726c                 jb 0x595b7c
// 00595b10  8bae88020000         mov ebp, dword ptr [esi + 0x288]
// 00595b16  0fb6042f             movzx eax, byte ptr [edi + ebp]
// 00595b1a  8d142f               lea edx, [edi + ebp]
// 00595b1d  0fb67a01             movzx edi, byte ptr [edx + 1]
// 00595b21  c1e008               shl eax, 8
// 00595b24  0bc7                 or eax, edi
// 00595b26  0fb67a02             movzx edi, byte ptr [edx + 2]
// 00595b2a  c1e008               shl eax, 8
// 00595b2d  0bc7                 or eax, edi
// 00595b2f  0fb67a03             movzx edi, byte ptr [edx + 3]
// 00595b33  c1e008               shl eax, 8
// 00595b36  0bc7                 or eax, edi
// 00595b38  3bc1                 cmp eax, ecx
// 00595b3a  7330                 jae 0x595b6c
// 00595b3c  8bc8                 mov ecx, eax
// 00595b3e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00595b42  51                   push ecx
// 00595b43  52                   push edx
// 00595b44  53                   push ebx
// 00595b45  55                   push ebp
// 00595b46  50                   push eax
// 00595b47  56                   push esi
// 00595b48  e8d3b3feff           call 0x580f20
// 00595b4d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00595b53  51                   push ecx
// 00595b54  56                   push esi
// 00595b55  e85691ffff           call 0x58ecb0
// 00595b5a  83c420               add esp, 0x20
// 00595b5d  5f                   pop edi
// 00595b5e  5d                   pop ebp
// 00595b5f  5b                   pop ebx
// 00595b60  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00595b6a  5e                   pop esi
// 00595b6b  c3                   ret 
// 00595b6c  76d0                 jbe 0x595b3e
// 00595b6e  55                   push ebp
// 00595b6f  56                   push esi
// 00595b70  e83b91ffff           call 0x58ecb0
// 00595b75  6814268d00           push 0x8d2614
// 00595b7a  eb12                 jmp 0x595b8e
// 00595b7c  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00595b82  52                   push edx
// 00595b83  56                   push esi
// 00595b84  e82791ffff           call 0x58ecb0
// 00595b89  68e8258d00           push 0x8d25e8
// 00595b8e  56                   push esi
// 00595b8f  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00595b99  e87286ffff           call 0x58e210
// 00595b9e  83c410               add esp, 0x10
// 00595ba1  5f                   pop edi
// 00595ba2  5d                   pop ebp
// 00595ba3  5b                   pop ebx
// 00595ba4  5e                   pop esi
// 00595ba5  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
