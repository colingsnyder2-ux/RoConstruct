// from server: 100% by auto
// roc 2010-06 0078fee0  unit: RBX::GroupDragTool  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078fee0
//
// 0078fee0  53                   push ebx
// 0078fee1  56                   push esi
// 0078fee2  e8f9feffff           call 0x78fde0
// 0078fee7  8b03                 mov eax, dword ptr [ebx]
// 0078fee9  8d48ff               lea ecx, [eax - 1]
// 0078feec  83c408               add esp, 8
// 0078feef  83f90b               cmp ecx, 0xb
// 0078fef2  0f87c2000000         ja 0x78ffba
// 0078fef8  ff248dbcff7800       jmp dword ptr [ecx*4 + 0x78ffbc]
// 0078feff  6a01                 push 1
// 0078ff01  57                   push edi
// 0078ff02  56                   push esi
// 0078ff03  e848fdffff           call 0x78fc50
// 0078ff08  83c40c               add esp, 0xc
// 0078ff0b  897b08               mov dword ptr [ebx + 8], edi
// 0078ff0e  c7030c000000         mov dword ptr [ebx], 0xc
// 0078ff14  c3                   ret 
// 0078ff15  33c9                 xor ecx, ecx
// 0078ff17  83f802               cmp eax, 2
// 0078ff1a  0f94c1               sete cl
// 0078ff1d  6a00                 push 0
// 0078ff1f  51                   push ecx
// 0078ff20  57                   push edi
// 0078ff21  6a02                 push 2
// 0078ff23  56                   push esi
// 0078ff24  e837fcffff           call 0x78fb60
// 0078ff29  83c414               add esp, 0x14
// 0078ff2c  897b08               mov dword ptr [ebx + 8], edi
// 0078ff2f  c7030c000000         mov dword ptr [ebx], 0xc
// 0078ff35  c3                   ret 
// 0078ff36  8b5308               mov edx, dword ptr [ebx + 8]
// 0078ff39  52                   push edx
// 0078ff3a  57                   push edi
// 0078ff3b  6a01                 push 1
// 0078ff3d  56                   push esi
// 0078ff3e  e84dfcffff           call 0x78fb90
// 0078ff43  83c410               add esp, 0x10
// 0078ff46  897b08               mov dword ptr [ebx + 8], edi
// 0078ff49  c7030c000000         mov dword ptr [ebx], 0xc
// 0078ff4f  c3                   ret 
// 0078ff50  dd4308               fld qword ptr [ebx + 8]
// 0078ff53  83ec08               sub esp, 8
// 0078ff56  dd1c24               fstp qword ptr [esp]
// 0078ff59  56                   push esi
// 0078ff5a  e8d1f8ffff           call 0x78f830
// 0078ff5f  50                   push eax
// 0078ff60  57                   push edi
// 0078ff61  6a01                 push 1
// 0078ff63  56                   push esi
// 0078ff64  e827fcffff           call 0x78fb90
// 0078ff69  83c41c               add esp, 0x1c
// 0078ff6c  897b08               mov dword ptr [ebx + 8], edi
// 0078ff6f  c7030c000000         mov dword ptr [ebx], 0xc
// 0078ff75  c3                   ret 
// 0078ff76  8b0e                 mov ecx, dword ptr [esi]
// 0078ff78  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0078ff7b  8b4308               mov eax, dword ptr [ebx + 8]
// 0078ff7e  8bcf                 mov ecx, edi
// 0078ff80  c1e106               shl ecx, 6
// 0078ff83  330c82               xor ecx, dword ptr [edx + eax*4]
// 0078ff86  8d0482               lea eax, [edx + eax*4]
// 0078ff89  81e1c03f0000         and ecx, 0x3fc0
// 0078ff8f  3108                 xor dword ptr [eax], ecx
// 0078ff91  897b08               mov dword ptr [ebx + 8], edi
// 0078ff94  c7030c000000         mov dword ptr [ebx], 0xc
// 0078ff9a  c3                   ret 
// 0078ff9b  8b4308               mov eax, dword ptr [ebx + 8]
// 0078ff9e  3bf8                 cmp edi, eax
// 0078ffa0  740f                 je 0x78ffb1
// 0078ffa2  6a00                 push 0
// 0078ffa4  50                   push eax
// 0078ffa5  57                   push edi
// 0078ffa6  6a00                 push 0
// 0078ffa8  56                   push esi
// 0078ffa9  e8b2fbffff           call 0x78fb60
// 0078ffae  83c414               add esp, 0x14
// 0078ffb1  897b08               mov dword ptr [ebx + 8], edi
// 0078ffb4  c7030c000000         mov dword ptr [ebx], 0xc
// 0078ffba  c3                   ret 
// 0078ffbb  90                   nop 
// library lua-5.1/lcode.c (function _discharge2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
