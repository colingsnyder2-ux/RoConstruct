// from server: 100% by auto
// roc 2007-08 00546a20  unit: RBX::MD5HasherImpl  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00546a20
//
// 00546a20  53                   push ebx
// 00546a21  56                   push esi
// 00546a22  8bf1                 mov esi, ecx
// 00546a24  8b4604               mov eax, dword ptr [esi + 4]
// 00546a27  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00546a2b  57                   push edi
// 00546a2c  8b38                 mov edi, dword ptr [eax]
// 00546a2e  8b5704               mov edx, dword ptr [edi + 4]
// 00546a31  51                   push ecx
// 00546a32  52                   push edx
// 00546a33  57                   push edi
// 00546a34  8bce                 mov ecx, esi
// 00546a36  e815f7ffff           call 0x546150
// 00546a3b  6a01                 push 1
// 00546a3d  8bce                 mov ecx, esi
// 00546a3f  8bd8                 mov ebx, eax
// 00546a41  e80af4ffff           call 0x545e50
// 00546a46  895f04               mov dword ptr [edi + 4], ebx
// 00546a49  8b4304               mov eax, dword ptr [ebx + 4]
// 00546a4c  5f                   pop edi
// 00546a4d  5e                   pop esi
// 00546a4e  8918                 mov dword ptr [eax], ebx
// 00546a50  5b                   pop ebx
// 00546a51  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
