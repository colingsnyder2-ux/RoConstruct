// from server: 100% by auto
// roc 2011-06 0056c260  unit: seg_00560000  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c260
//
// 0056c260  83ec08               sub esp, 8
// 0056c263  53                   push ebx
// 0056c264  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0056c268  83fb04               cmp ebx, 4
// 0056c26b  56                   push esi
// 0056c26c  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056c270  c644240873           mov byte ptr [esp + 8], 0x73
// 0056c275  c644240952           mov byte ptr [esp + 9], 0x52
// 0056c27a  c644240a47           mov byte ptr [esp + 0xa], 0x47
// 0056c27f  c644240b42           mov byte ptr [esp + 0xb], 0x42
// 0056c284  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056c289  7c0e                 jl 0x56c299
// 0056c28b  68185fa800           push 0xa85f18
// 0056c290  56                   push esi
// 0056c291  e84a51ffff           call 0x5613e0
// 0056c296  83c408               add esp, 8
// 0056c299  885c2418             mov byte ptr [esp + 0x18], bl
// 0056c29d  85f6                 test esi, esi
// 0056c29f  745c                 je 0x56c2fd
// 0056c2a1  6a01                 push 1
// 0056c2a3  8d44240c             lea eax, [esp + 0xc]
// 0056c2a7  50                   push eax
// 0056c2a8  56                   push esi
// 0056c2a9  e802e7ffff           call 0x56a9b0
// 0056c2ae  6a01                 push 1
// 0056c2b0  8d4c2428             lea ecx, [esp + 0x28]
// 0056c2b4  51                   push ecx
// 0056c2b5  56                   push esi
// 0056c2b6  e885e5feff           call 0x55a840
// 0056c2bb  6a01                 push 1
// 0056c2bd  8d542434             lea edx, [esp + 0x34]
// 0056c2c1  52                   push edx
// 0056c2c2  56                   push esi
// 0056c2c3  e88845feff           call 0x550850
// 0056c2c8  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056c2ce  8bd0                 mov edx, eax
// 0056c2d0  8bc8                 mov ecx, eax
// 0056c2d2  c1e918               shr ecx, 0x18
// 0056c2d5  c1ea10               shr edx, 0x10
// 0056c2d8  884c2438             mov byte ptr [esp + 0x38], cl
// 0056c2dc  88542439             mov byte ptr [esp + 0x39], dl
// 0056c2e0  6a04                 push 4
// 0056c2e2  8d54243c             lea edx, [esp + 0x3c]
// 0056c2e6  8bc8                 mov ecx, eax
// 0056c2e8  52                   push edx
// 0056c2e9  c1e908               shr ecx, 8
// 0056c2ec  56                   push esi
// 0056c2ed  884c2446             mov byte ptr [esp + 0x46], cl
// 0056c2f1  88442447             mov byte ptr [esp + 0x47], al
// 0056c2f5  e846e5feff           call 0x55a840
// 0056c2fa  83c430               add esp, 0x30
// 0056c2fd  5e                   pop esi
// 0056c2fe  5b                   pop ebx
// 0056c2ff  83c408               add esp, 8
// 0056c302  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sRGB)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
