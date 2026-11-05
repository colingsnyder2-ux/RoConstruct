// from server: 100% by auto
// roc 2008-06 0069aff0  unit: Ogre::InstancedGeometry  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069aff0
//
// 0069aff0  64a100000000         mov eax, dword ptr fs:[0]
// 0069aff6  8b542404             mov edx, dword ptr [esp + 4]
// 0069affa  6aff                 push -1
// 0069affc  68b05e7d00           push 0x7d5eb0
// 0069b001  50                   push eax
// 0069b002  64892500000000       mov dword ptr fs:[0], esp
// 0069b009  53                   push ebx
// 0069b00a  56                   push esi
// 0069b00b  57                   push edi
// 0069b00c  3bca                 cmp ecx, edx
// 0069b00e  744c                 je 0x69b05c
// 0069b010  8b32                 mov esi, dword ptr [edx]
// 0069b012  8b01                 mov eax, dword ptr [ecx]
// 0069b014  8931                 mov dword ptr [ecx], esi
// 0069b016  8902                 mov dword ptr [edx], eax
// 0069b018  8b31                 mov esi, dword ptr [ecx]
// 0069b01a  3bf0                 cmp esi, eax
// 0069b01c  7408                 je 0x69b026
// 0069b01e  8b18                 mov ebx, dword ptr [eax]
// 0069b020  8b3e                 mov edi, dword ptr [esi]
// 0069b022  891e                 mov dword ptr [esi], ebx
// 0069b024  8938                 mov dword ptr [eax], edi
// 0069b026  8d420c               lea eax, [edx + 0xc]
// 0069b029  8d710c               lea esi, [ecx + 0xc]
// 0069b02c  3bf0                 cmp esi, eax
// 0069b02e  7408                 je 0x69b038
// 0069b030  8b18                 mov ebx, dword ptr [eax]
// 0069b032  8b3e                 mov edi, dword ptr [esi]
// 0069b034  891e                 mov dword ptr [esi], ebx
// 0069b036  8938                 mov dword ptr [eax], edi
// 0069b038  8d4210               lea eax, [edx + 0x10]
// 0069b03b  8d7110               lea esi, [ecx + 0x10]
// 0069b03e  3bf0                 cmp esi, eax
// 0069b040  7408                 je 0x69b04a
// 0069b042  8b18                 mov ebx, dword ptr [eax]
// 0069b044  8b3e                 mov edi, dword ptr [esi]
// 0069b046  891e                 mov dword ptr [esi], ebx
// 0069b048  8938                 mov dword ptr [eax], edi
// 0069b04a  8d4214               lea eax, [edx + 0x14]
// 0069b04d  83c114               add ecx, 0x14
// 0069b050  3bc8                 cmp ecx, eax
// 0069b052  7408                 je 0x69b05c
// 0069b054  8b30                 mov esi, dword ptr [eax]
// 0069b056  8b11                 mov edx, dword ptr [ecx]
// 0069b058  8931                 mov dword ptr [ecx], esi
// 0069b05a  8910                 mov dword ptr [eax], edx
// 0069b05c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0069b060  5f                   pop edi
// 0069b061  5e                   pop esi
// 0069b062  64890d00000000       mov dword ptr fs:[0], ecx
// 0069b069  5b                   pop ebx
// 0069b06a  83c40c               add esp, 0xc
// 0069b06d  c20400               ret 4
// standard library vector<ptr> (function ?swap@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXAAV12@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
