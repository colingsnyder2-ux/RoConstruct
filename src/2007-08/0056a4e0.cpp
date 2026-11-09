// from server: 100% by auto
// roc 2007-08 0056a4e0  unit: RBX::ModelInstance  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056a4e0
//
// 0056a4e0  83ec08               sub esp, 8
// 0056a4e3  53                   push ebx
// 0056a4e4  55                   push ebp
// 0056a4e5  56                   push esi
// 0056a4e6  57                   push edi
// 0056a4e7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056a4eb  85ff                 test edi, edi
// 0056a4ed  8bf1                 mov esi, ecx
// 0056a4ef  8b4604               mov eax, dword ptr [esi + 4]
// 0056a4f2  8b28                 mov ebp, dword ptr [eax]
// 0056a4f4  7404                 je 0x56a4fa
// 0056a4f6  3bfe                 cmp edi, esi
// 0056a4f8  7406                 je 0x56a500
// 0056a4fa  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a500  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056a504  3bdd                 cmp ebx, ebp
// 0056a506  7559                 jne 0x56a561
// 0056a508  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056a50c  85c0                 test eax, eax
// 0056a50e  8b6e04               mov ebp, dword ptr [esi + 4]
// 0056a511  7404                 je 0x56a517
// 0056a513  3bc6                 cmp eax, esi
// 0056a515  7406                 je 0x56a51d
// 0056a517  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a51d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 0056a521  753e                 jne 0x56a561
// 0056a523  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056a526  8b5104               mov edx, dword ptr [ecx + 4]
// 0056a529  52                   push edx
// 0056a52a  8bce                 mov ecx, esi
// 0056a52c  e8effcffff           call 0x56a220
// 0056a531  8b4604               mov eax, dword ptr [esi + 4]
// 0056a534  894004               mov dword ptr [eax + 4], eax
// 0056a537  8b4604               mov eax, dword ptr [esi + 4]
// 0056a53a  c7460800000000       mov dword ptr [esi + 8], 0
// 0056a541  8900                 mov dword ptr [eax], eax
// 0056a543  8b4604               mov eax, dword ptr [esi + 4]
// 0056a546  894008               mov dword ptr [eax + 8], eax
// 0056a549  8b4604               mov eax, dword ptr [esi + 4]
// 0056a54c  8b08                 mov ecx, dword ptr [eax]
// 0056a54e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056a552  5f                   pop edi
// 0056a553  8930                 mov dword ptr [eax], esi
// 0056a555  5e                   pop esi
// 0056a556  5d                   pop ebp
// 0056a557  894804               mov dword ptr [eax + 4], ecx
// 0056a55a  5b                   pop ebx
// 0056a55b  83c408               add esp, 8
// 0056a55e  c21400               ret 0x14
// 0056a561  85ff                 test edi, edi
// 0056a563  7406                 je 0x56a56b
// 0056a565  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0056a569  7406                 je 0x56a571
// 0056a56b  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a571  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0056a575  7421                 je 0x56a598
// 0056a577  8d4c2420             lea ecx, [esp + 0x20]
// 0056a57b  e8b0efffff           call 0x569530
// 0056a580  53                   push ebx
// 0056a581  57                   push edi
// 0056a582  8d542418             lea edx, [esp + 0x18]
// 0056a586  52                   push edx
// 0056a587  8bce                 mov ecx, esi
// 0056a589  e8d2f6ffff           call 0x569c60
// 0056a58e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056a592  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056a596  ebc9                 jmp 0x56a561
// 0056a598  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056a59c  8938                 mov dword ptr [eax], edi
// 0056a59e  5f                   pop edi
// 0056a59f  5e                   pop esi
// 0056a5a0  5d                   pop ebp
// 0056a5a1  895804               mov dword ptr [eax + 4], ebx
// 0056a5a4  5b                   pop ebx
// 0056a5a5  83c408               add esp, 8
// 0056a5a8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
