// roc 2009-12 007dce00  unit: RBX::GroupDragTool  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dce00
//
// 007dce00  53                   push ebx
// 007dce01  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007dce05  56                   push esi
// 007dce06  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dce0a  57                   push edi
// 007dce0b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007dce0f  8b07                 mov eax, dword ptr [edi]
// 007dce11  83c0fa               add eax, -6
// 007dce14  83f803               cmp eax, 3
// 007dce17  0f879f000000         ja 0x7dcebc
// 007dce1d  ff2485dcce7d00       jmp dword ptr [eax*4 + 0x7dcedc]
// 007dce24  8bc3                 mov eax, ebx
// 007dce26  83380c               cmp dword ptr [eax], 0xc
// 007dce29  8bce                 mov ecx, esi
// 007dce2b  7516                 jne 0x7dce43
// 007dce2d  8b5008               mov edx, dword ptr [eax + 8]
// 007dce30  f7c200010000         test edx, 0x100
// 007dce36  750b                 jne 0x7dce43
// 007dce38  0fb67132             movzx esi, byte ptr [ecx + 0x32]
// 007dce3c  3bd6                 cmp edx, esi
// 007dce3e  7c03                 jl 0x7dce43
// 007dce40  ff4924               dec dword ptr [ecx + 0x24]
// 007dce43  8b5708               mov edx, dword ptr [edi + 8]
// 007dce46  52                   push edx
// 007dce47  e8a4fcffff           call 0x7dcaf0
// 007dce4c  83c404               add esp, 4
// 007dce4f  5f                   pop edi
// 007dce50  5e                   pop esi
// 007dce51  5b                   pop ebx
// 007dce52  c3                   ret 
// 007dce53  53                   push ebx
// 007dce54  56                   push esi
// 007dce55  e836feffff           call 0x7dcc90
// 007dce5a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dce5d  8b5108               mov edx, dword ptr [ecx + 8]
// 007dce60  8b4f08               mov ecx, dword ptr [edi + 8]
// 007dce63  c1e111               shl ecx, 0x11
// 007dce66  0bc8                 or ecx, eax
// 007dce68  c1e106               shl ecx, 6
// 007dce6b  52                   push edx
// 007dce6c  83c908               or ecx, 8
// 007dce6f  51                   push ecx
// 007dce70  e8ebf6ffff           call 0x7dc560
// 007dce75  83c410               add esp, 0x10
// 007dce78  eb42                 jmp 0x7dcebc
// 007dce7a  53                   push ebx
// 007dce7b  56                   push esi
// 007dce7c  e80ffeffff           call 0x7dcc90
// 007dce81  8b560c               mov edx, dword ptr [esi + 0xc]
// 007dce84  8b4a08               mov ecx, dword ptr [edx + 8]
// 007dce87  8b5708               mov edx, dword ptr [edi + 8]
// 007dce8a  c1e208               shl edx, 8
// 007dce8d  0bd0                 or edx, eax
// 007dce8f  c1e206               shl edx, 6
// 007dce92  51                   push ecx
// 007dce93  83ca07               or edx, 7
// 007dce96  52                   push edx
// 007dce97  e8c4f6ffff           call 0x7dc560
// 007dce9c  83c410               add esp, 0x10
// 007dce9f  eb1b                 jmp 0x7dcebc
// 007dcea1  53                   push ebx
// 007dcea2  56                   push esi
// 007dcea3  e858feffff           call 0x7dcd00
// 007dcea8  8b4f08               mov ecx, dword ptr [edi + 8]
// 007dceab  50                   push eax
// 007dceac  8b470c               mov eax, dword ptr [edi + 0xc]
// 007dceaf  50                   push eax
// 007dceb0  51                   push ecx
// 007dceb1  6a09                 push 9
// 007dceb3  56                   push esi
// 007dceb4  e847f7ffff           call 0x7dc600
// 007dceb9  83c41c               add esp, 0x1c
// 007dcebc  833b0c               cmp dword ptr [ebx], 0xc
// 007dcebf  7516                 jne 0x7dced7
// 007dcec1  8b5b08               mov ebx, dword ptr [ebx + 8]
// 007dcec4  f7c300010000         test ebx, 0x100
// 007dceca  750b                 jne 0x7dced7
// 007dcecc  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007dced0  3bda                 cmp ebx, edx
// 007dced2  7c03                 jl 0x7dced7
// 007dced4  ff4e24               dec dword ptr [esi + 0x24]
// 007dced7  5f                   pop edi
// 007dced8  5e                   pop esi
// 007dced9  5b                   pop ebx
// 007dceda  c3                   ret 
// 007dcedb  90                   nop 
// 007dcedc  24ce                 and al, 0xce
// 007dcede  7d00                 jge 0x7dcee0
// 007dcee0  53                   push ebx
// 007dcee1  ce                   into 
// 007dcee2  7d00                 jge 0x7dcee4
// 007dcee4  7ace                 jp 0x7dceb4
// 007dcee6  7d00                 jge 0x7dcee8
// library lua-5.1/lcode.c (function _luaK_storevar)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
