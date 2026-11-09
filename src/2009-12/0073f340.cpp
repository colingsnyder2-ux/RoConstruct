// from server: 100% by auto
// roc 2009-12 0073f340  unit: RBX::VInstance::V?$shared_ptr::V?$vector::V?$copy_on_write_ptr::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073f340
//
// 0073f340  83ec08               sub esp, 8
// 0073f343  53                   push ebx
// 0073f344  55                   push ebp
// 0073f345  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0073f34b  56                   push esi
// 0073f34c  8bf1                 mov esi, ecx
// 0073f34e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f351  8b18                 mov ebx, dword ptr [eax]
// 0073f353  8b06                 mov eax, dword ptr [esi]
// 0073f355  57                   push edi
// 0073f356  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0073f35a  85ff                 test edi, edi
// 0073f35c  7404                 je 0x73f362
// 0073f35e  3bf8                 cmp edi, eax
// 0073f360  7406                 je 0x73f368
// 0073f362  ffd5                 call ebp
// 0073f364  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0073f368  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0073f36c  7562                 jne 0x73f3d0
// 0073f36e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0073f372  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0073f375  8b06                 mov eax, dword ptr [esi]
// 0073f377  85c9                 test ecx, ecx
// 0073f379  7404                 je 0x73f37f
// 0073f37b  3bc8                 cmp ecx, eax
// 0073f37d  7406                 je 0x73f385
// 0073f37f  ffd5                 call ebp
// 0073f381  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0073f385  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0073f389  7545                 jne 0x73f3d0
// 0073f38b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0073f38e  8b5104               mov edx, dword ptr [ecx + 4]
// 0073f391  52                   push edx
// 0073f392  8bce                 mov ecx, esi
// 0073f394  e8f7faffff           call 0x73ee90
// 0073f399  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f39c  894004               mov dword ptr [eax + 4], eax
// 0073f39f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f3a2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0073f3a9  8900                 mov dword ptr [eax], eax
// 0073f3ab  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f3ae  894008               mov dword ptr [eax + 8], eax
// 0073f3b1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f3b4  8b16                 mov edx, dword ptr [esi]
// 0073f3b6  8b08                 mov ecx, dword ptr [eax]
// 0073f3b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0073f3bc  5f                   pop edi
// 0073f3bd  5e                   pop esi
// 0073f3be  5d                   pop ebp
// 0073f3bf  894804               mov dword ptr [eax + 4], ecx
// 0073f3c2  8910                 mov dword ptr [eax], edx
// 0073f3c4  5b                   pop ebx
// 0073f3c5  83c408               add esp, 8
// 0073f3c8  c21400               ret 0x14
// 0073f3cb  eb03                 jmp 0x73f3d0
// 0073f3cd  8d4900               lea ecx, [ecx]
// 0073f3d0  85ff                 test edi, edi
// 0073f3d2  7406                 je 0x73f3da
// 0073f3d4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0073f3d8  7406                 je 0x73f3e0
// 0073f3da  ffd5                 call ebp
// 0073f3dc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0073f3e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0073f3e4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0073f3e8  741d                 je 0x73f407
// 0073f3ea  8d4c2420             lea ecx, [esp + 0x20]
// 0073f3ee  e8fd44ddff           call 0x5138f0
// 0073f3f3  53                   push ebx
// 0073f3f4  57                   push edi
// 0073f3f5  8d442418             lea eax, [esp + 0x18]
// 0073f3f9  50                   push eax
// 0073f3fa  8bce                 mov ecx, esi
// 0073f3fc  e8aff7ffff           call 0x73ebb0
// 0073f401  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0073f405  ebc9                 jmp 0x73f3d0
// 0073f407  8b36                 mov esi, dword ptr [esi]
// 0073f409  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0073f40d  5f                   pop edi
// 0073f40e  8930                 mov dword ptr [eax], esi
// 0073f410  5e                   pop esi
// 0073f411  5d                   pop ebp
// 0073f412  895804               mov dword ptr [eax + 4], ebx
// 0073f415  5b                   pop ebx
// 0073f416  83c408               add esp, 8
// 0073f419  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
