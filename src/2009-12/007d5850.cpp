// from server: 100% by auto
// roc 2009-12 007d5850  unit: seg_007d0000  size: 327 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5850
//
// 007d5850  83ec5c               sub esp, 0x5c
// 007d5853  53                   push ebx
// 007d5854  55                   push ebp
// 007d5855  57                   push edi
// 007d5856  8b3e                 mov edi, dword ptr [esi]
// 007d5858  33ed                 xor ebp, ebp
// 007d585a  57                   push edi
// 007d585b  8bde                 mov ebx, esi
// 007d585d  896c2410             mov dword ptr [esp + 0x10], ebp
// 007d5861  897c2418             mov dword ptr [esp + 0x18], edi
// 007d5865  e816f9ffff           call 0x7d5180
// 007d586a  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d586d  8b08                 mov ecx, dword ptr [eax]
// 007d586f  83c404               add esp, 4
// 007d5872  8d51ff               lea edx, [ecx - 1]
// 007d5875  8910                 mov dword ptr [eax], edx
// 007d5877  85c9                 test ecx, ecx
// 007d5879  760f                 jbe 0x7d588a
// 007d587b  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 007d587e  8b5104               mov edx, dword ptr [ecx + 4]
// 007d5881  0fb602               movzx eax, byte ptr [edx]
// 007d5884  42                   inc edx
// 007d5885  895104               mov dword ptr [ecx + 4], edx
// 007d5888  eb0c                 jmp 0x7d5896
// 007d588a  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d588d  50                   push eax
// 007d588e  e83db8ffff           call 0x7d10d0
// 007d5893  83c404               add esp, 4
// 007d5896  8906                 mov dword ptr [esi], eax
// 007d5898  83f83d               cmp eax, 0x3d
// 007d589b  0f85dd000000         jne 0x7d597e
// 007d58a1  8d68c4               lea ebp, [eax - 0x3c]
// 007d58a4  8b7e3c               mov edi, dword ptr [esi + 0x3c]
// 007d58a7  8b5704               mov edx, dword ptr [edi + 4]
// 007d58aa  8b4708               mov eax, dword ptr [edi + 8]
// 007d58ad  8b0e                 mov ecx, dword ptr [esi]
// 007d58af  03d5                 add edx, ebp
// 007d58b1  894c2410             mov dword ptr [esp + 0x10], ecx
// 007d58b5  3bd0                 cmp edx, eax
// 007d58b7  7676                 jbe 0x7d592f
// 007d58b9  3dfeffff7f           cmp eax, 0x7ffffffe
// 007d58be  723d                 jb 0x7d58fd
// 007d58c0  8b4640               mov eax, dword ptr [esi + 0x40]
// 007d58c3  6a50                 push 0x50
// 007d58c5  83c010               add eax, 0x10
// 007d58c8  50                   push eax
// 007d58c9  8d4c2420             lea ecx, [esp + 0x20]
// 007d58cd  51                   push ecx
// 007d58ce  e8cd4cfcff           call 0x79a5a0
// 007d58d3  8b5604               mov edx, dword ptr [esi + 4]
// 007d58d6  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007d58d9  68b8f39e00           push 0x9ef3b8
// 007d58de  52                   push edx
// 007d58df  8d44242c             lea eax, [esp + 0x2c]
// 007d58e3  50                   push eax
// 007d58e4  68b4ab9e00           push 0x9eabb4
// 007d58e9  51                   push ecx
// 007d58ea  e8914cfcff           call 0x79a580
// 007d58ef  8b5634               mov edx, dword ptr [esi + 0x34]
// 007d58f2  6a03                 push 3
// 007d58f4  52                   push edx
// 007d58f5  e8561ffcff           call 0x797850
// 007d58fa  83c428               add esp, 0x28
// 007d58fd  8b4708               mov eax, dword ptr [edi + 8]
// 007d5900  8d1c00               lea ebx, [eax + eax]
// 007d5903  8d4b01               lea ecx, [ebx + 1]
// 007d5906  83f9fd               cmp ecx, -3
// 007d5909  7713                 ja 0x7d591e
// 007d590b  8b17                 mov edx, dword ptr [edi]
// 007d590d  53                   push ebx
// 007d590e  50                   push eax
// 007d590f  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d5912  52                   push edx
// 007d5913  50                   push eax
// 007d5914  e897beffff           call 0x7d17b0
// 007d5919  83c410               add esp, 0x10
// 007d591c  eb0c                 jmp 0x7d592a
// 007d591e  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007d5921  51                   push ecx
// 007d5922  e869beffff           call 0x7d1790
// 007d5927  83c404               add esp, 4
// 007d592a  8907                 mov dword ptr [edi], eax
// 007d592c  895f08               mov dword ptr [edi + 8], ebx
// 007d592f  8b4704               mov eax, dword ptr [edi + 4]
// 007d5932  8b17                 mov edx, dword ptr [edi]
// 007d5934  8a4c2410             mov cl, byte ptr [esp + 0x10]
// 007d5938  880c02               mov byte ptr [edx + eax], cl
// 007d593b  016f04               add dword ptr [edi + 4], ebp
// 007d593e  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d5941  8b08                 mov ecx, dword ptr [eax]
// 007d5943  8d51ff               lea edx, [ecx - 1]
// 007d5946  8910                 mov dword ptr [eax], edx
// 007d5948  85c9                 test ecx, ecx
// 007d594a  760f                 jbe 0x7d595b
// 007d594c  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 007d594f  8b5104               mov edx, dword ptr [ecx + 4]
// 007d5952  0fb602               movzx eax, byte ptr [edx]
// 007d5955  42                   inc edx
// 007d5956  895104               mov dword ptr [ecx + 4], edx
// 007d5959  eb0c                 jmp 0x7d5967
// 007d595b  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d595e  50                   push eax
// 007d595f  e86cb7ffff           call 0x7d10d0
// 007d5964  83c404               add esp, 4
// 007d5967  016c240c             add dword ptr [esp + 0xc], ebp
// 007d596b  8906                 mov dword ptr [esi], eax
// 007d596d  83f83d               cmp eax, 0x3d
// 007d5970  0f842effffff         je 0x7d58a4
// 007d5976  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007d597a  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d597e  393e                 cmp dword ptr [esi], edi
// 007d5980  7509                 jne 0x7d598b
// 007d5982  5f                   pop edi
// 007d5983  8bc5                 mov eax, ebp
// 007d5985  5d                   pop ebp
// 007d5986  5b                   pop ebx
// 007d5987  83c45c               add esp, 0x5c
// 007d598a  c3                   ret 
// 007d598b  83c8ff               or eax, 0xffffffff
// 007d598e  5f                   pop edi
// 007d598f  2bc5                 sub eax, ebp
// 007d5991  5d                   pop ebp
// 007d5992  5b                   pop ebx
// 007d5993  83c45c               add esp, 0x5c
// 007d5996  c3                   ret 
// library lua-5.1/llex.c (function _skip_sep)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
