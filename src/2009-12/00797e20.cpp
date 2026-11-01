// from server: 100% by auto
// roc 2009-12 00797e20  unit: lua_exception  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797e20
//
// 00797e20  53                   push ebx
// 00797e21  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00797e27  56                   push esi
// 00797e28  8bf1                 mov esi, ecx
// 00797e2a  8b06                 mov eax, dword ptr [esi]
// 00797e2c  57                   push edi
// 00797e2d  85c0                 test eax, eax
// 00797e2f  7508                 jne 0x797e39
// 00797e31  ffd3                 call ebx
// 00797e33  8b06                 mov eax, dword ptr [esi]
// 00797e35  85c0                 test eax, eax
// 00797e37  7404                 je 0x797e3d
// 00797e39  8b10                 mov edx, dword ptr [eax]
// 00797e3b  eb02                 jmp 0x797e3f
// 00797e3d  33d2                 xor edx, edx
// 00797e3f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00797e43  8d3c49               lea edi, [ecx + ecx*2]
// 00797e46  8b4e04               mov ecx, dword ptr [esi + 4]
// 00797e49  03ff                 add edi, edi
// 00797e4b  03ff                 add edi, edi
// 00797e4d  03ff                 add edi, edi
// 00797e4f  03cf                 add ecx, edi
// 00797e51  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 00797e54  770f                 ja 0x797e65
// 00797e56  85c0                 test eax, eax
// 00797e58  7404                 je 0x797e5e
// 00797e5a  8b00                 mov eax, dword ptr [eax]
// 00797e5c  eb02                 jmp 0x797e60
// 00797e5e  33c0                 xor eax, eax
// 00797e60  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00797e63  7302                 jae 0x797e67
// 00797e65  ffd3                 call ebx
// 00797e67  017e04               add dword ptr [esi + 4], edi
// 00797e6a  5f                   pop edi
// 00797e6b  8bc6                 mov eax, esi
// 00797e6d  5e                   pop esi
// 00797e6e  5b                   pop ebx
// 00797e6f  c20400               ret 4
// standard library vector<pod24> (function ??Y?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@H@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
