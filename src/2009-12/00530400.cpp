// from server: 100% by auto
// roc 2009-12 00530400  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00530400
//
// 00530400  83ec08               sub esp, 8
// 00530403  53                   push ebx
// 00530404  55                   push ebp
// 00530405  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0053040b  56                   push esi
// 0053040c  8bf1                 mov esi, ecx
// 0053040e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00530411  8b18                 mov ebx, dword ptr [eax]
// 00530413  8b06                 mov eax, dword ptr [esi]
// 00530415  57                   push edi
// 00530416  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053041a  85ff                 test edi, edi
// 0053041c  7404                 je 0x530422
// 0053041e  3bf8                 cmp edi, eax
// 00530420  7406                 je 0x530428
// 00530422  ffd5                 call ebp
// 00530424  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00530428  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0053042c  7562                 jne 0x530490
// 0053042e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00530432  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00530435  8b06                 mov eax, dword ptr [esi]
// 00530437  85c9                 test ecx, ecx
// 00530439  7404                 je 0x53043f
// 0053043b  3bc8                 cmp ecx, eax
// 0053043d  7406                 je 0x530445
// 0053043f  ffd5                 call ebp
// 00530441  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00530445  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00530449  7545                 jne 0x530490
// 0053044b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053044e  8b5104               mov edx, dword ptr [ecx + 4]
// 00530451  52                   push edx
// 00530452  8bce                 mov ecx, esi
// 00530454  e887f7ffff           call 0x52fbe0
// 00530459  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053045c  894004               mov dword ptr [eax + 4], eax
// 0053045f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00530462  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00530469  8900                 mov dword ptr [eax], eax
// 0053046b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053046e  894008               mov dword ptr [eax + 8], eax
// 00530471  8b4618               mov eax, dword ptr [esi + 0x18]
// 00530474  8b16                 mov edx, dword ptr [esi]
// 00530476  8b08                 mov ecx, dword ptr [eax]
// 00530478  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053047c  5f                   pop edi
// 0053047d  5e                   pop esi
// 0053047e  5d                   pop ebp
// 0053047f  894804               mov dword ptr [eax + 4], ecx
// 00530482  8910                 mov dword ptr [eax], edx
// 00530484  5b                   pop ebx
// 00530485  83c408               add esp, 8
// 00530488  c21400               ret 0x14
// 0053048b  eb03                 jmp 0x530490
// 0053048d  8d4900               lea ecx, [ecx]
// 00530490  85ff                 test edi, edi
// 00530492  7406                 je 0x53049a
// 00530494  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00530498  7406                 je 0x5304a0
// 0053049a  ffd5                 call ebp
// 0053049c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005304a0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005304a4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005304a8  741d                 je 0x5304c7
// 005304aa  8d4c2420             lea ecx, [esp + 0x20]
// 005304ae  e82df1ffff           call 0x52f5e0
// 005304b3  53                   push ebx
// 005304b4  57                   push edi
// 005304b5  8d442418             lea eax, [esp + 0x18]
// 005304b9  50                   push eax
// 005304ba  8bce                 mov ecx, esi
// 005304bc  e8aff9ffff           call 0x52fe70
// 005304c1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005304c5  ebc9                 jmp 0x530490
// 005304c7  8b36                 mov esi, dword ptr [esi]
// 005304c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005304cd  5f                   pop edi
// 005304ce  8930                 mov dword ptr [eax], esi
// 005304d0  5e                   pop esi
// 005304d1  5d                   pop ebp
// 005304d2  895804               mov dword ptr [eax + 4], ebx
// 005304d5  5b                   pop ebx
// 005304d6  83c408               add esp, 8
// 005304d9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
