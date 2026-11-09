// from server: 100% by auto
// roc 2009-06 0057f590  unit: G3D::_internal::DialogTemplate  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057f590
//
// 0057f590  55                   push ebp
// 0057f591  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0057f595  85ed                 test ebp, ebp
// 0057f597  0f8459010000         je 0x57f6f6
// 0057f59d  f6456804             test byte ptr [ebp + 0x68], 4
// 0057f5a1  750e                 jne 0x57f5b1
// 0057f5a3  68c0c28c00           push 0x8cc2c0
// 0057f5a8  55                   push ebp
// 0057f5a9  e8b2eb0000           call 0x58e160
// 0057f5ae  83c408               add esp, 8
// 0057f5b1  56                   push esi
// 0057f5b2  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057f5b6  85f6                 test esi, esi
// 0057f5b8  0f842a010000         je 0x57f6e8
// 0057f5be  b800020000           mov eax, 0x200
// 0057f5c3  854608               test dword ptr [esi + 8], eax
// 0057f5c6  7412                 je 0x57f5da
// 0057f5c8  854568               test dword ptr [ebp + 0x68], eax
// 0057f5cb  750d                 jne 0x57f5da
// 0057f5cd  8d463c               lea eax, [esi + 0x3c]
// 0057f5d0  50                   push eax
// 0057f5d1  55                   push ebp
// 0057f5d2  e869d90000           call 0x58cf40
// 0057f5d7  83c408               add esp, 8
// 0057f5da  53                   push ebx
// 0057f5db  33db                 xor ebx, ebx
// 0057f5dd  395e30               cmp dword ptr [esi + 0x30], ebx
// 0057f5e0  57                   push edi
// 0057f5e1  0f8e88000000         jle 0x57f66f
// 0057f5e7  33ff                 xor edi, edi
// 0057f5e9  8da42400000000       lea esp, [esp]
// 0057f5f0  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0057f5f3  8b040f               mov eax, dword ptr [edi + ecx]
// 0057f5f6  85c0                 test eax, eax
// 0057f5f8  7e1a                 jle 0x57f614
// 0057f5fa  6870c28c00           push 0x8cc270
// 0057f5ff  55                   push ebp
// 0057f600  e80bec0000           call 0x58e210
// 0057f605  8b5638               mov edx, dword ptr [esi + 0x38]
// 0057f608  83c408               add esp, 8
// 0057f60b  c70417fdffffff       mov dword ptr [edi + edx], 0xfffffffd
// 0057f612  eb52                 jmp 0x57f666
// 0057f614  7c28                 jl 0x57f63e
// 0057f616  8bc1                 mov eax, ecx
// 0057f618  8b0c38               mov ecx, dword ptr [eax + edi]
// 0057f61b  8b543808             mov edx, dword ptr [eax + edi + 8]
// 0057f61f  03c7                 add eax, edi
// 0057f621  8b4004               mov eax, dword ptr [eax + 4]
// 0057f624  51                   push ecx
// 0057f625  6a00                 push 0
// 0057f627  52                   push edx
// 0057f628  50                   push eax
// 0057f629  55                   push ebp
// 0057f62a  e8b1bb0000           call 0x58b1e0
// 0057f62f  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0057f632  83c414               add esp, 0x14
// 0057f635  c7040ffeffffff       mov dword ptr [edi + ecx], 0xfffffffe
// 0057f63c  eb28                 jmp 0x57f666
// 0057f63e  83f8ff               cmp eax, -1
// 0057f641  7523                 jne 0x57f666
// 0057f643  8bd1                 mov edx, ecx
// 0057f645  8b4c3a08             mov ecx, dword ptr [edx + edi + 8]
// 0057f649  8d043a               lea eax, [edx + edi]
// 0057f64c  8b5004               mov edx, dword ptr [eax + 4]
// 0057f64f  6a00                 push 0
// 0057f651  51                   push ecx
// 0057f652  52                   push edx
// 0057f653  55                   push ebp
// 0057f654  e8a7ba0000           call 0x58b100
// 0057f659  8b4638               mov eax, dword ptr [esi + 0x38]
// 0057f65c  83c410               add esp, 0x10
// 0057f65f  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 0057f666  43                   inc ebx
// 0057f667  83c710               add edi, 0x10
// 0057f66a  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 0057f66d  7c81                 jl 0x57f5f0
// 0057f66f  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0057f675  85c0                 test eax, eax
// 0057f677  746d                 je 0x57f6e6
// 0057f679  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 0057f67f  8d0c80               lea ecx, [eax + eax*4]
// 0057f682  8d148f               lea edx, [edi + ecx*4]
// 0057f685  3bfa                 cmp edi, edx
// 0057f687  735d                 jae 0x57f6e6
// 0057f689  bb00000100           mov ebx, 0x10000
// 0057f68e  8bff                 mov edi, edi
// 0057f690  57                   push edi
// 0057f691  55                   push ebp
// 0057f692  e899260000           call 0x581d30
// 0057f697  83c408               add esp, 8
// 0057f69a  83f801               cmp eax, 1
// 0057f69d  742e                 je 0x57f6cd
// 0057f69f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 0057f6a2  84c9                 test cl, cl
// 0057f6a4  7427                 je 0x57f6cd
// 0057f6a6  f6c108               test cl, 8
// 0057f6a9  7422                 je 0x57f6cd
// 0057f6ab  f6470320             test byte ptr [edi + 3], 0x20
// 0057f6af  750a                 jne 0x57f6bb
// 0057f6b1  83f803               cmp eax, 3
// 0057f6b4  7405                 je 0x57f6bb
// 0057f6b6  855d6c               test dword ptr [ebp + 0x6c], ebx
// 0057f6b9  7412                 je 0x57f6cd
// 0057f6bb  8b470c               mov eax, dword ptr [edi + 0xc]
// 0057f6be  8b4f08               mov ecx, dword ptr [edi + 8]
// 0057f6c1  50                   push eax
// 0057f6c2  51                   push ecx
// 0057f6c3  57                   push edi
// 0057f6c4  55                   push ebp
// 0057f6c5  e856c30000           call 0x58ba20
// 0057f6ca  83c410               add esp, 0x10
// 0057f6cd  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0057f6d3  8d1480               lea edx, [eax + eax*4]
// 0057f6d6  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0057f6dc  83c714               add edi, 0x14
// 0057f6df  8d0c90               lea ecx, [eax + edx*4]
// 0057f6e2  3bf9                 cmp edi, ecx
// 0057f6e4  72aa                 jb 0x57f690
// 0057f6e6  5f                   pop edi
// 0057f6e7  5b                   pop ebx
// 0057f6e8  834d6808             or dword ptr [ebp + 0x68], 8
// 0057f6ec  55                   push ebp
// 0057f6ed  e82ec90000           call 0x58c020
// 0057f6f2  83c404               add esp, 4
// 0057f6f5  5e                   pop esi
// 0057f6f6  5d                   pop ebp
// 0057f6f7  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
