// from server: 100% by auto
// roc 2009-12 004c0090  unit: RBX::RbxParticleEmitter  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0090
//
// 004c0090  53                   push ebx
// 004c0091  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004c0097  56                   push esi
// 004c0098  8bf1                 mov esi, ecx
// 004c009a  8b06                 mov eax, dword ptr [esi]
// 004c009c  57                   push edi
// 004c009d  85c0                 test eax, eax
// 004c009f  7508                 jne 0x4c00a9
// 004c00a1  ffd3                 call ebx
// 004c00a3  8b06                 mov eax, dword ptr [esi]
// 004c00a5  85c0                 test eax, eax
// 004c00a7  7404                 je 0x4c00ad
// 004c00a9  8b10                 mov edx, dword ptr [eax]
// 004c00ab  eb02                 jmp 0x4c00af
// 004c00ad  33d2                 xor edx, edx
// 004c00af  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c00b3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c00b6  03ff                 add edi, edi
// 004c00b8  03ff                 add edi, edi
// 004c00ba  03ff                 add edi, edi
// 004c00bc  03cf                 add ecx, edi
// 004c00be  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 004c00c1  770f                 ja 0x4c00d2
// 004c00c3  85c0                 test eax, eax
// 004c00c5  7404                 je 0x4c00cb
// 004c00c7  8b00                 mov eax, dword ptr [eax]
// 004c00c9  eb02                 jmp 0x4c00cd
// 004c00cb  33c0                 xor eax, eax
// 004c00cd  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004c00d0  7302                 jae 0x4c00d4
// 004c00d2  ffd3                 call ebx
// 004c00d4  017e04               add dword ptr [esi + 4], edi
// 004c00d7  5f                   pop edi
// 004c00d8  8bc6                 mov eax, esi
// 004c00da  5e                   pop esi
// 004c00db  5b                   pop ebx
// 004c00dc  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
