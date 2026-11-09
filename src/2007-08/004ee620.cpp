// from server: 100% by auto
// roc 2007-08 004ee620  unit: HeadBuilder  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ee620
//
// 004ee620  51                   push ecx
// 004ee621  53                   push ebx
// 004ee622  55                   push ebp
// 004ee623  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004ee627  56                   push esi
// 004ee628  8bf1                 mov esi, ecx
// 004ee62a  57                   push edi
// 004ee62b  8b7e04               mov edi, dword ptr [esi + 4]
// 004ee62e  85ff                 test edi, edi
// 004ee630  740c                 je 0x4ee63e
// 004ee632  8b4608               mov eax, dword ptr [esi + 8]
// 004ee635  8bc8                 mov ecx, eax
// 004ee637  2bcf                 sub ecx, edi
// 004ee639  c1f902               sar ecx, 2
// 004ee63c  7504                 jne 0x4ee642
// 004ee63e  33db                 xor ebx, ebx
// 004ee640  eb21                 jmp 0x4ee663
// 004ee642  3bf8                 cmp edi, eax
// 004ee644  7606                 jbe 0x4ee64c
// 004ee646  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ee64c  85ed                 test ebp, ebp
// 004ee64e  7404                 je 0x4ee654
// 004ee650  3bee                 cmp ebp, esi
// 004ee652  7406                 je 0x4ee65a
// 004ee654  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ee65a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004ee65e  2bdf                 sub ebx, edi
// 004ee660  c1fb02               sar ebx, 2
// 004ee663  8b542424             mov edx, dword ptr [esp + 0x24]
// 004ee667  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ee66b  52                   push edx
// 004ee66c  6a01                 push 1
// 004ee66e  50                   push eax
// 004ee66f  55                   push ebp
// 004ee670  8bce                 mov ecx, esi
// 004ee672  e87971f5ff           call 0x4457f0
// 004ee677  8b7e04               mov edi, dword ptr [esi + 4]
// 004ee67a  3b7e08               cmp edi, dword ptr [esi + 8]
// 004ee67d  7606                 jbe 0x4ee685
// 004ee67f  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ee685  897c2420             mov dword ptr [esp + 0x20], edi
// 004ee689  8d3c9f               lea edi, [edi + ebx*4]
// 004ee68c  3b7e08               cmp edi, dword ptr [esi + 8]
// 004ee68f  7705                 ja 0x4ee696
// 004ee691  3b7e04               cmp edi, dword ptr [esi + 4]
// 004ee694  7306                 jae 0x4ee69c
// 004ee696  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ee69c  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ee6a0  897804               mov dword ptr [eax + 4], edi
// 004ee6a3  5f                   pop edi
// 004ee6a4  8930                 mov dword ptr [eax], esi
// 004ee6a6  5e                   pop esi
// 004ee6a7  5d                   pop ebp
// 004ee6a8  5b                   pop ebx
// 004ee6a9  59                   pop ecx
// 004ee6aa  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
