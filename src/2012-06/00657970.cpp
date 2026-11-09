// from server: 100% by auto
// roc 2012-06 00657970  unit: seg_00650000  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657970
//
// 00657970  83ec08               sub esp, 8
// 00657973  53                   push ebx
// 00657974  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00657978  83fb04               cmp ebx, 4
// 0065797b  56                   push esi
// 0065797c  8b742414             mov esi, dword ptr [esp + 0x14]
// 00657980  c644240873           mov byte ptr [esp + 8], 0x73
// 00657985  c644240952           mov byte ptr [esp + 9], 0x52
// 0065798a  c644240a47           mov byte ptr [esp + 0xa], 0x47
// 0065798f  c644240b42           mov byte ptr [esp + 0xb], 0x42
// 00657994  c644240c00           mov byte ptr [esp + 0xc], 0
// 00657999  7c0e                 jl 0x6579a9
// 0065799b  68689db800           push 0xb89d68
// 006579a0  56                   push esi
// 006579a1  e8ba68ffff           call 0x64e260
// 006579a6  83c408               add esp, 8
// 006579a9  885c2418             mov byte ptr [esp + 0x18], bl
// 006579ad  85f6                 test esi, esi
// 006579af  745c                 je 0x657a0d
// 006579b1  6a01                 push 1
// 006579b3  8d44240c             lea eax, [esp + 0xc]
// 006579b7  50                   push eax
// 006579b8  56                   push esi
// 006579b9  e802e7ffff           call 0x6560c0
// 006579be  6a01                 push 1
// 006579c0  8d4c2428             lea ecx, [esp + 0x28]
// 006579c4  51                   push ecx
// 006579c5  56                   push esi
// 006579c6  e8f5fcfeff           call 0x6476c0
// 006579cb  6a01                 push 1
// 006579cd  8d542434             lea edx, [esp + 0x34]
// 006579d1  52                   push edx
// 006579d2  56                   push esi
// 006579d3  e8b864feff           call 0x63de90
// 006579d8  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 006579de  8bd0                 mov edx, eax
// 006579e0  8bc8                 mov ecx, eax
// 006579e2  c1e918               shr ecx, 0x18
// 006579e5  c1ea10               shr edx, 0x10
// 006579e8  884c2438             mov byte ptr [esp + 0x38], cl
// 006579ec  88542439             mov byte ptr [esp + 0x39], dl
// 006579f0  6a04                 push 4
// 006579f2  8d54243c             lea edx, [esp + 0x3c]
// 006579f6  8bc8                 mov ecx, eax
// 006579f8  52                   push edx
// 006579f9  c1e908               shr ecx, 8
// 006579fc  56                   push esi
// 006579fd  884c2446             mov byte ptr [esp + 0x46], cl
// 00657a01  88442447             mov byte ptr [esp + 0x47], al
// 00657a05  e8b6fcfeff           call 0x6476c0
// 00657a0a  83c430               add esp, 0x30
// 00657a0d  5e                   pop esi
// 00657a0e  5b                   pop ebx
// 00657a0f  83c408               add esp, 8
// 00657a12  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sRGB)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
