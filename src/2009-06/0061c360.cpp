// from server: 100% by auto
// roc 2009-06 0061c360  unit: RBX::Network::VPlayer::?$BoundFuncDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061c360
//
// 0061c360  83ec08               sub esp, 8
// 0061c363  53                   push ebx
// 0061c364  55                   push ebp
// 0061c365  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0061c36b  56                   push esi
// 0061c36c  8bf1                 mov esi, ecx
// 0061c36e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061c371  8b18                 mov ebx, dword ptr [eax]
// 0061c373  8b06                 mov eax, dword ptr [esi]
// 0061c375  57                   push edi
// 0061c376  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c37a  85ff                 test edi, edi
// 0061c37c  7404                 je 0x61c382
// 0061c37e  3bf8                 cmp edi, eax
// 0061c380  7406                 je 0x61c388
// 0061c382  ffd5                 call ebp
// 0061c384  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c388  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0061c38c  7562                 jne 0x61c3f0
// 0061c38e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0061c392  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0061c395  8b06                 mov eax, dword ptr [esi]
// 0061c397  85c9                 test ecx, ecx
// 0061c399  7404                 je 0x61c39f
// 0061c39b  3bc8                 cmp ecx, eax
// 0061c39d  7406                 je 0x61c3a5
// 0061c39f  ffd5                 call ebp
// 0061c3a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c3a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0061c3a9  7545                 jne 0x61c3f0
// 0061c3ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061c3ae  8b5104               mov edx, dword ptr [ecx + 4]
// 0061c3b1  52                   push edx
// 0061c3b2  8bce                 mov ecx, esi
// 0061c3b4  e8d7eeffff           call 0x61b290
// 0061c3b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061c3bc  894004               mov dword ptr [eax + 4], eax
// 0061c3bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061c3c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0061c3c9  8900                 mov dword ptr [eax], eax
// 0061c3cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061c3ce  894008               mov dword ptr [eax + 8], eax
// 0061c3d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061c3d4  8b16                 mov edx, dword ptr [esi]
// 0061c3d6  8b08                 mov ecx, dword ptr [eax]
// 0061c3d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061c3dc  5f                   pop edi
// 0061c3dd  5e                   pop esi
// 0061c3de  5d                   pop ebp
// 0061c3df  894804               mov dword ptr [eax + 4], ecx
// 0061c3e2  8910                 mov dword ptr [eax], edx
// 0061c3e4  5b                   pop ebx
// 0061c3e5  83c408               add esp, 8
// 0061c3e8  c21400               ret 0x14
// 0061c3eb  eb03                 jmp 0x61c3f0
// 0061c3ed  8d4900               lea ecx, [ecx]
// 0061c3f0  85ff                 test edi, edi
// 0061c3f2  7406                 je 0x61c3fa
// 0061c3f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0061c3f8  7406                 je 0x61c400
// 0061c3fa  ffd5                 call ebp
// 0061c3fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c400  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0061c404  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0061c408  741d                 je 0x61c427
// 0061c40a  8d4c2420             lea ecx, [esp + 0x20]
// 0061c40e  e85dbfffff           call 0x618370
// 0061c413  53                   push ebx
// 0061c414  57                   push edi
// 0061c415  8d442418             lea eax, [esp + 0x18]
// 0061c419  50                   push eax
// 0061c41a  8bce                 mov ecx, esi
// 0061c41c  e84ff7ffff           call 0x61bb70
// 0061c421  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061c425  ebc9                 jmp 0x61c3f0
// 0061c427  8b36                 mov esi, dword ptr [esi]
// 0061c429  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061c42d  5f                   pop edi
// 0061c42e  8930                 mov dword ptr [eax], esi
// 0061c430  5e                   pop esi
// 0061c431  5d                   pop ebp
// 0061c432  895804               mov dword ptr [eax + 4], ebx
// 0061c435  5b                   pop ebx
// 0061c436  83c408               add esp, 8
// 0061c439  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
