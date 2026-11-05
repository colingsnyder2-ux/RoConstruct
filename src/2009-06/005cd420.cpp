// from server: 100% by auto
// roc 2009-06 005cd420  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005cd420
//
// 005cd420  83ec08               sub esp, 8
// 005cd423  53                   push ebx
// 005cd424  55                   push ebp
// 005cd425  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 005cd42b  56                   push esi
// 005cd42c  8bf1                 mov esi, ecx
// 005cd42e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005cd431  8b18                 mov ebx, dword ptr [eax]
// 005cd433  8b06                 mov eax, dword ptr [esi]
// 005cd435  57                   push edi
// 005cd436  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005cd43a  85ff                 test edi, edi
// 005cd43c  7404                 je 0x5cd442
// 005cd43e  3bf8                 cmp edi, eax
// 005cd440  7406                 je 0x5cd448
// 005cd442  ffd5                 call ebp
// 005cd444  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005cd448  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005cd44c  7562                 jne 0x5cd4b0
// 005cd44e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005cd452  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005cd455  8b06                 mov eax, dword ptr [esi]
// 005cd457  85c9                 test ecx, ecx
// 005cd459  7404                 je 0x5cd45f
// 005cd45b  3bc8                 cmp ecx, eax
// 005cd45d  7406                 je 0x5cd465
// 005cd45f  ffd5                 call ebp
// 005cd461  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005cd465  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005cd469  7545                 jne 0x5cd4b0
// 005cd46b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005cd46e  8b5104               mov edx, dword ptr [ecx + 4]
// 005cd471  52                   push edx
// 005cd472  8bce                 mov ecx, esi
// 005cd474  e8e7feffff           call 0x5cd360
// 005cd479  8b4618               mov eax, dword ptr [esi + 0x18]
// 005cd47c  894004               mov dword ptr [eax + 4], eax
// 005cd47f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005cd482  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005cd489  8900                 mov dword ptr [eax], eax
// 005cd48b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005cd48e  894008               mov dword ptr [eax + 8], eax
// 005cd491  8b4618               mov eax, dword ptr [esi + 0x18]
// 005cd494  8b16                 mov edx, dword ptr [esi]
// 005cd496  8b08                 mov ecx, dword ptr [eax]
// 005cd498  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005cd49c  5f                   pop edi
// 005cd49d  5e                   pop esi
// 005cd49e  5d                   pop ebp
// 005cd49f  894804               mov dword ptr [eax + 4], ecx
// 005cd4a2  8910                 mov dword ptr [eax], edx
// 005cd4a4  5b                   pop ebx
// 005cd4a5  83c408               add esp, 8
// 005cd4a8  c21400               ret 0x14
// 005cd4ab  eb03                 jmp 0x5cd4b0
// 005cd4ad  8d4900               lea ecx, [ecx]
// 005cd4b0  85ff                 test edi, edi
// 005cd4b2  7406                 je 0x5cd4ba
// 005cd4b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005cd4b8  7406                 je 0x5cd4c0
// 005cd4ba  ffd5                 call ebp
// 005cd4bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005cd4c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005cd4c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005cd4c8  741d                 je 0x5cd4e7
// 005cd4ca  8d4c2420             lea ecx, [esp + 0x20]
// 005cd4ce  e83d150700           call 0x63ea10
// 005cd4d3  53                   push ebx
// 005cd4d4  57                   push edi
// 005cd4d5  8d442418             lea eax, [esp + 0x18]
// 005cd4d9  50                   push eax
// 005cd4da  8bce                 mov ecx, esi
// 005cd4dc  e89ffbffff           call 0x5cd080
// 005cd4e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005cd4e5  ebc9                 jmp 0x5cd4b0
// 005cd4e7  8b36                 mov esi, dword ptr [esi]
// 005cd4e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005cd4ed  5f                   pop edi
// 005cd4ee  8930                 mov dword ptr [eax], esi
// 005cd4f0  5e                   pop esi
// 005cd4f1  5d                   pop ebp
// 005cd4f2  895804               mov dword ptr [eax + 4], ebx
// 005cd4f5  5b                   pop ebx
// 005cd4f6  83c408               add esp, 8
// 005cd4f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
