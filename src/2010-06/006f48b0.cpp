// from server: 100% by auto
// roc 2010-06 006f48b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f48b0
//
// 006f48b0  83ec08               sub esp, 8
// 006f48b3  53                   push ebx
// 006f48b4  55                   push ebp
// 006f48b5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006f48bb  56                   push esi
// 006f48bc  8bf1                 mov esi, ecx
// 006f48be  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f48c1  8b18                 mov ebx, dword ptr [eax]
// 006f48c3  8b06                 mov eax, dword ptr [esi]
// 006f48c5  57                   push edi
// 006f48c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f48ca  85ff                 test edi, edi
// 006f48cc  7404                 je 0x6f48d2
// 006f48ce  3bf8                 cmp edi, eax
// 006f48d0  7406                 je 0x6f48d8
// 006f48d2  ffd5                 call ebp
// 006f48d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f48d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006f48dc  7562                 jne 0x6f4940
// 006f48de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f48e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006f48e5  8b06                 mov eax, dword ptr [esi]
// 006f48e7  85c9                 test ecx, ecx
// 006f48e9  7404                 je 0x6f48ef
// 006f48eb  3bc8                 cmp ecx, eax
// 006f48ed  7406                 je 0x6f48f5
// 006f48ef  ffd5                 call ebp
// 006f48f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f48f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006f48f9  7545                 jne 0x6f4940
// 006f48fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f48fe  8b5104               mov edx, dword ptr [ecx + 4]
// 006f4901  52                   push edx
// 006f4902  8bce                 mov ecx, esi
// 006f4904  e847f7ffff           call 0x6f4050
// 006f4909  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f490c  894004               mov dword ptr [eax + 4], eax
// 006f490f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f4912  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f4919  8900                 mov dword ptr [eax], eax
// 006f491b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f491e  894008               mov dword ptr [eax + 8], eax
// 006f4921  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f4924  8b16                 mov edx, dword ptr [esi]
// 006f4926  8b08                 mov ecx, dword ptr [eax]
// 006f4928  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f492c  5f                   pop edi
// 006f492d  5e                   pop esi
// 006f492e  5d                   pop ebp
// 006f492f  894804               mov dword ptr [eax + 4], ecx
// 006f4932  8910                 mov dword ptr [eax], edx
// 006f4934  5b                   pop ebx
// 006f4935  83c408               add esp, 8
// 006f4938  c21400               ret 0x14
// 006f493b  eb03                 jmp 0x6f4940
// 006f493d  8d4900               lea ecx, [ecx]
// 006f4940  85ff                 test edi, edi
// 006f4942  7406                 je 0x6f494a
// 006f4944  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006f4948  7406                 je 0x6f4950
// 006f494a  ffd5                 call ebp
// 006f494c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f4950  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006f4954  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006f4958  741d                 je 0x6f4977
// 006f495a  8d4c2420             lea ecx, [esp + 0x20]
// 006f495e  e88df3ffff           call 0x6f3cf0
// 006f4963  53                   push ebx
// 006f4964  57                   push edi
// 006f4965  8d442418             lea eax, [esp + 0x18]
// 006f4969  50                   push eax
// 006f496a  8bce                 mov ecx, esi
// 006f496c  e88ff7ffff           call 0x6f4100
// 006f4971  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f4975  ebc9                 jmp 0x6f4940
// 006f4977  8b36                 mov esi, dword ptr [esi]
// 006f4979  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f497d  5f                   pop edi
// 006f497e  8930                 mov dword ptr [eax], esi
// 006f4980  5e                   pop esi
// 006f4981  5d                   pop ebp
// 006f4982  895804               mov dword ptr [eax + 4], ebx
// 006f4985  5b                   pop ebx
// 006f4986  83c408               add esp, 8
// 006f4989  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
