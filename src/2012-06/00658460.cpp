// from server: 100% by auto
// roc 2012-06 00658460  unit: seg_00650000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00658460
//
// 00658460  83ec14               sub esp, 0x14
// 00658463  53                   push ebx
// 00658464  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00658468  83fb02               cmp ebx, 2
// 0065846b  b046                 mov al, 0x46
// 0065846d  56                   push esi
// 0065846e  8b742420             mov esi, dword ptr [esp + 0x20]
// 00658472  c64424086f           mov byte ptr [esp + 8], 0x6f
// 00658477  88442409             mov byte ptr [esp + 9], al
// 0065847b  8844240a             mov byte ptr [esp + 0xa], al
// 0065847f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 00658484  c644240c00           mov byte ptr [esp + 0xc], 0
// 00658489  7c0e                 jl 0x658499
// 0065848b  68ec9fb800           push 0xb89fec
// 00658490  56                   push esi
// 00658491  e8ca5dffff           call 0x64e260
// 00658496  83c408               add esp, 8
// 00658499  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065849d  8bc8                 mov ecx, eax
// 0065849f  c1f918               sar ecx, 0x18
// 006584a2  884c2410             mov byte ptr [esp + 0x10], cl
// 006584a6  8bd0                 mov edx, eax
// 006584a8  c1fa10               sar edx, 0x10
// 006584ab  88542411             mov byte ptr [esp + 0x11], dl
// 006584af  8bc8                 mov ecx, eax
// 006584b1  88442413             mov byte ptr [esp + 0x13], al
// 006584b5  8b442428             mov eax, dword ptr [esp + 0x28]
// 006584b9  c1f908               sar ecx, 8
// 006584bc  8bd0                 mov edx, eax
// 006584be  c1fa18               sar edx, 0x18
// 006584c1  884c2412             mov byte ptr [esp + 0x12], cl
// 006584c5  88542414             mov byte ptr [esp + 0x14], dl
// 006584c9  8bc8                 mov ecx, eax
// 006584cb  8bd0                 mov edx, eax
// 006584cd  c1f910               sar ecx, 0x10
// 006584d0  c1fa08               sar edx, 8
// 006584d3  884c2415             mov byte ptr [esp + 0x15], cl
// 006584d7  88542416             mov byte ptr [esp + 0x16], dl
// 006584db  88442417             mov byte ptr [esp + 0x17], al
// 006584df  885c2418             mov byte ptr [esp + 0x18], bl
// 006584e3  85f6                 test esi, esi
// 006584e5  745c                 je 0x658543
// 006584e7  6a09                 push 9
// 006584e9  8d44240c             lea eax, [esp + 0xc]
// 006584ed  50                   push eax
// 006584ee  56                   push esi
// 006584ef  e8ccdbffff           call 0x6560c0
// 006584f4  6a09                 push 9
// 006584f6  8d4c2420             lea ecx, [esp + 0x20]
// 006584fa  51                   push ecx
// 006584fb  56                   push esi
// 006584fc  e8bff1feff           call 0x6476c0
// 00658501  6a09                 push 9
// 00658503  8d54242c             lea edx, [esp + 0x2c]
// 00658507  52                   push edx
// 00658508  56                   push esi
// 00658509  e88259feff           call 0x63de90
// 0065850e  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00658514  8bd0                 mov edx, eax
// 00658516  8bc8                 mov ecx, eax
// 00658518  c1e918               shr ecx, 0x18
// 0065851b  c1ea10               shr edx, 0x10
// 0065851e  884c2450             mov byte ptr [esp + 0x50], cl
// 00658522  88542451             mov byte ptr [esp + 0x51], dl
// 00658526  6a04                 push 4
// 00658528  8d542454             lea edx, [esp + 0x54]
// 0065852c  8bc8                 mov ecx, eax
// 0065852e  52                   push edx
// 0065852f  c1e908               shr ecx, 8
// 00658532  56                   push esi
// 00658533  884c245e             mov byte ptr [esp + 0x5e], cl
// 00658537  8844245f             mov byte ptr [esp + 0x5f], al
// 0065853b  e880f1feff           call 0x6476c0
// 00658540  83c430               add esp, 0x30
// 00658543  5e                   pop esi
// 00658544  5b                   pop ebx
// 00658545  83c414               add esp, 0x14
// 00658548  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_oFFs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
