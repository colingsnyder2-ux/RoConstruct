// from server: 100% by auto
// roc 2011-06 00924980  unit: RBX::AdornRbxGfx  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00924980
//
// 00924980  56                   push esi
// 00924981  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00924985  57                   push edi
// 00924986  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0092498a  8bc6                 mov eax, esi
// 0092498c  8bcf                 mov ecx, edi
// 0092498e  85f6                 test esi, esi
// 00924990  7612                 jbe 0x9249a4
// 00924992  8b542414             mov edx, dword ptr [esp + 0x14]
// 00924996  53                   push ebx
// 00924997  8b1a                 mov ebx, dword ptr [edx]
// 00924999  8919                 mov dword ptr [ecx], ebx
// 0092499b  48                   dec eax
// 0092499c  83c104               add ecx, 4
// 0092499f  85c0                 test eax, eax
// 009249a1  77f4                 ja 0x924997
// 009249a3  5b                   pop ebx
// 009249a4  8d04b7               lea eax, [edi + esi*4]
// 009249a7  5f                   pop edi
// 009249a8  5e                   pop esi
// 009249a9  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
