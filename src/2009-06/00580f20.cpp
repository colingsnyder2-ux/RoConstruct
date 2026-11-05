// from server: 100% by auto
// roc 2009-06 00580f20  unit: seg_00580000  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00580f20
//
// 00580f20  53                   push ebx
// 00580f21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00580f25  85db                 test ebx, ebx
// 00580f27  0f84e1000000         je 0x58100e
// 00580f2d  56                   push esi
// 00580f2e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00580f32  85f6                 test esi, esi
// 00580f34  0f84d3000000         je 0x58100d
// 00580f3a  8b442414             mov eax, dword ptr [esp + 0x14]
// 00580f3e  85c0                 test eax, eax
// 00580f40  0f84c7000000         je 0x58100d
// 00580f46  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00580f4b  0f84bc000000         je 0x58100d
// 00580f51  8d5001               lea edx, [eax + 1]
// 00580f54  8a08                 mov cl, byte ptr [eax]
// 00580f56  40                   inc eax
// 00580f57  84c9                 test cl, cl
// 00580f59  75f9                 jne 0x580f54
// 00580f5b  55                   push ebp
// 00580f5c  2bc2                 sub eax, edx
// 00580f5e  57                   push edi
// 00580f5f  8d6801               lea ebp, [eax + 1]
// 00580f62  55                   push ebp
// 00580f63  53                   push ebx
// 00580f64  e877dd0000           call 0x58ece0
// 00580f69  8bf8                 mov edi, eax
// 00580f6b  83c408               add esp, 8
// 00580f6e  85ff                 test edi, edi
// 00580f70  7513                 jne 0x580f85
// 00580f72  6820c88c00           push 0x8cc820
// 00580f77  53                   push ebx
// 00580f78  e893d20000           call 0x58e210
// 00580f7d  83c408               add esp, 8
// 00580f80  5f                   pop edi
// 00580f81  5d                   pop ebp
// 00580f82  5e                   pop esi
// 00580f83  5b                   pop ebx
// 00580f84  c3                   ret 
// 00580f85  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00580f89  55                   push ebp
// 00580f8a  50                   push eax
// 00580f8b  57                   push edi
// 00580f8c  e8258f1900           call 0x719eb6
// 00580f91  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00580f95  55                   push ebp
// 00580f96  53                   push ebx
// 00580f97  e844dd0000           call 0x58ece0
// 00580f9c  8bd8                 mov ebx, eax
// 00580f9e  83c414               add esp, 0x14
// 00580fa1  85db                 test ebx, ebx
// 00580fa3  751e                 jne 0x580fc3
// 00580fa5  8b742414             mov esi, dword ptr [esp + 0x14]
// 00580fa9  57                   push edi
// 00580faa  56                   push esi
// 00580fab  e800dd0000           call 0x58ecb0
// 00580fb0  68f0c78c00           push 0x8cc7f0
// 00580fb5  56                   push esi
// 00580fb6  e855d20000           call 0x58e210
// 00580fbb  83c410               add esp, 0x10
// 00580fbe  5f                   pop edi
// 00580fbf  5d                   pop ebp
// 00580fc0  5e                   pop esi
// 00580fc1  5b                   pop ebx
// 00580fc2  c3                   ret 
// 00580fc3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00580fc7  55                   push ebp
// 00580fc8  51                   push ecx
// 00580fc9  53                   push ebx
// 00580fca  e8e78e1900           call 0x719eb6
// 00580fcf  8b542420             mov edx, dword ptr [esp + 0x20]
// 00580fd3  6a00                 push 0
// 00580fd5  6a10                 push 0x10
// 00580fd7  56                   push esi
// 00580fd8  52                   push edx
// 00580fd9  e832090000           call 0x581910
// 00580fde  8a44243c             mov al, byte ptr [esp + 0x3c]
// 00580fe2  838eb800000010       or dword ptr [esi + 0xb8], 0x10
// 00580fe9  83c41c               add esp, 0x1c
// 00580fec  814e0800100000       or dword ptr [esi + 8], 0x1000
// 00580ff3  89bec4000000         mov dword ptr [esi + 0xc4], edi
// 00580ff9  5f                   pop edi
// 00580ffa  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 00581000  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 00581006  8886d0000000         mov byte ptr [esi + 0xd0], al
// 0058100c  5d                   pop ebp
// 0058100d  5e                   pop esi
// 0058100e  5b                   pop ebx
// 0058100f  c3                   ret 
// library libpng-1.2.24/pngset.c (function _png_set_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngset.c
