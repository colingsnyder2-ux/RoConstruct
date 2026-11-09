// from server: 100% by auto
// roc 2009-06 004d9110  unit: RBX::Network::VGuidRegistryService::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d9110
//
// 004d9110  83ec08               sub esp, 8
// 004d9113  53                   push ebx
// 004d9114  55                   push ebp
// 004d9115  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004d911b  56                   push esi
// 004d911c  8bf1                 mov esi, ecx
// 004d911e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d9121  8b18                 mov ebx, dword ptr [eax]
// 004d9123  8b06                 mov eax, dword ptr [esi]
// 004d9125  57                   push edi
// 004d9126  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d912a  85ff                 test edi, edi
// 004d912c  7404                 je 0x4d9132
// 004d912e  3bf8                 cmp edi, eax
// 004d9130  7406                 je 0x4d9138
// 004d9132  ffd5                 call ebp
// 004d9134  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d9138  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004d913c  7562                 jne 0x4d91a0
// 004d913e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004d9142  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004d9145  8b06                 mov eax, dword ptr [esi]
// 004d9147  85c9                 test ecx, ecx
// 004d9149  7404                 je 0x4d914f
// 004d914b  3bc8                 cmp ecx, eax
// 004d914d  7406                 je 0x4d9155
// 004d914f  ffd5                 call ebp
// 004d9151  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d9155  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004d9159  7545                 jne 0x4d91a0
// 004d915b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004d915e  8b5104               mov edx, dword ptr [ecx + 4]
// 004d9161  52                   push edx
// 004d9162  8bce                 mov ecx, esi
// 004d9164  e857fcffff           call 0x4d8dc0
// 004d9169  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d916c  894004               mov dword ptr [eax + 4], eax
// 004d916f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d9172  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004d9179  8900                 mov dword ptr [eax], eax
// 004d917b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d917e  894008               mov dword ptr [eax + 8], eax
// 004d9181  8b4618               mov eax, dword ptr [esi + 0x18]
// 004d9184  8b16                 mov edx, dword ptr [esi]
// 004d9186  8b08                 mov ecx, dword ptr [eax]
// 004d9188  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d918c  5f                   pop edi
// 004d918d  5e                   pop esi
// 004d918e  5d                   pop ebp
// 004d918f  894804               mov dword ptr [eax + 4], ecx
// 004d9192  8910                 mov dword ptr [eax], edx
// 004d9194  5b                   pop ebx
// 004d9195  83c408               add esp, 8
// 004d9198  c21400               ret 0x14
// 004d919b  eb03                 jmp 0x4d91a0
// 004d919d  8d4900               lea ecx, [ecx]
// 004d91a0  85ff                 test edi, edi
// 004d91a2  7406                 je 0x4d91aa
// 004d91a4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004d91a8  7406                 je 0x4d91b0
// 004d91aa  ffd5                 call ebp
// 004d91ac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d91b0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004d91b4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004d91b8  741d                 je 0x4d91d7
// 004d91ba  8d4c2420             lea ecx, [esp + 0x20]
// 004d91be  e8fd901400           call 0x6222c0
// 004d91c3  53                   push ebx
// 004d91c4  57                   push edi
// 004d91c5  8d442418             lea eax, [esp + 0x18]
// 004d91c9  50                   push eax
// 004d91ca  8bce                 mov ecx, esi
// 004d91cc  e86ffcffff           call 0x4d8e40
// 004d91d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d91d5  ebc9                 jmp 0x4d91a0
// 004d91d7  8b36                 mov esi, dword ptr [esi]
// 004d91d9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d91dd  5f                   pop edi
// 004d91de  8930                 mov dword ptr [eax], esi
// 004d91e0  5e                   pop esi
// 004d91e1  5d                   pop ebp
// 004d91e2  895804               mov dword ptr [eax + 4], ebx
// 004d91e5  5b                   pop ebx
// 004d91e6  83c408               add esp, 8
// 004d91e9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
