// from server: 100% by auto
// roc 2009-06 0058c9f0  unit: seg_00580000  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c9f0
//
// 0058c9f0  83ec10               sub esp, 0x10
// 0058c9f3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058c9f7  c6042474             mov byte ptr [esp], 0x74
// 0058c9fb  c644240152           mov byte ptr [esp + 1], 0x52
// 0058ca00  c64424024e           mov byte ptr [esp + 2], 0x4e
// 0058ca05  c644240353           mov byte ptr [esp + 3], 0x53
// 0058ca0a  c644240400           mov byte ptr [esp + 4], 0
// 0058ca0f  83f803               cmp eax, 3
// 0058ca12  7541                 jne 0x58ca55
// 0058ca14  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058ca18  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0058ca1c  85c0                 test eax, eax
// 0058ca1e  7e23                 jle 0x58ca43
// 0058ca20  0fb79118010000       movzx edx, word ptr [ecx + 0x118]
// 0058ca27  3bc2                 cmp eax, edx
// 0058ca29  7f18                 jg 0x58ca43
// 0058ca2b  50                   push eax
// 0058ca2c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058ca30  50                   push eax
// 0058ca31  8d542408             lea edx, [esp + 8]
// 0058ca35  52                   push edx
// 0058ca36  51                   push ecx
// 0058ca37  e8e4efffff           call 0x58ba20
// 0058ca3c  83c410               add esp, 0x10
// 0058ca3f  83c410               add esp, 0x10
// 0058ca42  c3                   ret 
// 0058ca43  68f0f18c00           push 0x8cf1f0
// 0058ca48  51                   push ecx
// 0058ca49  e8c2170000           call 0x58e210
// 0058ca4e  83c408               add esp, 8
// 0058ca51  83c410               add esp, 0x10
// 0058ca54  c3                   ret 
// 0058ca55  56                   push esi
// 0058ca56  85c0                 test eax, eax
// 0058ca58  7557                 jne 0x58cab1
// 0058ca5a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058ca5e  8a8a27010000         mov cl, byte ptr [edx + 0x127]
// 0058ca64  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058ca68  0fb74008             movzx eax, word ptr [eax + 8]
// 0058ca6c  be01000000           mov esi, 1
// 0058ca71  d3e6                 shl esi, cl
// 0058ca73  3bc6                 cmp eax, esi
// 0058ca75  7c13                 jl 0x58ca8a
// 0058ca77  68b0f18c00           push 0x8cf1b0
// 0058ca7c  52                   push edx
// 0058ca7d  e88e170000           call 0x58e210
// 0058ca82  83c408               add esp, 8
// 0058ca85  5e                   pop esi
// 0058ca86  83c410               add esp, 0x10
// 0058ca89  c3                   ret 
// 0058ca8a  8bc8                 mov ecx, eax
// 0058ca8c  c1e908               shr ecx, 8
// 0058ca8f  8844240d             mov byte ptr [esp + 0xd], al
// 0058ca93  6a02                 push 2
// 0058ca95  8d442410             lea eax, [esp + 0x10]
// 0058ca99  884c2410             mov byte ptr [esp + 0x10], cl
// 0058ca9d  50                   push eax
// 0058ca9e  8d4c240c             lea ecx, [esp + 0xc]
// 0058caa2  51                   push ecx
// 0058caa3  52                   push edx
// 0058caa4  e877efffff           call 0x58ba20
// 0058caa9  83c410               add esp, 0x10
// 0058caac  5e                   pop esi
// 0058caad  83c410               add esp, 0x10
// 0058cab0  c3                   ret 
// 0058cab1  83f802               cmp eax, 2
// 0058cab4  7579                 jne 0x58cb2f
// 0058cab6  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058caba  0fb74602             movzx eax, word ptr [esi + 2]
// 0058cabe  8bc8                 mov ecx, eax
// 0058cac0  8844240d             mov byte ptr [esp + 0xd], al
// 0058cac4  0fb74604             movzx eax, word ptr [esi + 4]
// 0058cac8  53                   push ebx
// 0058cac9  0fb75e06             movzx ebx, word ptr [esi + 6]
// 0058cacd  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0058cad1  8bd0                 mov edx, eax
// 0058cad3  88442413             mov byte ptr [esp + 0x13], al
// 0058cad7  8bc3                 mov eax, ebx
// 0058cad9  c1e908               shr ecx, 8
// 0058cadc  c1ea08               shr edx, 8
// 0058cadf  c1e808               shr eax, 8
// 0058cae2  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0058cae9  885c2415             mov byte ptr [esp + 0x15], bl
// 0058caed  884c2410             mov byte ptr [esp + 0x10], cl
// 0058caf1  88542412             mov byte ptr [esp + 0x12], dl
// 0058caf5  88442414             mov byte ptr [esp + 0x14], al
// 0058caf9  5b                   pop ebx
// 0058cafa  7519                 jne 0x58cb15
// 0058cafc  0ac2                 or al, dl
// 0058cafe  0ac1                 or al, cl
// 0058cb00  7413                 je 0x58cb15
// 0058cb02  6870f18c00           push 0x8cf170
// 0058cb07  56                   push esi
// 0058cb08  e803170000           call 0x58e210
// 0058cb0d  83c408               add esp, 8
// 0058cb10  5e                   pop esi
// 0058cb11  83c410               add esp, 0x10
// 0058cb14  c3                   ret 
// 0058cb15  6a06                 push 6
// 0058cb17  8d542410             lea edx, [esp + 0x10]
// 0058cb1b  52                   push edx
// 0058cb1c  8d44240c             lea eax, [esp + 0xc]
// 0058cb20  50                   push eax
// 0058cb21  56                   push esi
// 0058cb22  e8f9eeffff           call 0x58ba20
// 0058cb27  83c410               add esp, 0x10
// 0058cb2a  5e                   pop esi
// 0058cb2b  83c410               add esp, 0x10
// 0058cb2e  c3                   ret 
// 0058cb2f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0058cb33  6848f18c00           push 0x8cf148
// 0058cb38  51                   push ecx
// 0058cb39  e8d2160000           call 0x58e210
// 0058cb3e  83c408               add esp, 8
// 0058cb41  5e                   pop esi
// 0058cb42  83c410               add esp, 0x10
// 0058cb45  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
