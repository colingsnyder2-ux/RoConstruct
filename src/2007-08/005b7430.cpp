// from server: 100% by auto
// roc 2007-08 005b7430  unit: RBX::$01MP8Surface::?$SurfaceGetSet  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b7430
//
// 005b7430  83ec08               sub esp, 8
// 005b7433  53                   push ebx
// 005b7434  55                   push ebp
// 005b7435  56                   push esi
// 005b7436  57                   push edi
// 005b7437  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b743b  85ff                 test edi, edi
// 005b743d  8bf1                 mov esi, ecx
// 005b743f  8b4604               mov eax, dword ptr [esi + 4]
// 005b7442  8b28                 mov ebp, dword ptr [eax]
// 005b7444  7404                 je 0x5b744a
// 005b7446  3bfe                 cmp edi, esi
// 005b7448  7406                 je 0x5b7450
// 005b744a  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b7450  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b7454  3bdd                 cmp ebx, ebp
// 005b7456  7559                 jne 0x5b74b1
// 005b7458  8b442428             mov eax, dword ptr [esp + 0x28]
// 005b745c  85c0                 test eax, eax
// 005b745e  8b6e04               mov ebp, dword ptr [esi + 4]
// 005b7461  7404                 je 0x5b7467
// 005b7463  3bc6                 cmp eax, esi
// 005b7465  7406                 je 0x5b746d
// 005b7467  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b746d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 005b7471  753e                 jne 0x5b74b1
// 005b7473  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b7476  8b5104               mov edx, dword ptr [ecx + 4]
// 005b7479  52                   push edx
// 005b747a  8bce                 mov ecx, esi
// 005b747c  e86fdde8ff           call 0x4451f0
// 005b7481  8b4604               mov eax, dword ptr [esi + 4]
// 005b7484  894004               mov dword ptr [eax + 4], eax
// 005b7487  8b4604               mov eax, dword ptr [esi + 4]
// 005b748a  c7460800000000       mov dword ptr [esi + 8], 0
// 005b7491  8900                 mov dword ptr [eax], eax
// 005b7493  8b4604               mov eax, dword ptr [esi + 4]
// 005b7496  894008               mov dword ptr [eax + 8], eax
// 005b7499  8b4604               mov eax, dword ptr [esi + 4]
// 005b749c  8b08                 mov ecx, dword ptr [eax]
// 005b749e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b74a2  5f                   pop edi
// 005b74a3  8930                 mov dword ptr [eax], esi
// 005b74a5  5e                   pop esi
// 005b74a6  5d                   pop ebp
// 005b74a7  894804               mov dword ptr [eax + 4], ecx
// 005b74aa  5b                   pop ebx
// 005b74ab  83c408               add esp, 8
// 005b74ae  c21400               ret 0x14
// 005b74b1  85ff                 test edi, edi
// 005b74b3  7406                 je 0x5b74bb
// 005b74b5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005b74b9  7406                 je 0x5b74c1
// 005b74bb  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b74c1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005b74c5  7421                 je 0x5b74e8
// 005b74c7  8d4c2420             lea ecx, [esp + 0x20]
// 005b74cb  e8e019e8ff           call 0x438eb0
// 005b74d0  53                   push ebx
// 005b74d1  57                   push edi
// 005b74d2  8d542418             lea edx, [esp + 0x18]
// 005b74d6  52                   push edx
// 005b74d7  8bce                 mov ecx, esi
// 005b74d9  e892fcffff           call 0x5b7170
// 005b74de  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b74e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b74e6  ebc9                 jmp 0x5b74b1
// 005b74e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b74ec  8938                 mov dword ptr [eax], edi
// 005b74ee  5f                   pop edi
// 005b74ef  5e                   pop esi
// 005b74f0  5d                   pop ebp
// 005b74f1  895804               mov dword ptr [eax + 4], ebx
// 005b74f4  5b                   pop ebx
// 005b74f5  83c408               add esp, 8
// 005b74f8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
