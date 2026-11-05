// from server: 100% by auto
// roc 2007-08 005cdf80  unit: RBX::BlockBlockContact  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cdf80
//
// 005cdf80  51                   push ecx
// 005cdf81  53                   push ebx
// 005cdf82  55                   push ebp
// 005cdf83  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005cdf87  56                   push esi
// 005cdf88  8bf1                 mov esi, ecx
// 005cdf8a  57                   push edi
// 005cdf8b  8b7e04               mov edi, dword ptr [esi + 4]
// 005cdf8e  85ff                 test edi, edi
// 005cdf90  740c                 je 0x5cdf9e
// 005cdf92  8b4608               mov eax, dword ptr [esi + 8]
// 005cdf95  8bc8                 mov ecx, eax
// 005cdf97  2bcf                 sub ecx, edi
// 005cdf99  c1f902               sar ecx, 2
// 005cdf9c  7504                 jne 0x5cdfa2
// 005cdf9e  33db                 xor ebx, ebx
// 005cdfa0  eb21                 jmp 0x5cdfc3
// 005cdfa2  3bf8                 cmp edi, eax
// 005cdfa4  7606                 jbe 0x5cdfac
// 005cdfa6  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdfac  85ed                 test ebp, ebp
// 005cdfae  7404                 je 0x5cdfb4
// 005cdfb0  3bee                 cmp ebp, esi
// 005cdfb2  7406                 je 0x5cdfba
// 005cdfb4  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdfba  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005cdfbe  2bdf                 sub ebx, edi
// 005cdfc0  c1fb02               sar ebx, 2
// 005cdfc3  8b542424             mov edx, dword ptr [esp + 0x24]
// 005cdfc7  8b442420             mov eax, dword ptr [esp + 0x20]
// 005cdfcb  52                   push edx
// 005cdfcc  6a01                 push 1
// 005cdfce  50                   push eax
// 005cdfcf  55                   push ebp
// 005cdfd0  8bce                 mov ecx, esi
// 005cdfd2  e829fdffff           call 0x5cdd00
// 005cdfd7  8b7e04               mov edi, dword ptr [esi + 4]
// 005cdfda  3b7e08               cmp edi, dword ptr [esi + 8]
// 005cdfdd  7606                 jbe 0x5cdfe5
// 005cdfdf  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdfe5  897c2420             mov dword ptr [esp + 0x20], edi
// 005cdfe9  8d3c9f               lea edi, [edi + ebx*4]
// 005cdfec  3b7e08               cmp edi, dword ptr [esi + 8]
// 005cdfef  7705                 ja 0x5cdff6
// 005cdff1  3b7e04               cmp edi, dword ptr [esi + 4]
// 005cdff4  7306                 jae 0x5cdffc
// 005cdff6  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdffc  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ce000  897804               mov dword ptr [eax + 4], edi
// 005ce003  5f                   pop edi
// 005ce004  8930                 mov dword ptr [eax], esi
// 005ce006  5e                   pop esi
// 005ce007  5d                   pop ebp
// 005ce008  5b                   pop ebx
// 005ce009  59                   pop ecx
// 005ce00a  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
