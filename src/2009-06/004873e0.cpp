// from server: 100% by auto
// roc 2009-06 004873e0  unit: Ogre::RbxMeshPartAdapter  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004873e0
//
// 004873e0  64a100000000         mov eax, dword ptr fs:[0]
// 004873e6  8b542404             mov edx, dword ptr [esp + 4]
// 004873ea  6aff                 push -1
// 004873ec  6810798600           push 0x867910
// 004873f1  50                   push eax
// 004873f2  64892500000000       mov dword ptr fs:[0], esp
// 004873f9  53                   push ebx
// 004873fa  56                   push esi
// 004873fb  57                   push edi
// 004873fc  3bca                 cmp ecx, edx
// 004873fe  744c                 je 0x48744c
// 00487400  8b32                 mov esi, dword ptr [edx]
// 00487402  8b01                 mov eax, dword ptr [ecx]
// 00487404  8931                 mov dword ptr [ecx], esi
// 00487406  8902                 mov dword ptr [edx], eax
// 00487408  8b31                 mov esi, dword ptr [ecx]
// 0048740a  3bf0                 cmp esi, eax
// 0048740c  7408                 je 0x487416
// 0048740e  8b18                 mov ebx, dword ptr [eax]
// 00487410  8b3e                 mov edi, dword ptr [esi]
// 00487412  891e                 mov dword ptr [esi], ebx
// 00487414  8938                 mov dword ptr [eax], edi
// 00487416  8d420c               lea eax, [edx + 0xc]
// 00487419  8d710c               lea esi, [ecx + 0xc]
// 0048741c  3bf0                 cmp esi, eax
// 0048741e  7408                 je 0x487428
// 00487420  8b18                 mov ebx, dword ptr [eax]
// 00487422  8b3e                 mov edi, dword ptr [esi]
// 00487424  891e                 mov dword ptr [esi], ebx
// 00487426  8938                 mov dword ptr [eax], edi
// 00487428  8d4210               lea eax, [edx + 0x10]
// 0048742b  8d7110               lea esi, [ecx + 0x10]
// 0048742e  3bf0                 cmp esi, eax
// 00487430  7408                 je 0x48743a
// 00487432  8b18                 mov ebx, dword ptr [eax]
// 00487434  8b3e                 mov edi, dword ptr [esi]
// 00487436  891e                 mov dword ptr [esi], ebx
// 00487438  8938                 mov dword ptr [eax], edi
// 0048743a  8d4214               lea eax, [edx + 0x14]
// 0048743d  83c114               add ecx, 0x14
// 00487440  3bc8                 cmp ecx, eax
// 00487442  7408                 je 0x48744c
// 00487444  8b30                 mov esi, dword ptr [eax]
// 00487446  8b11                 mov edx, dword ptr [ecx]
// 00487448  8931                 mov dword ptr [ecx], esi
// 0048744a  8910                 mov dword ptr [eax], edx
// 0048744c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00487450  5f                   pop edi
// 00487451  5e                   pop esi
// 00487452  64890d00000000       mov dword ptr fs:[0], ecx
// 00487459  5b                   pop ebx
// 0048745a  83c40c               add esp, 0xc
// 0048745d  c20400               ret 4
// standard library vector<ptr> (function ?swap@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXAAV12@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
