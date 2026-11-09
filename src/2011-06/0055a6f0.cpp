// from server: 100% by auto
// roc 2011-06 0055a6f0  unit: seg_00550000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a6f0
//
// 0055a6f0  51                   push ecx
// 0055a6f1  53                   push ebx
// 0055a6f2  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0055a6f6  85db                 test ebx, ebx
// 0055a6f8  0f843f010000         je 0x55a83d
// 0055a6fe  55                   push ebp
// 0055a6ff  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0055a703  85ed                 test ebp, ebp
// 0055a705  0f8431010000         je 0x55a83c
// 0055a70b  57                   push edi
// 0055a70c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055a710  85ff                 test edi, edi
// 0055a712  0f8423010000         je 0x55a83b
// 0055a718  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 0055a71e  03c7                 add eax, edi
// 0055a720  8d0480               lea eax, [eax + eax*4]
// 0055a723  03c0                 add eax, eax
// 0055a725  56                   push esi
// 0055a726  03c0                 add eax, eax
// 0055a728  50                   push eax
// 0055a729  53                   push ebx
// 0055a72a  e8a16f0000           call 0x5616d0
// 0055a72f  8bf0                 mov esi, eax
// 0055a731  83c408               add esp, 8
// 0055a734  89742410             mov dword ptr [esp + 0x10], esi
// 0055a738  85f6                 test esi, esi
// 0055a73a  7514                 jne 0x55a750
// 0055a73c  686025a800           push 0xa82560
// 0055a741  53                   push ebx
// 0055a742  e8996c0000           call 0x5613e0
// 0055a747  83c408               add esp, 8
// 0055a74a  5e                   pop esi
// 0055a74b  5f                   pop edi
// 0055a74c  5d                   pop ebp
// 0055a74d  5b                   pop ebx
// 0055a74e  59                   pop ecx
// 0055a74f  c3                   ret 
// 0055a750  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 0055a756  8b95bc000000         mov edx, dword ptr [ebp + 0xbc]
// 0055a75c  8d0c80               lea ecx, [eax + eax*4]
// 0055a75f  03c9                 add ecx, ecx
// 0055a761  03c9                 add ecx, ecx
// 0055a763  51                   push ecx
// 0055a764  52                   push edx
// 0055a765  56                   push esi
// 0055a766  e8710e2b00           call 0x80b5dc
// 0055a76b  8b85bc000000         mov eax, dword ptr [ebp + 0xbc]
// 0055a771  50                   push eax
// 0055a772  53                   push ebx
// 0055a773  e8286f0000           call 0x5616a0
// 0055a778  33c9                 xor ecx, ecx
// 0055a77a  83c414               add esp, 0x14
// 0055a77d  3bf9                 cmp edi, ecx
// 0055a77f  898dbc000000         mov dword ptr [ebp + 0xbc], ecx
// 0055a785  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055a789  0f8e95000000         jle 0x55a824
// 0055a78f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055a793  83c70c               add edi, 0xc
// 0055a796  eb08                 jmp 0x55a7a0
// 0055a798  8da42400000000       lea esp, [esp]
// 0055a79f  90                   nop 
// 0055a7a0  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 0055a7a6  8b57f4               mov edx, dword ptr [edi - 0xc]
// 0055a7a9  03c1                 add eax, ecx
// 0055a7ab  8d0c80               lea ecx, [eax + eax*4]
// 0055a7ae  8d348e               lea esi, [esi + ecx*4]
// 0055a7b1  8916                 mov dword ptr [esi], edx
// 0055a7b3  c6460400             mov byte ptr [esi + 4], 0
// 0055a7b7  8b0f                 mov ecx, dword ptr [edi]
// 0055a7b9  894e0c               mov dword ptr [esi + 0xc], ecx
// 0055a7bc  8a5368               mov dl, byte ptr [ebx + 0x68]
// 0055a7bf  885610               mov byte ptr [esi + 0x10], dl
// 0055a7c2  833f00               cmp dword ptr [edi], 0
// 0055a7c5  7509                 jne 0x55a7d0
// 0055a7c7  c7460800000000       mov dword ptr [esi + 8], 0
// 0055a7ce  eb3a                 jmp 0x55a80a
// 0055a7d0  8b07                 mov eax, dword ptr [edi]
// 0055a7d2  50                   push eax
// 0055a7d3  53                   push ebx
// 0055a7d4  e8f76e0000           call 0x5616d0
// 0055a7d9  83c408               add esp, 8
// 0055a7dc  894608               mov dword ptr [esi + 8], eax
// 0055a7df  85c0                 test eax, eax
// 0055a7e1  7517                 jne 0x55a7fa
// 0055a7e3  686025a800           push 0xa82560
// 0055a7e8  53                   push ebx
// 0055a7e9  e8f26b0000           call 0x5613e0
// 0055a7ee  83c408               add esp, 8
// 0055a7f1  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0055a7f8  eb10                 jmp 0x55a80a
// 0055a7fa  8b0f                 mov ecx, dword ptr [edi]
// 0055a7fc  8b57fc               mov edx, dword ptr [edi - 4]
// 0055a7ff  51                   push ecx
// 0055a800  52                   push edx
// 0055a801  50                   push eax
// 0055a802  e8d50d2b00           call 0x80b5dc
// 0055a807  83c40c               add esp, 0xc
// 0055a80a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055a80e  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055a812  41                   inc ecx
// 0055a813  83c714               add edi, 0x14
// 0055a816  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 0055a81a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0055a81e  7c80                 jl 0x55a7a0
// 0055a820  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0055a824  01bdc0000000         add dword ptr [ebp + 0xc0], edi
// 0055a82a  818db800000000020000 or dword ptr [ebp + 0xb8], 0x200
// 0055a834  89b5bc000000         mov dword ptr [ebp + 0xbc], esi
// 0055a83a  5e                   pop esi
// 0055a83b  5f                   pop edi
// 0055a83c  5d                   pop ebp
// 0055a83d  5b                   pop ebx
// 0055a83e  59                   pop ecx
// 0055a83f  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_unknown_chunks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
