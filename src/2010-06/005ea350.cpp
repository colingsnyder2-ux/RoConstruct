// from server: 100% by auto
// roc 2010-06 005ea350  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ea350
//
// 005ea350  8b442404             mov eax, dword ptr [esp + 4]
// 005ea354  53                   push ebx
// 005ea355  56                   push esi
// 005ea356  57                   push edi
// 005ea357  8bf1                 mov esi, ecx
// 005ea359  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005ea35c  8b4f04               mov ecx, dword ptr [edi + 4]
// 005ea35f  50                   push eax
// 005ea360  51                   push ecx
// 005ea361  57                   push edi
// 005ea362  8bce                 mov ecx, esi
// 005ea364  e877ac0d00           call 0x6c4fe0
// 005ea369  6a01                 push 1
// 005ea36b  8bce                 mov ecx, esi
// 005ea36d  8bd8                 mov ebx, eax
// 005ea36f  e89cf8ffff           call 0x5e9c10
// 005ea374  895f04               mov dword ptr [edi + 4], ebx
// 005ea377  8b5304               mov edx, dword ptr [ebx + 4]
// 005ea37a  5f                   pop edi
// 005ea37b  5e                   pop esi
// 005ea37c  891a                 mov dword ptr [edx], ebx
// 005ea37e  5b                   pop ebx
// 005ea37f  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
