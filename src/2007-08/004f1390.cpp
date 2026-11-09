// from server: 100% by auto
// roc 2007-08 004f1390  unit: RBX::Render::AggregatingSceneManager  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f1390
//
// 004f1390  83ec08               sub esp, 8
// 004f1393  53                   push ebx
// 004f1394  55                   push ebp
// 004f1395  56                   push esi
// 004f1396  57                   push edi
// 004f1397  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f139b  85ff                 test edi, edi
// 004f139d  8bf1                 mov esi, ecx
// 004f139f  8b4604               mov eax, dword ptr [esi + 4]
// 004f13a2  8b28                 mov ebp, dword ptr [eax]
// 004f13a4  7404                 je 0x4f13aa
// 004f13a6  3bfe                 cmp edi, esi
// 004f13a8  7406                 je 0x4f13b0
// 004f13aa  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f13b0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004f13b4  3bdd                 cmp ebx, ebp
// 004f13b6  7559                 jne 0x4f1411
// 004f13b8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004f13bc  85c0                 test eax, eax
// 004f13be  8b6e04               mov ebp, dword ptr [esi + 4]
// 004f13c1  7404                 je 0x4f13c7
// 004f13c3  3bc6                 cmp eax, esi
// 004f13c5  7406                 je 0x4f13cd
// 004f13c7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f13cd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004f13d1  753e                 jne 0x4f1411
// 004f13d3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f13d6  8b5104               mov edx, dword ptr [ecx + 4]
// 004f13d9  52                   push edx
// 004f13da  8bce                 mov ecx, esi
// 004f13dc  e8dff3ffff           call 0x4f07c0
// 004f13e1  8b4604               mov eax, dword ptr [esi + 4]
// 004f13e4  894004               mov dword ptr [eax + 4], eax
// 004f13e7  8b4604               mov eax, dword ptr [esi + 4]
// 004f13ea  c7460800000000       mov dword ptr [esi + 8], 0
// 004f13f1  8900                 mov dword ptr [eax], eax
// 004f13f3  8b4604               mov eax, dword ptr [esi + 4]
// 004f13f6  894008               mov dword ptr [eax + 8], eax
// 004f13f9  8b4604               mov eax, dword ptr [esi + 4]
// 004f13fc  8b08                 mov ecx, dword ptr [eax]
// 004f13fe  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f1402  5f                   pop edi
// 004f1403  8930                 mov dword ptr [eax], esi
// 004f1405  5e                   pop esi
// 004f1406  5d                   pop ebp
// 004f1407  894804               mov dword ptr [eax + 4], ecx
// 004f140a  5b                   pop ebx
// 004f140b  83c408               add esp, 8
// 004f140e  c21400               ret 0x14
// 004f1411  85ff                 test edi, edi
// 004f1413  7406                 je 0x4f141b
// 004f1415  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004f1419  7406                 je 0x4f1421
// 004f141b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1421  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004f1425  7421                 je 0x4f1448
// 004f1427  8d4c2420             lea ecx, [esp + 0x20]
// 004f142b  e8807af4ff           call 0x438eb0
// 004f1430  53                   push ebx
// 004f1431  57                   push edi
// 004f1432  8d542418             lea edx, [esp + 0x18]
// 004f1436  52                   push edx
// 004f1437  8bce                 mov ecx, esi
// 004f1439  e852f5ffff           call 0x4f0990
// 004f143e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004f1442  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1446  ebc9                 jmp 0x4f1411
// 004f1448  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f144c  8938                 mov dword ptr [eax], edi
// 004f144e  5f                   pop edi
// 004f144f  5e                   pop esi
// 004f1450  5d                   pop ebp
// 004f1451  895804               mov dword ptr [eax + 4], ebx
// 004f1454  5b                   pop ebx
// 004f1455  83c408               add esp, 8
// 004f1458  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
