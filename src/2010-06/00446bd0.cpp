// from server: 100% by auto
// roc 2010-06 00446bd0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446bd0
//
// 00446bd0  83ec08               sub esp, 8
// 00446bd3  53                   push ebx
// 00446bd4  55                   push ebp
// 00446bd5  56                   push esi
// 00446bd6  8bf1                 mov esi, ecx
// 00446bd8  8b4610               mov eax, dword ptr [esi + 0x10]
// 00446bdb  57                   push edi
// 00446bdc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00446bdf  8bc8                 mov ecx, eax
// 00446be1  2bcf                 sub ecx, edi
// 00446be3  f7c1fcffffff         test ecx, 0xfffffffc
// 00446be9  7504                 jne 0x446bef
// 00446beb  33db                 xor ebx, ebx
// 00446bed  eb27                 jmp 0x446c16
// 00446bef  3bf8                 cmp edi, eax
// 00446bf1  7606                 jbe 0x446bf9
// 00446bf3  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446bf9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00446bfd  8b06                 mov eax, dword ptr [esi]
// 00446bff  85c9                 test ecx, ecx
// 00446c01  7404                 je 0x446c07
// 00446c03  3bc8                 cmp ecx, eax
// 00446c05  7406                 je 0x446c0d
// 00446c07  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446c0d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00446c11  2bdf                 sub ebx, edi
// 00446c13  c1fb02               sar ebx, 2
// 00446c16  8b542428             mov edx, dword ptr [esp + 0x28]
// 00446c1a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00446c1e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00446c22  52                   push edx
// 00446c23  6a01                 push 1
// 00446c25  50                   push eax
// 00446c26  51                   push ecx
// 00446c27  8bce                 mov ecx, esi
// 00446c29  e892faffff           call 0x4466c0
// 00446c2e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00446c31  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00446c34  7606                 jbe 0x446c3c
// 00446c36  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446c3c  8b36                 mov esi, dword ptr [esi]
// 00446c3e  8bee                 mov ebp, esi
// 00446c40  897c2414             mov dword ptr [esp + 0x14], edi
// 00446c44  85f6                 test esi, esi
// 00446c46  7518                 jne 0x446c60
// 00446c48  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446c4e  33c0                 xor eax, eax
// 00446c50  8d3c9f               lea edi, [edi + ebx*4]
// 00446c53  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00446c56  7713                 ja 0x446c6b
// 00446c58  85f6                 test esi, esi
// 00446c5a  7408                 je 0x446c64
// 00446c5c  8b36                 mov esi, dword ptr [esi]
// 00446c5e  eb06                 jmp 0x446c66
// 00446c60  8b06                 mov eax, dword ptr [esi]
// 00446c62  ebec                 jmp 0x446c50
// 00446c64  33f6                 xor esi, esi
// 00446c66  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00446c69  7306                 jae 0x446c71
// 00446c6b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446c71  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00446c75  897804               mov dword ptr [eax + 4], edi
// 00446c78  5f                   pop edi
// 00446c79  5e                   pop esi
// 00446c7a  8928                 mov dword ptr [eax], ebp
// 00446c7c  5d                   pop ebp
// 00446c7d  5b                   pop ebx
// 00446c7e  83c408               add esp, 8
// 00446c81  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
