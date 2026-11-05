// from server: 100% by auto
// roc 2010-06 005704a0  unit: G3D::LineSegment  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005704a0
//
// 005704a0  83ec10               sub esp, 0x10
// 005704a3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005704a7  56                   push esi
// 005704a8  c644240462           mov byte ptr [esp + 4], 0x62
// 005704ad  c64424054b           mov byte ptr [esp + 5], 0x4b
// 005704b2  c644240647           mov byte ptr [esp + 6], 0x47
// 005704b7  c644240744           mov byte ptr [esp + 7], 0x44
// 005704bc  c644240800           mov byte ptr [esp + 8], 0
// 005704c1  83f803               cmp eax, 3
// 005704c4  7559                 jne 0x57051f
// 005704c6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005704ca  0fb78118010000       movzx eax, word ptr [ecx + 0x118]
// 005704d1  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005704d5  6685c0               test ax, ax
// 005704d8  7509                 jne 0x5704e3
// 005704da  f6813002000001       test byte ptr [ecx + 0x230], 1
// 005704e1  751c                 jne 0x5704ff
// 005704e3  660fb632             movzx si, byte ptr [edx]
// 005704e7  663bf0               cmp si, ax
// 005704ea  7613                 jbe 0x5704ff
// 005704ec  68a83ea200           push 0xa23ea8
// 005704f1  51                   push ecx
// 005704f2  e869160000           call 0x571b60
// 005704f7  83c408               add esp, 8
// 005704fa  5e                   pop esi
// 005704fb  83c410               add esp, 0x10
// 005704fe  c3                   ret 
// 005704ff  8a02                 mov al, byte ptr [edx]
// 00570501  6a01                 push 1
// 00570503  8d542410             lea edx, [esp + 0x10]
// 00570507  88442410             mov byte ptr [esp + 0x10], al
// 0057050b  52                   push edx
// 0057050c  8d44240c             lea eax, [esp + 0xc]
// 00570510  50                   push eax
// 00570511  51                   push ecx
// 00570512  e879eeffff           call 0x56f390
// 00570517  83c410               add esp, 0x10
// 0057051a  5e                   pop esi
// 0057051b  83c410               add esp, 0x10
// 0057051e  c3                   ret 
// 0057051f  a802                 test al, 2
// 00570521  7479                 je 0x57059c
// 00570523  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00570527  0fb74602             movzx eax, word ptr [esi + 2]
// 0057052b  8bc8                 mov ecx, eax
// 0057052d  8844240d             mov byte ptr [esp + 0xd], al
// 00570531  0fb74604             movzx eax, word ptr [esi + 4]
// 00570535  53                   push ebx
// 00570536  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0057053a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0057053e  8bd0                 mov edx, eax
// 00570540  88442413             mov byte ptr [esp + 0x13], al
// 00570544  8bc3                 mov eax, ebx
// 00570546  c1e908               shr ecx, 8
// 00570549  c1ea08               shr edx, 8
// 0057054c  c1e808               shr eax, 8
// 0057054f  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 00570556  885c2415             mov byte ptr [esp + 0x15], bl
// 0057055a  884c2410             mov byte ptr [esp + 0x10], cl
// 0057055e  88542412             mov byte ptr [esp + 0x12], dl
// 00570562  88442414             mov byte ptr [esp + 0x14], al
// 00570566  5b                   pop ebx
// 00570567  7519                 jne 0x570582
// 00570569  0ac2                 or al, dl
// 0057056b  0ac1                 or al, cl
// 0057056d  7413                 je 0x570582
// 0057056f  68683ea200           push 0xa23e68
// 00570574  56                   push esi
// 00570575  e8e6150000           call 0x571b60
// 0057057a  83c408               add esp, 8
// 0057057d  5e                   pop esi
// 0057057e  83c410               add esp, 0x10
// 00570581  c3                   ret 
// 00570582  6a06                 push 6
// 00570584  8d4c2410             lea ecx, [esp + 0x10]
// 00570588  51                   push ecx
// 00570589  8d54240c             lea edx, [esp + 0xc]
// 0057058d  52                   push edx
// 0057058e  56                   push esi
// 0057058f  e8fcedffff           call 0x56f390
// 00570594  83c410               add esp, 0x10
// 00570597  5e                   pop esi
// 00570598  83c410               add esp, 0x10
// 0057059b  c3                   ret 
// 0057059c  8b542418             mov edx, dword ptr [esp + 0x18]
// 005705a0  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 005705a6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005705aa  0fb74008             movzx eax, word ptr [eax + 8]
// 005705ae  be01000000           mov esi, 1
// 005705b3  d3e6                 shl esi, cl
// 005705b5  3bc6                 cmp eax, esi
// 005705b7  7c13                 jl 0x5705cc
// 005705b9  68283ea200           push 0xa23e28
// 005705be  52                   push edx
// 005705bf  e89c150000           call 0x571b60
// 005705c4  83c408               add esp, 8
// 005705c7  5e                   pop esi
// 005705c8  83c410               add esp, 0x10
// 005705cb  c3                   ret 
// 005705cc  8bc8                 mov ecx, eax
// 005705ce  c1e908               shr ecx, 8
// 005705d1  8844240d             mov byte ptr [esp + 0xd], al
// 005705d5  6a02                 push 2
// 005705d7  8d442410             lea eax, [esp + 0x10]
// 005705db  884c2410             mov byte ptr [esp + 0x10], cl
// 005705df  50                   push eax
// 005705e0  8d4c240c             lea ecx, [esp + 0xc]
// 005705e4  51                   push ecx
// 005705e5  52                   push edx
// 005705e6  e8a5edffff           call 0x56f390
// 005705eb  83c410               add esp, 0x10
// 005705ee  5e                   pop esi
// 005705ef  83c410               add esp, 0x10
// 005705f2  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
