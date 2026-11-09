// from server: 100% by auto
// roc 2009-12 007dcef0  unit: RBX::GroupDragTool  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcef0
//
// 007dcef0  53                   push ebx
// 007dcef1  55                   push ebp
// 007dcef2  56                   push esi
// 007dcef3  8b742410             mov esi, dword ptr [esp + 0x10]
// 007dcef7  57                   push edi
// 007dcef8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007dcefc  57                   push edi
// 007dcefd  56                   push esi
// 007dcefe  e88dfdffff           call 0x7dcc90
// 007dcf03  83c408               add esp, 8
// 007dcf06  833f0c               cmp dword ptr [edi], 0xc
// 007dcf09  7515                 jne 0x7dcf20
// 007dcf0b  8b4708               mov eax, dword ptr [edi + 8]
// 007dcf0e  a900010000           test eax, 0x100
// 007dcf13  750b                 jne 0x7dcf20
// 007dcf15  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007dcf19  3bc1                 cmp eax, ecx
// 007dcf1b  7c03                 jl 0x7dcf20
// 007dcf1d  ff4e24               dec dword ptr [esi + 0x24]
// 007dcf20  8b16                 mov edx, dword ptr [esi]
// 007dcf22  8b6e24               mov ebp, dword ptr [esi + 0x24]
// 007dcf25  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 007dcf29  8d5d02               lea ebx, [ebp + 2]
// 007dcf2c  3bd8                 cmp ebx, eax
// 007dcf2e  7e1e                 jle 0x7dcf4e
// 007dcf30  81fbfa000000         cmp ebx, 0xfa
// 007dcf36  7c11                 jl 0x7dcf49
// 007dcf38  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dcf3b  6834fb9e00           push 0x9efb34
// 007dcf40  51                   push ecx
// 007dcf41  e8fa83ffff           call 0x7d5340
// 007dcf46  83c408               add esp, 8
// 007dcf49  8b16                 mov edx, dword ptr [esi]
// 007dcf4b  885a4b               mov byte ptr [edx + 0x4b], bl
// 007dcf4e  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007dcf52  83462402             add dword ptr [esi + 0x24], 2
// 007dcf56  53                   push ebx
// 007dcf57  56                   push esi
// 007dcf58  e8a3fdffff           call 0x7dcd00
// 007dcf5d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dcf60  8b5108               mov edx, dword ptr [ecx + 8]
// 007dcf63  8b4f08               mov ecx, dword ptr [edi + 8]
// 007dcf66  c1e109               shl ecx, 9
// 007dcf69  0bc8                 or ecx, eax
// 007dcf6b  c1e108               shl ecx, 8
// 007dcf6e  0bcd                 or ecx, ebp
// 007dcf70  c1e106               shl ecx, 6
// 007dcf73  52                   push edx
// 007dcf74  83c90b               or ecx, 0xb
// 007dcf77  51                   push ecx
// 007dcf78  e8e3f5ffff           call 0x7dc560
// 007dcf7d  83c410               add esp, 0x10
// 007dcf80  833b0c               cmp dword ptr [ebx], 0xc
// 007dcf83  7516                 jne 0x7dcf9b
// 007dcf85  8b5b08               mov ebx, dword ptr [ebx + 8]
// 007dcf88  f7c300010000         test ebx, 0x100
// 007dcf8e  750b                 jne 0x7dcf9b
// 007dcf90  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007dcf94  3bda                 cmp ebx, edx
// 007dcf96  7c03                 jl 0x7dcf9b
// 007dcf98  ff4e24               dec dword ptr [esi + 0x24]
// 007dcf9b  896f08               mov dword ptr [edi + 8], ebp
// 007dcf9e  c7070c000000         mov dword ptr [edi], 0xc
// 007dcfa4  5f                   pop edi
// 007dcfa5  5e                   pop esi
// 007dcfa6  5d                   pop ebp
// 007dcfa7  5b                   pop ebx
// 007dcfa8  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_self)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
