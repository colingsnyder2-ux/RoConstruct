// from server: 100% by auto
// roc 2011-06 0056af20  unit: seg_00560000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056af20
//
// 0056af20  83ec08               sub esp, 8
// 0056af23  53                   push ebx
// 0056af24  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0056af28  57                   push edi
// 0056af29  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056af2d  0fb78718010000       movzx eax, word ptr [edi + 0x118]
// 0056af34  3bd8                 cmp ebx, eax
// 0056af36  c644240868           mov byte ptr [esp + 8], 0x68
// 0056af3b  c644240949           mov byte ptr [esp + 9], 0x49
// 0056af40  c644240a53           mov byte ptr [esp + 0xa], 0x53
// 0056af45  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0056af4a  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056af4f  7e14                 jle 0x56af65
// 0056af51  68585ba800           push 0xa85b58
// 0056af56  57                   push edi
// 0056af57  e88464ffff           call 0x5613e0
// 0056af5c  83c408               add esp, 8
// 0056af5f  5f                   pop edi
// 0056af60  5b                   pop ebx
// 0056af61  83c408               add esp, 8
// 0056af64  c3                   ret 
// 0056af65  56                   push esi
// 0056af66  8d0c1b               lea ecx, [ebx + ebx]
// 0056af69  51                   push ecx
// 0056af6a  8d542410             lea edx, [esp + 0x10]
// 0056af6e  52                   push edx
// 0056af6f  57                   push edi
// 0056af70  e83bfaffff           call 0x56a9b0
// 0056af75  83c40c               add esp, 0xc
// 0056af78  33f6                 xor esi, esi
// 0056af7a  85db                 test ebx, ebx
// 0056af7c  7e3a                 jle 0x56afb8
// 0056af7e  55                   push ebp
// 0056af7f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0056af83  0fb7447500           movzx eax, word ptr [ebp + esi*2]
// 0056af88  6a02                 push 2
// 0056af8a  8d542420             lea edx, [esp + 0x20]
// 0056af8e  8bc8                 mov ecx, eax
// 0056af90  52                   push edx
// 0056af91  c1e908               shr ecx, 8
// 0056af94  57                   push edi
// 0056af95  884c2428             mov byte ptr [esp + 0x28], cl
// 0056af99  88442429             mov byte ptr [esp + 0x29], al
// 0056af9d  e89ef8feff           call 0x55a840
// 0056afa2  6a02                 push 2
// 0056afa4  8d44242c             lea eax, [esp + 0x2c]
// 0056afa8  50                   push eax
// 0056afa9  57                   push edi
// 0056afaa  e8a158feff           call 0x550850
// 0056afaf  46                   inc esi
// 0056afb0  83c418               add esp, 0x18
// 0056afb3  3bf3                 cmp esi, ebx
// 0056afb5  7ccc                 jl 0x56af83
// 0056afb7  5d                   pop ebp
// 0056afb8  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0056afbe  8bd0                 mov edx, eax
// 0056afc0  8bc8                 mov ecx, eax
// 0056afc2  c1e918               shr ecx, 0x18
// 0056afc5  c1ea10               shr edx, 0x10
// 0056afc8  884c2420             mov byte ptr [esp + 0x20], cl
// 0056afcc  88542421             mov byte ptr [esp + 0x21], dl
// 0056afd0  6a04                 push 4
// 0056afd2  8d542424             lea edx, [esp + 0x24]
// 0056afd6  8bc8                 mov ecx, eax
// 0056afd8  52                   push edx
// 0056afd9  c1e908               shr ecx, 8
// 0056afdc  57                   push edi
// 0056afdd  884c242e             mov byte ptr [esp + 0x2e], cl
// 0056afe1  8844242f             mov byte ptr [esp + 0x2f], al
// 0056afe5  e856f8feff           call 0x55a840
// 0056afea  83c40c               add esp, 0xc
// 0056afed  5e                   pop esi
// 0056afee  5f                   pop edi
// 0056afef  5b                   pop ebx
// 0056aff0  83c408               add esp, 8
// 0056aff3  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
