// from server: 100% by auto
// roc 2009-12 006bf310  unit: RBX::VInstance::?$NonFactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf310
//
// 006bf310  53                   push ebx
// 006bf311  56                   push esi
// 006bf312  8bf1                 mov esi, ecx
// 006bf314  8b4614               mov eax, dword ptr [esi + 0x14]
// 006bf317  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006bf31b  57                   push edi
// 006bf31c  8b38                 mov edi, dword ptr [eax]
// 006bf31e  8b5704               mov edx, dword ptr [edi + 4]
// 006bf321  51                   push ecx
// 006bf322  52                   push edx
// 006bf323  57                   push edi
// 006bf324  8bce                 mov ecx, esi
// 006bf326  e895eeffff           call 0x6be1c0
// 006bf32b  6a01                 push 1
// 006bf32d  8bce                 mov ecx, esi
// 006bf32f  8bd8                 mov ebx, eax
// 006bf331  e8dae7ffff           call 0x6bdb10
// 006bf336  895f04               mov dword ptr [edi + 4], ebx
// 006bf339  8b4304               mov eax, dword ptr [ebx + 4]
// 006bf33c  5f                   pop edi
// 006bf33d  5e                   pop esi
// 006bf33e  8918                 mov dword ptr [eax], ebx
// 006bf340  5b                   pop ebx
// 006bf341  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
