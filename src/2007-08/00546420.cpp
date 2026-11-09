// from server: 100% by auto
// roc 2007-08 00546420  unit: RBX::MD5HasherImpl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00546420
//
// 00546420  8b442404             mov eax, dword ptr [esp + 4]
// 00546424  53                   push ebx
// 00546425  56                   push esi
// 00546426  57                   push edi
// 00546427  8bf1                 mov esi, ecx
// 00546429  8b7e04               mov edi, dword ptr [esi + 4]
// 0054642c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0054642f  50                   push eax
// 00546430  51                   push ecx
// 00546431  57                   push edi
// 00546432  8bce                 mov ecx, esi
// 00546434  e8e7f8ffff           call 0x545d20
// 00546439  6a01                 push 1
// 0054643b  8bce                 mov ecx, esi
// 0054643d  8bd8                 mov ebx, eax
// 0054643f  e86cf9ffff           call 0x545db0
// 00546444  895f04               mov dword ptr [edi + 4], ebx
// 00546447  8b5304               mov edx, dword ptr [ebx + 4]
// 0054644a  5f                   pop edi
// 0054644b  5e                   pop esi
// 0054644c  891a                 mov dword ptr [edx], ebx
// 0054644e  5b                   pop ebx
// 0054644f  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
