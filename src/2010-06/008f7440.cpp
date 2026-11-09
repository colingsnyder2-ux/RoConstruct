// from server: 100% by auto
// roc 2010-06 008f7440  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f7440
//
// 008f7440  83ec08               sub esp, 8
// 008f7443  53                   push ebx
// 008f7444  55                   push ebp
// 008f7445  56                   push esi
// 008f7446  8bf1                 mov esi, ecx
// 008f7448  8b4610               mov eax, dword ptr [esi + 0x10]
// 008f744b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008f744e  8bc8                 mov ecx, eax
// 008f7450  2bcb                 sub ecx, ebx
// 008f7452  57                   push edi
// 008f7453  f7c1e0ffffff         test ecx, 0xffffffe0
// 008f7459  7504                 jne 0x8f745f
// 008f745b  33ff                 xor edi, edi
// 008f745d  eb27                 jmp 0x8f7486
// 008f745f  3bd8                 cmp ebx, eax
// 008f7461  7606                 jbe 0x8f7469
// 008f7463  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f7469  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008f746d  8b06                 mov eax, dword ptr [esi]
// 008f746f  85c9                 test ecx, ecx
// 008f7471  7404                 je 0x8f7477
// 008f7473  3bc8                 cmp ecx, eax
// 008f7475  7406                 je 0x8f747d
// 008f7477  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f747d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008f7481  2bfb                 sub edi, ebx
// 008f7483  c1ff05               sar edi, 5
// 008f7486  8b542428             mov edx, dword ptr [esp + 0x28]
// 008f748a  8b442424             mov eax, dword ptr [esp + 0x24]
// 008f748e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008f7492  52                   push edx
// 008f7493  6a01                 push 1
// 008f7495  50                   push eax
// 008f7496  51                   push ecx
// 008f7497  8bce                 mov ecx, esi
// 008f7499  e812f4ffff           call 0x8f68b0
// 008f749e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008f74a1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008f74a4  7606                 jbe 0x8f74ac
// 008f74a6  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f74ac  8b36                 mov esi, dword ptr [esi]
// 008f74ae  8bee                 mov ebp, esi
// 008f74b0  895c2414             mov dword ptr [esp + 0x14], ebx
// 008f74b4  85f6                 test esi, esi
// 008f74b6  751a                 jne 0x8f74d2
// 008f74b8  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f74be  33c0                 xor eax, eax
// 008f74c0  c1e705               shl edi, 5
// 008f74c3  03fb                 add edi, ebx
// 008f74c5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008f74c8  7713                 ja 0x8f74dd
// 008f74ca  85f6                 test esi, esi
// 008f74cc  7408                 je 0x8f74d6
// 008f74ce  8b36                 mov esi, dword ptr [esi]
// 008f74d0  eb06                 jmp 0x8f74d8
// 008f74d2  8b06                 mov eax, dword ptr [esi]
// 008f74d4  ebea                 jmp 0x8f74c0
// 008f74d6  33f6                 xor esi, esi
// 008f74d8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008f74db  7306                 jae 0x8f74e3
// 008f74dd  ff150ca99e00         call dword ptr [0x9ea90c]
// 008f74e3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f74e7  897804               mov dword ptr [eax + 4], edi
// 008f74ea  5f                   pop edi
// 008f74eb  5e                   pop esi
// 008f74ec  8928                 mov dword ptr [eax], ebp
// 008f74ee  5d                   pop ebp
// 008f74ef  5b                   pop ebx
// 008f74f0  83c408               add esp, 8
// 008f74f3  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
