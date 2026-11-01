// from server: 100% by auto
// roc 2009-12 00878fc0  unit: CXTPControlGalleryPaintManager  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00878fc0
//
// 00878fc0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00878fc4  8b442410             mov eax, dword ptr [esp + 0x10]
// 00878fc8  83ec08               sub esp, 8
// 00878fcb  53                   push ebx
// 00878fcc  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00878fd0  56                   push esi
// 00878fd1  57                   push edi
// 00878fd2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00878fd6  2bc3                 sub eax, ebx
// 00878fd8  2bcf                 sub ecx, edi
// 00878fda  3bc1                 cmp eax, ecx
// 00878fdc  8bf0                 mov esi, eax
// 00878fde  7c02                 jl 0x878fe2
// 00878fe0  8bf1                 mov esi, ecx
// 00878fe2  83fe06               cmp esi, 6
// 00878fe5  0f8cfc000000         jl 0x8790e7
// 00878feb  2bc6                 sub eax, esi
// 00878fed  99                   cdq 
// 00878fee  2bc2                 sub eax, edx
// 00878ff0  d1f8                 sar eax, 1
// 00878ff2  55                   push ebp
// 00878ff3  8d6c1802             lea ebp, [eax + ebx + 2]
// 00878ff7  8bc1                 mov eax, ecx
// 00878ff9  2bc6                 sub eax, esi
// 00878ffb  99                   cdq 
// 00878ffc  2bc2                 sub eax, edx
// 00878ffe  d1f8                 sar eax, 1
// 00879000  8d443802             lea eax, [eax + edi + 2]
// 00879004  83ee04               sub esi, 4
// 00879007  837c243800           cmp dword ptr [esp + 0x38], 0
// 0087900c  89442410             mov dword ptr [esp + 0x10], eax
// 00879010  7404                 je 0x879016
// 00879012  33ff                 xor edi, edi
// 00879014  eb0a                 jmp 0x879020
// 00879016  6a10                 push 0x10
// 00879018  ff15d8ca9800         call dword ptr [0x98cad8]
// 0087901e  8bf8                 mov edi, eax
// 00879020  68181ea000           push 0xa01e18
// 00879025  6a00                 push 0
// 00879027  6a00                 push 0
// 00879029  6a00                 push 0
// 0087902b  6a00                 push 0
// 0087902d  6a02                 push 2
// 0087902f  6a00                 push 0
// 00879031  6a00                 push 0
// 00879033  6a00                 push 0
// 00879035  6890010000           push 0x190
// 0087903a  6a00                 push 0
// 0087903c  6a00                 push 0
// 0087903e  6a00                 push 0
// 00879040  56                   push esi
// 00879041  ff158cb19800         call dword ptr [0x98b18c]
// 00879047  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0087904b  8bd8                 mov ebx, eax
// 0087904d  85f6                 test esi, esi
// 0087904f  7504                 jne 0x879055
// 00879051  33c0                 xor eax, eax
// 00879053  eb03                 jmp 0x879058
// 00879055  8b4604               mov eax, dword ptr [esi + 4]
// 00879058  53                   push ebx
// 00879059  50                   push eax
// 0087905a  ff154cb19800         call dword ptr [0x98b14c]
// 00879060  89442414             mov dword ptr [esp + 0x14], eax
// 00879064  85f6                 test esi, esi
// 00879066  7504                 jne 0x87906c
// 00879068  33c0                 xor eax, eax
// 0087906a  eb03                 jmp 0x87906f
// 0087906c  8b4604               mov eax, dword ptr [esi + 4]
// 0087906f  57                   push edi
// 00879070  50                   push eax
// 00879071  ff1500b19800         call dword ptr [0x98b100]
// 00879077  6a01                 push 1
// 00879079  8bce                 mov ecx, esi
// 0087907b  e810d40a00           call 0x926490
// 00879080  837c243000           cmp dword ptr [esp + 0x30], 0
// 00879085  7415                 je 0x87909c
// 00879087  837c243400           cmp dword ptr [esp + 0x34], 0
// 0087908c  7407                 je 0x879095
// 0087908e  b9141ea000           mov ecx, 0xa01e14
// 00879093  eb18                 jmp 0x8790ad
// 00879095  b958a59a00           mov ecx, 0x9aa558
// 0087909a  eb11                 jmp 0x8790ad
// 0087909c  837c243400           cmp dword ptr [esp + 0x34], 0
// 008790a1  b9101ea000           mov ecx, 0xa01e10
// 008790a6  7505                 jne 0x8790ad
// 008790a8  b970ba9b00           mov ecx, 0x9bba70
// 008790ad  85f6                 test esi, esi
// 008790af  7504                 jne 0x8790b5
// 008790b1  33c0                 xor eax, eax
// 008790b3  eb03                 jmp 0x8790b8
// 008790b5  8b4604               mov eax, dword ptr [esi + 4]
// 008790b8  6a01                 push 1
// 008790ba  51                   push ecx
// 008790bb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008790bf  51                   push ecx
// 008790c0  55                   push ebp
// 008790c1  50                   push eax
// 008790c2  ff15ecb09800         call dword ptr [0x98b0ec]
// 008790c8  5d                   pop ebp
// 008790c9  85f6                 test esi, esi
// 008790cb  7504                 jne 0x8790d1
// 008790cd  33f6                 xor esi, esi
// 008790cf  eb03                 jmp 0x8790d4
// 008790d1  8b7604               mov esi, dword ptr [esi + 4]
// 008790d4  8b542410             mov edx, dword ptr [esp + 0x10]
// 008790d8  52                   push edx
// 008790d9  56                   push esi
// 008790da  ff154cb19800         call dword ptr [0x98b14c]
// 008790e0  53                   push ebx
// 008790e1  ff153cb19800         call dword ptr [0x98b13c]
// 008790e7  5f                   pop edi
// 008790e8  5e                   pop esi
// 008790e9  5b                   pop ebx
// 008790ea  83c408               add esp, 8
// 008790ed  c3                   ret 
// library xtp-15.2.1/Source\Controls\Scroll\XTPScrollBar.cpp (function ?DrawArrowGlyph@@YAXPAVCDC@@VCRect@@HHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Scroll/XTPScrollBar.cpp
