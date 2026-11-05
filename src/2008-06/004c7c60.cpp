// from server: 100% by auto
// roc 2008-06 004c7c60  unit: RBX::VInstance::?$Association::Item  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c7c60
//
// 004c7c60  83ec08               sub esp, 8
// 004c7c63  53                   push ebx
// 004c7c64  55                   push ebp
// 004c7c65  56                   push esi
// 004c7c66  8bf1                 mov esi, ecx
// 004c7c68  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c7c6b  57                   push edi
// 004c7c6c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004c7c6f  8bc8                 mov ecx, eax
// 004c7c71  2bcf                 sub ecx, edi
// 004c7c73  f7c1fcffffff         test ecx, 0xfffffffc
// 004c7c79  7504                 jne 0x4c7c7f
// 004c7c7b  33db                 xor ebx, ebx
// 004c7c7d  eb27                 jmp 0x4c7ca6
// 004c7c7f  3bf8                 cmp edi, eax
// 004c7c81  7606                 jbe 0x4c7c89
// 004c7c83  ff1590288000         call dword ptr [0x802890]
// 004c7c89  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c7c8d  8b06                 mov eax, dword ptr [esi]
// 004c7c8f  85c9                 test ecx, ecx
// 004c7c91  7404                 je 0x4c7c97
// 004c7c93  3bc8                 cmp ecx, eax
// 004c7c95  7406                 je 0x4c7c9d
// 004c7c97  ff1590288000         call dword ptr [0x802890]
// 004c7c9d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004c7ca1  2bdf                 sub ebx, edi
// 004c7ca3  c1fb02               sar ebx, 2
// 004c7ca6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004c7caa  8b442424             mov eax, dword ptr [esp + 0x24]
// 004c7cae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c7cb2  52                   push edx
// 004c7cb3  6a01                 push 1
// 004c7cb5  50                   push eax
// 004c7cb6  51                   push ecx
// 004c7cb7  8bce                 mov ecx, esi
// 004c7cb9  e8d2fbffff           call 0x4c7890
// 004c7cbe  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004c7cc1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004c7cc4  7606                 jbe 0x4c7ccc
// 004c7cc6  ff1590288000         call dword ptr [0x802890]
// 004c7ccc  8b36                 mov esi, dword ptr [esi]
// 004c7cce  8bee                 mov ebp, esi
// 004c7cd0  897c2414             mov dword ptr [esp + 0x14], edi
// 004c7cd4  85f6                 test esi, esi
// 004c7cd6  7518                 jne 0x4c7cf0
// 004c7cd8  ff1590288000         call dword ptr [0x802890]
// 004c7cde  33c0                 xor eax, eax
// 004c7ce0  8d3c9f               lea edi, [edi + ebx*4]
// 004c7ce3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004c7ce6  7713                 ja 0x4c7cfb
// 004c7ce8  85f6                 test esi, esi
// 004c7cea  7408                 je 0x4c7cf4
// 004c7cec  8b36                 mov esi, dword ptr [esi]
// 004c7cee  eb06                 jmp 0x4c7cf6
// 004c7cf0  8b06                 mov eax, dword ptr [esi]
// 004c7cf2  ebec                 jmp 0x4c7ce0
// 004c7cf4  33f6                 xor esi, esi
// 004c7cf6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004c7cf9  7306                 jae 0x4c7d01
// 004c7cfb  ff1590288000         call dword ptr [0x802890]
// 004c7d01  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c7d05  897804               mov dword ptr [eax + 4], edi
// 004c7d08  5f                   pop edi
// 004c7d09  5e                   pop esi
// 004c7d0a  8928                 mov dword ptr [eax], ebp
// 004c7d0c  5d                   pop ebp
// 004c7d0d  5b                   pop ebx
// 004c7d0e  83c408               add esp, 8
// 004c7d11  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
