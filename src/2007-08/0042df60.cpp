// from server: 100% by auto
// roc 2007-08 0042df60  unit: boost::any::_N::?$holder  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042df60
//
// 0042df60  51                   push ecx
// 0042df61  53                   push ebx
// 0042df62  55                   push ebp
// 0042df63  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0042df67  56                   push esi
// 0042df68  8bf1                 mov esi, ecx
// 0042df6a  57                   push edi
// 0042df6b  8b7e04               mov edi, dword ptr [esi + 4]
// 0042df6e  85ff                 test edi, edi
// 0042df70  740c                 je 0x42df7e
// 0042df72  8b4608               mov eax, dword ptr [esi + 8]
// 0042df75  8bc8                 mov ecx, eax
// 0042df77  2bcf                 sub ecx, edi
// 0042df79  c1f903               sar ecx, 3
// 0042df7c  7504                 jne 0x42df82
// 0042df7e  33db                 xor ebx, ebx
// 0042df80  eb21                 jmp 0x42dfa3
// 0042df82  3bf8                 cmp edi, eax
// 0042df84  7606                 jbe 0x42df8c
// 0042df86  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042df8c  85ed                 test ebp, ebp
// 0042df8e  7404                 je 0x42df94
// 0042df90  3bee                 cmp ebp, esi
// 0042df92  7406                 je 0x42df9a
// 0042df94  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042df9a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0042df9e  2bdf                 sub ebx, edi
// 0042dfa0  c1fb03               sar ebx, 3
// 0042dfa3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0042dfa7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042dfab  52                   push edx
// 0042dfac  6a01                 push 1
// 0042dfae  50                   push eax
// 0042dfaf  55                   push ebp
// 0042dfb0  8bce                 mov ecx, esi
// 0042dfb2  e899fcffff           call 0x42dc50
// 0042dfb7  8b7e04               mov edi, dword ptr [esi + 4]
// 0042dfba  3b7e08               cmp edi, dword ptr [esi + 8]
// 0042dfbd  7606                 jbe 0x42dfc5
// 0042dfbf  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042dfc5  897c2420             mov dword ptr [esp + 0x20], edi
// 0042dfc9  8d3cdf               lea edi, [edi + ebx*8]
// 0042dfcc  3b7e08               cmp edi, dword ptr [esi + 8]
// 0042dfcf  7705                 ja 0x42dfd6
// 0042dfd1  3b7e04               cmp edi, dword ptr [esi + 4]
// 0042dfd4  7306                 jae 0x42dfdc
// 0042dfd6  ff15d8e67700         call dword ptr [0x77e6d8]
// 0042dfdc  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042dfe0  897804               mov dword ptr [eax + 4], edi
// 0042dfe3  5f                   pop edi
// 0042dfe4  8930                 mov dword ptr [eax], esi
// 0042dfe6  5e                   pop esi
// 0042dfe7  5d                   pop ebp
// 0042dfe8  5b                   pop ebx
// 0042dfe9  59                   pop ecx
// 0042dfea  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V32@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
