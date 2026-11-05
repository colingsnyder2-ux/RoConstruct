// from server: 100% by auto
// roc 2007-08 00423420  unit: CSelectionTreeCtrl  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00423420
//
// 00423420  51                   push ecx
// 00423421  53                   push ebx
// 00423422  55                   push ebp
// 00423423  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00423427  56                   push esi
// 00423428  8bf1                 mov esi, ecx
// 0042342a  57                   push edi
// 0042342b  8b7e04               mov edi, dword ptr [esi + 4]
// 0042342e  85ff                 test edi, edi
// 00423430  740c                 je 0x42343e
// 00423432  8b4608               mov eax, dword ptr [esi + 8]
// 00423435  8bc8                 mov ecx, eax
// 00423437  2bcf                 sub ecx, edi
// 00423439  c1f903               sar ecx, 3
// 0042343c  7504                 jne 0x423442
// 0042343e  33db                 xor ebx, ebx
// 00423440  eb21                 jmp 0x423463
// 00423442  3bf8                 cmp edi, eax
// 00423444  7606                 jbe 0x42344c
// 00423446  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042344c  85ed                 test ebp, ebp
// 0042344e  7404                 je 0x423454
// 00423450  3bee                 cmp ebp, esi
// 00423452  7406                 je 0x42345a
// 00423454  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042345a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0042345e  2bdf                 sub ebx, edi
// 00423460  c1fb03               sar ebx, 3
// 00423463  8b542424             mov edx, dword ptr [esp + 0x24]
// 00423467  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042346b  52                   push edx
// 0042346c  6a01                 push 1
// 0042346e  50                   push eax
// 0042346f  55                   push ebp
// 00423470  8bce                 mov ecx, esi
// 00423472  e809a8feff           call 0x40dc80
// 00423477  8b7e04               mov edi, dword ptr [esi + 4]
// 0042347a  3b7e08               cmp edi, dword ptr [esi + 8]
// 0042347d  7606                 jbe 0x423485
// 0042347f  ff15d8e67700         call dword ptr [0x77e6d8]
// 00423485  897c2420             mov dword ptr [esp + 0x20], edi
// 00423489  8d3cdf               lea edi, [edi + ebx*8]
// 0042348c  3b7e08               cmp edi, dword ptr [esi + 8]
// 0042348f  7705                 ja 0x423496
// 00423491  3b7e04               cmp edi, dword ptr [esi + 4]
// 00423494  7306                 jae 0x42349c
// 00423496  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042349c  8b442418             mov eax, dword ptr [esp + 0x18]
// 004234a0  897804               mov dword ptr [eax + 4], edi
// 004234a3  5f                   pop edi
// 004234a4  8930                 mov dword ptr [eax], esi
// 004234a6  5e                   pop esi
// 004234a7  5d                   pop ebp
// 004234a8  5b                   pop ebx
// 004234a9  59                   pop ecx
// 004234aa  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V32@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
