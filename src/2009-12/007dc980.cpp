// roc 2009-12 007dc980  unit: RBX::GroupDragTool  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc980
//
// 007dc980  53                   push ebx
// 007dc981  56                   push esi
// 007dc982  e8f9feffff           call 0x7dc880
// 007dc987  8b03                 mov eax, dword ptr [ebx]
// 007dc989  8d48ff               lea ecx, [eax - 1]
// 007dc98c  83c408               add esp, 8
// 007dc98f  83f90b               cmp ecx, 0xb
// 007dc992  0f87c2000000         ja 0x7dca5a
// 007dc998  ff248d5cca7d00       jmp dword ptr [ecx*4 + 0x7dca5c]
// 007dc99f  6a01                 push 1
// 007dc9a1  57                   push edi
// 007dc9a2  56                   push esi
// 007dc9a3  e848fdffff           call 0x7dc6f0
// 007dc9a8  83c40c               add esp, 0xc
// 007dc9ab  897b08               mov dword ptr [ebx + 8], edi
// 007dc9ae  c7030c000000         mov dword ptr [ebx], 0xc
// 007dc9b4  c3                   ret 
// 007dc9b5  33c9                 xor ecx, ecx
// 007dc9b7  83f802               cmp eax, 2
// 007dc9ba  0f94c1               sete cl
// 007dc9bd  6a00                 push 0
// 007dc9bf  51                   push ecx
// 007dc9c0  57                   push edi
// 007dc9c1  6a02                 push 2
// 007dc9c3  56                   push esi
// 007dc9c4  e837fcffff           call 0x7dc600
// 007dc9c9  83c414               add esp, 0x14
// 007dc9cc  897b08               mov dword ptr [ebx + 8], edi
// 007dc9cf  c7030c000000         mov dword ptr [ebx], 0xc
// 007dc9d5  c3                   ret 
// 007dc9d6  8b5308               mov edx, dword ptr [ebx + 8]
// 007dc9d9  52                   push edx
// 007dc9da  57                   push edi
// 007dc9db  6a01                 push 1
// 007dc9dd  56                   push esi
// 007dc9de  e84dfcffff           call 0x7dc630
// 007dc9e3  83c410               add esp, 0x10
// 007dc9e6  897b08               mov dword ptr [ebx + 8], edi
// 007dc9e9  c7030c000000         mov dword ptr [ebx], 0xc
// 007dc9ef  c3                   ret 
// 007dc9f0  dd4308               fld qword ptr [ebx + 8]
// 007dc9f3  83ec08               sub esp, 8
// 007dc9f6  dd1c24               fstp qword ptr [esp]
// 007dc9f9  56                   push esi
// 007dc9fa  e8d1f8ffff           call 0x7dc2d0
// 007dc9ff  50                   push eax
// 007dca00  57                   push edi
// 007dca01  6a01                 push 1
// 007dca03  56                   push esi
// 007dca04  e827fcffff           call 0x7dc630
// 007dca09  83c41c               add esp, 0x1c
// 007dca0c  897b08               mov dword ptr [ebx + 8], edi
// 007dca0f  c7030c000000         mov dword ptr [ebx], 0xc
// 007dca15  c3                   ret 
// 007dca16  8b0e                 mov ecx, dword ptr [esi]
// 007dca18  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007dca1b  8b4308               mov eax, dword ptr [ebx + 8]
// 007dca1e  8bcf                 mov ecx, edi
// 007dca20  c1e106               shl ecx, 6
// 007dca23  330c82               xor ecx, dword ptr [edx + eax*4]
// 007dca26  8d0482               lea eax, [edx + eax*4]
// 007dca29  81e1c03f0000         and ecx, 0x3fc0
// 007dca2f  3108                 xor dword ptr [eax], ecx
// 007dca31  897b08               mov dword ptr [ebx + 8], edi
// 007dca34  c7030c000000         mov dword ptr [ebx], 0xc
// 007dca3a  c3                   ret 
// 007dca3b  8b4308               mov eax, dword ptr [ebx + 8]
// 007dca3e  3bf8                 cmp edi, eax
// 007dca40  740f                 je 0x7dca51
// 007dca42  6a00                 push 0
// 007dca44  50                   push eax
// 007dca45  57                   push edi
// 007dca46  6a00                 push 0
// 007dca48  56                   push esi
// 007dca49  e8b2fbffff           call 0x7dc600
// 007dca4e  83c414               add esp, 0x14
// 007dca51  897b08               mov dword ptr [ebx + 8], edi
// 007dca54  c7030c000000         mov dword ptr [ebx], 0xc
// 007dca5a  c3                   ret 
// 007dca5b  90                   nop 
// 007dca5c  9f                   lahf 
// 007dca5d  c9                   leave 
// 007dca5e  7d00                 jge 0x7dca60
// 007dca60  b5c9                 mov ch, 0xc9
// 007dca62  7d00                 jge 0x7dca64
// 007dca64  b5c9                 mov ch, 0xc9
// 007dca66  7d00                 jge 0x7dca68
// 007dca68  d6                   salc 
// 007dca69  c9                   leave 
// 007dca6a  7d00                 jge 0x7dca6c
// library lua-5.1/lcode.c (function _discharge2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
