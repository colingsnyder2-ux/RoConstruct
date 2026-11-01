// from server: 100% by auto
// roc 2007-03 005ff690  unit: seg_005f0000  size: 631 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ff690
//
// 005ff690  83ec24               sub esp, 0x24
// 005ff693  8b4330               mov eax, dword ptr [ebx + 0x30]
// 005ff696  55                   push ebp
// 005ff697  56                   push esi
// 005ff698  57                   push edi
// 005ff699  6a0f                 push 0xf
// 005ff69b  89442414             mov dword ptr [esp + 0x14], eax
// 005ff69f  8b4024               mov eax, dword ptr [eax + 0x24]
// 005ff6a2  6854067c00           push 0x7c0654
// 005ff6a7  53                   push ebx
// 005ff6a8  89442420             mov dword ptr [esp + 0x20], eax
// 005ff6ac  e8df180000           call 0x600f90
// 005ff6b1  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005ff6b4  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff6b8  83c101               add ecx, 1
// 005ff6bb  83c40c               add esp, 0xc
// 005ff6be  81f9c8000000         cmp ecx, 0xc8
// 005ff6c4  8bf8                 mov edi, eax
// 005ff6c6  7e0f                 jle 0x5ff6d7
// 005ff6c8  b9cc047c00           mov ecx, 0x7c04cc
// 005ff6cd  bac8000000           mov edx, 0xc8
// 005ff6d2  e8a9ddffff           call 0x5fd480
// 005ff6d7  57                   push edi
// 005ff6d8  53                   push ebx
// 005ff6d9  e8e2deffff           call 0x5fd5c0
// 005ff6de  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ff6e2  6a0b                 push 0xb
// 005ff6e4  6848067c00           push 0x7c0648
// 005ff6e9  53                   push ebx
// 005ff6ea  66898456ac000000     mov word ptr [esi + edx*2 + 0xac], ax
// 005ff6f2  e899180000           call 0x600f90
// 005ff6f7  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005ff6fa  8bf8                 mov edi, eax
// 005ff6fc  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 005ff700  83c002               add eax, 2
// 005ff703  83c414               add esp, 0x14
// 005ff706  3dc8000000           cmp eax, 0xc8
// 005ff70b  7e0f                 jle 0x5ff71c
// 005ff70d  b9cc047c00           mov ecx, 0x7c04cc
// 005ff712  bac8000000           mov edx, 0xc8
// 005ff717  e864ddffff           call 0x5fd480
// 005ff71c  57                   push edi
// 005ff71d  53                   push ebx
// 005ff71e  e89ddeffff           call 0x5fd5c0
// 005ff723  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff727  6a0d                 push 0xd
// 005ff729  6838067c00           push 0x7c0638
// 005ff72e  53                   push ebx
// 005ff72f  6689844eae000000     mov word ptr [esi + ecx*2 + 0xae], ax
// 005ff737  e854180000           call 0x600f90
// 005ff73c  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005ff73f  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ff743  83c203               add edx, 3
// 005ff746  83c414               add esp, 0x14
// 005ff749  81fac8000000         cmp edx, 0xc8
// 005ff74f  8bf8                 mov edi, eax
// 005ff751  7e0f                 jle 0x5ff762
// 005ff753  b9cc047c00           mov ecx, 0x7c04cc
// 005ff758  bac8000000           mov edx, 0xc8
// 005ff75d  e81eddffff           call 0x5fd480
// 005ff762  57                   push edi
// 005ff763  53                   push ebx
// 005ff764  e857deffff           call 0x5fd5c0
// 005ff769  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff76d  6689844eb0000000     mov word ptr [esi + ecx*2 + 0xb0], ax
// 005ff775  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005ff778  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005ff77c  83c204               add edx, 4
// 005ff77f  83c408               add esp, 8
// 005ff782  81fac8000000         cmp edx, 0xc8
// 005ff788  7e0f                 jle 0x5ff799
// 005ff78a  b9cc047c00           mov ecx, 0x7c04cc
// 005ff78f  bac8000000           mov edx, 0xc8
// 005ff794  e8e7dcffff           call 0x5fd480
// 005ff799  8b442434             mov eax, dword ptr [esp + 0x34]
// 005ff79d  50                   push eax
// 005ff79e  53                   push ebx
// 005ff79f  e81cdeffff           call 0x5fd5c0
// 005ff7a4  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff7a8  83c408               add esp, 8
// 005ff7ab  6689844eb2000000     mov word ptr [esi + ecx*2 + 0xb2], ax
// 005ff7b3  bf04000000           mov edi, 4
// 005ff7b8  eb06                 jmp 0x5ff7c0
// 005ff7ba  8d9b00000000         lea ebx, [ebx]
// 005ff7c0  837b102c             cmp dword ptr [ebx + 0x10], 0x2c
// 005ff7c4  0f85bc000000         jne 0x5ff886
// 005ff7ca  53                   push ebx
// 005ff7cb  e8d02b0000           call 0x6023a0
// 005ff7d0  83c404               add esp, 4
// 005ff7d3  817b101d010000       cmp dword ptr [ebx + 0x10], 0x11d
// 005ff7da  7424                 je 0x5ff800
// 005ff7dc  681d010000           push 0x11d
// 005ff7e1  53                   push ebx
// 005ff7e2  e889160000           call 0x600e70
// 005ff7e7  8b5334               mov edx, dword ptr [ebx + 0x34]
// 005ff7ea  50                   push eax
// 005ff7eb  6828047c00           push 0x7c0428
// 005ff7f0  52                   push edx
// 005ff7f1  e84a90ffff           call 0x5f8840
// 005ff7f6  50                   push eax
// 005ff7f7  53                   push ebx
// 005ff7f8  e873170000           call 0x600f70
// 005ff7fd  83c41c               add esp, 0x1c
// 005ff800  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 005ff803  53                   push ebx
// 005ff804  e8972b0000           call 0x6023a0
// 005ff809  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005ff80c  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 005ff810  8d4c3801             lea ecx, [eax + edi + 1]
// 005ff814  83c404               add esp, 4
// 005ff817  81f9c8000000         cmp ecx, 0xc8
// 005ff81d  7e47                 jle 0x5ff866
// 005ff81f  8b16                 mov edx, dword ptr [esi]
// 005ff821  8b423c               mov eax, dword ptr [edx + 0x3c]
// 005ff824  85c0                 test eax, eax
// 005ff826  68cc047c00           push 0x7c04cc
// 005ff82b  68c8000000           push 0xc8
// 005ff830  7513                 jne 0x5ff845
// 005ff832  8b4610               mov eax, dword ptr [esi + 0x10]
// 005ff835  6860047c00           push 0x7c0460
// 005ff83a  50                   push eax
// 005ff83b  e80090ffff           call 0x5f8840
// 005ff840  83c410               add esp, 0x10
// 005ff843  eb12                 jmp 0x5ff857
// 005ff845  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005ff848  50                   push eax
// 005ff849  6838047c00           push 0x7c0438
// 005ff84e  51                   push ecx
// 005ff84f  e8ec8fffff           call 0x5f8840
// 005ff854  83c414               add esp, 0x14
// 005ff857  8b560c               mov edx, dword ptr [esi + 0xc]
// 005ff85a  6a00                 push 0
// 005ff85c  50                   push eax
// 005ff85d  52                   push edx
// 005ff85e  e86d160000           call 0x600ed0
// 005ff863  83c40c               add esp, 0xc
// 005ff866  55                   push ebp
// 005ff867  53                   push ebx
// 005ff868  e853ddffff           call 0x5fd5c0
// 005ff86d  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005ff871  03cf                 add ecx, edi
// 005ff873  83c408               add esp, 8
// 005ff876  6689844eac000000     mov word ptr [esi + ecx*2 + 0xac], ax
// 005ff87e  83c701               add edi, 1
// 005ff881  e93affffff           jmp 0x5ff7c0
// 005ff886  817b100b010000       cmp dword ptr [ebx + 0x10], 0x10b
// 005ff88d  897c240c             mov dword ptr [esp + 0xc], edi
// 005ff891  7424                 je 0x5ff8b7
// 005ff893  680b010000           push 0x10b
// 005ff898  53                   push ebx
// 005ff899  e8d2150000           call 0x600e70
// 005ff89e  8b5334               mov edx, dword ptr [ebx + 0x34]
// 005ff8a1  50                   push eax
// 005ff8a2  6828047c00           push 0x7c0428
// 005ff8a7  52                   push edx
// 005ff8a8  e8938fffff           call 0x5f8840
// 005ff8ad  50                   push eax
// 005ff8ae  53                   push ebx
// 005ff8af  e8bc160000           call 0x600f70
// 005ff8b4  83c41c               add esp, 0x1c
// 005ff8b7  53                   push ebx
// 005ff8b8  e8e32a0000           call 0x6023a0
// 005ff8bd  8b6b04               mov ebp, dword ptr [ebx + 4]
// 005ff8c0  8d7c241c             lea edi, [esp + 0x1c]
// 005ff8c4  8bf3                 mov esi, ebx
// 005ff8c6  e895ebffff           call 0x5fe460
// 005ff8cb  50                   push eax
// 005ff8cc  8bcf                 mov ecx, edi
// 005ff8ce  ba03000000           mov edx, 3
// 005ff8d3  8bc3                 mov eax, ebx
// 005ff8d5  e8a6e0ffff           call 0x5fd980
// 005ff8da  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ff8de  6a03                 push 3
// 005ff8e0  50                   push eax
// 005ff8e1  e8ba4d0100           call 0x6146a0
// 005ff8e6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ff8ea  8b542424             mov edx, dword ptr [esp + 0x24]
// 005ff8ee  6a00                 push 0
// 005ff8f0  83c1fd               add ecx, -3
// 005ff8f3  51                   push ecx
// 005ff8f4  55                   push ebp
// 005ff8f5  52                   push edx
// 005ff8f6  8bc3                 mov eax, ebx
// 005ff8f8  e8d3f9ffff           call 0x5ff2d0
// 005ff8fd  83c420               add esp, 0x20
// 005ff900  5f                   pop edi
// 005ff901  5e                   pop esi
// 005ff902  5d                   pop ebp
// 005ff903  83c424               add esp, 0x24
// 005ff906  c3                   ret 
// library lua-5.1.1/lparser.c (function _forlist)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
