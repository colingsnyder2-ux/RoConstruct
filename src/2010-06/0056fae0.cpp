// from server: 100% by auto
// roc 2010-06 0056fae0  unit: G3D::LineSegment  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056fae0
//
// 0056fae0  83ec08               sub esp, 8
// 0056fae3  53                   push ebx
// 0056fae4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0056fae8  83fb04               cmp ebx, 4
// 0056faeb  56                   push esi
// 0056faec  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056faf0  c644240873           mov byte ptr [esp + 8], 0x73
// 0056faf5  c644240952           mov byte ptr [esp + 9], 0x52
// 0056fafa  c644240a47           mov byte ptr [esp + 0xa], 0x47
// 0056faff  c644240b42           mov byte ptr [esp + 0xb], 0x42
// 0056fb04  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056fb09  7c0e                 jl 0x56fb19
// 0056fb0b  68943ba200           push 0xa23b94
// 0056fb10  56                   push esi
// 0056fb11  e84a200000           call 0x571b60
// 0056fb16  83c408               add esp, 8
// 0056fb19  885c2418             mov byte ptr [esp + 0x18], bl
// 0056fb1d  85f6                 test esi, esi
// 0056fb1f  745c                 je 0x56fb7d
// 0056fb21  6a01                 push 1
// 0056fb23  8d44240c             lea eax, [esp + 0xc]
// 0056fb27  50                   push eax
// 0056fb28  56                   push esi
// 0056fb29  e802e7ffff           call 0x56e230
// 0056fb2e  6a01                 push 1
// 0056fb30  8d4c2428             lea ecx, [esp + 0x28]
// 0056fb34  51                   push ecx
// 0056fb35  56                   push esi
// 0056fb36  e8c551ffff           call 0x564d00
// 0056fb3b  6a01                 push 1
// 0056fb3d  8d542434             lea edx, [esp + 0x34]
// 0056fb41  52                   push edx
// 0056fb42  56                   push esi
// 0056fb43  e89854ffff           call 0x564fe0
// 0056fb48  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056fb4e  8bd0                 mov edx, eax
// 0056fb50  8bc8                 mov ecx, eax
// 0056fb52  c1e918               shr ecx, 0x18
// 0056fb55  c1ea10               shr edx, 0x10
// 0056fb58  884c2438             mov byte ptr [esp + 0x38], cl
// 0056fb5c  88542439             mov byte ptr [esp + 0x39], dl
// 0056fb60  6a04                 push 4
// 0056fb62  8d54243c             lea edx, [esp + 0x3c]
// 0056fb66  8bc8                 mov ecx, eax
// 0056fb68  52                   push edx
// 0056fb69  c1e908               shr ecx, 8
// 0056fb6c  56                   push esi
// 0056fb6d  884c2446             mov byte ptr [esp + 0x46], cl
// 0056fb71  88442447             mov byte ptr [esp + 0x47], al
// 0056fb75  e88651ffff           call 0x564d00
// 0056fb7a  83c430               add esp, 0x30
// 0056fb7d  5e                   pop esi
// 0056fb7e  5b                   pop ebx
// 0056fb7f  83c408               add esp, 8
// 0056fb82  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sRGB)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
