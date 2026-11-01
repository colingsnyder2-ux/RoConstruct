// from server: 100% by auto
// roc 2009-12 007dd3c0  unit: RBX::GroupDragTool  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd3c0
//
// 007dd3c0  83ec18               sub esp, 0x18
// 007dd3c3  d9ee                 fldz 
// 007dd3c5  8b442420             mov eax, dword ptr [esp + 0x20]
// 007dd3c9  83c9ff               or ecx, 0xffffffff
// 007dd3cc  dd5c2408             fstp qword ptr [esp + 8]
// 007dd3d0  83e800               sub eax, 0
// 007dd3d3  53                   push ebx
// 007dd3d4  57                   push edi
// 007dd3d5  894c241c             mov dword ptr [esp + 0x1c], ecx
// 007dd3d9  894c2418             mov dword ptr [esp + 0x18], ecx
// 007dd3dd  c744240805000000     mov dword ptr [esp + 8], 5
// 007dd3e5  7443                 je 0x7dd42a
// 007dd3e7  83e801               sub eax, 1
// 007dd3ea  7429                 je 0x7dd415
// 007dd3ec  83e801               sub eax, 1
// 007dd3ef  7569                 jne 0x7dd45a
// 007dd3f1  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 007dd3f5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007dd3f9  53                   push ebx
// 007dd3fa  57                   push edi
// 007dd3fb  e890f8ffff           call 0x7dcc90
// 007dd400  8d442410             lea eax, [esp + 0x10]
// 007dd404  50                   push eax
// 007dd405  6a14                 push 0x14
// 007dd407  e834feffff           call 0x7dd240
// 007dd40c  83c410               add esp, 0x10
// 007dd40f  5f                   pop edi
// 007dd410  5b                   pop ebx
// 007dd411  83c418               add esp, 0x18
// 007dd414  c3                   ret 
// 007dd415  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007dd419  56                   push esi
// 007dd41a  8b742430             mov esi, dword ptr [esp + 0x30]
// 007dd41e  e83dfdffff           call 0x7dd160
// 007dd423  5e                   pop esi
// 007dd424  5f                   pop edi
// 007dd425  5b                   pop ebx
// 007dd426  83c418               add esp, 0x18
// 007dd429  c3                   ret 
// 007dd42a  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 007dd42e  833b05               cmp dword ptr [ebx], 5
// 007dd431  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007dd435  750a                 jne 0x7dd441
// 007dd437  394b10               cmp dword ptr [ebx + 0x10], ecx
// 007dd43a  7505                 jne 0x7dd441
// 007dd43c  394b14               cmp dword ptr [ebx + 0x14], ecx
// 007dd43f  740a                 je 0x7dd44b
// 007dd441  53                   push ebx
// 007dd442  57                   push edi
// 007dd443  e848f8ffff           call 0x7dcc90
// 007dd448  83c408               add esp, 8
// 007dd44b  8d4c2408             lea ecx, [esp + 8]
// 007dd44f  51                   push ecx
// 007dd450  6a12                 push 0x12
// 007dd452  e8e9fdffff           call 0x7dd240
// 007dd457  83c408               add esp, 8
// 007dd45a  5f                   pop edi
// 007dd45b  5b                   pop ebx
// 007dd45c  83c418               add esp, 0x18
// 007dd45f  c3                   ret 
// library lua-5.1.3/lcode.c (function _luaK_prefix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lcode.c
