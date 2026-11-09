// from server: 100% by auto
// roc 2009-12 0060ece0  unit: seg_00600000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060ece0
//
// 0060ece0  83ec14               sub esp, 0x14
// 0060ece3  53                   push ebx
// 0060ece4  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0060ece8  83fb02               cmp ebx, 2
// 0060eceb  b046                 mov al, 0x46
// 0060eced  56                   push esi
// 0060ecee  8b742420             mov esi, dword ptr [esp + 0x20]
// 0060ecf2  c64424086f           mov byte ptr [esp + 8], 0x6f
// 0060ecf7  88442409             mov byte ptr [esp + 9], al
// 0060ecfb  8844240a             mov byte ptr [esp + 0xa], al
// 0060ecff  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 0060ed04  c644240c00           mov byte ptr [esp + 0xc], 0
// 0060ed09  7c0e                 jl 0x60ed19
// 0060ed0b  6854619c00           push 0x9c6154
// 0060ed10  56                   push esi
// 0060ed11  e82a150000           call 0x610240
// 0060ed16  83c408               add esp, 8
// 0060ed19  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060ed1d  8bc8                 mov ecx, eax
// 0060ed1f  c1f918               sar ecx, 0x18
// 0060ed22  884c2410             mov byte ptr [esp + 0x10], cl
// 0060ed26  8bd0                 mov edx, eax
// 0060ed28  c1fa10               sar edx, 0x10
// 0060ed2b  88542411             mov byte ptr [esp + 0x11], dl
// 0060ed2f  8bc8                 mov ecx, eax
// 0060ed31  88442413             mov byte ptr [esp + 0x13], al
// 0060ed35  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060ed39  c1f908               sar ecx, 8
// 0060ed3c  8bd0                 mov edx, eax
// 0060ed3e  c1fa18               sar edx, 0x18
// 0060ed41  884c2412             mov byte ptr [esp + 0x12], cl
// 0060ed45  88542414             mov byte ptr [esp + 0x14], dl
// 0060ed49  8bc8                 mov ecx, eax
// 0060ed4b  8bd0                 mov edx, eax
// 0060ed4d  c1f910               sar ecx, 0x10
// 0060ed50  c1fa08               sar edx, 8
// 0060ed53  884c2415             mov byte ptr [esp + 0x15], cl
// 0060ed57  88542416             mov byte ptr [esp + 0x16], dl
// 0060ed5b  88442417             mov byte ptr [esp + 0x17], al
// 0060ed5f  885c2418             mov byte ptr [esp + 0x18], bl
// 0060ed63  85f6                 test esi, esi
// 0060ed65  745c                 je 0x60edc3
// 0060ed67  6a09                 push 9
// 0060ed69  8d44240c             lea eax, [esp + 0xc]
// 0060ed6d  50                   push eax
// 0060ed6e  56                   push esi
// 0060ed6f  e89cdbffff           call 0x60c910
// 0060ed74  6a09                 push 9
// 0060ed76  8d4c2420             lea ecx, [esp + 0x20]
// 0060ed7a  51                   push ecx
// 0060ed7b  56                   push esi
// 0060ed7c  e80f46ffff           call 0x603390
// 0060ed81  6a09                 push 9
// 0060ed83  8d54242c             lea edx, [esp + 0x2c]
// 0060ed87  52                   push edx
// 0060ed88  56                   push esi
// 0060ed89  e8e248ffff           call 0x603670
// 0060ed8e  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060ed94  8bd0                 mov edx, eax
// 0060ed96  8bc8                 mov ecx, eax
// 0060ed98  c1e918               shr ecx, 0x18
// 0060ed9b  c1ea10               shr edx, 0x10
// 0060ed9e  884c2450             mov byte ptr [esp + 0x50], cl
// 0060eda2  88542451             mov byte ptr [esp + 0x51], dl
// 0060eda6  6a04                 push 4
// 0060eda8  8d542454             lea edx, [esp + 0x54]
// 0060edac  8bc8                 mov ecx, eax
// 0060edae  52                   push edx
// 0060edaf  c1e908               shr ecx, 8
// 0060edb2  56                   push esi
// 0060edb3  884c245e             mov byte ptr [esp + 0x5e], cl
// 0060edb7  8844245f             mov byte ptr [esp + 0x5f], al
// 0060edbb  e8d045ffff           call 0x603390
// 0060edc0  83c430               add esp, 0x30
// 0060edc3  5e                   pop esi
// 0060edc4  5b                   pop ebx
// 0060edc5  83c414               add esp, 0x14
// 0060edc8  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_oFFs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
