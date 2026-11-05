// from server: 100% by auto
// roc 2010-06 00906580  unit: RBX::RbxParticleEmitter  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00906580
//
// 00906580  53                   push ebx
// 00906581  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00906587  56                   push esi
// 00906588  8bf1                 mov esi, ecx
// 0090658a  8b06                 mov eax, dword ptr [esi]
// 0090658c  57                   push edi
// 0090658d  85c0                 test eax, eax
// 0090658f  7508                 jne 0x906599
// 00906591  ffd3                 call ebx
// 00906593  8b06                 mov eax, dword ptr [esi]
// 00906595  85c0                 test eax, eax
// 00906597  7404                 je 0x90659d
// 00906599  8b10                 mov edx, dword ptr [eax]
// 0090659b  eb02                 jmp 0x90659f
// 0090659d  33d2                 xor edx, edx
// 0090659f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 009065a3  8b4e04               mov ecx, dword ptr [esi + 4]
// 009065a6  03ff                 add edi, edi
// 009065a8  03ff                 add edi, edi
// 009065aa  03ff                 add edi, edi
// 009065ac  03cf                 add ecx, edi
// 009065ae  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 009065b1  770f                 ja 0x9065c2
// 009065b3  85c0                 test eax, eax
// 009065b5  7404                 je 0x9065bb
// 009065b7  8b00                 mov eax, dword ptr [eax]
// 009065b9  eb02                 jmp 0x9065bd
// 009065bb  33c0                 xor eax, eax
// 009065bd  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 009065c0  7302                 jae 0x9065c4
// 009065c2  ffd3                 call ebx
// 009065c4  017e04               add dword ptr [esi + 4], edi
// 009065c7  5f                   pop edi
// 009065c8  8bc6                 mov eax, esi
// 009065ca  5e                   pop esi
// 009065cb  5b                   pop ebx
// 009065cc  c20400               ret 4
// standard library vector<double> (function ??Y?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QAEAAV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
