// from server: 100% by auto
// roc 2009-06 006fa9d0  unit: RBX::GroupDragTool  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fa9d0
//
// 006fa9d0  53                   push ebx
// 006fa9d1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006fa9d5  56                   push esi
// 006fa9d6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa9da  57                   push edi
// 006fa9db  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006fa9df  8b07                 mov eax, dword ptr [edi]
// 006fa9e1  83c0fa               add eax, -6
// 006fa9e4  83f803               cmp eax, 3
// 006fa9e7  0f879f000000         ja 0x6faa8c
// 006fa9ed  ff2485acaa6f00       jmp dword ptr [eax*4 + 0x6faaac]
// 006fa9f4  8bc3                 mov eax, ebx
// 006fa9f6  83380c               cmp dword ptr [eax], 0xc
// 006fa9f9  8bce                 mov ecx, esi
// 006fa9fb  7516                 jne 0x6faa13
// 006fa9fd  8b5008               mov edx, dword ptr [eax + 8]
// 006faa00  f7c200010000         test edx, 0x100
// 006faa06  750b                 jne 0x6faa13
// 006faa08  0fb67132             movzx esi, byte ptr [ecx + 0x32]
// 006faa0c  3bd6                 cmp edx, esi
// 006faa0e  7c03                 jl 0x6faa13
// 006faa10  ff4924               dec dword ptr [ecx + 0x24]
// 006faa13  8b5708               mov edx, dword ptr [edi + 8]
// 006faa16  52                   push edx
// 006faa17  e8a4fcffff           call 0x6fa6c0
// 006faa1c  83c404               add esp, 4
// 006faa1f  5f                   pop edi
// 006faa20  5e                   pop esi
// 006faa21  5b                   pop ebx
// 006faa22  c3                   ret 
// 006faa23  53                   push ebx
// 006faa24  56                   push esi
// 006faa25  e836feffff           call 0x6fa860
// 006faa2a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006faa2d  8b5108               mov edx, dword ptr [ecx + 8]
// 006faa30  8b4f08               mov ecx, dword ptr [edi + 8]
// 006faa33  c1e111               shl ecx, 0x11
// 006faa36  0bc8                 or ecx, eax
// 006faa38  c1e106               shl ecx, 6
// 006faa3b  52                   push edx
// 006faa3c  83c908               or ecx, 8
// 006faa3f  51                   push ecx
// 006faa40  e8ebf6ffff           call 0x6fa130
// 006faa45  83c410               add esp, 0x10
// 006faa48  eb42                 jmp 0x6faa8c
// 006faa4a  53                   push ebx
// 006faa4b  56                   push esi
// 006faa4c  e80ffeffff           call 0x6fa860
// 006faa51  8b560c               mov edx, dword ptr [esi + 0xc]
// 006faa54  8b4a08               mov ecx, dword ptr [edx + 8]
// 006faa57  8b5708               mov edx, dword ptr [edi + 8]
// 006faa5a  c1e208               shl edx, 8
// 006faa5d  0bd0                 or edx, eax
// 006faa5f  c1e206               shl edx, 6
// 006faa62  51                   push ecx
// 006faa63  83ca07               or edx, 7
// 006faa66  52                   push edx
// 006faa67  e8c4f6ffff           call 0x6fa130
// 006faa6c  83c410               add esp, 0x10
// 006faa6f  eb1b                 jmp 0x6faa8c
// 006faa71  53                   push ebx
// 006faa72  56                   push esi
// 006faa73  e858feffff           call 0x6fa8d0
// 006faa78  8b4f08               mov ecx, dword ptr [edi + 8]
// 006faa7b  50                   push eax
// 006faa7c  8b470c               mov eax, dword ptr [edi + 0xc]
// 006faa7f  50                   push eax
// 006faa80  51                   push ecx
// 006faa81  6a09                 push 9
// 006faa83  56                   push esi
// 006faa84  e847f7ffff           call 0x6fa1d0
// 006faa89  83c41c               add esp, 0x1c
// 006faa8c  833b0c               cmp dword ptr [ebx], 0xc
// 006faa8f  7516                 jne 0x6faaa7
// 006faa91  8b5b08               mov ebx, dword ptr [ebx + 8]
// 006faa94  f7c300010000         test ebx, 0x100
// 006faa9a  750b                 jne 0x6faaa7
// 006faa9c  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 006faaa0  3bda                 cmp ebx, edx
// 006faaa2  7c03                 jl 0x6faaa7
// 006faaa4  ff4e24               dec dword ptr [esi + 0x24]
// 006faaa7  5f                   pop edi
// 006faaa8  5e                   pop esi
// 006faaa9  5b                   pop ebx
// 006faaaa  c3                   ret 
// 006faaab  90                   nop 
// 006faaac  f4                   hlt 
// 006faaad  a96f0023aa           test eax, 0xaa23006f
// 006faab2  6f                   outsd dx, dword ptr [esi]
// 006faab3  004aaa               add byte ptr [edx - 0x56], cl
// 006faab6  6f                   outsd dx, dword ptr [esi]
// 006faab7  0071aa               add byte ptr [ecx - 0x56], dh
// 006faaba  6f                   outsd dx, dword ptr [esi]
// library lua-5.1/lcode.c (function _luaK_storevar)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
