// from server: 100% by auto
// roc 2009-12 0060ce90  unit: seg_00600000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060ce90
//
// 0060ce90  83ec08               sub esp, 8
// 0060ce93  53                   push ebx
// 0060ce94  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0060ce98  57                   push edi
// 0060ce99  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0060ce9d  0fb78718010000       movzx eax, word ptr [edi + 0x118]
// 0060cea4  3bd8                 cmp ebx, eax
// 0060cea6  c644240868           mov byte ptr [esp + 8], 0x68
// 0060ceab  c644240949           mov byte ptr [esp + 9], 0x49
// 0060ceb0  c644240a53           mov byte ptr [esp + 0xa], 0x53
// 0060ceb5  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0060ceba  c644240c00           mov byte ptr [esp + 0xc], 0
// 0060cebf  7e14                 jle 0x60ced5
// 0060cec1  68285a9c00           push 0x9c5a28
// 0060cec6  57                   push edi
// 0060cec7  e874330000           call 0x610240
// 0060cecc  83c408               add esp, 8
// 0060cecf  5f                   pop edi
// 0060ced0  5b                   pop ebx
// 0060ced1  83c408               add esp, 8
// 0060ced4  c3                   ret 
// 0060ced5  56                   push esi
// 0060ced6  8d0c1b               lea ecx, [ebx + ebx]
// 0060ced9  51                   push ecx
// 0060ceda  8d542410             lea edx, [esp + 0x10]
// 0060cede  52                   push edx
// 0060cedf  57                   push edi
// 0060cee0  e82bfaffff           call 0x60c910
// 0060cee5  83c40c               add esp, 0xc
// 0060cee8  33f6                 xor esi, esi
// 0060ceea  85db                 test ebx, ebx
// 0060ceec  7e3a                 jle 0x60cf28
// 0060ceee  55                   push ebp
// 0060ceef  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0060cef3  0fb7447500           movzx eax, word ptr [ebp + esi*2]
// 0060cef8  6a02                 push 2
// 0060cefa  8d542420             lea edx, [esp + 0x20]
// 0060cefe  8bc8                 mov ecx, eax
// 0060cf00  52                   push edx
// 0060cf01  c1e908               shr ecx, 8
// 0060cf04  57                   push edi
// 0060cf05  884c2428             mov byte ptr [esp + 0x28], cl
// 0060cf09  88442429             mov byte ptr [esp + 0x29], al
// 0060cf0d  e87e64ffff           call 0x603390
// 0060cf12  6a02                 push 2
// 0060cf14  8d44242c             lea eax, [esp + 0x2c]
// 0060cf18  50                   push eax
// 0060cf19  57                   push edi
// 0060cf1a  e85167ffff           call 0x603670
// 0060cf1f  46                   inc esi
// 0060cf20  83c418               add esp, 0x18
// 0060cf23  3bf3                 cmp esi, ebx
// 0060cf25  7ccc                 jl 0x60cef3
// 0060cf27  5d                   pop ebp
// 0060cf28  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0060cf2e  8bd0                 mov edx, eax
// 0060cf30  8bc8                 mov ecx, eax
// 0060cf32  c1e918               shr ecx, 0x18
// 0060cf35  c1ea10               shr edx, 0x10
// 0060cf38  884c2420             mov byte ptr [esp + 0x20], cl
// 0060cf3c  88542421             mov byte ptr [esp + 0x21], dl
// 0060cf40  6a04                 push 4
// 0060cf42  8d542424             lea edx, [esp + 0x24]
// 0060cf46  8bc8                 mov ecx, eax
// 0060cf48  52                   push edx
// 0060cf49  c1e908               shr ecx, 8
// 0060cf4c  57                   push edi
// 0060cf4d  884c242e             mov byte ptr [esp + 0x2e], cl
// 0060cf51  8844242f             mov byte ptr [esp + 0x2f], al
// 0060cf55  e83664ffff           call 0x603390
// 0060cf5a  83c40c               add esp, 0xc
// 0060cf5d  5e                   pop esi
// 0060cf5e  5f                   pop edi
// 0060cf5f  5b                   pop ebx
// 0060cf60  83c408               add esp, 8
// 0060cf63  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
