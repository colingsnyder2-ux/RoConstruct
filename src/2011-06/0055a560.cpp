// from server: 100% by auto
// roc 2011-06 0055a560  unit: seg_00550000  size: 389 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a560
//
// 0055a560  51                   push ecx
// 0055a561  55                   push ebp
// 0055a562  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0055a566  85ed                 test ebp, ebp
// 0055a568  0f8474010000         je 0x55a6e2
// 0055a56e  56                   push esi
// 0055a56f  8b742414             mov esi, dword ptr [esp + 0x14]
// 0055a573  85f6                 test esi, esi
// 0055a575  0f8466010000         je 0x55a6e1
// 0055a57b  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0055a581  53                   push ebx
// 0055a582  57                   push edi
// 0055a583  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0055a587  03c7                 add eax, edi
// 0055a589  c1e004               shl eax, 4
// 0055a58c  50                   push eax
// 0055a58d  55                   push ebp
// 0055a58e  e83d710000           call 0x5616d0
// 0055a593  8bd8                 mov ebx, eax
// 0055a595  83c408               add esp, 8
// 0055a598  895c2410             mov dword ptr [esp + 0x10], ebx
// 0055a59c  85db                 test ebx, ebx
// 0055a59e  7514                 jne 0x55a5b4
// 0055a5a0  684025a800           push 0xa82540
// 0055a5a5  55                   push ebp
// 0055a5a6  e8356e0000           call 0x5613e0
// 0055a5ab  83c408               add esp, 8
// 0055a5ae  5f                   pop edi
// 0055a5af  5b                   pop ebx
// 0055a5b0  5e                   pop esi
// 0055a5b1  5d                   pop ebp
// 0055a5b2  59                   pop ecx
// 0055a5b3  c3                   ret 
// 0055a5b4  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0055a5ba  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 0055a5c0  c1e104               shl ecx, 4
// 0055a5c3  51                   push ecx
// 0055a5c4  52                   push edx
// 0055a5c5  53                   push ebx
// 0055a5c6  e811102b00           call 0x80b5dc
// 0055a5cb  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 0055a5d1  50                   push eax
// 0055a5d2  55                   push ebp
// 0055a5d3  e8c8700000           call 0x5616a0
// 0055a5d8  33c0                 xor eax, eax
// 0055a5da  83c414               add esp, 0x14
// 0055a5dd  3bf8                 cmp edi, eax
// 0055a5df  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0055a5e5  89442418             mov dword ptr [esp + 0x18], eax
// 0055a5e9  0f8ed6000000         jle 0x55a6c5
// 0055a5ef  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055a5f3  83c70c               add edi, 0xc
// 0055a5f6  eb08                 jmp 0x55a600
// 0055a5f8  8da42400000000       lea esp, [esp]
// 0055a5ff  90                   nop 
// 0055a600  8bb6d8000000         mov esi, dword ptr [esi + 0xd8]
// 0055a606  03742418             add esi, dword ptr [esp + 0x18]
// 0055a60a  8b47f4               mov eax, dword ptr [edi - 0xc]
// 0055a60d  c1e604               shl esi, 4
// 0055a610  03f3                 add esi, ebx
// 0055a612  8d5001               lea edx, [eax + 1]
// 0055a615  8a08                 mov cl, byte ptr [eax]
// 0055a617  40                   inc eax
// 0055a618  84c9                 test cl, cl
// 0055a61a  75f9                 jne 0x55a615
// 0055a61c  2bc2                 sub eax, edx
// 0055a61e  8d5801               lea ebx, [eax + 1]
// 0055a621  53                   push ebx
// 0055a622  55                   push ebp
// 0055a623  e8a8700000           call 0x5616d0
// 0055a628  83c408               add esp, 8
// 0055a62b  8906                 mov dword ptr [esi], eax
// 0055a62d  85c0                 test eax, eax
// 0055a62f  7510                 jne 0x55a641
// 0055a631  681425a800           push 0xa82514
// 0055a636  55                   push ebp
// 0055a637  e8a46d0000           call 0x5613e0
// 0055a63c  83c408               add esp, 8
// 0055a63f  eb62                 jmp 0x55a6a3
// 0055a641  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 0055a644  53                   push ebx
// 0055a645  51                   push ecx
// 0055a646  50                   push eax
// 0055a647  e8900f2b00           call 0x80b5dc
// 0055a64c  8b07                 mov eax, dword ptr [edi]
// 0055a64e  8d1480               lea edx, [eax + eax*4]
// 0055a651  03d2                 add edx, edx
// 0055a653  52                   push edx
// 0055a654  55                   push ebp
// 0055a655  e876700000           call 0x5616d0
// 0055a65a  83c414               add esp, 0x14
// 0055a65d  894608               mov dword ptr [esi + 8], eax
// 0055a660  85c0                 test eax, eax
// 0055a662  751f                 jne 0x55a683
// 0055a664  681425a800           push 0xa82514
// 0055a669  55                   push ebp
// 0055a66a  e8716d0000           call 0x5613e0
// 0055a66f  8b06                 mov eax, dword ptr [esi]
// 0055a671  50                   push eax
// 0055a672  55                   push ebp
// 0055a673  e828700000           call 0x5616a0
// 0055a678  83c410               add esp, 0x10
// 0055a67b  c70600000000         mov dword ptr [esi], 0
// 0055a681  eb20                 jmp 0x55a6a3
// 0055a683  8b0f                 mov ecx, dword ptr [edi]
// 0055a685  8b57fc               mov edx, dword ptr [edi - 4]
// 0055a688  8d0c89               lea ecx, [ecx + ecx*4]
// 0055a68b  03c9                 add ecx, ecx
// 0055a68d  51                   push ecx
// 0055a68e  52                   push edx
// 0055a68f  50                   push eax
// 0055a690  e8470f2b00           call 0x80b5dc
// 0055a695  8b07                 mov eax, dword ptr [edi]
// 0055a697  89460c               mov dword ptr [esi + 0xc], eax
// 0055a69a  8a4ff8               mov cl, byte ptr [edi - 8]
// 0055a69d  83c40c               add esp, 0xc
// 0055a6a0  884e04               mov byte ptr [esi + 4], cl
// 0055a6a3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0055a6a7  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0055a6ab  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055a6af  40                   inc eax
// 0055a6b0  83c710               add edi, 0x10
// 0055a6b3  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0055a6b7  89442418             mov dword ptr [esp + 0x18], eax
// 0055a6bb  0f8c3fffffff         jl 0x55a600
// 0055a6c1  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0055a6c5  01bed8000000         add dword ptr [esi + 0xd8], edi
// 0055a6cb  814e0800200000       or dword ptr [esi + 8], 0x2000
// 0055a6d2  838eb800000020       or dword ptr [esi + 0xb8], 0x20
// 0055a6d9  5f                   pop edi
// 0055a6da  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 0055a6e0  5b                   pop ebx
// 0055a6e1  5e                   pop esi
// 0055a6e2  5d                   pop ebp
// 0055a6e3  59                   pop ecx
// 0055a6e4  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
