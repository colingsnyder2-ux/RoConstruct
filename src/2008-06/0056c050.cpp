// from server: 100% by auto
// roc 2008-06 0056c050  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056c050
//
// 0056c050  56                   push esi
// 0056c051  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0056c055  57                   push edi
// 0056c056  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0056c05a  8bc6                 mov eax, esi
// 0056c05c  8bcf                 mov ecx, edi
// 0056c05e  85f6                 test esi, esi
// 0056c060  7612                 jbe 0x56c074
// 0056c062  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056c066  53                   push ebx
// 0056c067  8b1a                 mov ebx, dword ptr [edx]
// 0056c069  8919                 mov dword ptr [ecx], ebx
// 0056c06b  48                   dec eax
// 0056c06c  83c104               add ecx, 4
// 0056c06f  85c0                 test eax, eax
// 0056c071  77f4                 ja 0x56c067
// 0056c073  5b                   pop ebx
// 0056c074  8d04b7               lea eax, [edi + esi*4]
// 0056c077  5f                   pop edi
// 0056c078  5e                   pop esi
// 0056c079  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
