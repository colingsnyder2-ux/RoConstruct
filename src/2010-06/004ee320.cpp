// from server: 100% by auto
// roc 2010-06 004ee320  unit: RBX::Network::Replicator::NewInstanceItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ee320
//
// 004ee320  83ec08               sub esp, 8
// 004ee323  53                   push ebx
// 004ee324  55                   push ebp
// 004ee325  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004ee32b  56                   push esi
// 004ee32c  8bf1                 mov esi, ecx
// 004ee32e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ee331  8b18                 mov ebx, dword ptr [eax]
// 004ee333  8b06                 mov eax, dword ptr [esi]
// 004ee335  57                   push edi
// 004ee336  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ee33a  85ff                 test edi, edi
// 004ee33c  7404                 je 0x4ee342
// 004ee33e  3bf8                 cmp edi, eax
// 004ee340  7406                 je 0x4ee348
// 004ee342  ffd5                 call ebp
// 004ee344  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ee348  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004ee34c  7562                 jne 0x4ee3b0
// 004ee34e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ee352  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004ee355  8b06                 mov eax, dword ptr [esi]
// 004ee357  85c9                 test ecx, ecx
// 004ee359  7404                 je 0x4ee35f
// 004ee35b  3bc8                 cmp ecx, eax
// 004ee35d  7406                 je 0x4ee365
// 004ee35f  ffd5                 call ebp
// 004ee361  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ee365  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004ee369  7545                 jne 0x4ee3b0
// 004ee36b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004ee36e  8b5104               mov edx, dword ptr [ecx + 4]
// 004ee371  52                   push edx
// 004ee372  8bce                 mov ecx, esi
// 004ee374  e827e2ffff           call 0x4ec5a0
// 004ee379  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ee37c  894004               mov dword ptr [eax + 4], eax
// 004ee37f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ee382  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004ee389  8900                 mov dword ptr [eax], eax
// 004ee38b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ee38e  894008               mov dword ptr [eax + 8], eax
// 004ee391  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ee394  8b16                 mov edx, dword ptr [esi]
// 004ee396  8b08                 mov ecx, dword ptr [eax]
// 004ee398  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ee39c  5f                   pop edi
// 004ee39d  5e                   pop esi
// 004ee39e  5d                   pop ebp
// 004ee39f  894804               mov dword ptr [eax + 4], ecx
// 004ee3a2  8910                 mov dword ptr [eax], edx
// 004ee3a4  5b                   pop ebx
// 004ee3a5  83c408               add esp, 8
// 004ee3a8  c21400               ret 0x14
// 004ee3ab  eb03                 jmp 0x4ee3b0
// 004ee3ad  8d4900               lea ecx, [ecx]
// 004ee3b0  85ff                 test edi, edi
// 004ee3b2  7406                 je 0x4ee3ba
// 004ee3b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004ee3b8  7406                 je 0x4ee3c0
// 004ee3ba  ffd5                 call ebp
// 004ee3bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ee3c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ee3c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004ee3c8  741d                 je 0x4ee3e7
// 004ee3ca  8d4c2420             lea ecx, [esp + 0x20]
// 004ee3ce  e85d86ffff           call 0x4e6a30
// 004ee3d3  53                   push ebx
// 004ee3d4  57                   push edi
// 004ee3d5  8d442418             lea eax, [esp + 0x18]
// 004ee3d9  50                   push eax
// 004ee3da  8bce                 mov ecx, esi
// 004ee3dc  e8bfdeffff           call 0x4ec2a0
// 004ee3e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ee3e5  ebc9                 jmp 0x4ee3b0
// 004ee3e7  8b36                 mov esi, dword ptr [esi]
// 004ee3e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ee3ed  5f                   pop edi
// 004ee3ee  8930                 mov dword ptr [eax], esi
// 004ee3f0  5e                   pop esi
// 004ee3f1  5d                   pop ebp
// 004ee3f2  895804               mov dword ptr [eax + 4], ebx
// 004ee3f5  5b                   pop ebx
// 004ee3f6  83c408               add esp, 8
// 004ee3f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
