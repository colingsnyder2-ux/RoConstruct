// from server: 100% by auto
// roc 2009-12 0060eb80  unit: seg_00600000  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060eb80
//
// 0060eb80  83ec10               sub esp, 0x10
// 0060eb83  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060eb87  56                   push esi
// 0060eb88  c644240462           mov byte ptr [esp + 4], 0x62
// 0060eb8d  c64424054b           mov byte ptr [esp + 5], 0x4b
// 0060eb92  c644240647           mov byte ptr [esp + 6], 0x47
// 0060eb97  c644240744           mov byte ptr [esp + 7], 0x44
// 0060eb9c  c644240800           mov byte ptr [esp + 8], 0
// 0060eba1  83f803               cmp eax, 3
// 0060eba4  7559                 jne 0x60ebff
// 0060eba6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060ebaa  0fb78118010000       movzx eax, word ptr [ecx + 0x118]
// 0060ebb1  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0060ebb5  6685c0               test ax, ax
// 0060ebb8  7509                 jne 0x60ebc3
// 0060ebba  f6813002000001       test byte ptr [ecx + 0x230], 1
// 0060ebc1  751c                 jne 0x60ebdf
// 0060ebc3  660fb632             movzx si, byte ptr [edx]
// 0060ebc7  663bf0               cmp si, ax
// 0060ebca  7613                 jbe 0x60ebdf
// 0060ebcc  6830619c00           push 0x9c6130
// 0060ebd1  51                   push ecx
// 0060ebd2  e869160000           call 0x610240
// 0060ebd7  83c408               add esp, 8
// 0060ebda  5e                   pop esi
// 0060ebdb  83c410               add esp, 0x10
// 0060ebde  c3                   ret 
// 0060ebdf  8a02                 mov al, byte ptr [edx]
// 0060ebe1  6a01                 push 1
// 0060ebe3  8d542410             lea edx, [esp + 0x10]
// 0060ebe7  88442410             mov byte ptr [esp + 0x10], al
// 0060ebeb  52                   push edx
// 0060ebec  8d44240c             lea eax, [esp + 0xc]
// 0060ebf0  50                   push eax
// 0060ebf1  51                   push ecx
// 0060ebf2  e879eeffff           call 0x60da70
// 0060ebf7  83c410               add esp, 0x10
// 0060ebfa  5e                   pop esi
// 0060ebfb  83c410               add esp, 0x10
// 0060ebfe  c3                   ret 
// 0060ebff  a802                 test al, 2
// 0060ec01  7479                 je 0x60ec7c
// 0060ec03  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0060ec07  0fb74602             movzx eax, word ptr [esi + 2]
// 0060ec0b  8bc8                 mov ecx, eax
// 0060ec0d  8844240d             mov byte ptr [esp + 0xd], al
// 0060ec11  0fb74604             movzx eax, word ptr [esi + 4]
// 0060ec15  53                   push ebx
// 0060ec16  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0060ec1a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0060ec1e  8bd0                 mov edx, eax
// 0060ec20  88442413             mov byte ptr [esp + 0x13], al
// 0060ec24  8bc3                 mov eax, ebx
// 0060ec26  c1e908               shr ecx, 8
// 0060ec29  c1ea08               shr edx, 8
// 0060ec2c  c1e808               shr eax, 8
// 0060ec2f  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0060ec36  885c2415             mov byte ptr [esp + 0x15], bl
// 0060ec3a  884c2410             mov byte ptr [esp + 0x10], cl
// 0060ec3e  88542412             mov byte ptr [esp + 0x12], dl
// 0060ec42  88442414             mov byte ptr [esp + 0x14], al
// 0060ec46  5b                   pop ebx
// 0060ec47  7519                 jne 0x60ec62
// 0060ec49  0ac2                 or al, dl
// 0060ec4b  0ac1                 or al, cl
// 0060ec4d  7413                 je 0x60ec62
// 0060ec4f  68f0609c00           push 0x9c60f0
// 0060ec54  56                   push esi
// 0060ec55  e8e6150000           call 0x610240
// 0060ec5a  83c408               add esp, 8
// 0060ec5d  5e                   pop esi
// 0060ec5e  83c410               add esp, 0x10
// 0060ec61  c3                   ret 
// 0060ec62  6a06                 push 6
// 0060ec64  8d4c2410             lea ecx, [esp + 0x10]
// 0060ec68  51                   push ecx
// 0060ec69  8d54240c             lea edx, [esp + 0xc]
// 0060ec6d  52                   push edx
// 0060ec6e  56                   push esi
// 0060ec6f  e8fcedffff           call 0x60da70
// 0060ec74  83c410               add esp, 0x10
// 0060ec77  5e                   pop esi
// 0060ec78  83c410               add esp, 0x10
// 0060ec7b  c3                   ret 
// 0060ec7c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060ec80  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 0060ec86  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060ec8a  0fb74008             movzx eax, word ptr [eax + 8]
// 0060ec8e  be01000000           mov esi, 1
// 0060ec93  d3e6                 shl esi, cl
// 0060ec95  3bc6                 cmp eax, esi
// 0060ec97  7c13                 jl 0x60ecac
// 0060ec99  68b0609c00           push 0x9c60b0
// 0060ec9e  52                   push edx
// 0060ec9f  e89c150000           call 0x610240
// 0060eca4  83c408               add esp, 8
// 0060eca7  5e                   pop esi
// 0060eca8  83c410               add esp, 0x10
// 0060ecab  c3                   ret 
// 0060ecac  8bc8                 mov ecx, eax
// 0060ecae  c1e908               shr ecx, 8
// 0060ecb1  8844240d             mov byte ptr [esp + 0xd], al
// 0060ecb5  6a02                 push 2
// 0060ecb7  8d442410             lea eax, [esp + 0x10]
// 0060ecbb  884c2410             mov byte ptr [esp + 0x10], cl
// 0060ecbf  50                   push eax
// 0060ecc0  8d4c240c             lea ecx, [esp + 0xc]
// 0060ecc4  51                   push ecx
// 0060ecc5  52                   push edx
// 0060ecc6  e8a5edffff           call 0x60da70
// 0060eccb  83c410               add esp, 0x10
// 0060ecce  5e                   pop esi
// 0060eccf  83c410               add esp, 0x10
// 0060ecd2  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
