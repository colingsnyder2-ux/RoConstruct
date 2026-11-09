// from server: 100% by auto
// roc 2009-06 006d38b0  unit: RBX::Block  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d38b0
//
// 006d38b0  83ec08               sub esp, 8
// 006d38b3  53                   push ebx
// 006d38b4  55                   push ebp
// 006d38b5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006d38bb  56                   push esi
// 006d38bc  8bf1                 mov esi, ecx
// 006d38be  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d38c1  8b18                 mov ebx, dword ptr [eax]
// 006d38c3  8b06                 mov eax, dword ptr [esi]
// 006d38c5  57                   push edi
// 006d38c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006d38ca  85ff                 test edi, edi
// 006d38cc  7404                 je 0x6d38d2
// 006d38ce  3bf8                 cmp edi, eax
// 006d38d0  7406                 je 0x6d38d8
// 006d38d2  ffd5                 call ebp
// 006d38d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006d38d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006d38dc  7562                 jne 0x6d3940
// 006d38de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006d38e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006d38e5  8b06                 mov eax, dword ptr [esi]
// 006d38e7  85c9                 test ecx, ecx
// 006d38e9  7404                 je 0x6d38ef
// 006d38eb  3bc8                 cmp ecx, eax
// 006d38ed  7406                 je 0x6d38f5
// 006d38ef  ffd5                 call ebp
// 006d38f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006d38f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006d38f9  7545                 jne 0x6d3940
// 006d38fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006d38fe  8b5104               mov edx, dword ptr [ecx + 4]
// 006d3901  52                   push edx
// 006d3902  8bce                 mov ecx, esi
// 006d3904  e867f9ffff           call 0x6d3270
// 006d3909  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d390c  894004               mov dword ptr [eax + 4], eax
// 006d390f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d3912  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006d3919  8900                 mov dword ptr [eax], eax
// 006d391b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d391e  894008               mov dword ptr [eax + 8], eax
// 006d3921  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d3924  8b16                 mov edx, dword ptr [esi]
// 006d3926  8b08                 mov ecx, dword ptr [eax]
// 006d3928  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006d392c  5f                   pop edi
// 006d392d  5e                   pop esi
// 006d392e  5d                   pop ebp
// 006d392f  894804               mov dword ptr [eax + 4], ecx
// 006d3932  8910                 mov dword ptr [eax], edx
// 006d3934  5b                   pop ebx
// 006d3935  83c408               add esp, 8
// 006d3938  c21400               ret 0x14
// 006d393b  eb03                 jmp 0x6d3940
// 006d393d  8d4900               lea ecx, [ecx]
// 006d3940  85ff                 test edi, edi
// 006d3942  7406                 je 0x6d394a
// 006d3944  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006d3948  7406                 je 0x6d3950
// 006d394a  ffd5                 call ebp
// 006d394c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006d3950  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006d3954  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006d3958  741d                 je 0x6d3977
// 006d395a  8d4c2420             lea ecx, [esp + 0x20]
// 006d395e  e8ddf5ffff           call 0x6d2f40
// 006d3963  53                   push ebx
// 006d3964  57                   push edi
// 006d3965  8d442418             lea eax, [esp + 0x18]
// 006d3969  50                   push eax
// 006d396a  8bce                 mov ecx, esi
// 006d396c  e83ffbffff           call 0x6d34b0
// 006d3971  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006d3975  ebc9                 jmp 0x6d3940
// 006d3977  8b36                 mov esi, dword ptr [esi]
// 006d3979  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006d397d  5f                   pop edi
// 006d397e  8930                 mov dword ptr [eax], esi
// 006d3980  5e                   pop esi
// 006d3981  5d                   pop ebp
// 006d3982  895804               mov dword ptr [eax + 4], ebx
// 006d3985  5b                   pop ebx
// 006d3986  83c408               add esp, 8
// 006d3989  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
