// from server: 100% by auto
// roc 2009-12 006bf350  unit: RBX::VInstance::?$NonFactoryProduct  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf350
//
// 006bf350  83ec08               sub esp, 8
// 006bf353  53                   push ebx
// 006bf354  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 006bf35a  56                   push esi
// 006bf35b  8bf1                 mov esi, ecx
// 006bf35d  8b4614               mov eax, dword ptr [esi + 0x14]
// 006bf360  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006bf364  57                   push edi
// 006bf365  8b38                 mov edi, dword ptr [eax]
// 006bf367  8b06                 mov eax, dword ptr [esi]
// 006bf369  85c9                 test ecx, ecx
// 006bf36b  7404                 je 0x6bf371
// 006bf36d  3bc8                 cmp ecx, eax
// 006bf36f  7406                 je 0x6bf377
// 006bf371  ffd3                 call ebx
// 006bf373  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006bf377  8b442420             mov eax, dword ptr [esp + 0x20]
// 006bf37b  3bc7                 cmp eax, edi
// 006bf37d  7541                 jne 0x6bf3c0
// 006bf37f  8b7e14               mov edi, dword ptr [esi + 0x14]
// 006bf382  8b16                 mov edx, dword ptr [esi]
// 006bf384  55                   push ebp
// 006bf385  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 006bf389  85ed                 test ebp, ebp
// 006bf38b  7404                 je 0x6bf391
// 006bf38d  3bea                 cmp ebp, edx
// 006bf38f  740a                 je 0x6bf39b
// 006bf391  ffd3                 call ebx
// 006bf393  8b442424             mov eax, dword ptr [esp + 0x24]
// 006bf397  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006bf39b  5d                   pop ebp
// 006bf39c  397c2428             cmp dword ptr [esp + 0x28], edi
// 006bf3a0  751e                 jne 0x6bf3c0
// 006bf3a2  8bce                 mov ecx, esi
// 006bf3a4  e8b7f2ffff           call 0x6be660
// 006bf3a9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006bf3ac  8b16                 mov edx, dword ptr [esi]
// 006bf3ae  8b442418             mov eax, dword ptr [esp + 0x18]
// 006bf3b2  5f                   pop edi
// 006bf3b3  5e                   pop esi
// 006bf3b4  894804               mov dword ptr [eax + 4], ecx
// 006bf3b7  8910                 mov dword ptr [eax], edx
// 006bf3b9  5b                   pop ebx
// 006bf3ba  83c408               add esp, 8
// 006bf3bd  c21400               ret 0x14
// 006bf3c0  85c9                 test ecx, ecx
// 006bf3c2  7406                 je 0x6bf3ca
// 006bf3c4  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 006bf3c8  740a                 je 0x6bf3d4
// 006bf3ca  ffd3                 call ebx
// 006bf3cc  8b442420             mov eax, dword ptr [esp + 0x20]
// 006bf3d0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006bf3d4  8b542428             mov edx, dword ptr [esp + 0x28]
// 006bf3d8  3bc2                 cmp eax, edx
// 006bf3da  741d                 je 0x6bf3f9
// 006bf3dc  50                   push eax
// 006bf3dd  51                   push ecx
// 006bf3de  8d442414             lea eax, [esp + 0x14]
// 006bf3e2  50                   push eax
// 006bf3e3  8bce                 mov ecx, esi
// 006bf3e5  e8e6f1ffff           call 0x6be5d0
// 006bf3ea  8b08                 mov ecx, dword ptr [eax]
// 006bf3ec  894c241c             mov dword ptr [esp + 0x1c], ecx
// 006bf3f0  8b4004               mov eax, dword ptr [eax + 4]
// 006bf3f3  89442420             mov dword ptr [esp + 0x20], eax
// 006bf3f7  ebc7                 jmp 0x6bf3c0
// 006bf3f9  8b0e                 mov ecx, dword ptr [esi]
// 006bf3fb  8b442418             mov eax, dword ptr [esp + 0x18]
// 006bf3ff  5f                   pop edi
// 006bf400  5e                   pop esi
// 006bf401  895004               mov dword ptr [eax + 4], edx
// 006bf404  8908                 mov dword ptr [eax], ecx
// 006bf406  5b                   pop ebx
// 006bf407  83c408               add esp, 8
// 006bf40a  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
