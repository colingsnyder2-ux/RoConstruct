// from server: 100% by auto
// roc 2009-06 00618d50  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618d50
//
// 00618d50  8b442404             mov eax, dword ptr [esp + 4]
// 00618d54  53                   push ebx
// 00618d55  56                   push esi
// 00618d56  57                   push edi
// 00618d57  8bf1                 mov esi, ecx
// 00618d59  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00618d5c  8b4f04               mov ecx, dword ptr [edi + 4]
// 00618d5f  50                   push eax
// 00618d60  51                   push ecx
// 00618d61  57                   push edi
// 00618d62  8bce                 mov ecx, esi
// 00618d64  e8278f0500           call 0x671c90
// 00618d69  6a01                 push 1
// 00618d6b  8bce                 mov ecx, esi
// 00618d6d  8bd8                 mov ebx, eax
// 00618d6f  e85c8f0500           call 0x671cd0
// 00618d74  895f04               mov dword ptr [edi + 4], ebx
// 00618d77  8b5304               mov edx, dword ptr [ebx + 4]
// 00618d7a  5f                   pop edi
// 00618d7b  5e                   pop esi
// 00618d7c  891a                 mov dword ptr [edx], ebx
// 00618d7e  5b                   pop ebx
// 00618d7f  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
