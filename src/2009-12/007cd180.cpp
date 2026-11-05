// from server: 100% by auto
// roc 2009-12 007cd180  unit: RBX::PartDropTool  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd180
//
// 007cd180  837e2000             cmp dword ptr [esi + 0x20], 0
// 007cd184  7407                 je 0x7cd18d
// 007cd186  8b4620               mov eax, dword ptr [esi + 0x20]
// 007cd189  806005fc             and byte ptr [eax + 5], 0xfc
// 007cd18d  57                   push edi
// 007cd18e  33ff                 xor edi, edi
// 007cd190  397e28               cmp dword ptr [esi + 0x28], edi
// 007cd193  7e36                 jle 0x7cd1cb
// 007cd195  55                   push ebp
// 007cd196  33ed                 xor ebp, ebp
// 007cd198  eb06                 jmp 0x7cd1a0
// 007cd19a  8d9b00000000         lea ebx, [ebx]
// 007cd1a0  8b4608               mov eax, dword ptr [esi + 8]
// 007cd1a3  03c5                 add eax, ebp
// 007cd1a5  83780804             cmp dword ptr [eax + 8], 4
// 007cd1a9  7c16                 jl 0x7cd1c1
// 007cd1ab  8b00                 mov eax, dword ptr [eax]
// 007cd1ad  f6400503             test byte ptr [eax + 5], 3
// 007cd1b1  740e                 je 0x7cd1c1
// 007cd1b3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007cd1b7  50                   push eax
// 007cd1b8  51                   push ecx
// 007cd1b9  e892fcffff           call 0x7cce50
// 007cd1be  83c408               add esp, 8
// 007cd1c1  47                   inc edi
// 007cd1c2  83c510               add ebp, 0x10
// 007cd1c5  3b7e28               cmp edi, dword ptr [esi + 0x28]
// 007cd1c8  7cd6                 jl 0x7cd1a0
// 007cd1ca  5d                   pop ebp
// 007cd1cb  33c0                 xor eax, eax
// 007cd1cd  394624               cmp dword ptr [esi + 0x24], eax
// 007cd1d0  7e18                 jle 0x7cd1ea
// 007cd1d2  8b561c               mov edx, dword ptr [esi + 0x1c]
// 007cd1d5  833c8200             cmp dword ptr [edx + eax*4], 0
// 007cd1d9  7409                 je 0x7cd1e4
// 007cd1db  8bca                 mov ecx, edx
// 007cd1dd  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 007cd1e0  806105fc             and byte ptr [ecx + 5], 0xfc
// 007cd1e4  40                   inc eax
// 007cd1e5  3b4624               cmp eax, dword ptr [esi + 0x24]
// 007cd1e8  7ce8                 jl 0x7cd1d2
// 007cd1ea  33ff                 xor edi, edi
// 007cd1ec  397e34               cmp dword ptr [esi + 0x34], edi
// 007cd1ef  7e28                 jle 0x7cd219
// 007cd1f1  8b5610               mov edx, dword ptr [esi + 0x10]
// 007cd1f4  833cba00             cmp dword ptr [edx + edi*4], 0
// 007cd1f8  8d04ba               lea eax, [edx + edi*4]
// 007cd1fb  7416                 je 0x7cd213
// 007cd1fd  8b00                 mov eax, dword ptr [eax]
// 007cd1ff  f6400503             test byte ptr [eax + 5], 3
// 007cd203  740e                 je 0x7cd213
// 007cd205  50                   push eax
// 007cd206  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007cd20a  50                   push eax
// 007cd20b  e840fcffff           call 0x7cce50
// 007cd210  83c408               add esp, 8
// 007cd213  47                   inc edi
// 007cd214  3b7e34               cmp edi, dword ptr [esi + 0x34]
// 007cd217  7cd8                 jl 0x7cd1f1
// 007cd219  33ff                 xor edi, edi
// 007cd21b  397e38               cmp dword ptr [esi + 0x38], edi
// 007cd21e  7e26                 jle 0x7cd246
// 007cd220  33c0                 xor eax, eax
// 007cd222  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007cd225  833c0800             cmp dword ptr [eax + ecx], 0
// 007cd229  7412                 je 0x7cd23d
// 007cd22b  8bd1                 mov edx, ecx
// 007cd22d  8d0c02               lea ecx, [edx + eax]
// 007cd230  8b11                 mov edx, dword ptr [ecx]
// 007cd232  8a5205               mov dl, byte ptr [edx + 5]
// 007cd235  8b09                 mov ecx, dword ptr [ecx]
// 007cd237  80e2fc               and dl, 0xfc
// 007cd23a  885105               mov byte ptr [ecx + 5], dl
// 007cd23d  47                   inc edi
// 007cd23e  83c00c               add eax, 0xc
// 007cd241  3b7e38               cmp edi, dword ptr [esi + 0x38]
// 007cd244  7cdc                 jl 0x7cd222
// 007cd246  5f                   pop edi
// 007cd247  c3                   ret 
// library lua-5.1/lgc.c (function _traverseproto)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
