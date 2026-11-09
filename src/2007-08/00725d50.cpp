// from server: 100% by auto
// roc 2007-08 00725d50  unit: boost::thread_resource_error  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00725d50
//
// 00725d50  51                   push ecx
// 00725d51  53                   push ebx
// 00725d52  55                   push ebp
// 00725d53  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00725d57  56                   push esi
// 00725d58  8bf1                 mov esi, ecx
// 00725d5a  57                   push edi
// 00725d5b  8b7e04               mov edi, dword ptr [esi + 4]
// 00725d5e  85ff                 test edi, edi
// 00725d60  740c                 je 0x725d6e
// 00725d62  8b4608               mov eax, dword ptr [esi + 8]
// 00725d65  8bc8                 mov ecx, eax
// 00725d67  2bcf                 sub ecx, edi
// 00725d69  c1f902               sar ecx, 2
// 00725d6c  7504                 jne 0x725d72
// 00725d6e  33db                 xor ebx, ebx
// 00725d70  eb21                 jmp 0x725d93
// 00725d72  3bf8                 cmp edi, eax
// 00725d74  7606                 jbe 0x725d7c
// 00725d76  ff15d8e67700         call dword ptr [0x77e6d8]
// 00725d7c  85ed                 test ebp, ebp
// 00725d7e  7404                 je 0x725d84
// 00725d80  3bee                 cmp ebp, esi
// 00725d82  7406                 je 0x725d8a
// 00725d84  ff15d8e67700         call dword ptr [0x77e6d8]
// 00725d8a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00725d8e  2bdf                 sub ebx, edi
// 00725d90  c1fb02               sar ebx, 2
// 00725d93  8b542424             mov edx, dword ptr [esp + 0x24]
// 00725d97  8b442420             mov eax, dword ptr [esp + 0x20]
// 00725d9b  52                   push edx
// 00725d9c  6a01                 push 1
// 00725d9e  50                   push eax
// 00725d9f  55                   push ebp
// 00725da0  8bce                 mov ecx, esi
// 00725da2  e869fdffff           call 0x725b10
// 00725da7  8b7e04               mov edi, dword ptr [esi + 4]
// 00725daa  3b7e08               cmp edi, dword ptr [esi + 8]
// 00725dad  7606                 jbe 0x725db5
// 00725daf  ff15d8e67700         call dword ptr [0x77e6d8]
// 00725db5  897c2420             mov dword ptr [esp + 0x20], edi
// 00725db9  8d3c9f               lea edi, [edi + ebx*4]
// 00725dbc  3b7e08               cmp edi, dword ptr [esi + 8]
// 00725dbf  7705                 ja 0x725dc6
// 00725dc1  3b7e04               cmp edi, dword ptr [esi + 4]
// 00725dc4  7306                 jae 0x725dcc
// 00725dc6  ff15d8e67700         call dword ptr [0x77e6d8]
// 00725dcc  8b442418             mov eax, dword ptr [esp + 0x18]
// 00725dd0  897804               mov dword ptr [eax + 4], edi
// 00725dd3  5f                   pop edi
// 00725dd4  8930                 mov dword ptr [eax], esi
// 00725dd6  5e                   pop esi
// 00725dd7  5d                   pop ebp
// 00725dd8  5b                   pop ebx
// 00725dd9  59                   pop ecx
// 00725dda  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
