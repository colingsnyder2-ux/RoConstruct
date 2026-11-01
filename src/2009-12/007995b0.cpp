// from server: 100% by auto
// roc 2009-12 007995b0  unit: lua_exception  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007995b0
//
// 007995b0  83ec08               sub esp, 8
// 007995b3  53                   push ebx
// 007995b4  55                   push ebp
// 007995b5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007995bb  56                   push esi
// 007995bc  8bf1                 mov esi, ecx
// 007995be  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007995c1  57                   push edi
// 007995c2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007995c5  8bcb                 mov ecx, ebx
// 007995c7  2bcf                 sub ecx, edi
// 007995c9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007995ce  f7e9                 imul ecx
// 007995d0  c1fa02               sar edx, 2
// 007995d3  8bc2                 mov eax, edx
// 007995d5  c1e81f               shr eax, 0x1f
// 007995d8  03c2                 add eax, edx
// 007995da  7504                 jne 0x7995e0
// 007995dc  33ff                 xor edi, edi
// 007995de  eb2d                 jmp 0x79960d
// 007995e0  3bfb                 cmp edi, ebx
// 007995e2  7602                 jbe 0x7995e6
// 007995e4  ffd5                 call ebp
// 007995e6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007995ea  8b06                 mov eax, dword ptr [esi]
// 007995ec  85c9                 test ecx, ecx
// 007995ee  7404                 je 0x7995f4
// 007995f0  3bc8                 cmp ecx, eax
// 007995f2  7402                 je 0x7995f6
// 007995f4  ffd5                 call ebp
// 007995f6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007995fa  2bcf                 sub ecx, edi
// 007995fc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00799601  f7e9                 imul ecx
// 00799603  c1fa02               sar edx, 2
// 00799606  8bfa                 mov edi, edx
// 00799608  c1ef1f               shr edi, 0x1f
// 0079960b  03fa                 add edi, edx
// 0079960d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00799611  8b542424             mov edx, dword ptr [esp + 0x24]
// 00799615  8b442420             mov eax, dword ptr [esp + 0x20]
// 00799619  51                   push ecx
// 0079961a  6a01                 push 1
// 0079961c  52                   push edx
// 0079961d  50                   push eax
// 0079961e  8bce                 mov ecx, esi
// 00799620  e83bf8ffff           call 0x798e60
// 00799625  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00799628  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0079962b  7602                 jbe 0x79962f
// 0079962d  ffd5                 call ebp
// 0079962f  8b36                 mov esi, dword ptr [esi]
// 00799631  57                   push edi
// 00799632  8d4c2414             lea ecx, [esp + 0x14]
// 00799636  89742414             mov dword ptr [esp + 0x14], esi
// 0079963a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0079963e  e8dde7ffff           call 0x797e20
// 00799643  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00799647  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079964b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0079964f  5f                   pop edi
// 00799650  5e                   pop esi
// 00799651  5d                   pop ebp
// 00799652  8908                 mov dword ptr [eax], ecx
// 00799654  895004               mov dword ptr [eax + 4], edx
// 00799657  5b                   pop ebx
// 00799658  83c408               add esp, 8
// 0079965b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
