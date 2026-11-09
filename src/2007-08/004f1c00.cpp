// from server: 100% by auto
// roc 2007-08 004f1c00  unit: RBX::Render::AggregatingSceneManager  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f1c00
//
// 004f1c00  51                   push ecx
// 004f1c01  53                   push ebx
// 004f1c02  55                   push ebp
// 004f1c03  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004f1c07  56                   push esi
// 004f1c08  8bf1                 mov esi, ecx
// 004f1c0a  57                   push edi
// 004f1c0b  8b7e04               mov edi, dword ptr [esi + 4]
// 004f1c0e  85ff                 test edi, edi
// 004f1c10  740c                 je 0x4f1c1e
// 004f1c12  8b4608               mov eax, dword ptr [esi + 8]
// 004f1c15  8bc8                 mov ecx, eax
// 004f1c17  2bcf                 sub ecx, edi
// 004f1c19  c1f902               sar ecx, 2
// 004f1c1c  7504                 jne 0x4f1c22
// 004f1c1e  33db                 xor ebx, ebx
// 004f1c20  eb21                 jmp 0x4f1c43
// 004f1c22  3bf8                 cmp edi, eax
// 004f1c24  7606                 jbe 0x4f1c2c
// 004f1c26  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1c2c  85ed                 test ebp, ebp
// 004f1c2e  7404                 je 0x4f1c34
// 004f1c30  3bee                 cmp ebp, esi
// 004f1c32  7406                 je 0x4f1c3a
// 004f1c34  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1c3a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004f1c3e  2bdf                 sub ebx, edi
// 004f1c40  c1fb02               sar ebx, 2
// 004f1c43  8b542424             mov edx, dword ptr [esp + 0x24]
// 004f1c47  8b442420             mov eax, dword ptr [esp + 0x20]
// 004f1c4b  52                   push edx
// 004f1c4c  6a01                 push 1
// 004f1c4e  50                   push eax
// 004f1c4f  55                   push ebp
// 004f1c50  8bce                 mov ecx, esi
// 004f1c52  e809f8ffff           call 0x4f1460
// 004f1c57  8b7e04               mov edi, dword ptr [esi + 4]
// 004f1c5a  3b7e08               cmp edi, dword ptr [esi + 8]
// 004f1c5d  7606                 jbe 0x4f1c65
// 004f1c5f  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1c65  897c2420             mov dword ptr [esp + 0x20], edi
// 004f1c69  8d3c9f               lea edi, [edi + ebx*4]
// 004f1c6c  3b7e08               cmp edi, dword ptr [esi + 8]
// 004f1c6f  7705                 ja 0x4f1c76
// 004f1c71  3b7e04               cmp edi, dword ptr [esi + 4]
// 004f1c74  7306                 jae 0x4f1c7c
// 004f1c76  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1c7c  8b442418             mov eax, dword ptr [esp + 0x18]
// 004f1c80  897804               mov dword ptr [eax + 4], edi
// 004f1c83  5f                   pop edi
// 004f1c84  8930                 mov dword ptr [eax], esi
// 004f1c86  5e                   pop esi
// 004f1c87  5d                   pop ebp
// 004f1c88  5b                   pop ebx
// 004f1c89  59                   pop ecx
// 004f1c8a  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
