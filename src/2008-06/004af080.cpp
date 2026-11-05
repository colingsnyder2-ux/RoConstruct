// from server: 100% by auto
// roc 2008-06 004af080  unit: RBX::Network::Replicator::MarkerItem  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004af080
//
// 004af080  8b442404             mov eax, dword ptr [esp + 4]
// 004af084  53                   push ebx
// 004af085  56                   push esi
// 004af086  57                   push edi
// 004af087  8bf1                 mov esi, ecx
// 004af089  8b7e14               mov edi, dword ptr [esi + 0x14]
// 004af08c  8b4f04               mov ecx, dword ptr [edi + 4]
// 004af08f  50                   push eax
// 004af090  51                   push ecx
// 004af091  57                   push edi
// 004af092  8bce                 mov ecx, esi
// 004af094  e8c7e7ffff           call 0x4ad860
// 004af099  6a01                 push 1
// 004af09b  8bce                 mov ecx, esi
// 004af09d  8bd8                 mov ebx, eax
// 004af09f  e8acdaffff           call 0x4acb50
// 004af0a4  895f04               mov dword ptr [edi + 4], ebx
// 004af0a7  8b5304               mov edx, dword ptr [ebx + 4]
// 004af0aa  5f                   pop edi
// 004af0ab  5e                   pop esi
// 004af0ac  891a                 mov dword ptr [edx], ebx
// 004af0ae  5b                   pop ebx
// 004af0af  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
