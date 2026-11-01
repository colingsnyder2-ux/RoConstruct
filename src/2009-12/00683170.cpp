// from server: 100% by auto
// roc 2009-12 00683170  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00683170
//
// 00683170  8b442404             mov eax, dword ptr [esp + 4]
// 00683174  53                   push ebx
// 00683175  56                   push esi
// 00683176  57                   push edi
// 00683177  8bf1                 mov esi, ecx
// 00683179  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0068317c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0068317f  50                   push eax
// 00683180  51                   push ecx
// 00683181  57                   push edi
// 00683182  8bce                 mov ecx, esi
// 00683184  e8e7200c00           call 0x745270
// 00683189  6a01                 push 1
// 0068318b  8bce                 mov ecx, esi
// 0068318d  8bd8                 mov ebx, eax
// 0068318f  e8dcf10900           call 0x722370
// 00683194  895f04               mov dword ptr [edi + 4], ebx
// 00683197  8b5304               mov edx, dword ptr [ebx + 4]
// 0068319a  5f                   pop edi
// 0068319b  5e                   pop esi
// 0068319c  891a                 mov dword ptr [edx], ebx
// 0068319e  5b                   pop ebx
// 0068319f  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
