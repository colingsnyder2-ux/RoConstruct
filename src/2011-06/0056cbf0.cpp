// from server: 100% by auto
// roc 2011-06 0056cbf0  unit: seg_00560000  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056cbf0
//
// 0056cbf0  83ec10               sub esp, 0x10
// 0056cbf3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056cbf7  56                   push esi
// 0056cbf8  c644240462           mov byte ptr [esp + 4], 0x62
// 0056cbfd  c64424054b           mov byte ptr [esp + 5], 0x4b
// 0056cc02  c644240647           mov byte ptr [esp + 6], 0x47
// 0056cc07  c644240744           mov byte ptr [esp + 7], 0x44
// 0056cc0c  c644240800           mov byte ptr [esp + 8], 0
// 0056cc11  83f803               cmp eax, 3
// 0056cc14  7559                 jne 0x56cc6f
// 0056cc16  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056cc1a  0fb78118010000       movzx eax, word ptr [ecx + 0x118]
// 0056cc21  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0056cc25  6685c0               test ax, ax
// 0056cc28  7509                 jne 0x56cc33
// 0056cc2a  f6813002000001       test byte ptr [ecx + 0x230], 1
// 0056cc31  751c                 jne 0x56cc4f
// 0056cc33  660fb632             movzx si, byte ptr [edx]
// 0056cc37  663bf0               cmp si, ax
// 0056cc3a  7213                 jb 0x56cc4f
// 0056cc3c  687861a800           push 0xa86178
// 0056cc41  51                   push ecx
// 0056cc42  e89947ffff           call 0x5613e0
// 0056cc47  83c408               add esp, 8
// 0056cc4a  5e                   pop esi
// 0056cc4b  83c410               add esp, 0x10
// 0056cc4e  c3                   ret 
// 0056cc4f  8a02                 mov al, byte ptr [edx]
// 0056cc51  6a01                 push 1
// 0056cc53  8d542410             lea edx, [esp + 0x10]
// 0056cc57  88442410             mov byte ptr [esp + 0x10], al
// 0056cc5b  52                   push edx
// 0056cc5c  8d44240c             lea eax, [esp + 0xc]
// 0056cc60  50                   push eax
// 0056cc61  51                   push ecx
// 0056cc62  e8a9eeffff           call 0x56bb10
// 0056cc67  83c410               add esp, 0x10
// 0056cc6a  5e                   pop esi
// 0056cc6b  83c410               add esp, 0x10
// 0056cc6e  c3                   ret 
// 0056cc6f  a802                 test al, 2
// 0056cc71  7479                 je 0x56ccec
// 0056cc73  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0056cc77  0fb74602             movzx eax, word ptr [esi + 2]
// 0056cc7b  8bc8                 mov ecx, eax
// 0056cc7d  8844240d             mov byte ptr [esp + 0xd], al
// 0056cc81  0fb74604             movzx eax, word ptr [esi + 4]
// 0056cc85  53                   push ebx
// 0056cc86  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0056cc8a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0056cc8e  8bd0                 mov edx, eax
// 0056cc90  88442413             mov byte ptr [esp + 0x13], al
// 0056cc94  8bc3                 mov eax, ebx
// 0056cc96  c1e908               shr ecx, 8
// 0056cc99  c1ea08               shr edx, 8
// 0056cc9c  c1e808               shr eax, 8
// 0056cc9f  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0056cca6  885c2415             mov byte ptr [esp + 0x15], bl
// 0056ccaa  884c2410             mov byte ptr [esp + 0x10], cl
// 0056ccae  88542412             mov byte ptr [esp + 0x12], dl
// 0056ccb2  88442414             mov byte ptr [esp + 0x14], al
// 0056ccb6  5b                   pop ebx
// 0056ccb7  7519                 jne 0x56ccd2
// 0056ccb9  0ac2                 or al, dl
// 0056ccbb  0ac1                 or al, cl
// 0056ccbd  7413                 je 0x56ccd2
// 0056ccbf  683861a800           push 0xa86138
// 0056ccc4  56                   push esi
// 0056ccc5  e81647ffff           call 0x5613e0
// 0056ccca  83c408               add esp, 8
// 0056cccd  5e                   pop esi
// 0056ccce  83c410               add esp, 0x10
// 0056ccd1  c3                   ret 
// 0056ccd2  6a06                 push 6
// 0056ccd4  8d4c2410             lea ecx, [esp + 0x10]
// 0056ccd8  51                   push ecx
// 0056ccd9  8d54240c             lea edx, [esp + 0xc]
// 0056ccdd  52                   push edx
// 0056ccde  56                   push esi
// 0056ccdf  e82ceeffff           call 0x56bb10
// 0056cce4  83c410               add esp, 0x10
// 0056cce7  5e                   pop esi
// 0056cce8  83c410               add esp, 0x10
// 0056cceb  c3                   ret 
// 0056ccec  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056ccf0  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 0056ccf6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056ccfa  0fb74008             movzx eax, word ptr [eax + 8]
// 0056ccfe  be01000000           mov esi, 1
// 0056cd03  d3e6                 shl esi, cl
// 0056cd05  3bc6                 cmp eax, esi
// 0056cd07  7c13                 jl 0x56cd1c
// 0056cd09  68f860a800           push 0xa860f8
// 0056cd0e  52                   push edx
// 0056cd0f  e8cc46ffff           call 0x5613e0
// 0056cd14  83c408               add esp, 8
// 0056cd17  5e                   pop esi
// 0056cd18  83c410               add esp, 0x10
// 0056cd1b  c3                   ret 
// 0056cd1c  8bc8                 mov ecx, eax
// 0056cd1e  c1e908               shr ecx, 8
// 0056cd21  8844240d             mov byte ptr [esp + 0xd], al
// 0056cd25  6a02                 push 2
// 0056cd27  8d442410             lea eax, [esp + 0x10]
// 0056cd2b  884c2410             mov byte ptr [esp + 0x10], cl
// 0056cd2f  50                   push eax
// 0056cd30  8d4c240c             lea ecx, [esp + 0xc]
// 0056cd34  51                   push ecx
// 0056cd35  52                   push edx
// 0056cd36  e8d5edffff           call 0x56bb10
// 0056cd3b  83c410               add esp, 0x10
// 0056cd3e  5e                   pop esi
// 0056cd3f  83c410               add esp, 0x10
// 0056cd42  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
