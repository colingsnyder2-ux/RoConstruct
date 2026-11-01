// from server: 100% by auto
// roc 2009-12 007dc560  unit: RBX::GroupDragTool  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc560
//
// 007dc560  8b4618               mov eax, dword ptr [esi + 0x18]
// 007dc563  57                   push edi
// 007dc564  8b3e                 mov edi, dword ptr [esi]
// 007dc566  50                   push eax
// 007dc567  68ff000000           push 0xff
// 007dc56c  50                   push eax
// 007dc56d  8b4620               mov eax, dword ptr [esi + 0x20]
// 007dc570  56                   push esi
// 007dc571  e89afaffff           call 0x7dc010
// 007dc576  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007dc579  8d472c               lea eax, [edi + 0x2c]
// 007dc57c  41                   inc ecx
// 007dc57d  83c410               add esp, 0x10
// 007dc580  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 007dc587  3b08                 cmp ecx, dword ptr [eax]
// 007dc589  7e20                 jle 0x7dc5ab
// 007dc58b  8b570c               mov edx, dword ptr [edi + 0xc]
// 007dc58e  6858fb9e00           push 0x9efb58
// 007dc593  68fdffff7f           push 0x7ffffffd
// 007dc598  6a04                 push 4
// 007dc59a  50                   push eax
// 007dc59b  8b4610               mov eax, dword ptr [esi + 0x10]
// 007dc59e  52                   push edx
// 007dc59f  50                   push eax
// 007dc5a0  e85b52ffff           call 0x7d1800
// 007dc5a5  83c418               add esp, 0x18
// 007dc5a8  89470c               mov dword ptr [edi + 0xc], eax
// 007dc5ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007dc5ae  8b442408             mov eax, dword ptr [esp + 8]
// 007dc5b2  8b570c               mov edx, dword ptr [edi + 0xc]
// 007dc5b5  89048a               mov dword ptr [edx + ecx*4], eax
// 007dc5b8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007dc5bb  8d4730               lea eax, [edi + 0x30]
// 007dc5be  41                   inc ecx
// 007dc5bf  3b08                 cmp ecx, dword ptr [eax]
// 007dc5c1  7e20                 jle 0x7dc5e3
// 007dc5c3  8b5714               mov edx, dword ptr [edi + 0x14]
// 007dc5c6  6858fb9e00           push 0x9efb58
// 007dc5cb  68fdffff7f           push 0x7ffffffd
// 007dc5d0  6a04                 push 4
// 007dc5d2  50                   push eax
// 007dc5d3  8b4610               mov eax, dword ptr [esi + 0x10]
// 007dc5d6  52                   push edx
// 007dc5d7  50                   push eax
// 007dc5d8  e82352ffff           call 0x7d1800
// 007dc5dd  83c418               add esp, 0x18
// 007dc5e0  894714               mov dword ptr [edi + 0x14], eax
// 007dc5e3  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007dc5e6  8b5714               mov edx, dword ptr [edi + 0x14]
// 007dc5e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dc5ed  89048a               mov dword ptr [edx + ecx*4], eax
// 007dc5f0  8b4618               mov eax, dword ptr [esi + 0x18]
// 007dc5f3  8d4801               lea ecx, [eax + 1]
// 007dc5f6  894e18               mov dword ptr [esi + 0x18], ecx
// 007dc5f9  5f                   pop edi
// 007dc5fa  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_code)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
