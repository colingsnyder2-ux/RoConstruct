// from server: 100% by auto
// roc 2010-06 008d3ff0  unit: Ogre::VisualEngine  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3ff0
//
// 008d3ff0  83ec08               sub esp, 8
// 008d3ff3  53                   push ebx
// 008d3ff4  55                   push ebp
// 008d3ff5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008d3ffb  56                   push esi
// 008d3ffc  8bf1                 mov esi, ecx
// 008d3ffe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008d4001  57                   push edi
// 008d4002  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008d4005  8bcb                 mov ecx, ebx
// 008d4007  2bcf                 sub ecx, edi
// 008d4009  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d400e  f7e9                 imul ecx
// 008d4010  c1fa02               sar edx, 2
// 008d4013  8bc2                 mov eax, edx
// 008d4015  c1e81f               shr eax, 0x1f
// 008d4018  03c2                 add eax, edx
// 008d401a  7504                 jne 0x8d4020
// 008d401c  33ff                 xor edi, edi
// 008d401e  eb2d                 jmp 0x8d404d
// 008d4020  3bfb                 cmp edi, ebx
// 008d4022  7602                 jbe 0x8d4026
// 008d4024  ffd5                 call ebp
// 008d4026  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d402a  8b06                 mov eax, dword ptr [esi]
// 008d402c  85c9                 test ecx, ecx
// 008d402e  7404                 je 0x8d4034
// 008d4030  3bc8                 cmp ecx, eax
// 008d4032  7402                 je 0x8d4036
// 008d4034  ffd5                 call ebp
// 008d4036  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d403a  2bcf                 sub ecx, edi
// 008d403c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d4041  f7e9                 imul ecx
// 008d4043  c1fa02               sar edx, 2
// 008d4046  8bfa                 mov edi, edx
// 008d4048  c1ef1f               shr edi, 0x1f
// 008d404b  03fa                 add edi, edx
// 008d404d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d4051  8b542424             mov edx, dword ptr [esp + 0x24]
// 008d4055  8b442420             mov eax, dword ptr [esp + 0x20]
// 008d4059  51                   push ecx
// 008d405a  6a01                 push 1
// 008d405c  52                   push edx
// 008d405d  50                   push eax
// 008d405e  8bce                 mov ecx, esi
// 008d4060  e82bf4ffff           call 0x8d3490
// 008d4065  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d4068  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008d406b  7602                 jbe 0x8d406f
// 008d406d  ffd5                 call ebp
// 008d406f  8b36                 mov esi, dword ptr [esi]
// 008d4071  57                   push edi
// 008d4072  8d4c2414             lea ecx, [esp + 0x14]
// 008d4076  89742414             mov dword ptr [esp + 0x14], esi
// 008d407a  895c2418             mov dword ptr [esp + 0x18], ebx
// 008d407e  e8fdc5e5ff           call 0x730680
// 008d4083  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d4087  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d408b  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d408f  5f                   pop edi
// 008d4090  5e                   pop esi
// 008d4091  5d                   pop ebp
// 008d4092  8908                 mov dword ptr [eax], ecx
// 008d4094  895004               mov dword ptr [eax + 4], edx
// 008d4097  5b                   pop ebx
// 008d4098  83c408               add esp, 8
// 008d409b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
