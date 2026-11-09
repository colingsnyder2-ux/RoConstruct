// from server: 100% by auto
// roc 2007-08 00576ad0  unit: RBX::PartInstance  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00576ad0
//
// 00576ad0  51                   push ecx
// 00576ad1  53                   push ebx
// 00576ad2  55                   push ebp
// 00576ad3  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00576ad7  56                   push esi
// 00576ad8  8bf1                 mov esi, ecx
// 00576ada  57                   push edi
// 00576adb  8b7e04               mov edi, dword ptr [esi + 4]
// 00576ade  85ff                 test edi, edi
// 00576ae0  740c                 je 0x576aee
// 00576ae2  8b4608               mov eax, dword ptr [esi + 8]
// 00576ae5  8bc8                 mov ecx, eax
// 00576ae7  2bcf                 sub ecx, edi
// 00576ae9  c1f903               sar ecx, 3
// 00576aec  7504                 jne 0x576af2
// 00576aee  33db                 xor ebx, ebx
// 00576af0  eb21                 jmp 0x576b13
// 00576af2  3bf8                 cmp edi, eax
// 00576af4  7606                 jbe 0x576afc
// 00576af6  ff15d8e67700         call dword ptr [0x77e6d8]
// 00576afc  85ed                 test ebp, ebp
// 00576afe  7404                 je 0x576b04
// 00576b00  3bee                 cmp ebp, esi
// 00576b02  7406                 je 0x576b0a
// 00576b04  ff15d8e67700         call dword ptr [0x77e6d8]
// 00576b0a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00576b0e  2bdf                 sub ebx, edi
// 00576b10  c1fb03               sar ebx, 3
// 00576b13  8b542424             mov edx, dword ptr [esp + 0x24]
// 00576b17  8b442420             mov eax, dword ptr [esp + 0x20]
// 00576b1b  52                   push edx
// 00576b1c  6a01                 push 1
// 00576b1e  50                   push eax
// 00576b1f  55                   push ebp
// 00576b20  8bce                 mov ecx, esi
// 00576b22  e879fcffff           call 0x5767a0
// 00576b27  8b7e04               mov edi, dword ptr [esi + 4]
// 00576b2a  3b7e08               cmp edi, dword ptr [esi + 8]
// 00576b2d  7606                 jbe 0x576b35
// 00576b2f  ff15d8e67700         call dword ptr [0x77e6d8]
// 00576b35  897c2420             mov dword ptr [esp + 0x20], edi
// 00576b39  8d3cdf               lea edi, [edi + ebx*8]
// 00576b3c  3b7e08               cmp edi, dword ptr [esi + 8]
// 00576b3f  7705                 ja 0x576b46
// 00576b41  3b7e04               cmp edi, dword ptr [esi + 4]
// 00576b44  7306                 jae 0x576b4c
// 00576b46  ff15d8e67700         call dword ptr [0x77e6d8]
// 00576b4c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00576b50  897804               mov dword ptr [eax + 4], edi
// 00576b53  5f                   pop edi
// 00576b54  8930                 mov dword ptr [eax], esi
// 00576b56  5e                   pop esi
// 00576b57  5d                   pop ebp
// 00576b58  5b                   pop ebx
// 00576b59  59                   pop ecx
// 00576b5a  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V32@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
