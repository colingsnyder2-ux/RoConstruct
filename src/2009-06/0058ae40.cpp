// from server: 100% by auto
// roc 2009-06 0058ae40  unit: seg_00580000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ae40
//
// 0058ae40  83ec08               sub esp, 8
// 0058ae43  53                   push ebx
// 0058ae44  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0058ae48  57                   push edi
// 0058ae49  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0058ae4d  0fb78718010000       movzx eax, word ptr [edi + 0x118]
// 0058ae54  3bd8                 cmp ebx, eax
// 0058ae56  c644240868           mov byte ptr [esp + 8], 0x68
// 0058ae5b  c644240949           mov byte ptr [esp + 9], 0x49
// 0058ae60  c644240a53           mov byte ptr [esp + 0xa], 0x53
// 0058ae65  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0058ae6a  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058ae6f  7e14                 jle 0x58ae85
// 0058ae71  6890eb8c00           push 0x8ceb90
// 0058ae76  57                   push edi
// 0058ae77  e894330000           call 0x58e210
// 0058ae7c  83c408               add esp, 8
// 0058ae7f  5f                   pop edi
// 0058ae80  5b                   pop ebx
// 0058ae81  83c408               add esp, 8
// 0058ae84  c3                   ret 
// 0058ae85  56                   push esi
// 0058ae86  8d0c1b               lea ecx, [ebx + ebx]
// 0058ae89  51                   push ecx
// 0058ae8a  8d542410             lea edx, [esp + 0x10]
// 0058ae8e  52                   push edx
// 0058ae8f  57                   push edi
// 0058ae90  e82bfaffff           call 0x58a8c0
// 0058ae95  83c40c               add esp, 0xc
// 0058ae98  33f6                 xor esi, esi
// 0058ae9a  85db                 test ebx, ebx
// 0058ae9c  7e3a                 jle 0x58aed8
// 0058ae9e  55                   push ebp
// 0058ae9f  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0058aea3  0fb7447500           movzx eax, word ptr [ebp + esi*2]
// 0058aea8  6a02                 push 2
// 0058aeaa  8d542420             lea edx, [esp + 0x20]
// 0058aeae  8bc8                 mov ecx, eax
// 0058aeb0  52                   push edx
// 0058aeb1  c1e908               shr ecx, 8
// 0058aeb4  57                   push edi
// 0058aeb5  884c2428             mov byte ptr [esp + 0x28], cl
// 0058aeb9  88442429             mov byte ptr [esp + 0x29], al
// 0058aebd  e81e67ffff           call 0x5815e0
// 0058aec2  6a02                 push 2
// 0058aec4  8d44242c             lea eax, [esp + 0x2c]
// 0058aec8  50                   push eax
// 0058aec9  57                   push edi
// 0058aeca  e8f169ffff           call 0x5818c0
// 0058aecf  46                   inc esi
// 0058aed0  83c418               add esp, 0x18
// 0058aed3  3bf3                 cmp esi, ebx
// 0058aed5  7ccc                 jl 0x58aea3
// 0058aed7  5d                   pop ebp
// 0058aed8  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0058aede  8bd0                 mov edx, eax
// 0058aee0  8bc8                 mov ecx, eax
// 0058aee2  c1e918               shr ecx, 0x18
// 0058aee5  c1ea10               shr edx, 0x10
// 0058aee8  884c2420             mov byte ptr [esp + 0x20], cl
// 0058aeec  88542421             mov byte ptr [esp + 0x21], dl
// 0058aef0  6a04                 push 4
// 0058aef2  8d542424             lea edx, [esp + 0x24]
// 0058aef6  8bc8                 mov ecx, eax
// 0058aef8  52                   push edx
// 0058aef9  c1e908               shr ecx, 8
// 0058aefc  57                   push edi
// 0058aefd  884c242e             mov byte ptr [esp + 0x2e], cl
// 0058af01  8844242f             mov byte ptr [esp + 0x2f], al
// 0058af05  e8d666ffff           call 0x5815e0
// 0058af0a  83c40c               add esp, 0xc
// 0058af0d  5e                   pop esi
// 0058af0e  5f                   pop edi
// 0058af0f  5b                   pop ebx
// 0058af10  83c408               add esp, 8
// 0058af13  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
