// from server: 100% by auto
// roc 2007-08 00629000  unit: RBX::AssemblyStage  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00629000
//
// 00629000  57                   push edi
// 00629001  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00629005  8b07                 mov eax, dword ptr [edi]
// 00629007  83c0fa               add eax, -6
// 0062900a  83f808               cmp eax, 8
// 0062900d  0f87c6000000         ja 0x6290d9
// 00629013  56                   push esi
// 00629014  ff2485dc906200       jmp dword ptr [eax*4 + 0x6290dc]
// 0062901b  5e                   pop esi
// 0062901c  c7070c000000         mov dword ptr [edi], 0xc
// 00629022  5f                   pop edi
// 00629023  c3                   ret 
// 00629024  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00629028  8b4708               mov eax, dword ptr [edi + 8]
// 0062902b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0062902e  8b5108               mov edx, dword ptr [ecx + 8]
// 00629031  c1e017               shl eax, 0x17
// 00629034  52                   push edx
// 00629035  83c804               or eax, 4
// 00629038  50                   push eax
// 00629039  e8a2fcffff           call 0x628ce0
// 0062903e  83c408               add esp, 8
// 00629041  5e                   pop esi
// 00629042  894708               mov dword ptr [edi + 8], eax
// 00629045  c7070b000000         mov dword ptr [edi], 0xb
// 0062904b  5f                   pop edi
// 0062904c  c3                   ret 
// 0062904d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00629051  8b4708               mov eax, dword ptr [edi + 8]
// 00629054  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00629057  8b5108               mov edx, dword ptr [ecx + 8]
// 0062905a  c1e00e               shl eax, 0xe
// 0062905d  52                   push edx
// 0062905e  83c805               or eax, 5
// 00629061  50                   push eax
// 00629062  e879fcffff           call 0x628ce0
// 00629067  83c408               add esp, 8
// 0062906a  5e                   pop esi
// 0062906b  894708               mov dword ptr [edi + 8], eax
// 0062906e  c7070b000000         mov dword ptr [edi], 0xb
// 00629074  5f                   pop edi
// 00629075  c3                   ret 
// 00629076  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00629079  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0062907d  83caff               or edx, 0xffffffff
// 00629080  f7c100010000         test ecx, 0x100
// 00629086  750b                 jne 0x629093
// 00629088  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 0062908c  3bce                 cmp ecx, esi
// 0062908e  7c03                 jl 0x629093
// 00629090  015024               add dword ptr [eax + 0x24], edx
// 00629093  8b4f08               mov ecx, dword ptr [edi + 8]
// 00629096  f7c100010000         test ecx, 0x100
// 0062909c  750b                 jne 0x6290a9
// 0062909e  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 006290a2  3bce                 cmp ecx, esi
// 006290a4  7c03                 jl 0x6290a9
// 006290a6  015024               add dword ptr [eax + 0x24], edx
// 006290a9  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 006290ac  8b5708               mov edx, dword ptr [edi + 8]
// 006290af  51                   push ecx
// 006290b0  52                   push edx
// 006290b1  6a00                 push 0
// 006290b3  6a06                 push 6
// 006290b5  50                   push eax
// 006290b6  e8c5fcffff           call 0x628d80
// 006290bb  83c414               add esp, 0x14
// 006290be  5e                   pop esi
// 006290bf  894708               mov dword ptr [edi + 8], eax
// 006290c2  c7070b000000         mov dword ptr [edi], 0xb
// 006290c8  5f                   pop edi
// 006290c9  c3                   ret 
// 006290ca  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006290ce  57                   push edi
// 006290cf  50                   push eax
// 006290d0  e84bfaffff           call 0x628b20
// 006290d5  83c408               add esp, 8
// 006290d8  5e                   pop esi
// 006290d9  5f                   pop edi
// 006290da  c3                   ret 
// 006290db  90                   nop 
// 006290dc  1b9062002490         sbb edx, dword ptr [eax - 0x6fdbff9e]
// 006290e2  6200                 bound eax, qword ptr [eax]
// 006290e4  4d                   dec ebp
// 006290e5  90                   nop 
// 006290e6  6200                 bound eax, qword ptr [eax]
// 006290e8  7690                 jbe 0x62907a
// 006290ea  6200                 bound eax, qword ptr [eax]
// 006290ec  d8906200d890         fcom dword ptr [eax - 0x6f27ff9e]
// 006290f2  6200                 bound eax, qword ptr [eax]
// 006290f4  d8906200ca90         fcom dword ptr [eax - 0x6f35ff9e]
// 006290fa  6200                 bound eax, qword ptr [eax]
// 006290fc  ca9062               retf 0x6290
// library lua-5.1/lcode.c (function _luaK_dischargevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
