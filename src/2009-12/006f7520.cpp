// from server: 100% by auto
// roc 2009-12 006f7520  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f7520
//
// 006f7520  83ec08               sub esp, 8
// 006f7523  53                   push ebx
// 006f7524  55                   push ebp
// 006f7525  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006f752b  56                   push esi
// 006f752c  8bf1                 mov esi, ecx
// 006f752e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f7531  8b18                 mov ebx, dword ptr [eax]
// 006f7533  8b06                 mov eax, dword ptr [esi]
// 006f7535  57                   push edi
// 006f7536  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f753a  85ff                 test edi, edi
// 006f753c  7404                 je 0x6f7542
// 006f753e  3bf8                 cmp edi, eax
// 006f7540  7406                 je 0x6f7548
// 006f7542  ffd5                 call ebp
// 006f7544  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f7548  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006f754c  7562                 jne 0x6f75b0
// 006f754e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f7552  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006f7555  8b06                 mov eax, dword ptr [esi]
// 006f7557  85c9                 test ecx, ecx
// 006f7559  7404                 je 0x6f755f
// 006f755b  3bc8                 cmp ecx, eax
// 006f755d  7406                 je 0x6f7565
// 006f755f  ffd5                 call ebp
// 006f7561  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f7565  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006f7569  7545                 jne 0x6f75b0
// 006f756b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f756e  8b5104               mov edx, dword ptr [ecx + 4]
// 006f7571  52                   push edx
// 006f7572  8bce                 mov ecx, esi
// 006f7574  e857f4ffff           call 0x6f69d0
// 006f7579  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f757c  894004               mov dword ptr [eax + 4], eax
// 006f757f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f7582  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f7589  8900                 mov dword ptr [eax], eax
// 006f758b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f758e  894008               mov dword ptr [eax + 8], eax
// 006f7591  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f7594  8b16                 mov edx, dword ptr [esi]
// 006f7596  8b08                 mov ecx, dword ptr [eax]
// 006f7598  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f759c  5f                   pop edi
// 006f759d  5e                   pop esi
// 006f759e  5d                   pop ebp
// 006f759f  894804               mov dword ptr [eax + 4], ecx
// 006f75a2  8910                 mov dword ptr [eax], edx
// 006f75a4  5b                   pop ebx
// 006f75a5  83c408               add esp, 8
// 006f75a8  c21400               ret 0x14
// 006f75ab  eb03                 jmp 0x6f75b0
// 006f75ad  8d4900               lea ecx, [ecx]
// 006f75b0  85ff                 test edi, edi
// 006f75b2  7406                 je 0x6f75ba
// 006f75b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006f75b8  7406                 je 0x6f75c0
// 006f75ba  ffd5                 call ebp
// 006f75bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f75c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006f75c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006f75c8  741d                 je 0x6f75e7
// 006f75ca  8d4c2420             lea ecx, [esp + 0x20]
// 006f75ce  e8ad0fe4ff           call 0x538580
// 006f75d3  53                   push ebx
// 006f75d4  57                   push edi
// 006f75d5  8d442418             lea eax, [esp + 0x18]
// 006f75d9  50                   push eax
// 006f75da  8bce                 mov ecx, esi
// 006f75dc  e8eff0ffff           call 0x6f66d0
// 006f75e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006f75e5  ebc9                 jmp 0x6f75b0
// 006f75e7  8b36                 mov esi, dword ptr [esi]
// 006f75e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f75ed  5f                   pop edi
// 006f75ee  8930                 mov dword ptr [eax], esi
// 006f75f0  5e                   pop esi
// 006f75f1  5d                   pop ebp
// 006f75f2  895804               mov dword ptr [eax + 4], ebx
// 006f75f5  5b                   pop ebx
// 006f75f6  83c408               add esp, 8
// 006f75f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
