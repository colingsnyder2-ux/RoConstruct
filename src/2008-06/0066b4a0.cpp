// from server: 100% by auto
// roc 2008-06 0066b4a0  unit: RBX::GroupDragTool  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066b4a0
//
// 0066b4a0  57                   push edi
// 0066b4a1  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0066b4a5  8b07                 mov eax, dword ptr [edi]
// 0066b4a7  83c0fa               add eax, -6
// 0066b4aa  83f808               cmp eax, 8
// 0066b4ad  0f87c6000000         ja 0x66b579
// 0066b4b3  56                   push esi
// 0066b4b4  ff24857cb56600       jmp dword ptr [eax*4 + 0x66b57c]
// 0066b4bb  5e                   pop esi
// 0066b4bc  c7070c000000         mov dword ptr [edi], 0xc
// 0066b4c2  5f                   pop edi
// 0066b4c3  c3                   ret 
// 0066b4c4  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0066b4c8  8b4708               mov eax, dword ptr [edi + 8]
// 0066b4cb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0066b4ce  8b5108               mov edx, dword ptr [ecx + 8]
// 0066b4d1  c1e017               shl eax, 0x17
// 0066b4d4  52                   push edx
// 0066b4d5  83c804               or eax, 4
// 0066b4d8  50                   push eax
// 0066b4d9  e8b2fcffff           call 0x66b190
// 0066b4de  83c408               add esp, 8
// 0066b4e1  5e                   pop esi
// 0066b4e2  894708               mov dword ptr [edi + 8], eax
// 0066b4e5  c7070b000000         mov dword ptr [edi], 0xb
// 0066b4eb  5f                   pop edi
// 0066b4ec  c3                   ret 
// 0066b4ed  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0066b4f1  8b4708               mov eax, dword ptr [edi + 8]
// 0066b4f4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0066b4f7  8b5108               mov edx, dword ptr [ecx + 8]
// 0066b4fa  c1e00e               shl eax, 0xe
// 0066b4fd  52                   push edx
// 0066b4fe  83c805               or eax, 5
// 0066b501  50                   push eax
// 0066b502  e889fcffff           call 0x66b190
// 0066b507  83c408               add esp, 8
// 0066b50a  5e                   pop esi
// 0066b50b  894708               mov dword ptr [edi + 8], eax
// 0066b50e  c7070b000000         mov dword ptr [edi], 0xb
// 0066b514  5f                   pop edi
// 0066b515  c3                   ret 
// 0066b516  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0066b519  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066b51d  83caff               or edx, 0xffffffff
// 0066b520  f7c100010000         test ecx, 0x100
// 0066b526  750b                 jne 0x66b533
// 0066b528  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 0066b52c  3bce                 cmp ecx, esi
// 0066b52e  7c03                 jl 0x66b533
// 0066b530  015024               add dword ptr [eax + 0x24], edx
// 0066b533  8b4f08               mov ecx, dword ptr [edi + 8]
// 0066b536  f7c100010000         test ecx, 0x100
// 0066b53c  750b                 jne 0x66b549
// 0066b53e  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 0066b542  3bce                 cmp ecx, esi
// 0066b544  7c03                 jl 0x66b549
// 0066b546  015024               add dword ptr [eax + 0x24], edx
// 0066b549  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0066b54c  8b5708               mov edx, dword ptr [edi + 8]
// 0066b54f  51                   push ecx
// 0066b550  52                   push edx
// 0066b551  6a00                 push 0
// 0066b553  6a06                 push 6
// 0066b555  50                   push eax
// 0066b556  e8d5fcffff           call 0x66b230
// 0066b55b  83c414               add esp, 0x14
// 0066b55e  5e                   pop esi
// 0066b55f  894708               mov dword ptr [edi + 8], eax
// 0066b562  c7070b000000         mov dword ptr [edi], 0xb
// 0066b568  5f                   pop edi
// 0066b569  c3                   ret 
// 0066b56a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066b56e  57                   push edi
// 0066b56f  50                   push eax
// 0066b570  e85bfaffff           call 0x66afd0
// 0066b575  83c408               add esp, 8
// 0066b578  5e                   pop esi
// 0066b579  5f                   pop edi
// 0066b57a  c3                   ret 
// 0066b57b  90                   nop 
// 0066b57c  bbb46600c4           mov ebx, 0xc40066b4
// 0066b581  b466                 mov ah, 0x66
// 0066b583  00ed                 add ch, ch
// 0066b585  b466                 mov ah, 0x66
// 0066b587  0016                 add byte ptr [esi], dl
// 0066b589  b566                 mov ch, 0x66
// 0066b58b  0078b5               add byte ptr [eax - 0x4b], bh
// 0066b58e  660078b5             add byte ptr [eax - 0x4b], bh
// 0066b592  660078b5             add byte ptr [eax - 0x4b], bh
// 0066b596  66006ab5             add byte ptr [edx - 0x4b], ch
// 0066b59a  66006ab5             add byte ptr [edx - 0x4b], ch
// library lua-5.1/lcode.c (function _luaK_dischargevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
