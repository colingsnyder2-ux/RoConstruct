// from server: 100% by auto
// roc 2009-06 004ba5c0  unit: RBX::Network::Player  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ba5c0
//
// 004ba5c0  8b542404             mov edx, dword ptr [esp + 4]
// 004ba5c4  3bca                 cmp ecx, edx
// 004ba5c6  7452                 je 0x4ba61a
// 004ba5c8  8b01                 mov eax, dword ptr [ecx]
// 004ba5ca  53                   push ebx
// 004ba5cb  56                   push esi
// 004ba5cc  8b32                 mov esi, dword ptr [edx]
// 004ba5ce  8931                 mov dword ptr [ecx], esi
// 004ba5d0  8902                 mov dword ptr [edx], eax
// 004ba5d2  8b31                 mov esi, dword ptr [ecx]
// 004ba5d4  57                   push edi
// 004ba5d5  3bf0                 cmp esi, eax
// 004ba5d7  7408                 je 0x4ba5e1
// 004ba5d9  8b18                 mov ebx, dword ptr [eax]
// 004ba5db  8b3e                 mov edi, dword ptr [esi]
// 004ba5dd  891e                 mov dword ptr [esi], ebx
// 004ba5df  8938                 mov dword ptr [eax], edi
// 004ba5e1  8d420c               lea eax, [edx + 0xc]
// 004ba5e4  8d710c               lea esi, [ecx + 0xc]
// 004ba5e7  3bf0                 cmp esi, eax
// 004ba5e9  7408                 je 0x4ba5f3
// 004ba5eb  8b18                 mov ebx, dword ptr [eax]
// 004ba5ed  8b3e                 mov edi, dword ptr [esi]
// 004ba5ef  891e                 mov dword ptr [esi], ebx
// 004ba5f1  8938                 mov dword ptr [eax], edi
// 004ba5f3  8d4210               lea eax, [edx + 0x10]
// 004ba5f6  8d7110               lea esi, [ecx + 0x10]
// 004ba5f9  3bf0                 cmp esi, eax
// 004ba5fb  7408                 je 0x4ba605
// 004ba5fd  8b18                 mov ebx, dword ptr [eax]
// 004ba5ff  8b3e                 mov edi, dword ptr [esi]
// 004ba601  891e                 mov dword ptr [esi], ebx
// 004ba603  8938                 mov dword ptr [eax], edi
// 004ba605  8d4214               lea eax, [edx + 0x14]
// 004ba608  83c114               add ecx, 0x14
// 004ba60b  3bc8                 cmp ecx, eax
// 004ba60d  7408                 je 0x4ba617
// 004ba60f  8b30                 mov esi, dword ptr [eax]
// 004ba611  8b11                 mov edx, dword ptr [ecx]
// 004ba613  8931                 mov dword ptr [ecx], esi
// 004ba615  8910                 mov dword ptr [eax], edx
// 004ba617  5f                   pop edi
// 004ba618  5e                   pop esi
// 004ba619  5b                   pop ebx
// 004ba61a  c20400               ret 4
// standard library vector<char> (function ?swap@?$vector@DV?$allocator@D@std@@@std@@QAEXAAV12@@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
