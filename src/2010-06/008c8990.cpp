// from server: 100% by auto
// roc 2010-06 008c8990  unit: RBX::AdornRbxGfx  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c8990
//
// 008c8990  83ec08               sub esp, 8
// 008c8993  53                   push ebx
// 008c8994  55                   push ebp
// 008c8995  56                   push esi
// 008c8996  8bf1                 mov esi, ecx
// 008c8998  8b4610               mov eax, dword ptr [esi + 0x10]
// 008c899b  57                   push edi
// 008c899c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008c899f  8bc8                 mov ecx, eax
// 008c89a1  2bcf                 sub ecx, edi
// 008c89a3  f7c1fcffffff         test ecx, 0xfffffffc
// 008c89a9  7504                 jne 0x8c89af
// 008c89ab  33db                 xor ebx, ebx
// 008c89ad  eb27                 jmp 0x8c89d6
// 008c89af  3bf8                 cmp edi, eax
// 008c89b1  7606                 jbe 0x8c89b9
// 008c89b3  ff150ca99e00         call dword ptr [0x9ea90c]
// 008c89b9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008c89bd  8b06                 mov eax, dword ptr [esi]
// 008c89bf  85c9                 test ecx, ecx
// 008c89c1  7404                 je 0x8c89c7
// 008c89c3  3bc8                 cmp ecx, eax
// 008c89c5  7406                 je 0x8c89cd
// 008c89c7  ff150ca99e00         call dword ptr [0x9ea90c]
// 008c89cd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008c89d1  2bdf                 sub ebx, edi
// 008c89d3  c1fb02               sar ebx, 2
// 008c89d6  8b542428             mov edx, dword ptr [esp + 0x28]
// 008c89da  8b442424             mov eax, dword ptr [esp + 0x24]
// 008c89de  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008c89e2  52                   push edx
// 008c89e3  6a01                 push 1
// 008c89e5  50                   push eax
// 008c89e6  51                   push ecx
// 008c89e7  8bce                 mov ecx, esi
// 008c89e9  e882fcffff           call 0x8c8670
// 008c89ee  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008c89f1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008c89f4  7606                 jbe 0x8c89fc
// 008c89f6  ff150ca99e00         call dword ptr [0x9ea90c]
// 008c89fc  8b36                 mov esi, dword ptr [esi]
// 008c89fe  8bee                 mov ebp, esi
// 008c8a00  897c2414             mov dword ptr [esp + 0x14], edi
// 008c8a04  85f6                 test esi, esi
// 008c8a06  7518                 jne 0x8c8a20
// 008c8a08  ff150ca99e00         call dword ptr [0x9ea90c]
// 008c8a0e  33c0                 xor eax, eax
// 008c8a10  8d3c9f               lea edi, [edi + ebx*4]
// 008c8a13  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008c8a16  7713                 ja 0x8c8a2b
// 008c8a18  85f6                 test esi, esi
// 008c8a1a  7408                 je 0x8c8a24
// 008c8a1c  8b36                 mov esi, dword ptr [esi]
// 008c8a1e  eb06                 jmp 0x8c8a26
// 008c8a20  8b06                 mov eax, dword ptr [esi]
// 008c8a22  ebec                 jmp 0x8c8a10
// 008c8a24  33f6                 xor esi, esi
// 008c8a26  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008c8a29  7306                 jae 0x8c8a31
// 008c8a2b  ff150ca99e00         call dword ptr [0x9ea90c]
// 008c8a31  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008c8a35  897804               mov dword ptr [eax + 4], edi
// 008c8a38  5f                   pop edi
// 008c8a39  5e                   pop esi
// 008c8a3a  8928                 mov dword ptr [eax], ebp
// 008c8a3c  5d                   pop ebp
// 008c8a3d  5b                   pop ebx
// 008c8a3e  83c408               add esp, 8
// 008c8a41  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
