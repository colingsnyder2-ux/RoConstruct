// roc 2012-06 009679d0  unit: RBX::CellContact  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009679d0
//
// 009679d0  57                   push edi
// 009679d1  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 009679d5  8b07                 mov eax, dword ptr [edi]
// 009679d7  83c0fa               add eax, -6
// 009679da  83f808               cmp eax, 8
// 009679dd  0f87c6000000         ja 0x967aa9
// 009679e3  56                   push esi
// 009679e4  ff2485ac7a9600       jmp dword ptr [eax*4 + 0x967aac]
// 009679eb  5e                   pop esi
// 009679ec  c7070c000000         mov dword ptr [edi], 0xc
// 009679f2  5f                   pop edi
// 009679f3  c3                   ret 
// 009679f4  8b74240c             mov esi, dword ptr [esp + 0xc]
// 009679f8  8b4708               mov eax, dword ptr [edi + 8]
// 009679fb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 009679fe  8b5108               mov edx, dword ptr [ecx + 8]
// 00967a01  c1e017               shl eax, 0x17
// 00967a04  52                   push edx
// 00967a05  83c804               or eax, 4
// 00967a08  50                   push eax
// 00967a09  e8a2fcffff           call 0x9676b0
// 00967a0e  83c408               add esp, 8
// 00967a11  5e                   pop esi
// 00967a12  894708               mov dword ptr [edi + 8], eax
// 00967a15  c7070b000000         mov dword ptr [edi], 0xb
// 00967a1b  5f                   pop edi
// 00967a1c  c3                   ret 
// 00967a1d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00967a21  8b4708               mov eax, dword ptr [edi + 8]
// 00967a24  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00967a27  8b5108               mov edx, dword ptr [ecx + 8]
// 00967a2a  c1e00e               shl eax, 0xe
// 00967a2d  52                   push edx
// 00967a2e  83c805               or eax, 5
// 00967a31  50                   push eax
// 00967a32  e879fcffff           call 0x9676b0
// 00967a37  83c408               add esp, 8
// 00967a3a  5e                   pop esi
// 00967a3b  894708               mov dword ptr [edi + 8], eax
// 00967a3e  c7070b000000         mov dword ptr [edi], 0xb
// 00967a44  5f                   pop edi
// 00967a45  c3                   ret 
// 00967a46  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00967a49  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00967a4d  83caff               or edx, 0xffffffff
// 00967a50  f7c100010000         test ecx, 0x100
// 00967a56  750b                 jne 0x967a63
// 00967a58  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 00967a5c  3bce                 cmp ecx, esi
// 00967a5e  7c03                 jl 0x967a63
// 00967a60  015024               add dword ptr [eax + 0x24], edx
// 00967a63  8b4f08               mov ecx, dword ptr [edi + 8]
// 00967a66  f7c100010000         test ecx, 0x100
// 00967a6c  750b                 jne 0x967a79
// 00967a6e  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 00967a72  3bce                 cmp ecx, esi
// 00967a74  7c03                 jl 0x967a79
// 00967a76  015024               add dword ptr [eax + 0x24], edx
// 00967a79  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00967a7c  8b5708               mov edx, dword ptr [edi + 8]
// 00967a7f  51                   push ecx
// 00967a80  52                   push edx
// 00967a81  6a00                 push 0
// 00967a83  6a06                 push 6
// 00967a85  50                   push eax
// 00967a86  e8c5fcffff           call 0x967750
// 00967a8b  83c414               add esp, 0x14
// 00967a8e  5e                   pop esi
// 00967a8f  894708               mov dword ptr [edi + 8], eax
// 00967a92  c7070b000000         mov dword ptr [edi], 0xb
// 00967a98  5f                   pop edi
// 00967a99  c3                   ret 
// 00967a9a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00967a9e  57                   push edi
// 00967a9f  50                   push eax
// 00967aa0  e83bfaffff           call 0x9674e0
// 00967aa5  83c408               add esp, 8
// 00967aa8  5e                   pop esi
// 00967aa9  5f                   pop edi
// 00967aaa  c3                   ret 
// 00967aab  90                   nop 
// 00967aac  eb79                 jmp 0x967b27
// 00967aae  96                   xchg esi, eax
// 00967aaf  00f4                 add ah, dh
// 00967ab1  7996                 jns 0x967a49
// 00967ab3  001d7a960046         add byte ptr [0x4600967a], bl
// 00967ab9  7a96                 jp 0x967a51
// 00967abb  00a87a9600a8         add byte ptr [eax - 0x57ff6986], ch
// 00967ac1  7a96                 jp 0x967a59
// 00967ac3  00a87a96009a         add byte ptr [eax - 0x65ff6986], ch
// 00967ac9  7a96                 jp 0x967a61
// library lua-5.1/lcode.c (function _luaK_dischargevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
