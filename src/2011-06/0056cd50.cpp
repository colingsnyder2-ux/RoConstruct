// from server: 100% by auto
// roc 2011-06 0056cd50  unit: seg_00560000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056cd50
//
// 0056cd50  83ec14               sub esp, 0x14
// 0056cd53  53                   push ebx
// 0056cd54  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056cd58  83fb02               cmp ebx, 2
// 0056cd5b  b046                 mov al, 0x46
// 0056cd5d  56                   push esi
// 0056cd5e  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056cd62  c64424086f           mov byte ptr [esp + 8], 0x6f
// 0056cd67  88442409             mov byte ptr [esp + 9], al
// 0056cd6b  8844240a             mov byte ptr [esp + 0xa], al
// 0056cd6f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 0056cd74  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056cd79  7c0e                 jl 0x56cd89
// 0056cd7b  689c61a800           push 0xa8619c
// 0056cd80  56                   push esi
// 0056cd81  e85a46ffff           call 0x5613e0
// 0056cd86  83c408               add esp, 8
// 0056cd89  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056cd8d  8bc8                 mov ecx, eax
// 0056cd8f  c1f918               sar ecx, 0x18
// 0056cd92  884c2410             mov byte ptr [esp + 0x10], cl
// 0056cd96  8bd0                 mov edx, eax
// 0056cd98  c1fa10               sar edx, 0x10
// 0056cd9b  88542411             mov byte ptr [esp + 0x11], dl
// 0056cd9f  8bc8                 mov ecx, eax
// 0056cda1  88442413             mov byte ptr [esp + 0x13], al
// 0056cda5  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056cda9  c1f908               sar ecx, 8
// 0056cdac  8bd0                 mov edx, eax
// 0056cdae  c1fa18               sar edx, 0x18
// 0056cdb1  884c2412             mov byte ptr [esp + 0x12], cl
// 0056cdb5  88542414             mov byte ptr [esp + 0x14], dl
// 0056cdb9  8bc8                 mov ecx, eax
// 0056cdbb  8bd0                 mov edx, eax
// 0056cdbd  c1f910               sar ecx, 0x10
// 0056cdc0  c1fa08               sar edx, 8
// 0056cdc3  884c2415             mov byte ptr [esp + 0x15], cl
// 0056cdc7  88542416             mov byte ptr [esp + 0x16], dl
// 0056cdcb  88442417             mov byte ptr [esp + 0x17], al
// 0056cdcf  885c2418             mov byte ptr [esp + 0x18], bl
// 0056cdd3  85f6                 test esi, esi
// 0056cdd5  745c                 je 0x56ce33
// 0056cdd7  6a09                 push 9
// 0056cdd9  8d44240c             lea eax, [esp + 0xc]
// 0056cddd  50                   push eax
// 0056cdde  56                   push esi
// 0056cddf  e8ccdbffff           call 0x56a9b0
// 0056cde4  6a09                 push 9
// 0056cde6  8d4c2420             lea ecx, [esp + 0x20]
// 0056cdea  51                   push ecx
// 0056cdeb  56                   push esi
// 0056cdec  e84fdafeff           call 0x55a840
// 0056cdf1  6a09                 push 9
// 0056cdf3  8d54242c             lea edx, [esp + 0x2c]
// 0056cdf7  52                   push edx
// 0056cdf8  56                   push esi
// 0056cdf9  e8523afeff           call 0x550850
// 0056cdfe  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056ce04  8bd0                 mov edx, eax
// 0056ce06  8bc8                 mov ecx, eax
// 0056ce08  c1e918               shr ecx, 0x18
// 0056ce0b  c1ea10               shr edx, 0x10
// 0056ce0e  884c2450             mov byte ptr [esp + 0x50], cl
// 0056ce12  88542451             mov byte ptr [esp + 0x51], dl
// 0056ce16  6a04                 push 4
// 0056ce18  8d542454             lea edx, [esp + 0x54]
// 0056ce1c  8bc8                 mov ecx, eax
// 0056ce1e  52                   push edx
// 0056ce1f  c1e908               shr ecx, 8
// 0056ce22  56                   push esi
// 0056ce23  884c245e             mov byte ptr [esp + 0x5e], cl
// 0056ce27  8844245f             mov byte ptr [esp + 0x5f], al
// 0056ce2b  e810dafeff           call 0x55a840
// 0056ce30  83c430               add esp, 0x30
// 0056ce33  5e                   pop esi
// 0056ce34  5b                   pop ebx
// 0056ce35  83c414               add esp, 0x14
// 0056ce38  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_oFFs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
