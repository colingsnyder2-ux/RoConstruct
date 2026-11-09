// from server: 100% by auto
// roc 2009-12 007dc880  unit: RBX::GroupDragTool  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc880
//
// 007dc880  57                   push edi
// 007dc881  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007dc885  8b07                 mov eax, dword ptr [edi]
// 007dc887  83c0fa               add eax, -6
// 007dc88a  83f808               cmp eax, 8
// 007dc88d  0f87c6000000         ja 0x7dc959
// 007dc893  56                   push esi
// 007dc894  ff24855cc97d00       jmp dword ptr [eax*4 + 0x7dc95c]
// 007dc89b  5e                   pop esi
// 007dc89c  c7070c000000         mov dword ptr [edi], 0xc
// 007dc8a2  5f                   pop edi
// 007dc8a3  c3                   ret 
// 007dc8a4  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dc8a8  8b4708               mov eax, dword ptr [edi + 8]
// 007dc8ab  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dc8ae  8b5108               mov edx, dword ptr [ecx + 8]
// 007dc8b1  c1e017               shl eax, 0x17
// 007dc8b4  52                   push edx
// 007dc8b5  83c804               or eax, 4
// 007dc8b8  50                   push eax
// 007dc8b9  e8a2fcffff           call 0x7dc560
// 007dc8be  83c408               add esp, 8
// 007dc8c1  5e                   pop esi
// 007dc8c2  894708               mov dword ptr [edi + 8], eax
// 007dc8c5  c7070b000000         mov dword ptr [edi], 0xb
// 007dc8cb  5f                   pop edi
// 007dc8cc  c3                   ret 
// 007dc8cd  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dc8d1  8b4708               mov eax, dword ptr [edi + 8]
// 007dc8d4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dc8d7  8b5108               mov edx, dword ptr [ecx + 8]
// 007dc8da  c1e00e               shl eax, 0xe
// 007dc8dd  52                   push edx
// 007dc8de  83c805               or eax, 5
// 007dc8e1  50                   push eax
// 007dc8e2  e879fcffff           call 0x7dc560
// 007dc8e7  83c408               add esp, 8
// 007dc8ea  5e                   pop esi
// 007dc8eb  894708               mov dword ptr [edi + 8], eax
// 007dc8ee  c7070b000000         mov dword ptr [edi], 0xb
// 007dc8f4  5f                   pop edi
// 007dc8f5  c3                   ret 
// 007dc8f6  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 007dc8f9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dc8fd  83caff               or edx, 0xffffffff
// 007dc900  f7c100010000         test ecx, 0x100
// 007dc906  750b                 jne 0x7dc913
// 007dc908  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 007dc90c  3bce                 cmp ecx, esi
// 007dc90e  7c03                 jl 0x7dc913
// 007dc910  015024               add dword ptr [eax + 0x24], edx
// 007dc913  8b4f08               mov ecx, dword ptr [edi + 8]
// 007dc916  f7c100010000         test ecx, 0x100
// 007dc91c  750b                 jne 0x7dc929
// 007dc91e  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 007dc922  3bce                 cmp ecx, esi
// 007dc924  7c03                 jl 0x7dc929
// 007dc926  015024               add dword ptr [eax + 0x24], edx
// 007dc929  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 007dc92c  8b5708               mov edx, dword ptr [edi + 8]
// 007dc92f  51                   push ecx
// 007dc930  52                   push edx
// 007dc931  6a00                 push 0
// 007dc933  6a06                 push 6
// 007dc935  50                   push eax
// 007dc936  e8c5fcffff           call 0x7dc600
// 007dc93b  83c414               add esp, 0x14
// 007dc93e  5e                   pop esi
// 007dc93f  894708               mov dword ptr [edi + 8], eax
// 007dc942  c7070b000000         mov dword ptr [edi], 0xb
// 007dc948  5f                   pop edi
// 007dc949  c3                   ret 
// 007dc94a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dc94e  57                   push edi
// 007dc94f  50                   push eax
// 007dc950  e83bfaffff           call 0x7dc390
// 007dc955  83c408               add esp, 8
// 007dc958  5e                   pop esi
// 007dc959  5f                   pop edi
// 007dc95a  c3                   ret 
// 007dc95b  90                   nop 
// 007dc95c  9b                   wait 
// 007dc95d  c87d00a4             enter 0x7d, -0x5c
// 007dc961  c87d00cd             enter 0x7d, -0x33
// 007dc965  c87d00f6             enter 0x7d, -0xa
// 007dc969  c87d0058             enter 0x7d, 0x58
// 007dc96d  c9                   leave 
// 007dc96e  7d00                 jge 0x7dc970
// 007dc970  58                   pop eax
// 007dc971  c9                   leave 
// 007dc972  7d00                 jge 0x7dc974
// 007dc974  58                   pop eax
// 007dc975  c9                   leave 
// 007dc976  7d00                 jge 0x7dc978
// 007dc978  4a                   dec edx
// 007dc979  c9                   leave 
// 007dc97a  7d00                 jge 0x7dc97c
// 007dc97c  4a                   dec edx
// 007dc97d  c9                   leave 
// 007dc97e  7d00                 jge 0x7dc980
// library lua-5.1/lcode.c (function _luaK_dischargevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
