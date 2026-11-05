// from server: 100% by auto
// roc 2009-12 007d4080  unit: seg_007d0000  size: 274 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4080
//
// 007d4080  83ec18               sub esp, 0x18
// 007d4083  53                   push ebx
// 007d4084  56                   push esi
// 007d4085  57                   push edi
// 007d4086  8bf0                 mov esi, eax
// 007d4088  33db                 xor ebx, ebx
// 007d408a  55                   push ebp
// 007d408b  eb03                 jmp 0x7d4090
// 007d408d  8d4900               lea ecx, [ecx]
// 007d4090  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d4097  7424                 je 0x7d40bd
// 007d4099  681d010000           push 0x11d
// 007d409e  56                   push esi
// 007d409f  e89c110000           call 0x7d5240
// 007d40a4  50                   push eax
// 007d40a5  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d40a8  68d0ed9e00           push 0x9eedd0
// 007d40ad  50                   push eax
// 007d40ae  e8cd64fcff           call 0x79a580
// 007d40b3  50                   push eax
// 007d40b4  56                   push esi
// 007d40b5  e886120000           call 0x7d5340
// 007d40ba  83c41c               add esp, 0x1c
// 007d40bd  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 007d40c0  56                   push esi
// 007d40c1  e86a260000           call 0x7d6730
// 007d40c6  8b7e30               mov edi, dword ptr [esi + 0x30]
// 007d40c9  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007d40cd  8d541901             lea edx, [ecx + ebx + 1]
// 007d40d1  83c404               add esp, 4
// 007d40d4  81fac8000000         cmp edx, 0xc8
// 007d40da  7e47                 jle 0x7d4123
// 007d40dc  8b07                 mov eax, dword ptr [edi]
// 007d40de  8b403c               mov eax, dword ptr [eax + 0x3c]
// 007d40e1  6874ee9e00           push 0x9eee74
// 007d40e6  68c8000000           push 0xc8
// 007d40eb  85c0                 test eax, eax
// 007d40ed  7513                 jne 0x7d4102
// 007d40ef  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 007d40f2  6808ee9e00           push 0x9eee08
// 007d40f7  51                   push ecx
// 007d40f8  e88364fcff           call 0x79a580
// 007d40fd  83c410               add esp, 0x10
// 007d4100  eb12                 jmp 0x7d4114
// 007d4102  8b5710               mov edx, dword ptr [edi + 0x10]
// 007d4105  50                   push eax
// 007d4106  68e0ed9e00           push 0x9eede0
// 007d410b  52                   push edx
// 007d410c  e86f64fcff           call 0x79a580
// 007d4111  83c414               add esp, 0x14
// 007d4114  6a00                 push 0
// 007d4116  50                   push eax
// 007d4117  8b470c               mov eax, dword ptr [edi + 0xc]
// 007d411a  50                   push eax
// 007d411b  e880110000           call 0x7d52a0
// 007d4120  83c40c               add esp, 0xc
// 007d4123  55                   push ebp
// 007d4124  56                   push esi
// 007d4125  e8a6d8ffff           call 0x7d19d0
// 007d412a  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007d412e  03cb                 add ecx, ebx
// 007d4130  83c408               add esp, 8
// 007d4133  6689844fac000000     mov word ptr [edi + ecx*2 + 0xac], ax
// 007d413b  43                   inc ebx
// 007d413c  837e102c             cmp dword ptr [esi + 0x10], 0x2c
// 007d4140  750e                 jne 0x7d4150
// 007d4142  56                   push esi
// 007d4143  e8e8250000           call 0x7d6730
// 007d4148  83c404               add esp, 4
// 007d414b  e940ffffff           jmp 0x7d4090
// 007d4150  837e103d             cmp dword ptr [esi + 0x10], 0x3d
// 007d4154  5d                   pop ebp
// 007d4155  7514                 jne 0x7d416b
// 007d4157  56                   push esi
// 007d4158  e8d3250000           call 0x7d6730
// 007d415d  83c404               add esp, 4
// 007d4160  8d7c240c             lea edi, [esp + 0xc]
// 007d4164  e8d7e6ffff           call 0x7d2840
// 007d4169  eb06                 jmp 0x7d4171
// 007d416b  33c0                 xor eax, eax
// 007d416d  8944240c             mov dword ptr [esp + 0xc], eax
// 007d4171  50                   push eax
// 007d4172  8d4c2410             lea ecx, [esp + 0x10]
// 007d4176  8bd3                 mov edx, ebx
// 007d4178  8bc6                 mov eax, esi
// 007d417a  e8f1dbffff           call 0x7d1d70
// 007d417f  83c404               add esp, 4
// 007d4182  8bd3                 mov edx, ebx
// 007d4184  8bc6                 mov eax, esi
// 007d4186  e8e5d8ffff           call 0x7d1a70
// 007d418b  5f                   pop edi
// 007d418c  5e                   pop esi
// 007d418d  5b                   pop ebx
// 007d418e  83c418               add esp, 0x18
// 007d4191  c3                   ret 
// library lua-5.1/lparser.c (function _localstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
