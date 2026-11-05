// from server: 100% by auto
// roc 2009-06 004dade0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dade0
//
// 004dade0  83ec08               sub esp, 8
// 004dade3  53                   push ebx
// 004dade4  55                   push ebp
// 004dade5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004dadeb  56                   push esi
// 004dadec  8bf1                 mov esi, ecx
// 004dadee  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dadf1  8b18                 mov ebx, dword ptr [eax]
// 004dadf3  8b06                 mov eax, dword ptr [esi]
// 004dadf5  57                   push edi
// 004dadf6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dadfa  85ff                 test edi, edi
// 004dadfc  7404                 je 0x4dae02
// 004dadfe  3bf8                 cmp edi, eax
// 004dae00  7406                 je 0x4dae08
// 004dae02  ffd5                 call ebp
// 004dae04  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dae08  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004dae0c  7562                 jne 0x4dae70
// 004dae0e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004dae12  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004dae15  8b06                 mov eax, dword ptr [esi]
// 004dae17  85c9                 test ecx, ecx
// 004dae19  7404                 je 0x4dae1f
// 004dae1b  3bc8                 cmp ecx, eax
// 004dae1d  7406                 je 0x4dae25
// 004dae1f  ffd5                 call ebp
// 004dae21  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dae25  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004dae29  7545                 jne 0x4dae70
// 004dae2b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004dae2e  8b5104               mov edx, dword ptr [ecx + 4]
// 004dae31  52                   push edx
// 004dae32  8bce                 mov ecx, esi
// 004dae34  e8f7f8ffff           call 0x4da730
// 004dae39  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dae3c  894004               mov dword ptr [eax + 4], eax
// 004dae3f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dae42  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004dae49  8900                 mov dword ptr [eax], eax
// 004dae4b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dae4e  894008               mov dword ptr [eax + 8], eax
// 004dae51  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dae54  8b16                 mov edx, dword ptr [esi]
// 004dae56  8b08                 mov ecx, dword ptr [eax]
// 004dae58  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004dae5c  5f                   pop edi
// 004dae5d  5e                   pop esi
// 004dae5e  5d                   pop ebp
// 004dae5f  894804               mov dword ptr [eax + 4], ecx
// 004dae62  8910                 mov dword ptr [eax], edx
// 004dae64  5b                   pop ebx
// 004dae65  83c408               add esp, 8
// 004dae68  c21400               ret 0x14
// 004dae6b  eb03                 jmp 0x4dae70
// 004dae6d  8d4900               lea ecx, [ecx]
// 004dae70  85ff                 test edi, edi
// 004dae72  7406                 je 0x4dae7a
// 004dae74  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004dae78  7406                 je 0x4dae80
// 004dae7a  ffd5                 call ebp
// 004dae7c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dae80  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004dae84  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004dae88  741d                 je 0x4daea7
// 004dae8a  8d4c2420             lea ecx, [esp + 0x20]
// 004dae8e  e84df3ffff           call 0x4da1e0
// 004dae93  53                   push ebx
// 004dae94  57                   push edi
// 004dae95  8d442418             lea eax, [esp + 0x18]
// 004dae99  50                   push eax
// 004dae9a  8bce                 mov ecx, esi
// 004dae9c  e82ffbffff           call 0x4da9d0
// 004daea1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004daea5  ebc9                 jmp 0x4dae70
// 004daea7  8b36                 mov esi, dword ptr [esi]
// 004daea9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004daead  5f                   pop edi
// 004daeae  8930                 mov dword ptr [eax], esi
// 004daeb0  5e                   pop esi
// 004daeb1  5d                   pop ebp
// 004daeb2  895804               mov dword ptr [eax + 4], ebx
// 004daeb5  5b                   pop ebx
// 004daeb6  83c408               add esp, 8
// 004daeb9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
