// from server: 100% by auto
// roc 2007-03 005f8d00  unit: seg_005f0000  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8d00
//
// 005f8d00  837e2000             cmp dword ptr [esi + 0x20], 0
// 005f8d04  7407                 je 0x5f8d0d
// 005f8d06  8b4620               mov eax, dword ptr [esi + 0x20]
// 005f8d09  806005fc             and byte ptr [eax + 5], 0xfc
// 005f8d0d  57                   push edi
// 005f8d0e  33ff                 xor edi, edi
// 005f8d10  397e28               cmp dword ptr [esi + 0x28], edi
// 005f8d13  7e38                 jle 0x5f8d4d
// 005f8d15  55                   push ebp
// 005f8d16  33ed                 xor ebp, ebp
// 005f8d18  eb06                 jmp 0x5f8d20
// 005f8d1a  8d9b00000000         lea ebx, [ebx]
// 005f8d20  8b4608               mov eax, dword ptr [esi + 8]
// 005f8d23  03c5                 add eax, ebp
// 005f8d25  83780804             cmp dword ptr [eax + 8], 4
// 005f8d29  7c16                 jl 0x5f8d41
// 005f8d2b  8b00                 mov eax, dword ptr [eax]
// 005f8d2d  f6400503             test byte ptr [eax + 5], 3
// 005f8d31  740e                 je 0x5f8d41
// 005f8d33  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005f8d37  50                   push eax
// 005f8d38  51                   push ecx
// 005f8d39  e882fcffff           call 0x5f89c0
// 005f8d3e  83c408               add esp, 8
// 005f8d41  83c701               add edi, 1
// 005f8d44  83c510               add ebp, 0x10
// 005f8d47  3b7e28               cmp edi, dword ptr [esi + 0x28]
// 005f8d4a  7cd4                 jl 0x5f8d20
// 005f8d4c  5d                   pop ebp
// 005f8d4d  33c0                 xor eax, eax
// 005f8d4f  394624               cmp dword ptr [esi + 0x24], eax
// 005f8d52  7e1a                 jle 0x5f8d6e
// 005f8d54  8b561c               mov edx, dword ptr [esi + 0x1c]
// 005f8d57  833c8200             cmp dword ptr [edx + eax*4], 0
// 005f8d5b  7409                 je 0x5f8d66
// 005f8d5d  8bca                 mov ecx, edx
// 005f8d5f  8b0c81               mov ecx, dword ptr [ecx + eax*4]
// 005f8d62  806105fc             and byte ptr [ecx + 5], 0xfc
// 005f8d66  83c001               add eax, 1
// 005f8d69  3b4624               cmp eax, dword ptr [esi + 0x24]
// 005f8d6c  7ce6                 jl 0x5f8d54
// 005f8d6e  33ff                 xor edi, edi
// 005f8d70  397e34               cmp dword ptr [esi + 0x34], edi
// 005f8d73  7e2a                 jle 0x5f8d9f
// 005f8d75  8b5610               mov edx, dword ptr [esi + 0x10]
// 005f8d78  833cba00             cmp dword ptr [edx + edi*4], 0
// 005f8d7c  8d04ba               lea eax, [edx + edi*4]
// 005f8d7f  7416                 je 0x5f8d97
// 005f8d81  8b00                 mov eax, dword ptr [eax]
// 005f8d83  f6400503             test byte ptr [eax + 5], 3
// 005f8d87  740e                 je 0x5f8d97
// 005f8d89  50                   push eax
// 005f8d8a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005f8d8e  50                   push eax
// 005f8d8f  e82cfcffff           call 0x5f89c0
// 005f8d94  83c408               add esp, 8
// 005f8d97  83c701               add edi, 1
// 005f8d9a  3b7e34               cmp edi, dword ptr [esi + 0x34]
// 005f8d9d  7cd6                 jl 0x5f8d75
// 005f8d9f  33ff                 xor edi, edi
// 005f8da1  397e38               cmp dword ptr [esi + 0x38], edi
// 005f8da4  7e30                 jle 0x5f8dd6
// 005f8da6  33c0                 xor eax, eax
// 005f8da8  eb06                 jmp 0x5f8db0
// 005f8daa  8d9b00000000         lea ebx, [ebx]
// 005f8db0  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005f8db3  833c0800             cmp dword ptr [eax + ecx], 0
// 005f8db7  7412                 je 0x5f8dcb
// 005f8db9  8bd1                 mov edx, ecx
// 005f8dbb  8d0c02               lea ecx, [edx + eax]
// 005f8dbe  8b11                 mov edx, dword ptr [ecx]
// 005f8dc0  8a5205               mov dl, byte ptr [edx + 5]
// 005f8dc3  8b09                 mov ecx, dword ptr [ecx]
// 005f8dc5  80e2fc               and dl, 0xfc
// 005f8dc8  885105               mov byte ptr [ecx + 5], dl
// 005f8dcb  83c701               add edi, 1
// 005f8dce  83c00c               add eax, 0xc
// 005f8dd1  3b7e38               cmp edi, dword ptr [esi + 0x38]
// 005f8dd4  7cda                 jl 0x5f8db0
// 005f8dd6  5f                   pop edi
// 005f8dd7  c3                   ret 
// library lua-5.1.1/lgc.c (function _traverseproto)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
