// from server: 100% by auto
// roc 2010-06 0078fde0  unit: RBX::GroupDragTool  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078fde0
//
// 0078fde0  57                   push edi
// 0078fde1  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078fde5  8b07                 mov eax, dword ptr [edi]
// 0078fde7  83c0fa               add eax, -6
// 0078fdea  83f808               cmp eax, 8
// 0078fded  0f87c6000000         ja 0x78feb9
// 0078fdf3  56                   push esi
// 0078fdf4  ff2485bcfe7800       jmp dword ptr [eax*4 + 0x78febc]
// 0078fdfb  5e                   pop esi
// 0078fdfc  c7070c000000         mov dword ptr [edi], 0xc
// 0078fe02  5f                   pop edi
// 0078fe03  c3                   ret 
// 0078fe04  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078fe08  8b4708               mov eax, dword ptr [edi + 8]
// 0078fe0b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0078fe0e  8b5108               mov edx, dword ptr [ecx + 8]
// 0078fe11  c1e017               shl eax, 0x17
// 0078fe14  52                   push edx
// 0078fe15  83c804               or eax, 4
// 0078fe18  50                   push eax
// 0078fe19  e8a2fcffff           call 0x78fac0
// 0078fe1e  83c408               add esp, 8
// 0078fe21  5e                   pop esi
// 0078fe22  894708               mov dword ptr [edi + 8], eax
// 0078fe25  c7070b000000         mov dword ptr [edi], 0xb
// 0078fe2b  5f                   pop edi
// 0078fe2c  c3                   ret 
// 0078fe2d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078fe31  8b4708               mov eax, dword ptr [edi + 8]
// 0078fe34  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0078fe37  8b5108               mov edx, dword ptr [ecx + 8]
// 0078fe3a  c1e00e               shl eax, 0xe
// 0078fe3d  52                   push edx
// 0078fe3e  83c805               or eax, 5
// 0078fe41  50                   push eax
// 0078fe42  e879fcffff           call 0x78fac0
// 0078fe47  83c408               add esp, 8
// 0078fe4a  5e                   pop esi
// 0078fe4b  894708               mov dword ptr [edi + 8], eax
// 0078fe4e  c7070b000000         mov dword ptr [edi], 0xb
// 0078fe54  5f                   pop edi
// 0078fe55  c3                   ret 
// 0078fe56  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0078fe59  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078fe5d  83caff               or edx, 0xffffffff
// 0078fe60  f7c100010000         test ecx, 0x100
// 0078fe66  750b                 jne 0x78fe73
// 0078fe68  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 0078fe6c  3bce                 cmp ecx, esi
// 0078fe6e  7c03                 jl 0x78fe73
// 0078fe70  015024               add dword ptr [eax + 0x24], edx
// 0078fe73  8b4f08               mov ecx, dword ptr [edi + 8]
// 0078fe76  f7c100010000         test ecx, 0x100
// 0078fe7c  750b                 jne 0x78fe89
// 0078fe7e  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 0078fe82  3bce                 cmp ecx, esi
// 0078fe84  7c03                 jl 0x78fe89
// 0078fe86  015024               add dword ptr [eax + 0x24], edx
// 0078fe89  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0078fe8c  8b5708               mov edx, dword ptr [edi + 8]
// 0078fe8f  51                   push ecx
// 0078fe90  52                   push edx
// 0078fe91  6a00                 push 0
// 0078fe93  6a06                 push 6
// 0078fe95  50                   push eax
// 0078fe96  e8c5fcffff           call 0x78fb60
// 0078fe9b  83c414               add esp, 0x14
// 0078fe9e  5e                   pop esi
// 0078fe9f  894708               mov dword ptr [edi + 8], eax
// 0078fea2  c7070b000000         mov dword ptr [edi], 0xb
// 0078fea8  5f                   pop edi
// 0078fea9  c3                   ret 
// 0078feaa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0078feae  57                   push edi
// 0078feaf  50                   push eax
// 0078feb0  e83bfaffff           call 0x78f8f0
// 0078feb5  83c408               add esp, 8
// 0078feb8  5e                   pop esi
// 0078feb9  5f                   pop edi
// 0078feba  c3                   ret 
// 0078febb  90                   nop 
// 0078febc  fb                   sti 
// 0078febd  fd                   std 
// 0078febe  7800                 js 0x78fec0
// 0078fec0  04fe                 add al, 0xfe
// 0078fec2  7800                 js 0x78fec4
// 0078fec4  2dfe780056           sub eax, 0x560078fe
// library lua-5.1/lcode.c (function _luaK_dischargevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
