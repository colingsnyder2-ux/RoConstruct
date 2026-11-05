// from server: 100% by auto
// roc 2010-06 004fc460  unit: RBX::Network::VReplicator::?$EventDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004fc460
//
// 004fc460  83ec08               sub esp, 8
// 004fc463  53                   push ebx
// 004fc464  55                   push ebp
// 004fc465  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004fc46b  56                   push esi
// 004fc46c  8bf1                 mov esi, ecx
// 004fc46e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc471  8b18                 mov ebx, dword ptr [eax]
// 004fc473  8b06                 mov eax, dword ptr [esi]
// 004fc475  57                   push edi
// 004fc476  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc47a  85ff                 test edi, edi
// 004fc47c  7404                 je 0x4fc482
// 004fc47e  3bf8                 cmp edi, eax
// 004fc480  7406                 je 0x4fc488
// 004fc482  ffd5                 call ebp
// 004fc484  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc488  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004fc48c  7562                 jne 0x4fc4f0
// 004fc48e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004fc492  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004fc495  8b06                 mov eax, dword ptr [esi]
// 004fc497  85c9                 test ecx, ecx
// 004fc499  7404                 je 0x4fc49f
// 004fc49b  3bc8                 cmp ecx, eax
// 004fc49d  7406                 je 0x4fc4a5
// 004fc49f  ffd5                 call ebp
// 004fc4a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc4a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004fc4a9  7545                 jne 0x4fc4f0
// 004fc4ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004fc4ae  8b5104               mov edx, dword ptr [ecx + 4]
// 004fc4b1  52                   push edx
// 004fc4b2  8bce                 mov ecx, esi
// 004fc4b4  e8f7d8ffff           call 0x4f9db0
// 004fc4b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc4bc  894004               mov dword ptr [eax + 4], eax
// 004fc4bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc4c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004fc4c9  8900                 mov dword ptr [eax], eax
// 004fc4cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc4ce  894008               mov dword ptr [eax + 8], eax
// 004fc4d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc4d4  8b16                 mov edx, dword ptr [esi]
// 004fc4d6  8b08                 mov ecx, dword ptr [eax]
// 004fc4d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004fc4dc  5f                   pop edi
// 004fc4dd  5e                   pop esi
// 004fc4de  5d                   pop ebp
// 004fc4df  894804               mov dword ptr [eax + 4], ecx
// 004fc4e2  8910                 mov dword ptr [eax], edx
// 004fc4e4  5b                   pop ebx
// 004fc4e5  83c408               add esp, 8
// 004fc4e8  c21400               ret 0x14
// 004fc4eb  eb03                 jmp 0x4fc4f0
// 004fc4ed  8d4900               lea ecx, [ecx]
// 004fc4f0  85ff                 test edi, edi
// 004fc4f2  7406                 je 0x4fc4fa
// 004fc4f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004fc4f8  7406                 je 0x4fc500
// 004fc4fa  ffd5                 call ebp
// 004fc4fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc500  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004fc504  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004fc508  741d                 je 0x4fc527
// 004fc50a  8d4c2420             lea ecx, [esp + 0x20]
// 004fc50e  e82d9d3c00           call 0x8c6240
// 004fc513  53                   push ebx
// 004fc514  57                   push edi
// 004fc515  8d442418             lea eax, [esp + 0x18]
// 004fc519  50                   push eax
// 004fc51a  8bce                 mov ecx, esi
// 004fc51c  e83f85feff           call 0x4e4a60
// 004fc521  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc525  ebc9                 jmp 0x4fc4f0
// 004fc527  8b36                 mov esi, dword ptr [esi]
// 004fc529  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004fc52d  5f                   pop edi
// 004fc52e  8930                 mov dword ptr [eax], esi
// 004fc530  5e                   pop esi
// 004fc531  5d                   pop ebp
// 004fc532  895804               mov dword ptr [eax + 4], ebx
// 004fc535  5b                   pop ebx
// 004fc536  83c408               add esp, 8
// 004fc539  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
