// from server: 100% by auto
// roc 2009-12 007e3d20  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e3d20
//
// 007e3d20  83ec08               sub esp, 8
// 007e3d23  53                   push ebx
// 007e3d24  55                   push ebp
// 007e3d25  56                   push esi
// 007e3d26  8bf1                 mov esi, ecx
// 007e3d28  8b4610               mov eax, dword ptr [esi + 0x10]
// 007e3d2b  57                   push edi
// 007e3d2c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007e3d2f  8bc8                 mov ecx, eax
// 007e3d31  2bcf                 sub ecx, edi
// 007e3d33  f7c1fcffffff         test ecx, 0xfffffffc
// 007e3d39  7504                 jne 0x7e3d3f
// 007e3d3b  33db                 xor ebx, ebx
// 007e3d3d  eb27                 jmp 0x7e3d66
// 007e3d3f  3bf8                 cmp edi, eax
// 007e3d41  7606                 jbe 0x7e3d49
// 007e3d43  ff1560b79800         call dword ptr [0x98b760]
// 007e3d49  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007e3d4d  8b06                 mov eax, dword ptr [esi]
// 007e3d4f  85c9                 test ecx, ecx
// 007e3d51  7404                 je 0x7e3d57
// 007e3d53  3bc8                 cmp ecx, eax
// 007e3d55  7406                 je 0x7e3d5d
// 007e3d57  ff1560b79800         call dword ptr [0x98b760]
// 007e3d5d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007e3d61  2bdf                 sub ebx, edi
// 007e3d63  c1fb02               sar ebx, 2
// 007e3d66  8b542428             mov edx, dword ptr [esp + 0x28]
// 007e3d6a  8b442424             mov eax, dword ptr [esp + 0x24]
// 007e3d6e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007e3d72  52                   push edx
// 007e3d73  6a01                 push 1
// 007e3d75  50                   push eax
// 007e3d76  51                   push ecx
// 007e3d77  8bce                 mov ecx, esi
// 007e3d79  e812faffff           call 0x7e3790
// 007e3d7e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007e3d81  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007e3d84  7606                 jbe 0x7e3d8c
// 007e3d86  ff1560b79800         call dword ptr [0x98b760]
// 007e3d8c  8b36                 mov esi, dword ptr [esi]
// 007e3d8e  8bee                 mov ebp, esi
// 007e3d90  897c2414             mov dword ptr [esp + 0x14], edi
// 007e3d94  85f6                 test esi, esi
// 007e3d96  7518                 jne 0x7e3db0
// 007e3d98  ff1560b79800         call dword ptr [0x98b760]
// 007e3d9e  33c0                 xor eax, eax
// 007e3da0  8d3c9f               lea edi, [edi + ebx*4]
// 007e3da3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007e3da6  7713                 ja 0x7e3dbb
// 007e3da8  85f6                 test esi, esi
// 007e3daa  7408                 je 0x7e3db4
// 007e3dac  8b36                 mov esi, dword ptr [esi]
// 007e3dae  eb06                 jmp 0x7e3db6
// 007e3db0  8b06                 mov eax, dword ptr [esi]
// 007e3db2  ebec                 jmp 0x7e3da0
// 007e3db4  33f6                 xor esi, esi
// 007e3db6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007e3db9  7306                 jae 0x7e3dc1
// 007e3dbb  ff1560b79800         call dword ptr [0x98b760]
// 007e3dc1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e3dc5  897804               mov dword ptr [eax + 4], edi
// 007e3dc8  5f                   pop edi
// 007e3dc9  5e                   pop esi
// 007e3dca  8928                 mov dword ptr [eax], ebp
// 007e3dcc  5d                   pop ebp
// 007e3dcd  5b                   pop ebx
// 007e3dce  83c408               add esp, 8
// 007e3dd1  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
