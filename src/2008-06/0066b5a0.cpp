// from server: 100% by auto
// roc 2008-06 0066b5a0  unit: RBX::GroupDragTool  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066b5a0
//
// 0066b5a0  53                   push ebx
// 0066b5a1  56                   push esi
// 0066b5a2  e8f9feffff           call 0x66b4a0
// 0066b5a7  8b03                 mov eax, dword ptr [ebx]
// 0066b5a9  8d48ff               lea ecx, [eax - 1]
// 0066b5ac  83c408               add esp, 8
// 0066b5af  83f90b               cmp ecx, 0xb
// 0066b5b2  0f87c2000000         ja 0x66b67a
// 0066b5b8  ff248d7cb66600       jmp dword ptr [ecx*4 + 0x66b67c]
// 0066b5bf  6a01                 push 1
// 0066b5c1  57                   push edi
// 0066b5c2  56                   push esi
// 0066b5c3  e858fdffff           call 0x66b320
// 0066b5c8  83c40c               add esp, 0xc
// 0066b5cb  897b08               mov dword ptr [ebx + 8], edi
// 0066b5ce  c7030c000000         mov dword ptr [ebx], 0xc
// 0066b5d4  c3                   ret 
// 0066b5d5  33c9                 xor ecx, ecx
// 0066b5d7  83f802               cmp eax, 2
// 0066b5da  0f94c1               sete cl
// 0066b5dd  6a00                 push 0
// 0066b5df  51                   push ecx
// 0066b5e0  57                   push edi
// 0066b5e1  6a02                 push 2
// 0066b5e3  56                   push esi
// 0066b5e4  e847fcffff           call 0x66b230
// 0066b5e9  83c414               add esp, 0x14
// 0066b5ec  897b08               mov dword ptr [ebx + 8], edi
// 0066b5ef  c7030c000000         mov dword ptr [ebx], 0xc
// 0066b5f5  c3                   ret 
// 0066b5f6  8b5308               mov edx, dword ptr [ebx + 8]
// 0066b5f9  52                   push edx
// 0066b5fa  57                   push edi
// 0066b5fb  6a01                 push 1
// 0066b5fd  56                   push esi
// 0066b5fe  e85dfcffff           call 0x66b260
// 0066b603  83c410               add esp, 0x10
// 0066b606  897b08               mov dword ptr [ebx + 8], edi
// 0066b609  c7030c000000         mov dword ptr [ebx], 0xc
// 0066b60f  c3                   ret 
// 0066b610  dd4308               fld qword ptr [ebx + 8]
// 0066b613  83ec08               sub esp, 8
// 0066b616  dd1c24               fstp qword ptr [esp]
// 0066b619  56                   push esi
// 0066b61a  e8f1f8ffff           call 0x66af10
// 0066b61f  50                   push eax
// 0066b620  57                   push edi
// 0066b621  6a01                 push 1
// 0066b623  56                   push esi
// 0066b624  e837fcffff           call 0x66b260
// 0066b629  83c41c               add esp, 0x1c
// 0066b62c  897b08               mov dword ptr [ebx + 8], edi
// 0066b62f  c7030c000000         mov dword ptr [ebx], 0xc
// 0066b635  c3                   ret 
// 0066b636  8b0e                 mov ecx, dword ptr [esi]
// 0066b638  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0066b63b  8b4308               mov eax, dword ptr [ebx + 8]
// 0066b63e  8bcf                 mov ecx, edi
// 0066b640  c1e106               shl ecx, 6
// 0066b643  330c82               xor ecx, dword ptr [edx + eax*4]
// 0066b646  8d0482               lea eax, [edx + eax*4]
// 0066b649  81e1c03f0000         and ecx, 0x3fc0
// 0066b64f  3108                 xor dword ptr [eax], ecx
// 0066b651  897b08               mov dword ptr [ebx + 8], edi
// 0066b654  c7030c000000         mov dword ptr [ebx], 0xc
// 0066b65a  c3                   ret 
// 0066b65b  8b4308               mov eax, dword ptr [ebx + 8]
// 0066b65e  3bf8                 cmp edi, eax
// 0066b660  740f                 je 0x66b671
// 0066b662  6a00                 push 0
// 0066b664  50                   push eax
// 0066b665  57                   push edi
// 0066b666  6a00                 push 0
// 0066b668  56                   push esi
// 0066b669  e8c2fbffff           call 0x66b230
// 0066b66e  83c414               add esp, 0x14
// 0066b671  897b08               mov dword ptr [ebx + 8], edi
// 0066b674  c7030c000000         mov dword ptr [ebx], 0xc
// 0066b67a  c3                   ret 
// 0066b67b  90                   nop 
// 0066b67c  bfb56600d5           mov edi, 0xd50066b5
// 0066b681  b566                 mov ch, 0x66
// 0066b683  00d5                 add ch, dl
// 0066b685  b566                 mov ch, 0x66
// 0066b687  00f6                 add dh, dh
// 0066b689  b566                 mov ch, 0x66
// 0066b68b  0010                 add byte ptr [eax], dl
// 0066b68d  b666                 mov dh, 0x66
// 0066b68f  007ab6               add byte ptr [edx - 0x4a], bh
// 0066b692  66007ab6             add byte ptr [edx - 0x4a], bh
// 0066b696  66007ab6             add byte ptr [edx - 0x4a], bh
// 0066b69a  66007ab6             add byte ptr [edx - 0x4a], bh
// 0066b69e  66007ab6             add byte ptr [edx - 0x4a], bh
// 0066b6a2  660036               add byte ptr [esi], dh
// 0066b6a5  b666                 mov dh, 0x66
// 0066b6a7  005bb6               add byte ptr [ebx - 0x4a], bl
// library lua-5.1/lcode.c (function _discharge2reg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
