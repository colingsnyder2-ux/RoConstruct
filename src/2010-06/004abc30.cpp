// from server: 100% by auto
// roc 2010-06 004abc30  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004abc30
//
// 004abc30  8b542404             mov edx, dword ptr [esp + 4]
// 004abc34  3bca                 cmp ecx, edx
// 004abc36  7452                 je 0x4abc8a
// 004abc38  8b01                 mov eax, dword ptr [ecx]
// 004abc3a  53                   push ebx
// 004abc3b  56                   push esi
// 004abc3c  8b32                 mov esi, dword ptr [edx]
// 004abc3e  8931                 mov dword ptr [ecx], esi
// 004abc40  8902                 mov dword ptr [edx], eax
// 004abc42  8b31                 mov esi, dword ptr [ecx]
// 004abc44  57                   push edi
// 004abc45  3bf0                 cmp esi, eax
// 004abc47  7408                 je 0x4abc51
// 004abc49  8b18                 mov ebx, dword ptr [eax]
// 004abc4b  8b3e                 mov edi, dword ptr [esi]
// 004abc4d  891e                 mov dword ptr [esi], ebx
// 004abc4f  8938                 mov dword ptr [eax], edi
// 004abc51  8d420c               lea eax, [edx + 0xc]
// 004abc54  8d710c               lea esi, [ecx + 0xc]
// 004abc57  3bf0                 cmp esi, eax
// 004abc59  7408                 je 0x4abc63
// 004abc5b  8b18                 mov ebx, dword ptr [eax]
// 004abc5d  8b3e                 mov edi, dword ptr [esi]
// 004abc5f  891e                 mov dword ptr [esi], ebx
// 004abc61  8938                 mov dword ptr [eax], edi
// 004abc63  8d4210               lea eax, [edx + 0x10]
// 004abc66  8d7110               lea esi, [ecx + 0x10]
// 004abc69  3bf0                 cmp esi, eax
// 004abc6b  7408                 je 0x4abc75
// 004abc6d  8b18                 mov ebx, dword ptr [eax]
// 004abc6f  8b3e                 mov edi, dword ptr [esi]
// 004abc71  891e                 mov dword ptr [esi], ebx
// 004abc73  8938                 mov dword ptr [eax], edi
// 004abc75  8d4214               lea eax, [edx + 0x14]
// 004abc78  83c114               add ecx, 0x14
// 004abc7b  3bc8                 cmp ecx, eax
// 004abc7d  7408                 je 0x4abc87
// 004abc7f  8b30                 mov esi, dword ptr [eax]
// 004abc81  8b11                 mov edx, dword ptr [ecx]
// 004abc83  8931                 mov dword ptr [ecx], esi
// 004abc85  8910                 mov dword ptr [eax], edx
// 004abc87  5f                   pop edi
// 004abc88  5e                   pop esi
// 004abc89  5b                   pop ebx
// 004abc8a  c20400               ret 4
// standard library vector<char> (function ?swap@?$vector@DV?$allocator@D@std@@@std@@QAEXAAV12@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
