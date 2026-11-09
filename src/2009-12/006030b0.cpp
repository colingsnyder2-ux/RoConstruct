// from server: 100% by auto
// roc 2009-12 006030b0  unit: seg_00600000  size: 389 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006030b0
//
// 006030b0  51                   push ecx
// 006030b1  55                   push ebp
// 006030b2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006030b6  85ed                 test ebp, ebp
// 006030b8  0f8474010000         je 0x603232
// 006030be  56                   push esi
// 006030bf  8b742414             mov esi, dword ptr [esp + 0x14]
// 006030c3  85f6                 test esi, esi
// 006030c5  0f8466010000         je 0x603231
// 006030cb  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 006030d1  53                   push ebx
// 006030d2  57                   push edi
// 006030d3  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006030d7  03c7                 add eax, edi
// 006030d9  c1e004               shl eax, 4
// 006030dc  50                   push eax
// 006030dd  55                   push ebp
// 006030de  e82ddc0000           call 0x610d10
// 006030e3  8bd8                 mov ebx, eax
// 006030e5  83c408               add esp, 8
// 006030e8  895c2410             mov dword ptr [esp + 0x10], ebx
// 006030ec  85db                 test ebx, ebx
// 006030ee  7514                 jne 0x603104
// 006030f0  6868379c00           push 0x9c3768
// 006030f5  55                   push ebp
// 006030f6  e845d10000           call 0x610240
// 006030fb  83c408               add esp, 8
// 006030fe  5f                   pop edi
// 006030ff  5b                   pop ebx
// 00603100  5e                   pop esi
// 00603101  5d                   pop ebp
// 00603102  59                   pop ecx
// 00603103  c3                   ret 
// 00603104  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0060310a  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00603110  c1e104               shl ecx, 4
// 00603113  51                   push ecx
// 00603114  52                   push edx
// 00603115  53                   push ebx
// 00603116  e8cb1b1f00           call 0x7f4ce6
// 0060311b  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00603121  50                   push eax
// 00603122  55                   push ebp
// 00603123  e8b8db0000           call 0x610ce0
// 00603128  33c0                 xor eax, eax
// 0060312a  83c414               add esp, 0x14
// 0060312d  3bf8                 cmp edi, eax
// 0060312f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00603135  89442418             mov dword ptr [esp + 0x18], eax
// 00603139  0f8ed6000000         jle 0x603215
// 0060313f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00603143  83c70c               add edi, 0xc
// 00603146  eb08                 jmp 0x603150
// 00603148  8da42400000000       lea esp, [esp]
// 0060314f  90                   nop 
// 00603150  8bb6d8000000         mov esi, dword ptr [esi + 0xd8]
// 00603156  03742418             add esi, dword ptr [esp + 0x18]
// 0060315a  8b47f4               mov eax, dword ptr [edi - 0xc]
// 0060315d  c1e604               shl esi, 4
// 00603160  03f3                 add esi, ebx
// 00603162  8d5001               lea edx, [eax + 1]
// 00603165  8a08                 mov cl, byte ptr [eax]
// 00603167  40                   inc eax
// 00603168  84c9                 test cl, cl
// 0060316a  75f9                 jne 0x603165
// 0060316c  2bc2                 sub eax, edx
// 0060316e  8d5801               lea ebx, [eax + 1]
// 00603171  53                   push ebx
// 00603172  55                   push ebp
// 00603173  e898db0000           call 0x610d10
// 00603178  83c408               add esp, 8
// 0060317b  8906                 mov dword ptr [esi], eax
// 0060317d  85c0                 test eax, eax
// 0060317f  7510                 jne 0x603191
// 00603181  683c379c00           push 0x9c373c
// 00603186  55                   push ebp
// 00603187  e8b4d00000           call 0x610240
// 0060318c  83c408               add esp, 8
// 0060318f  eb62                 jmp 0x6031f3
// 00603191  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 00603194  53                   push ebx
// 00603195  51                   push ecx
// 00603196  50                   push eax
// 00603197  e84a1b1f00           call 0x7f4ce6
// 0060319c  8b07                 mov eax, dword ptr [edi]
// 0060319e  8d1480               lea edx, [eax + eax*4]
// 006031a1  03d2                 add edx, edx
// 006031a3  52                   push edx
// 006031a4  55                   push ebp
// 006031a5  e866db0000           call 0x610d10
// 006031aa  83c414               add esp, 0x14
// 006031ad  894608               mov dword ptr [esi + 8], eax
// 006031b0  85c0                 test eax, eax
// 006031b2  751f                 jne 0x6031d3
// 006031b4  683c379c00           push 0x9c373c
// 006031b9  55                   push ebp
// 006031ba  e881d00000           call 0x610240
// 006031bf  8b06                 mov eax, dword ptr [esi]
// 006031c1  50                   push eax
// 006031c2  55                   push ebp
// 006031c3  e818db0000           call 0x610ce0
// 006031c8  83c410               add esp, 0x10
// 006031cb  c70600000000         mov dword ptr [esi], 0
// 006031d1  eb20                 jmp 0x6031f3
// 006031d3  8b0f                 mov ecx, dword ptr [edi]
// 006031d5  8b57fc               mov edx, dword ptr [edi - 4]
// 006031d8  8d0c89               lea ecx, [ecx + ecx*4]
// 006031db  03c9                 add ecx, ecx
// 006031dd  51                   push ecx
// 006031de  52                   push edx
// 006031df  50                   push eax
// 006031e0  e8011b1f00           call 0x7f4ce6
// 006031e5  8b07                 mov eax, dword ptr [edi]
// 006031e7  89460c               mov dword ptr [esi + 0xc], eax
// 006031ea  8a4ff8               mov cl, byte ptr [edi - 8]
// 006031ed  83c40c               add esp, 0xc
// 006031f0  884e04               mov byte ptr [esi + 4], cl
// 006031f3  8b442418             mov eax, dword ptr [esp + 0x18]
// 006031f7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006031fb  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006031ff  40                   inc eax
// 00603200  83c710               add edi, 0x10
// 00603203  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00603207  89442418             mov dword ptr [esp + 0x18], eax
// 0060320b  0f8c3fffffff         jl 0x603150
// 00603211  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00603215  01bed8000000         add dword ptr [esi + 0xd8], edi
// 0060321b  814e0800200000       or dword ptr [esi + 8], 0x2000
// 00603222  838eb800000020       or dword ptr [esi + 0xb8], 0x20
// 00603229  5f                   pop edi
// 0060322a  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00603230  5b                   pop ebx
// 00603231  5e                   pop esi
// 00603232  5d                   pop ebp
// 00603233  59                   pop ecx
// 00603234  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
