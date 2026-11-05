// from server: 100% by auto
// roc 2010-06 007413f0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007413f0
//
// 007413f0  53                   push ebx
// 007413f1  56                   push esi
// 007413f2  8bf1                 mov esi, ecx
// 007413f4  8b4614               mov eax, dword ptr [esi + 0x14]
// 007413f7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007413fb  57                   push edi
// 007413fc  8b38                 mov edi, dword ptr [eax]
// 007413fe  8b5704               mov edx, dword ptr [edi + 4]
// 00741401  51                   push ecx
// 00741402  52                   push edx
// 00741403  57                   push edi
// 00741404  8bce                 mov ecx, esi
// 00741406  e8a5f7ffff           call 0x740bb0
// 0074140b  6a01                 push 1
// 0074140d  8bce                 mov ecx, esi
// 0074140f  8bd8                 mov ebx, eax
// 00741411  e85aa4f2ff           call 0x66b870
// 00741416  895f04               mov dword ptr [edi + 4], ebx
// 00741419  8b4304               mov eax, dword ptr [ebx + 4]
// 0074141c  5f                   pop edi
// 0074141d  5e                   pop esi
// 0074141e  8918                 mov dword ptr [eax], ebx
// 00741420  5b                   pop ebx
// 00741421  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
