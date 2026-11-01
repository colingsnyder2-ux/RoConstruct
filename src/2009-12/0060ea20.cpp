// from server: 100% by auto
// roc 2009-12 0060ea20  unit: seg_00600000  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060ea20
//
// 0060ea20  83ec10               sub esp, 0x10
// 0060ea23  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060ea27  c6042474             mov byte ptr [esp], 0x74
// 0060ea2b  c644240152           mov byte ptr [esp + 1], 0x52
// 0060ea30  c64424024e           mov byte ptr [esp + 2], 0x4e
// 0060ea35  c644240353           mov byte ptr [esp + 3], 0x53
// 0060ea3a  c644240400           mov byte ptr [esp + 4], 0
// 0060ea3f  83f803               cmp eax, 3
// 0060ea42  7541                 jne 0x60ea85
// 0060ea44  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060ea48  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060ea4c  85c0                 test eax, eax
// 0060ea4e  7e23                 jle 0x60ea73
// 0060ea50  0fb79118010000       movzx edx, word ptr [ecx + 0x118]
// 0060ea57  3bc2                 cmp eax, edx
// 0060ea59  7f18                 jg 0x60ea73
// 0060ea5b  50                   push eax
// 0060ea5c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060ea60  50                   push eax
// 0060ea61  8d542408             lea edx, [esp + 8]
// 0060ea65  52                   push edx
// 0060ea66  51                   push ecx
// 0060ea67  e804f0ffff           call 0x60da70
// 0060ea6c  83c410               add esp, 0x10
// 0060ea6f  83c410               add esp, 0x10
// 0060ea72  c3                   ret 
// 0060ea73  6880609c00           push 0x9c6080
// 0060ea78  51                   push ecx
// 0060ea79  e8c2170000           call 0x610240
// 0060ea7e  83c408               add esp, 8
// 0060ea81  83c410               add esp, 0x10
// 0060ea84  c3                   ret 
// 0060ea85  56                   push esi
// 0060ea86  85c0                 test eax, eax
// 0060ea88  7557                 jne 0x60eae1
// 0060ea8a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060ea8e  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 0060ea94  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060ea98  0fb74008             movzx eax, word ptr [eax + 8]
// 0060ea9c  be01000000           mov esi, 1
// 0060eaa1  d3e6                 shl esi, cl
// 0060eaa3  3bc6                 cmp eax, esi
// 0060eaa5  7c13                 jl 0x60eaba
// 0060eaa7  6840609c00           push 0x9c6040
// 0060eaac  52                   push edx
// 0060eaad  e88e170000           call 0x610240
// 0060eab2  83c408               add esp, 8
// 0060eab5  5e                   pop esi
// 0060eab6  83c410               add esp, 0x10
// 0060eab9  c3                   ret 
// 0060eaba  8bc8                 mov ecx, eax
// 0060eabc  c1e908               shr ecx, 8
// 0060eabf  8844240d             mov byte ptr [esp + 0xd], al
// 0060eac3  6a02                 push 2
// 0060eac5  8d442410             lea eax, [esp + 0x10]
// 0060eac9  884c2410             mov byte ptr [esp + 0x10], cl
// 0060eacd  50                   push eax
// 0060eace  8d4c240c             lea ecx, [esp + 0xc]
// 0060ead2  51                   push ecx
// 0060ead3  52                   push edx
// 0060ead4  e897efffff           call 0x60da70
// 0060ead9  83c410               add esp, 0x10
// 0060eadc  5e                   pop esi
// 0060eadd  83c410               add esp, 0x10
// 0060eae0  c3                   ret 
// 0060eae1  83f802               cmp eax, 2
// 0060eae4  7579                 jne 0x60eb5f
// 0060eae6  8b742420             mov esi, dword ptr [esp + 0x20]
// 0060eaea  0fb74602             movzx eax, word ptr [esi + 2]
// 0060eaee  8bc8                 mov ecx, eax
// 0060eaf0  8844240d             mov byte ptr [esp + 0xd], al
// 0060eaf4  0fb74604             movzx eax, word ptr [esi + 4]
// 0060eaf8  53                   push ebx
// 0060eaf9  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0060eafd  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0060eb01  8bd0                 mov edx, eax
// 0060eb03  88442413             mov byte ptr [esp + 0x13], al
// 0060eb07  8bc3                 mov eax, ebx
// 0060eb09  c1e908               shr ecx, 8
// 0060eb0c  c1ea08               shr edx, 8
// 0060eb0f  c1e808               shr eax, 8
// 0060eb12  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0060eb19  885c2415             mov byte ptr [esp + 0x15], bl
// 0060eb1d  884c2410             mov byte ptr [esp + 0x10], cl
// 0060eb21  88542412             mov byte ptr [esp + 0x12], dl
// 0060eb25  88442414             mov byte ptr [esp + 0x14], al
// 0060eb29  5b                   pop ebx
// 0060eb2a  7519                 jne 0x60eb45
// 0060eb2c  0ac2                 or al, dl
// 0060eb2e  0ac1                 or al, cl
// 0060eb30  7413                 je 0x60eb45
// 0060eb32  6800609c00           push 0x9c6000
// 0060eb37  56                   push esi
// 0060eb38  e803170000           call 0x610240
// 0060eb3d  83c408               add esp, 8
// 0060eb40  5e                   pop esi
// 0060eb41  83c410               add esp, 0x10
// 0060eb44  c3                   ret 
// 0060eb45  6a06                 push 6
// 0060eb47  8d542410             lea edx, [esp + 0x10]
// 0060eb4b  52                   push edx
// 0060eb4c  8d44240c             lea eax, [esp + 0xc]
// 0060eb50  50                   push eax
// 0060eb51  56                   push esi
// 0060eb52  e819efffff           call 0x60da70
// 0060eb57  83c410               add esp, 0x10
// 0060eb5a  5e                   pop esi
// 0060eb5b  83c410               add esp, 0x10
// 0060eb5e  c3                   ret 
// 0060eb5f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060eb63  68d45f9c00           push 0x9c5fd4
// 0060eb68  51                   push ecx
// 0060eb69  e8d2160000           call 0x610240
// 0060eb6e  83c408               add esp, 8
// 0060eb71  5e                   pop esi
// 0060eb72  83c410               add esp, 0x10
// 0060eb75  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
