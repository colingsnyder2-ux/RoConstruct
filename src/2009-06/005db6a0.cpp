// from server: 100% by auto
// roc 2009-06 005db6a0  unit: RBX::VInstance::?$NonFactoryProduct  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005db6a0
//
// 005db6a0  83ec08               sub esp, 8
// 005db6a3  53                   push ebx
// 005db6a4  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 005db6aa  56                   push esi
// 005db6ab  8bf1                 mov esi, ecx
// 005db6ad  8b4614               mov eax, dword ptr [esi + 0x14]
// 005db6b0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005db6b4  57                   push edi
// 005db6b5  8b38                 mov edi, dword ptr [eax]
// 005db6b7  8b06                 mov eax, dword ptr [esi]
// 005db6b9  85c9                 test ecx, ecx
// 005db6bb  7404                 je 0x5db6c1
// 005db6bd  3bc8                 cmp ecx, eax
// 005db6bf  7406                 je 0x5db6c7
// 005db6c1  ffd3                 call ebx
// 005db6c3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005db6c7  8b442420             mov eax, dword ptr [esp + 0x20]
// 005db6cb  3bc7                 cmp eax, edi
// 005db6cd  7541                 jne 0x5db710
// 005db6cf  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005db6d2  8b16                 mov edx, dword ptr [esi]
// 005db6d4  55                   push ebp
// 005db6d5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005db6d9  85ed                 test ebp, ebp
// 005db6db  7404                 je 0x5db6e1
// 005db6dd  3bea                 cmp ebp, edx
// 005db6df  740a                 je 0x5db6eb
// 005db6e1  ffd3                 call ebx
// 005db6e3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005db6e7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005db6eb  5d                   pop ebp
// 005db6ec  397c2428             cmp dword ptr [esp + 0x28], edi
// 005db6f0  751e                 jne 0x5db710
// 005db6f2  8bce                 mov ecx, esi
// 005db6f4  e8c7f8ffff           call 0x5dafc0
// 005db6f9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005db6fc  8b16                 mov edx, dword ptr [esi]
// 005db6fe  8b442418             mov eax, dword ptr [esp + 0x18]
// 005db702  5f                   pop edi
// 005db703  5e                   pop esi
// 005db704  894804               mov dword ptr [eax + 4], ecx
// 005db707  8910                 mov dword ptr [eax], edx
// 005db709  5b                   pop ebx
// 005db70a  83c408               add esp, 8
// 005db70d  c21400               ret 0x14
// 005db710  85c9                 test ecx, ecx
// 005db712  7406                 je 0x5db71a
// 005db714  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 005db718  740a                 je 0x5db724
// 005db71a  ffd3                 call ebx
// 005db71c  8b442420             mov eax, dword ptr [esp + 0x20]
// 005db720  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005db724  8b542428             mov edx, dword ptr [esp + 0x28]
// 005db728  3bc2                 cmp eax, edx
// 005db72a  741d                 je 0x5db749
// 005db72c  50                   push eax
// 005db72d  51                   push ecx
// 005db72e  8d442414             lea eax, [esp + 0x14]
// 005db732  50                   push eax
// 005db733  8bce                 mov ecx, esi
// 005db735  e8f6f7ffff           call 0x5daf30
// 005db73a  8b08                 mov ecx, dword ptr [eax]
// 005db73c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005db740  8b4004               mov eax, dword ptr [eax + 4]
// 005db743  89442420             mov dword ptr [esp + 0x20], eax
// 005db747  ebc7                 jmp 0x5db710
// 005db749  8b0e                 mov ecx, dword ptr [esi]
// 005db74b  8b442418             mov eax, dword ptr [esp + 0x18]
// 005db74f  5f                   pop edi
// 005db750  5e                   pop esi
// 005db751  895004               mov dword ptr [eax + 4], edx
// 005db754  8908                 mov dword ptr [eax], ecx
// 005db756  5b                   pop ebx
// 005db757  83c408               add esp, 8
// 005db75a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
