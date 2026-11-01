// from server: 100% by auto
// roc 2007-03 00508490  unit: seg_00500000  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00508490
//
// 00508490  55                   push ebp
// 00508491  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00508495  f6456804             test byte ptr [ebp + 0x68], 4
// 00508499  56                   push esi
// 0050849a  750e                 jne 0x5084aa
// 0050849c  6828087a00           push 0x7a0828
// 005084a1  55                   push ebp
// 005084a2  e879fe0000           call 0x518320
// 005084a7  83c408               add esp, 8
// 005084aa  8b742410             mov esi, dword ptr [esp + 0x10]
// 005084ae  85f6                 test esi, esi
// 005084b0  0f8427010000         je 0x5085dd
// 005084b6  b800020000           mov eax, 0x200
// 005084bb  854608               test dword ptr [esi + 8], eax
// 005084be  7412                 je 0x5084d2
// 005084c0  854568               test dword ptr [ebp + 0x68], eax
// 005084c3  750d                 jne 0x5084d2
// 005084c5  8d463c               lea eax, [esi + 0x3c]
// 005084c8  50                   push eax
// 005084c9  55                   push ebp
// 005084ca  e8d1eb0000           call 0x5170a0
// 005084cf  83c408               add esp, 8
// 005084d2  53                   push ebx
// 005084d3  33db                 xor ebx, ebx
// 005084d5  395e30               cmp dword ptr [esi + 0x30], ebx
// 005084d8  57                   push edi
// 005084d9  0f8e87000000         jle 0x508566
// 005084df  33ff                 xor edi, edi
// 005084e1  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005084e4  8b040f               mov eax, dword ptr [edi + ecx]
// 005084e7  85c0                 test eax, eax
// 005084e9  7e1a                 jle 0x508505
// 005084eb  68d8077a00           push 0x7a07d8
// 005084f0  55                   push ebp
// 005084f1  e8dafe0000           call 0x5183d0
// 005084f6  8b5638               mov edx, dword ptr [esi + 0x38]
// 005084f9  83c408               add esp, 8
// 005084fc  c70417fdffffff       mov dword ptr [edi + edx], 0xfffffffd
// 00508503  eb52                 jmp 0x508557
// 00508505  7c28                 jl 0x50852f
// 00508507  8bc1                 mov eax, ecx
// 00508509  8b0c38               mov ecx, dword ptr [eax + edi]
// 0050850c  8b543808             mov edx, dword ptr [eax + edi + 8]
// 00508510  03c7                 add eax, edi
// 00508512  8b4004               mov eax, dword ptr [eax + 4]
// 00508515  51                   push ecx
// 00508516  6a00                 push 0
// 00508518  52                   push edx
// 00508519  50                   push eax
// 0050851a  55                   push ebp
// 0050851b  e820d30000           call 0x515840
// 00508520  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00508523  83c414               add esp, 0x14
// 00508526  c7040ffeffffff       mov dword ptr [edi + ecx], 0xfffffffe
// 0050852d  eb28                 jmp 0x508557
// 0050852f  83f8ff               cmp eax, -1
// 00508532  7523                 jne 0x508557
// 00508534  8bd1                 mov edx, ecx
// 00508536  8b4c3a08             mov ecx, dword ptr [edx + edi + 8]
// 0050853a  8d043a               lea eax, [edx + edi]
// 0050853d  8b5004               mov edx, dword ptr [eax + 4]
// 00508540  6a00                 push 0
// 00508542  51                   push ecx
// 00508543  52                   push edx
// 00508544  55                   push ebp
// 00508545  e846d20000           call 0x515790
// 0050854a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0050854d  83c410               add esp, 0x10
// 00508550  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00508557  83c301               add ebx, 1
// 0050855a  83c710               add edi, 0x10
// 0050855d  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 00508560  0f8c7bffffff         jl 0x5084e1
// 00508566  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0050856c  85c0                 test eax, eax
// 0050856e  746b                 je 0x5085db
// 00508570  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00508576  8d0c80               lea ecx, [eax + eax*4]
// 00508579  8d148f               lea edx, [edi + ecx*4]
// 0050857c  3bfa                 cmp edi, edx
// 0050857e  735b                 jae 0x5085db
// 00508580  bb00000100           mov ebx, 0x10000
// 00508585  57                   push edi
// 00508586  55                   push ebp
// 00508587  e804260000           call 0x50ab90
// 0050858c  83c408               add esp, 8
// 0050858f  83f801               cmp eax, 1
// 00508592  742e                 je 0x5085c2
// 00508594  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00508597  84c9                 test cl, cl
// 00508599  7427                 je 0x5085c2
// 0050859b  f6c108               test cl, 8
// 0050859e  7422                 je 0x5085c2
// 005085a0  f6470320             test byte ptr [edi + 3], 0x20
// 005085a4  750a                 jne 0x5085b0
// 005085a6  83f803               cmp eax, 3
// 005085a9  7405                 je 0x5085b0
// 005085ab  855d6c               test dword ptr [ebp + 0x6c], ebx
// 005085ae  7412                 je 0x5085c2
// 005085b0  8b470c               mov eax, dword ptr [edi + 0xc]
// 005085b3  8b4f08               mov ecx, dword ptr [edi + 8]
// 005085b6  50                   push eax
// 005085b7  51                   push ecx
// 005085b8  57                   push edi
// 005085b9  55                   push ebp
// 005085ba  e821da0000           call 0x515fe0
// 005085bf  83c410               add esp, 0x10
// 005085c2  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 005085c8  8d1480               lea edx, [eax + eax*4]
// 005085cb  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 005085d1  83c714               add edi, 0x14
// 005085d4  8d0c90               lea ecx, [eax + edx*4]
// 005085d7  3bf9                 cmp edi, ecx
// 005085d9  72aa                 jb 0x508585
// 005085db  5f                   pop edi
// 005085dc  5b                   pop ebx
// 005085dd  834d6808             or dword ptr [ebp + 0x68], 8
// 005085e1  55                   push ebp
// 005085e2  e8b9de0000           call 0x5164a0
// 005085e7  83c404               add esp, 4
// 005085ea  5e                   pop esi
// 005085eb  5d                   pop ebp
// 005085ec  c3                   ret 
// library libpng-1.2.7/pngwrite.c (function _png_write_end)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwrite.c
