// from server: 100% by auto
// roc 2008-06 00561780  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561780
//
// 00561780  8b442404             mov eax, dword ptr [esp + 4]
// 00561784  53                   push ebx
// 00561785  56                   push esi
// 00561786  57                   push edi
// 00561787  8bf1                 mov esi, ecx
// 00561789  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0056178c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0056178f  50                   push eax
// 00561790  51                   push ecx
// 00561791  57                   push edi
// 00561792  8bce                 mov ecx, esi
// 00561794  e8f7fcffff           call 0x561490
// 00561799  6a01                 push 1
// 0056179b  8bce                 mov ecx, esi
// 0056179d  8bd8                 mov ebx, eax
// 0056179f  e88cbbffff           call 0x55d330
// 005617a4  895f04               mov dword ptr [edi + 4], ebx
// 005617a7  8b5304               mov edx, dword ptr [ebx + 4]
// 005617aa  5f                   pop edi
// 005617ab  5e                   pop esi
// 005617ac  891a                 mov dword ptr [edx], ebx
// 005617ae  5b                   pop ebx
// 005617af  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
