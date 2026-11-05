// from server: 100% by auto
// roc 2009-06 0058cb50  unit: seg_00580000  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058cb50
//
// 0058cb50  83ec10               sub esp, 0x10
// 0058cb53  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058cb57  56                   push esi
// 0058cb58  c644240462           mov byte ptr [esp + 4], 0x62
// 0058cb5d  c64424054b           mov byte ptr [esp + 5], 0x4b
// 0058cb62  c644240647           mov byte ptr [esp + 6], 0x47
// 0058cb67  c644240744           mov byte ptr [esp + 7], 0x44
// 0058cb6c  c644240800           mov byte ptr [esp + 8], 0
// 0058cb71  83f803               cmp eax, 3
// 0058cb74  7559                 jne 0x58cbcf
// 0058cb76  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0058cb7a  0fb78118010000       movzx eax, word ptr [ecx + 0x118]
// 0058cb81  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0058cb85  6685c0               test ax, ax
// 0058cb88  7509                 jne 0x58cb93
// 0058cb8a  f6813002000001       test byte ptr [ecx + 0x230], 1
// 0058cb91  751c                 jne 0x58cbaf
// 0058cb93  660fb632             movzx si, byte ptr [edx]
// 0058cb97  663bf0               cmp si, ax
// 0058cb9a  7613                 jbe 0x58cbaf
// 0058cb9c  68a0f28c00           push 0x8cf2a0
// 0058cba1  51                   push ecx
// 0058cba2  e869160000           call 0x58e210
// 0058cba7  83c408               add esp, 8
// 0058cbaa  5e                   pop esi
// 0058cbab  83c410               add esp, 0x10
// 0058cbae  c3                   ret 
// 0058cbaf  8a02                 mov al, byte ptr [edx]
// 0058cbb1  6a01                 push 1
// 0058cbb3  8d542410             lea edx, [esp + 0x10]
// 0058cbb7  88442410             mov byte ptr [esp + 0x10], al
// 0058cbbb  52                   push edx
// 0058cbbc  8d44240c             lea eax, [esp + 0xc]
// 0058cbc0  50                   push eax
// 0058cbc1  51                   push ecx
// 0058cbc2  e859eeffff           call 0x58ba20
// 0058cbc7  83c410               add esp, 0x10
// 0058cbca  5e                   pop esi
// 0058cbcb  83c410               add esp, 0x10
// 0058cbce  c3                   ret 
// 0058cbcf  a802                 test al, 2
// 0058cbd1  7479                 je 0x58cc4c
// 0058cbd3  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0058cbd7  0fb74602             movzx eax, word ptr [esi + 2]
// 0058cbdb  8bc8                 mov ecx, eax
// 0058cbdd  8844240d             mov byte ptr [esp + 0xd], al
// 0058cbe1  0fb74604             movzx eax, word ptr [esi + 4]
// 0058cbe5  53                   push ebx
// 0058cbe6  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0058cbea  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0058cbee  8bd0                 mov edx, eax
// 0058cbf0  88442413             mov byte ptr [esp + 0x13], al
// 0058cbf4  8bc3                 mov eax, ebx
// 0058cbf6  c1e908               shr ecx, 8
// 0058cbf9  c1ea08               shr edx, 8
// 0058cbfc  c1e808               shr eax, 8
// 0058cbff  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0058cc06  885c2415             mov byte ptr [esp + 0x15], bl
// 0058cc0a  884c2410             mov byte ptr [esp + 0x10], cl
// 0058cc0e  88542412             mov byte ptr [esp + 0x12], dl
// 0058cc12  88442414             mov byte ptr [esp + 0x14], al
// 0058cc16  5b                   pop ebx
// 0058cc17  7519                 jne 0x58cc32
// 0058cc19  0ac2                 or al, dl
// 0058cc1b  0ac1                 or al, cl
// 0058cc1d  7413                 je 0x58cc32
// 0058cc1f  6860f28c00           push 0x8cf260
// 0058cc24  56                   push esi
// 0058cc25  e8e6150000           call 0x58e210
// 0058cc2a  83c408               add esp, 8
// 0058cc2d  5e                   pop esi
// 0058cc2e  83c410               add esp, 0x10
// 0058cc31  c3                   ret 
// 0058cc32  6a06                 push 6
// 0058cc34  8d4c2410             lea ecx, [esp + 0x10]
// 0058cc38  51                   push ecx
// 0058cc39  8d54240c             lea edx, [esp + 0xc]
// 0058cc3d  52                   push edx
// 0058cc3e  56                   push esi
// 0058cc3f  e8dcedffff           call 0x58ba20
// 0058cc44  83c410               add esp, 0x10
// 0058cc47  5e                   pop esi
// 0058cc48  83c410               add esp, 0x10
// 0058cc4b  c3                   ret 
// 0058cc4c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058cc50  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 0058cc56  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058cc5a  0fb74008             movzx eax, word ptr [eax + 8]
// 0058cc5e  be01000000           mov esi, 1
// 0058cc63  d3e6                 shl esi, cl
// 0058cc65  3bc6                 cmp eax, esi
// 0058cc67  7c13                 jl 0x58cc7c
// 0058cc69  6820f28c00           push 0x8cf220
// 0058cc6e  52                   push edx
// 0058cc6f  e89c150000           call 0x58e210
// 0058cc74  83c408               add esp, 8
// 0058cc77  5e                   pop esi
// 0058cc78  83c410               add esp, 0x10
// 0058cc7b  c3                   ret 
// 0058cc7c  8bc8                 mov ecx, eax
// 0058cc7e  c1e908               shr ecx, 8
// 0058cc81  8844240d             mov byte ptr [esp + 0xd], al
// 0058cc85  6a02                 push 2
// 0058cc87  8d442410             lea eax, [esp + 0x10]
// 0058cc8b  884c2410             mov byte ptr [esp + 0x10], cl
// 0058cc8f  50                   push eax
// 0058cc90  8d4c240c             lea ecx, [esp + 0xc]
// 0058cc94  51                   push ecx
// 0058cc95  52                   push edx
// 0058cc96  e885edffff           call 0x58ba20
// 0058cc9b  83c410               add esp, 0x10
// 0058cc9e  5e                   pop esi
// 0058cc9f  83c410               add esp, 0x10
// 0058cca2  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
