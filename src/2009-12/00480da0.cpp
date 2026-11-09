// from server: 100% by auto
// roc 2009-12 00480da0  unit: RBX::AdornRbxGfx  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480da0
//
// 00480da0  83ec08               sub esp, 8
// 00480da3  53                   push ebx
// 00480da4  55                   push ebp
// 00480da5  56                   push esi
// 00480da6  8bf1                 mov esi, ecx
// 00480da8  8b4610               mov eax, dword ptr [esi + 0x10]
// 00480dab  57                   push edi
// 00480dac  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00480daf  8bc8                 mov ecx, eax
// 00480db1  2bcf                 sub ecx, edi
// 00480db3  f7c1fcffffff         test ecx, 0xfffffffc
// 00480db9  7504                 jne 0x480dbf
// 00480dbb  33db                 xor ebx, ebx
// 00480dbd  eb27                 jmp 0x480de6
// 00480dbf  3bf8                 cmp edi, eax
// 00480dc1  7606                 jbe 0x480dc9
// 00480dc3  ff1560b79800         call dword ptr [0x98b760]
// 00480dc9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00480dcd  8b06                 mov eax, dword ptr [esi]
// 00480dcf  85c9                 test ecx, ecx
// 00480dd1  7404                 je 0x480dd7
// 00480dd3  3bc8                 cmp ecx, eax
// 00480dd5  7406                 je 0x480ddd
// 00480dd7  ff1560b79800         call dword ptr [0x98b760]
// 00480ddd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00480de1  2bdf                 sub ebx, edi
// 00480de3  c1fb02               sar ebx, 2
// 00480de6  8b542428             mov edx, dword ptr [esp + 0x28]
// 00480dea  8b442424             mov eax, dword ptr [esp + 0x24]
// 00480dee  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00480df2  52                   push edx
// 00480df3  6a01                 push 1
// 00480df5  50                   push eax
// 00480df6  51                   push ecx
// 00480df7  8bce                 mov ecx, esi
// 00480df9  e882fcffff           call 0x480a80
// 00480dfe  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00480e01  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00480e04  7606                 jbe 0x480e0c
// 00480e06  ff1560b79800         call dword ptr [0x98b760]
// 00480e0c  8b36                 mov esi, dword ptr [esi]
// 00480e0e  8bee                 mov ebp, esi
// 00480e10  897c2414             mov dword ptr [esp + 0x14], edi
// 00480e14  85f6                 test esi, esi
// 00480e16  7518                 jne 0x480e30
// 00480e18  ff1560b79800         call dword ptr [0x98b760]
// 00480e1e  33c0                 xor eax, eax
// 00480e20  8d3c9f               lea edi, [edi + ebx*4]
// 00480e23  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00480e26  7713                 ja 0x480e3b
// 00480e28  85f6                 test esi, esi
// 00480e2a  7408                 je 0x480e34
// 00480e2c  8b36                 mov esi, dword ptr [esi]
// 00480e2e  eb06                 jmp 0x480e36
// 00480e30  8b06                 mov eax, dword ptr [esi]
// 00480e32  ebec                 jmp 0x480e20
// 00480e34  33f6                 xor esi, esi
// 00480e36  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00480e39  7306                 jae 0x480e41
// 00480e3b  ff1560b79800         call dword ptr [0x98b760]
// 00480e41  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00480e45  897804               mov dword ptr [eax + 4], edi
// 00480e48  5f                   pop edi
// 00480e49  5e                   pop esi
// 00480e4a  8928                 mov dword ptr [eax], ebp
// 00480e4c  5d                   pop ebp
// 00480e4d  5b                   pop ebx
// 00480e4e  83c408               add esp, 8
// 00480e51  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
