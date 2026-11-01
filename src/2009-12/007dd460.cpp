// from server: 100% by auto
// roc 2009-12 007dd460  unit: RBX::GroupDragTool  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd460
//
// 007dd460  8b442408             mov eax, dword ptr [esp + 8]
// 007dd464  83f80e               cmp eax, 0xe
// 007dd467  7766                 ja 0x7dd4cf
// 007dd469  0fb680f8d47d00       movzx eax, byte ptr [eax + 0x7dd4f8]
// 007dd470  ff2485e4d47d00       jmp dword ptr [eax*4 + 0x7dd4e4]
// 007dd477  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007dd47b  8b542404             mov edx, dword ptr [esp + 4]
// 007dd47f  51                   push ecx
// 007dd480  52                   push edx
// 007dd481  e8aafbffff           call 0x7dd030
// 007dd486  83c408               add esp, 8
// 007dd489  c3                   ret 
// 007dd48a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dd48e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dd492  e939fcffff           jmp 0x7dd0d0
// 007dd497  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dd49b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dd49f  50                   push eax
// 007dd4a0  51                   push ecx
// 007dd4a1  e86af7ffff           call 0x7dcc10
// 007dd4a6  83c408               add esp, 8
// 007dd4a9  c3                   ret 
// 007dd4aa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dd4ae  833805               cmp dword ptr [eax], 5
// 007dd4b1  750d                 jne 0x7dd4c0
// 007dd4b3  83c9ff               or ecx, 0xffffffff
// 007dd4b6  394810               cmp dword ptr [eax + 0x10], ecx
// 007dd4b9  7505                 jne 0x7dd4c0
// 007dd4bb  394814               cmp dword ptr [eax + 0x14], ecx
// 007dd4be  7421                 je 0x7dd4e1
// 007dd4c0  8b542404             mov edx, dword ptr [esp + 4]
// 007dd4c4  50                   push eax
// 007dd4c5  52                   push edx
// 007dd4c6  e835f8ffff           call 0x7dcd00
// 007dd4cb  83c408               add esp, 8
// 007dd4ce  c3                   ret 
// 007dd4cf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dd4d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dd4d7  50                   push eax
// 007dd4d8  51                   push ecx
// 007dd4d9  e822f8ffff           call 0x7dcd00
// 007dd4de  83c408               add esp, 8
// 007dd4e1  c3                   ret 
// 007dd4e2  8bff                 mov edi, edi
// 007dd4e4  aa                   stosb byte ptr es:[edi], al
// 007dd4e5  d47d                 aam 0x7d
// 007dd4e7  0097d47d0077         add byte ptr [edi + 0x77007dd4], dl
// 007dd4ed  d47d                 aam 0x7d
// 007dd4ef  008ad47d00cf         add byte ptr [edx - 0x30ff822c], cl
// 007dd4f5  d47d                 aam 0x7d
// 007dd4f7  0000                 add byte ptr [eax], al
// 007dd4f9  0000                 add byte ptr [eax], al
// 007dd4fb  0000                 add byte ptr [eax], al
// 007dd4fd  0001                 add byte ptr [ecx], al
// 007dd4ff  0404                 add al, 4
// 007dd501  0404                 add al, 4
// 007dd503  0404                 add al, 4
// 007dd505  0203                 add al, byte ptr [ebx]
// library lua-5.1.2/lcode.c (function _luaK_infix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lcode.c
