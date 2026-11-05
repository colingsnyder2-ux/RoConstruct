// from server: 100% by auto
// roc 2008-06 0055e690  unit: RBX::MD5HasherImpl  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e690
//
// 0055e690  83ec08               sub esp, 8
// 0055e693  53                   push ebx
// 0055e694  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0055e69a  56                   push esi
// 0055e69b  8bf1                 mov esi, ecx
// 0055e69d  8b4614               mov eax, dword ptr [esi + 0x14]
// 0055e6a0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055e6a4  57                   push edi
// 0055e6a5  8b38                 mov edi, dword ptr [eax]
// 0055e6a7  8b06                 mov eax, dword ptr [esi]
// 0055e6a9  85c9                 test ecx, ecx
// 0055e6ab  7404                 je 0x55e6b1
// 0055e6ad  3bc8                 cmp ecx, eax
// 0055e6af  7406                 je 0x55e6b7
// 0055e6b1  ffd3                 call ebx
// 0055e6b3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0055e6b7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0055e6bb  3bc7                 cmp eax, edi
// 0055e6bd  7541                 jne 0x55e700
// 0055e6bf  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0055e6c2  8b16                 mov edx, dword ptr [esi]
// 0055e6c4  55                   push ebp
// 0055e6c5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0055e6c9  85ed                 test ebp, ebp
// 0055e6cb  7404                 je 0x55e6d1
// 0055e6cd  3bea                 cmp ebp, edx
// 0055e6cf  740a                 je 0x55e6db
// 0055e6d1  ffd3                 call ebx
// 0055e6d3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055e6d7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055e6db  5d                   pop ebp
// 0055e6dc  397c2428             cmp dword ptr [esp + 0x28], edi
// 0055e6e0  751e                 jne 0x55e700
// 0055e6e2  8bce                 mov ecx, esi
// 0055e6e4  e8e7f8ffff           call 0x55dfd0
// 0055e6e9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0055e6ec  8b16                 mov edx, dword ptr [esi]
// 0055e6ee  8b442418             mov eax, dword ptr [esp + 0x18]
// 0055e6f2  5f                   pop edi
// 0055e6f3  5e                   pop esi
// 0055e6f4  894804               mov dword ptr [eax + 4], ecx
// 0055e6f7  8910                 mov dword ptr [eax], edx
// 0055e6f9  5b                   pop ebx
// 0055e6fa  83c408               add esp, 8
// 0055e6fd  c21400               ret 0x14
// 0055e700  85c9                 test ecx, ecx
// 0055e702  7406                 je 0x55e70a
// 0055e704  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 0055e708  740a                 je 0x55e714
// 0055e70a  ffd3                 call ebx
// 0055e70c  8b442420             mov eax, dword ptr [esp + 0x20]
// 0055e710  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0055e714  8b542428             mov edx, dword ptr [esp + 0x28]
// 0055e718  3bc2                 cmp eax, edx
// 0055e71a  741d                 je 0x55e739
// 0055e71c  50                   push eax
// 0055e71d  51                   push ecx
// 0055e71e  8d442414             lea eax, [esp + 0x14]
// 0055e722  50                   push eax
// 0055e723  8bce                 mov ecx, esi
// 0055e725  e8261cebff           call 0x410350
// 0055e72a  8b08                 mov ecx, dword ptr [eax]
// 0055e72c  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0055e730  8b4004               mov eax, dword ptr [eax + 4]
// 0055e733  89442420             mov dword ptr [esp + 0x20], eax
// 0055e737  ebc7                 jmp 0x55e700
// 0055e739  8b0e                 mov ecx, dword ptr [esi]
// 0055e73b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0055e73f  5f                   pop edi
// 0055e740  5e                   pop esi
// 0055e741  895004               mov dword ptr [eax + 4], edx
// 0055e744  8908                 mov dword ptr [eax], ecx
// 0055e746  5b                   pop ebx
// 0055e747  83c408               add esp, 8
// 0055e74a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
