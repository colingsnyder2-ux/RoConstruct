// from server: 100% by auto
// roc 2010-06 0056e7b0  unit: G3D::LineSegment  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056e7b0
//
// 0056e7b0  83ec08               sub esp, 8
// 0056e7b3  53                   push ebx
// 0056e7b4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0056e7b8  57                   push edi
// 0056e7b9  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056e7bd  0fb78718010000       movzx eax, word ptr [edi + 0x118]
// 0056e7c4  3bd8                 cmp ebx, eax
// 0056e7c6  c644240868           mov byte ptr [esp + 8], 0x68
// 0056e7cb  c644240949           mov byte ptr [esp + 9], 0x49
// 0056e7d0  c644240a53           mov byte ptr [esp + 0xa], 0x53
// 0056e7d5  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0056e7da  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056e7df  7e14                 jle 0x56e7f5
// 0056e7e1  689c37a200           push 0xa2379c
// 0056e7e6  57                   push edi
// 0056e7e7  e874330000           call 0x571b60
// 0056e7ec  83c408               add esp, 8
// 0056e7ef  5f                   pop edi
// 0056e7f0  5b                   pop ebx
// 0056e7f1  83c408               add esp, 8
// 0056e7f4  c3                   ret 
// 0056e7f5  56                   push esi
// 0056e7f6  8d0c1b               lea ecx, [ebx + ebx]
// 0056e7f9  51                   push ecx
// 0056e7fa  8d542410             lea edx, [esp + 0x10]
// 0056e7fe  52                   push edx
// 0056e7ff  57                   push edi
// 0056e800  e82bfaffff           call 0x56e230
// 0056e805  83c40c               add esp, 0xc
// 0056e808  33f6                 xor esi, esi
// 0056e80a  85db                 test ebx, ebx
// 0056e80c  7e3a                 jle 0x56e848
// 0056e80e  55                   push ebp
// 0056e80f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0056e813  0fb7447500           movzx eax, word ptr [ebp + esi*2]
// 0056e818  6a02                 push 2
// 0056e81a  8d542420             lea edx, [esp + 0x20]
// 0056e81e  8bc8                 mov ecx, eax
// 0056e820  52                   push edx
// 0056e821  c1e908               shr ecx, 8
// 0056e824  57                   push edi
// 0056e825  884c2428             mov byte ptr [esp + 0x28], cl
// 0056e829  88442429             mov byte ptr [esp + 0x29], al
// 0056e82d  e8ce64ffff           call 0x564d00
// 0056e832  6a02                 push 2
// 0056e834  8d44242c             lea eax, [esp + 0x2c]
// 0056e838  50                   push eax
// 0056e839  57                   push edi
// 0056e83a  e8a167ffff           call 0x564fe0
// 0056e83f  46                   inc esi
// 0056e840  83c418               add esp, 0x18
// 0056e843  3bf3                 cmp esi, ebx
// 0056e845  7ccc                 jl 0x56e813
// 0056e847  5d                   pop ebp
// 0056e848  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0056e84e  8bd0                 mov edx, eax
// 0056e850  8bc8                 mov ecx, eax
// 0056e852  c1e918               shr ecx, 0x18
// 0056e855  c1ea10               shr edx, 0x10
// 0056e858  884c2420             mov byte ptr [esp + 0x20], cl
// 0056e85c  88542421             mov byte ptr [esp + 0x21], dl
// 0056e860  6a04                 push 4
// 0056e862  8d542424             lea edx, [esp + 0x24]
// 0056e866  8bc8                 mov ecx, eax
// 0056e868  52                   push edx
// 0056e869  c1e908               shr ecx, 8
// 0056e86c  57                   push edi
// 0056e86d  884c242e             mov byte ptr [esp + 0x2e], cl
// 0056e871  8844242f             mov byte ptr [esp + 0x2f], al
// 0056e875  e88664ffff           call 0x564d00
// 0056e87a  83c40c               add esp, 0xc
// 0056e87d  5e                   pop esi
// 0056e87e  5f                   pop edi
// 0056e87f  5b                   pop ebx
// 0056e880  83c408               add esp, 8
// 0056e883  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
