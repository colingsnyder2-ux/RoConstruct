// from server: 100% by auto
// roc 2007-03 005ff460  unit: seg_005f0000  size: 552 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ff460
//
// 005ff460  83ec1c               sub esp, 0x1c
// 005ff463  53                   push ebx
// 005ff464  55                   push ebp
// 005ff465  8b6f30               mov ebp, dword ptr [edi + 0x30]
// 005ff468  8b4524               mov eax, dword ptr [ebp + 0x24]
// 005ff46b  56                   push esi
// 005ff46c  6a0b                 push 0xb
// 005ff46e  682c067c00           push 0x7c062c
// 005ff473  57                   push edi
// 005ff474  89442418             mov dword ptr [esp + 0x18], eax
// 005ff478  e8131b0000           call 0x600f90
// 005ff47d  8b7730               mov esi, dword ptr [edi + 0x30]
// 005ff480  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff484  83c101               add ecx, 1
// 005ff487  83c40c               add esp, 0xc
// 005ff48a  81f9c8000000         cmp ecx, 0xc8
// 005ff490  8bd8                 mov ebx, eax
// 005ff492  7e0f                 jle 0x5ff4a3
// 005ff494  b9cc047c00           mov ecx, 0x7c04cc
// 005ff499  bac8000000           mov edx, 0xc8
// 005ff49e  e8dddfffff           call 0x5fd480
// 005ff4a3  53                   push ebx
// 005ff4a4  57                   push edi
// 005ff4a5  e816e1ffff           call 0x5fd5c0
// 005ff4aa  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ff4ae  6a0b                 push 0xb
// 005ff4b0  6820067c00           push 0x7c0620
// 005ff4b5  57                   push edi
// 005ff4b6  66898456ac000000     mov word ptr [esi + edx*2 + 0xac], ax
// 005ff4be  e8cd1a0000           call 0x600f90
// 005ff4c3  8b7730               mov esi, dword ptr [edi + 0x30]
// 005ff4c6  8bd8                 mov ebx, eax
// 005ff4c8  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 005ff4cc  83c002               add eax, 2
// 005ff4cf  83c414               add esp, 0x14
// 005ff4d2  3dc8000000           cmp eax, 0xc8
// 005ff4d7  7e0f                 jle 0x5ff4e8
// 005ff4d9  b9cc047c00           mov ecx, 0x7c04cc
// 005ff4de  bac8000000           mov edx, 0xc8
// 005ff4e3  e898dfffff           call 0x5fd480
// 005ff4e8  53                   push ebx
// 005ff4e9  57                   push edi
// 005ff4ea  e8d1e0ffff           call 0x5fd5c0
// 005ff4ef  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff4f3  6a0a                 push 0xa
// 005ff4f5  6814067c00           push 0x7c0614
// 005ff4fa  57                   push edi
// 005ff4fb  6689844eae000000     mov word ptr [esi + ecx*2 + 0xae], ax
// 005ff503  e8881a0000           call 0x600f90
// 005ff508  8b7730               mov esi, dword ptr [edi + 0x30]
// 005ff50b  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ff50f  83c203               add edx, 3
// 005ff512  83c414               add esp, 0x14
// 005ff515  81fac8000000         cmp edx, 0xc8
// 005ff51b  8bd8                 mov ebx, eax
// 005ff51d  7e0f                 jle 0x5ff52e
// 005ff51f  b9cc047c00           mov ecx, 0x7c04cc
// 005ff524  bac8000000           mov edx, 0xc8
// 005ff529  e852dfffff           call 0x5fd480
// 005ff52e  53                   push ebx
// 005ff52f  57                   push edi
// 005ff530  e88be0ffff           call 0x5fd5c0
// 005ff535  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff539  6689844eb0000000     mov word ptr [esi + ecx*2 + 0xb0], ax
// 005ff541  8b7730               mov esi, dword ptr [edi + 0x30]
// 005ff544  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ff548  83c204               add edx, 4
// 005ff54b  83c408               add esp, 8
// 005ff54e  81fac8000000         cmp edx, 0xc8
// 005ff554  7e0f                 jle 0x5ff565
// 005ff556  b9cc047c00           mov ecx, 0x7c04cc
// 005ff55b  bac8000000           mov edx, 0xc8
// 005ff560  e81bdfffff           call 0x5fd480
// 005ff565  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005ff569  50                   push eax
// 005ff56a  57                   push edi
// 005ff56b  e850e0ffff           call 0x5fd5c0
// 005ff570  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff574  83c408               add esp, 8
// 005ff577  6689844eb2000000     mov word ptr [esi + ecx*2 + 0xb2], ax
// 005ff57f  837f103d             cmp dword ptr [edi + 0x10], 0x3d
// 005ff583  7421                 je 0x5ff5a6
// 005ff585  6a3d                 push 0x3d
// 005ff587  57                   push edi
// 005ff588  e8e3180000           call 0x600e70
// 005ff58d  8b5734               mov edx, dword ptr [edi + 0x34]
// 005ff590  50                   push eax
// 005ff591  6828047c00           push 0x7c0428
// 005ff596  52                   push edx
// 005ff597  e8a492ffff           call 0x5f8840
// 005ff59c  50                   push eax
// 005ff59d  57                   push edi
// 005ff59e  e8cd190000           call 0x600f70
// 005ff5a3  83c41c               add esp, 0x1c
// 005ff5a6  57                   push edi
// 005ff5a7  e8f42d0000           call 0x6023a0
// 005ff5ac  6a00                 push 0
// 005ff5ae  8d442418             lea eax, [esp + 0x18]
// 005ff5b2  50                   push eax
// 005ff5b3  57                   push edi
// 005ff5b4  e817f7ffff           call 0x5fecd0
// 005ff5b9  8b5730               mov edx, dword ptr [edi + 0x30]
// 005ff5bc  8d4c2420             lea ecx, [esp + 0x20]
// 005ff5c0  51                   push ecx
// 005ff5c1  52                   push edx
// 005ff5c2  e8f95b0100           call 0x6151c0
// 005ff5c7  be2c000000           mov esi, 0x2c
// 005ff5cc  83c418               add esp, 0x18
// 005ff5cf  397710               cmp dword ptr [edi + 0x10], esi
// 005ff5d2  7420                 je 0x5ff5f4
// 005ff5d4  56                   push esi
// 005ff5d5  57                   push edi
// 005ff5d6  e895180000           call 0x600e70
// 005ff5db  50                   push eax
// 005ff5dc  8b4734               mov eax, dword ptr [edi + 0x34]
// 005ff5df  6828047c00           push 0x7c0428
// 005ff5e4  50                   push eax
// 005ff5e5  e85692ffff           call 0x5f8840
// 005ff5ea  50                   push eax
// 005ff5eb  57                   push edi
// 005ff5ec  e87f190000           call 0x600f70
// 005ff5f1  83c41c               add esp, 0x1c
// 005ff5f4  57                   push edi
// 005ff5f5  e8a62d0000           call 0x6023a0
// 005ff5fa  6a00                 push 0
// 005ff5fc  8d4c2418             lea ecx, [esp + 0x18]
// 005ff600  51                   push ecx
// 005ff601  57                   push edi
// 005ff602  e8c9f6ffff           call 0x5fecd0
// 005ff607  8b4730               mov eax, dword ptr [edi + 0x30]
// 005ff60a  8d542420             lea edx, [esp + 0x20]
// 005ff60e  52                   push edx
// 005ff60f  50                   push eax
// 005ff610  e8ab5b0100           call 0x6151c0
// 005ff615  83c418               add esp, 0x18
// 005ff618  397710               cmp dword ptr [edi + 0x10], esi
// 005ff61b  7526                 jne 0x5ff643
// 005ff61d  57                   push edi
// 005ff61e  e87d2d0000           call 0x6023a0
// 005ff623  6a00                 push 0
// 005ff625  8d4c2418             lea ecx, [esp + 0x18]
// 005ff629  51                   push ecx
// 005ff62a  57                   push edi
// 005ff62b  e8a0f6ffff           call 0x5fecd0
// 005ff630  8b4730               mov eax, dword ptr [edi + 0x30]
// 005ff633  8d542420             lea edx, [esp + 0x20]
// 005ff637  52                   push edx
// 005ff638  50                   push eax
// 005ff639  e8825b0100           call 0x6151c0
// 005ff63e  83c418               add esp, 0x18
// 005ff641  eb26                 jmp 0x5ff669
// 005ff643  d9e8                 fld1 
// 005ff645  83ec08               sub esp, 8
// 005ff648  dd1c24               fstp qword ptr [esp]
// 005ff64b  55                   push ebp
// 005ff64c  e8ff510100           call 0x614850
// 005ff651  8b4d24               mov ecx, dword ptr [ebp + 0x24]
// 005ff654  50                   push eax
// 005ff655  51                   push ecx
// 005ff656  6a01                 push 1
// 005ff658  55                   push ebp
// 005ff659  e882550100           call 0x614be0
// 005ff65e  6a01                 push 1
// 005ff660  55                   push ebp
// 005ff661  e87a500100           call 0x6146e0
// 005ff666  83c424               add esp, 0x24
// 005ff669  8b542430             mov edx, dword ptr [esp + 0x30]
// 005ff66d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ff671  6a01                 push 1
// 005ff673  6a01                 push 1
// 005ff675  52                   push edx
// 005ff676  50                   push eax
// 005ff677  8bc7                 mov eax, edi
// 005ff679  e852fcffff           call 0x5ff2d0
// 005ff67e  83c410               add esp, 0x10
// 005ff681  5e                   pop esi
// 005ff682  5d                   pop ebp
// 005ff683  5b                   pop ebx
// 005ff684  83c41c               add esp, 0x1c
// 005ff687  c3                   ret 
// library lua-5.1.1/lparser.c (function _fornum)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
