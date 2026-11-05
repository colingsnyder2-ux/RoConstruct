// from server: 100% by auto
// roc 2009-06 0058ccb0  unit: seg_00580000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ccb0
//
// 0058ccb0  83ec14               sub esp, 0x14
// 0058ccb3  53                   push ebx
// 0058ccb4  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0058ccb8  83fb02               cmp ebx, 2
// 0058ccbb  b046                 mov al, 0x46
// 0058ccbd  56                   push esi
// 0058ccbe  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058ccc2  c64424086f           mov byte ptr [esp + 8], 0x6f
// 0058ccc7  88442409             mov byte ptr [esp + 9], al
// 0058cccb  8844240a             mov byte ptr [esp + 0xa], al
// 0058cccf  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 0058ccd4  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058ccd9  7c0e                 jl 0x58cce9
// 0058ccdb  68c4f28c00           push 0x8cf2c4
// 0058cce0  56                   push esi
// 0058cce1  e82a150000           call 0x58e210
// 0058cce6  83c408               add esp, 8
// 0058cce9  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058cced  8bc8                 mov ecx, eax
// 0058ccef  c1f918               sar ecx, 0x18
// 0058ccf2  884c2410             mov byte ptr [esp + 0x10], cl
// 0058ccf6  8bd0                 mov edx, eax
// 0058ccf8  c1fa10               sar edx, 0x10
// 0058ccfb  88542411             mov byte ptr [esp + 0x11], dl
// 0058ccff  8bc8                 mov ecx, eax
// 0058cd01  88442413             mov byte ptr [esp + 0x13], al
// 0058cd05  8b442428             mov eax, dword ptr [esp + 0x28]
// 0058cd09  c1f908               sar ecx, 8
// 0058cd0c  8bd0                 mov edx, eax
// 0058cd0e  c1fa18               sar edx, 0x18
// 0058cd11  884c2412             mov byte ptr [esp + 0x12], cl
// 0058cd15  88542414             mov byte ptr [esp + 0x14], dl
// 0058cd19  8bc8                 mov ecx, eax
// 0058cd1b  8bd0                 mov edx, eax
// 0058cd1d  c1f910               sar ecx, 0x10
// 0058cd20  c1fa08               sar edx, 8
// 0058cd23  884c2415             mov byte ptr [esp + 0x15], cl
// 0058cd27  88542416             mov byte ptr [esp + 0x16], dl
// 0058cd2b  88442417             mov byte ptr [esp + 0x17], al
// 0058cd2f  885c2418             mov byte ptr [esp + 0x18], bl
// 0058cd33  85f6                 test esi, esi
// 0058cd35  745c                 je 0x58cd93
// 0058cd37  6a09                 push 9
// 0058cd39  8d44240c             lea eax, [esp + 0xc]
// 0058cd3d  50                   push eax
// 0058cd3e  56                   push esi
// 0058cd3f  e87cdbffff           call 0x58a8c0
// 0058cd44  6a09                 push 9
// 0058cd46  8d4c2420             lea ecx, [esp + 0x20]
// 0058cd4a  51                   push ecx
// 0058cd4b  56                   push esi
// 0058cd4c  e88f48ffff           call 0x5815e0
// 0058cd51  6a09                 push 9
// 0058cd53  8d54242c             lea edx, [esp + 0x2c]
// 0058cd57  52                   push edx
// 0058cd58  56                   push esi
// 0058cd59  e8624bffff           call 0x5818c0
// 0058cd5e  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058cd64  8bd0                 mov edx, eax
// 0058cd66  8bc8                 mov ecx, eax
// 0058cd68  c1e918               shr ecx, 0x18
// 0058cd6b  c1ea10               shr edx, 0x10
// 0058cd6e  884c2450             mov byte ptr [esp + 0x50], cl
// 0058cd72  88542451             mov byte ptr [esp + 0x51], dl
// 0058cd76  6a04                 push 4
// 0058cd78  8d542454             lea edx, [esp + 0x54]
// 0058cd7c  8bc8                 mov ecx, eax
// 0058cd7e  52                   push edx
// 0058cd7f  c1e908               shr ecx, 8
// 0058cd82  56                   push esi
// 0058cd83  884c245e             mov byte ptr [esp + 0x5e], cl
// 0058cd87  8844245f             mov byte ptr [esp + 0x5f], al
// 0058cd8b  e85048ffff           call 0x5815e0
// 0058cd90  83c430               add esp, 0x30
// 0058cd93  5e                   pop esi
// 0058cd94  5b                   pop ebx
// 0058cd95  83c414               add esp, 0x14
// 0058cd98  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_oFFs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
