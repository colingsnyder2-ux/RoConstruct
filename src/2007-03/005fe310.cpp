// from server: 100% by auto
// roc 2007-03 005fe310  unit: seg_005f0000  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fe310
//
// 005fe310  81ec3c020000         sub esp, 0x23c
// 005fe316  53                   push ebx
// 005fe317  55                   push ebp
// 005fe318  8bac2450020000       mov ebp, dword ptr [esp + 0x250]
// 005fe31f  56                   push esi
// 005fe320  8bd8                 mov ebx, eax
// 005fe322  57                   push edi
// 005fe323  8d442410             lea eax, [esp + 0x10]
// 005fe327  e824f8ffff           call 0x5fdb50
// 005fe32c  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fe330  89683c               mov dword ptr [eax + 0x3c], ebp
// 005fe333  837b1028             cmp dword ptr [ebx + 0x10], 0x28
// 005fe337  7421                 je 0x5fe35a
// 005fe339  6a28                 push 0x28
// 005fe33b  53                   push ebx
// 005fe33c  e82f2b0000           call 0x600e70
// 005fe341  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 005fe344  50                   push eax
// 005fe345  6828047c00           push 0x7c0428
// 005fe34a  51                   push ecx
// 005fe34b  e8f0a4ffff           call 0x5f8840
// 005fe350  50                   push eax
// 005fe351  53                   push ebx
// 005fe352  e8192c0000           call 0x600f70
// 005fe357  83c41c               add esp, 0x1c
// 005fe35a  53                   push ebx
// 005fe35b  e840400000           call 0x6023a0
// 005fe360  83c404               add esp, 4
// 005fe363  83bc245402000000     cmp dword ptr [esp + 0x254], 0
// 005fe36b  746b                 je 0x5fe3d8
// 005fe36d  6a04                 push 4
// 005fe36f  6858057c00           push 0x7c0558
// 005fe374  53                   push ebx
// 005fe375  e8162c0000           call 0x600f90
// 005fe37a  8b7330               mov esi, dword ptr [ebx + 0x30]
// 005fe37d  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005fe381  83c201               add edx, 1
// 005fe384  83c40c               add esp, 0xc
// 005fe387  81fac8000000         cmp edx, 0xc8
// 005fe38d  8bf8                 mov edi, eax
// 005fe38f  7e0f                 jle 0x5fe3a0
// 005fe391  b9cc047c00           mov ecx, 0x7c04cc
// 005fe396  bac8000000           mov edx, 0xc8
// 005fe39b  e8e0f0ffff           call 0x5fd480
// 005fe3a0  57                   push edi
// 005fe3a1  53                   push ebx
// 005fe3a2  e819f2ffff           call 0x5fd5c0
// 005fe3a7  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005fe3ab  6689844eac000000     mov word ptr [esi + ecx*2 + 0xac], ax
// 005fe3b3  8b4330               mov eax, dword ptr [ebx + 0x30]
// 005fe3b6  83c408               add esp, 8
// 005fe3b9  80403201             add byte ptr [eax + 0x32], 1
// 005fe3bd  0fb65032             movzx edx, byte ptr [eax + 0x32]
// 005fe3c1  0fb78c50aa000000     movzx ecx, word ptr [eax + edx*2 + 0xaa]
// 005fe3c9  8b10                 mov edx, dword ptr [eax]
// 005fe3cb  8b5218               mov edx, dword ptr [edx + 0x18]
// 005fe3ce  8b4018               mov eax, dword ptr [eax + 0x18]
// 005fe3d1  8d0c49               lea ecx, [ecx + ecx*2]
// 005fe3d4  89448a04             mov dword ptr [edx + ecx*4 + 4], eax
// 005fe3d8  8bfb                 mov edi, ebx
// 005fe3da  e8f1fdffff           call 0x5fe1d0
// 005fe3df  837b1029             cmp dword ptr [ebx + 0x10], 0x29
// 005fe3e3  7421                 je 0x5fe406
// 005fe3e5  6a29                 push 0x29
// 005fe3e7  53                   push ebx
// 005fe3e8  e8832a0000           call 0x600e70
// 005fe3ed  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 005fe3f0  50                   push eax
// 005fe3f1  6828047c00           push 0x7c0428
// 005fe3f6  51                   push ecx
// 005fe3f7  e844a4ffff           call 0x5f8840
// 005fe3fc  50                   push eax
// 005fe3fd  53                   push ebx
// 005fe3fe  e86d2b0000           call 0x600f70
// 005fe403  83c41c               add esp, 0x1c
// 005fe406  53                   push ebx
// 005fe407  e8943f0000           call 0x6023a0
// 005fe40c  53                   push ebx
// 005fe40d  e88e1d0000           call 0x6001a0
// 005fe412  8b442418             mov eax, dword ptr [esp + 0x18]
// 005fe416  8b5304               mov edx, dword ptr [ebx + 4]
// 005fe419  895040               mov dword ptr [eax + 0x40], edx
// 005fe41c  6809010000           push 0x109
// 005fe421  8bc5                 mov eax, ebp
// 005fe423  bf06010000           mov edi, 0x106
// 005fe428  8bf3                 mov esi, ebx
// 005fe42a  e8a1f0ffff           call 0x5fd4d0
// 005fe42f  53                   push ebx
// 005fe430  e8cbf7ffff           call 0x5fdc00
// 005fe435  8b8c2460020000       mov ecx, dword ptr [esp + 0x260]
// 005fe43c  51                   push ecx
// 005fe43d  8d542424             lea edx, [esp + 0x24]
// 005fe441  52                   push edx
// 005fe442  53                   push ebx
// 005fe443  e8f8f5ffff           call 0x5fda40
// 005fe448  83c41c               add esp, 0x1c
// 005fe44b  5f                   pop edi
// 005fe44c  5e                   pop esi
// 005fe44d  5d                   pop ebp
// 005fe44e  5b                   pop ebx
// 005fe44f  81c43c020000         add esp, 0x23c
// 005fe455  c3                   ret 
// library lua-5.1.1/lparser.c (function _body)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
