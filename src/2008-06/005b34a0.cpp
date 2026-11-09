// from server: 100% by auto
// roc 2008-06 005b34a0  unit: RBX::VHat::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b34a0
//
// 005b34a0  83ec08               sub esp, 8
// 005b34a3  53                   push ebx
// 005b34a4  55                   push ebp
// 005b34a5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005b34ab  56                   push esi
// 005b34ac  8bf1                 mov esi, ecx
// 005b34ae  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b34b1  8b18                 mov ebx, dword ptr [eax]
// 005b34b3  8b06                 mov eax, dword ptr [esi]
// 005b34b5  57                   push edi
// 005b34b6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b34ba  85ff                 test edi, edi
// 005b34bc  7404                 je 0x5b34c2
// 005b34be  3bf8                 cmp edi, eax
// 005b34c0  7406                 je 0x5b34c8
// 005b34c2  ffd5                 call ebp
// 005b34c4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b34c8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005b34cc  7562                 jne 0x5b3530
// 005b34ce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b34d2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005b34d5  8b06                 mov eax, dword ptr [esi]
// 005b34d7  85c9                 test ecx, ecx
// 005b34d9  7404                 je 0x5b34df
// 005b34db  3bc8                 cmp ecx, eax
// 005b34dd  7406                 je 0x5b34e5
// 005b34df  ffd5                 call ebp
// 005b34e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b34e5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005b34e9  7545                 jne 0x5b3530
// 005b34eb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005b34ee  8b5104               mov edx, dword ptr [ecx + 4]
// 005b34f1  52                   push edx
// 005b34f2  8bce                 mov ecx, esi
// 005b34f4  e867fbffff           call 0x5b3060
// 005b34f9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b34fc  894004               mov dword ptr [eax + 4], eax
// 005b34ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b3502  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005b3509  8900                 mov dword ptr [eax], eax
// 005b350b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b350e  894008               mov dword ptr [eax + 8], eax
// 005b3511  8b4618               mov eax, dword ptr [esi + 0x18]
// 005b3514  8b16                 mov edx, dword ptr [esi]
// 005b3516  8b08                 mov ecx, dword ptr [eax]
// 005b3518  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b351c  5f                   pop edi
// 005b351d  5e                   pop esi
// 005b351e  5d                   pop ebp
// 005b351f  894804               mov dword ptr [eax + 4], ecx
// 005b3522  8910                 mov dword ptr [eax], edx
// 005b3524  5b                   pop ebx
// 005b3525  83c408               add esp, 8
// 005b3528  c21400               ret 0x14
// 005b352b  eb03                 jmp 0x5b3530
// 005b352d  8d4900               lea ecx, [ecx]
// 005b3530  85ff                 test edi, edi
// 005b3532  7406                 je 0x5b353a
// 005b3534  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005b3538  7406                 je 0x5b3540
// 005b353a  ffd5                 call ebp
// 005b353c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b3540  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b3544  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005b3548  741d                 je 0x5b3567
// 005b354a  8d4c2420             lea ecx, [esp + 0x20]
// 005b354e  e8ed3cf2ff           call 0x4d7240
// 005b3553  53                   push ebx
// 005b3554  57                   push edi
// 005b3555  8d442418             lea eax, [esp + 0x18]
// 005b3559  50                   push eax
// 005b355a  8bce                 mov ecx, esi
// 005b355c  e8cfe60c00           call 0x681c30
// 005b3561  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b3565  ebc9                 jmp 0x5b3530
// 005b3567  8b36                 mov esi, dword ptr [esi]
// 005b3569  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b356d  5f                   pop edi
// 005b356e  8930                 mov dword ptr [eax], esi
// 005b3570  5e                   pop esi
// 005b3571  5d                   pop ebp
// 005b3572  895804               mov dword ptr [eax + 4], ebx
// 005b3575  5b                   pop ebx
// 005b3576  83c408               add esp, 8
// 005b3579  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
