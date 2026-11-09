// from server: 100% by auto
// roc 2012-06 00656630  unit: seg_00650000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656630
//
// 00656630  83ec08               sub esp, 8
// 00656633  53                   push ebx
// 00656634  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00656638  57                   push edi
// 00656639  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0065663d  0fb78718010000       movzx eax, word ptr [edi + 0x118]
// 00656644  3bd8                 cmp ebx, eax
// 00656646  c644240868           mov byte ptr [esp + 8], 0x68
// 0065664b  c644240949           mov byte ptr [esp + 9], 0x49
// 00656650  c644240a53           mov byte ptr [esp + 0xa], 0x53
// 00656655  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0065665a  c644240c00           mov byte ptr [esp + 0xc], 0
// 0065665f  7e14                 jle 0x656675
// 00656661  68a899b800           push 0xb899a8
// 00656666  57                   push edi
// 00656667  e8f47bffff           call 0x64e260
// 0065666c  83c408               add esp, 8
// 0065666f  5f                   pop edi
// 00656670  5b                   pop ebx
// 00656671  83c408               add esp, 8
// 00656674  c3                   ret 
// 00656675  56                   push esi
// 00656676  8d0c1b               lea ecx, [ebx + ebx]
// 00656679  51                   push ecx
// 0065667a  8d542410             lea edx, [esp + 0x10]
// 0065667e  52                   push edx
// 0065667f  57                   push edi
// 00656680  e83bfaffff           call 0x6560c0
// 00656685  83c40c               add esp, 0xc
// 00656688  33f6                 xor esi, esi
// 0065668a  85db                 test ebx, ebx
// 0065668c  7e3a                 jle 0x6566c8
// 0065668e  55                   push ebp
// 0065668f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00656693  0fb7447500           movzx eax, word ptr [ebp + esi*2]
// 00656698  6a02                 push 2
// 0065669a  8d542420             lea edx, [esp + 0x20]
// 0065669e  8bc8                 mov ecx, eax
// 006566a0  52                   push edx
// 006566a1  c1e908               shr ecx, 8
// 006566a4  57                   push edi
// 006566a5  884c2428             mov byte ptr [esp + 0x28], cl
// 006566a9  88442429             mov byte ptr [esp + 0x29], al
// 006566ad  e80e10ffff           call 0x6476c0
// 006566b2  6a02                 push 2
// 006566b4  8d44242c             lea eax, [esp + 0x2c]
// 006566b8  50                   push eax
// 006566b9  57                   push edi
// 006566ba  e8d177feff           call 0x63de90
// 006566bf  46                   inc esi
// 006566c0  83c418               add esp, 0x18
// 006566c3  3bf3                 cmp esi, ebx
// 006566c5  7ccc                 jl 0x656693
// 006566c7  5d                   pop ebp
// 006566c8  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 006566ce  8bd0                 mov edx, eax
// 006566d0  8bc8                 mov ecx, eax
// 006566d2  c1e918               shr ecx, 0x18
// 006566d5  c1ea10               shr edx, 0x10
// 006566d8  884c2420             mov byte ptr [esp + 0x20], cl
// 006566dc  88542421             mov byte ptr [esp + 0x21], dl
// 006566e0  6a04                 push 4
// 006566e2  8d542424             lea edx, [esp + 0x24]
// 006566e6  8bc8                 mov ecx, eax
// 006566e8  52                   push edx
// 006566e9  c1e908               shr ecx, 8
// 006566ec  57                   push edi
// 006566ed  884c242e             mov byte ptr [esp + 0x2e], cl
// 006566f1  8844242f             mov byte ptr [esp + 0x2f], al
// 006566f5  e8c60fffff           call 0x6476c0
// 006566fa  83c40c               add esp, 0xc
// 006566fd  5e                   pop esi
// 006566fe  5f                   pop edi
// 006566ff  5b                   pop ebx
// 00656700  83c408               add esp, 8
// 00656703  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
