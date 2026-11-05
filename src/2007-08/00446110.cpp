// from server: 100% by auto
// roc 2007-08 00446110  unit: VCRenderSettings::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00446110
//
// 00446110  51                   push ecx
// 00446111  53                   push ebx
// 00446112  55                   push ebp
// 00446113  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00446117  56                   push esi
// 00446118  8bf1                 mov esi, ecx
// 0044611a  57                   push edi
// 0044611b  8b7e04               mov edi, dword ptr [esi + 4]
// 0044611e  85ff                 test edi, edi
// 00446120  740c                 je 0x44612e
// 00446122  8b4608               mov eax, dword ptr [esi + 8]
// 00446125  8bc8                 mov ecx, eax
// 00446127  2bcf                 sub ecx, edi
// 00446129  c1f902               sar ecx, 2
// 0044612c  7504                 jne 0x446132
// 0044612e  33db                 xor ebx, ebx
// 00446130  eb21                 jmp 0x446153
// 00446132  3bf8                 cmp edi, eax
// 00446134  7606                 jbe 0x44613c
// 00446136  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044613c  85ed                 test ebp, ebp
// 0044613e  7404                 je 0x446144
// 00446140  3bee                 cmp ebp, esi
// 00446142  7406                 je 0x44614a
// 00446144  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044614a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0044614e  2bdf                 sub ebx, edi
// 00446150  c1fb02               sar ebx, 2
// 00446153  8b542424             mov edx, dword ptr [esp + 0x24]
// 00446157  8b442420             mov eax, dword ptr [esp + 0x20]
// 0044615b  52                   push edx
// 0044615c  6a01                 push 1
// 0044615e  50                   push eax
// 0044615f  55                   push ebp
// 00446160  8bce                 mov ecx, esi
// 00446162  e859faffff           call 0x445bc0
// 00446167  8b7e04               mov edi, dword ptr [esi + 4]
// 0044616a  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044616d  7606                 jbe 0x446175
// 0044616f  ff15d8e67700         call dword ptr [0x77e6d8]
// 00446175  897c2420             mov dword ptr [esp + 0x20], edi
// 00446179  8d3c9f               lea edi, [edi + ebx*4]
// 0044617c  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044617f  7705                 ja 0x446186
// 00446181  3b7e04               cmp edi, dword ptr [esi + 4]
// 00446184  7306                 jae 0x44618c
// 00446186  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044618c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00446190  897804               mov dword ptr [eax + 4], edi
// 00446193  5f                   pop edi
// 00446194  8930                 mov dword ptr [eax], esi
// 00446196  5e                   pop esi
// 00446197  5d                   pop ebp
// 00446198  5b                   pop ebx
// 00446199  59                   pop ecx
// 0044619a  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
