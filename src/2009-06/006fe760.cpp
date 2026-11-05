// from server: 100% by auto
// roc 2009-06 006fe760  unit: RBX::AdornRbxGfx  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe760
//
// 006fe760  83ec08               sub esp, 8
// 006fe763  53                   push ebx
// 006fe764  55                   push ebp
// 006fe765  56                   push esi
// 006fe766  8bf1                 mov esi, ecx
// 006fe768  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fe76b  57                   push edi
// 006fe76c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006fe76f  8bc8                 mov ecx, eax
// 006fe771  2bcf                 sub ecx, edi
// 006fe773  f7c1fcffffff         test ecx, 0xfffffffc
// 006fe779  7504                 jne 0x6fe77f
// 006fe77b  33db                 xor ebx, ebx
// 006fe77d  eb27                 jmp 0x6fe7a6
// 006fe77f  3bf8                 cmp edi, eax
// 006fe781  7606                 jbe 0x6fe789
// 006fe783  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe789  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006fe78d  8b06                 mov eax, dword ptr [esi]
// 006fe78f  85c9                 test ecx, ecx
// 006fe791  7404                 je 0x6fe797
// 006fe793  3bc8                 cmp ecx, eax
// 006fe795  7406                 je 0x6fe79d
// 006fe797  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe79d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006fe7a1  2bdf                 sub ebx, edi
// 006fe7a3  c1fb02               sar ebx, 2
// 006fe7a6  8b542428             mov edx, dword ptr [esp + 0x28]
// 006fe7aa  8b442424             mov eax, dword ptr [esp + 0x24]
// 006fe7ae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006fe7b2  52                   push edx
// 006fe7b3  6a01                 push 1
// 006fe7b5  50                   push eax
// 006fe7b6  51                   push ecx
// 006fe7b7  8bce                 mov ecx, esi
// 006fe7b9  e8d2fbffff           call 0x6fe390
// 006fe7be  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006fe7c1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 006fe7c4  7606                 jbe 0x6fe7cc
// 006fe7c6  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe7cc  8b36                 mov esi, dword ptr [esi]
// 006fe7ce  8bee                 mov ebp, esi
// 006fe7d0  897c2414             mov dword ptr [esp + 0x14], edi
// 006fe7d4  85f6                 test esi, esi
// 006fe7d6  7518                 jne 0x6fe7f0
// 006fe7d8  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe7de  33c0                 xor eax, eax
// 006fe7e0  8d3c9f               lea edi, [edi + ebx*4]
// 006fe7e3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006fe7e6  7713                 ja 0x6fe7fb
// 006fe7e8  85f6                 test esi, esi
// 006fe7ea  7408                 je 0x6fe7f4
// 006fe7ec  8b36                 mov esi, dword ptr [esi]
// 006fe7ee  eb06                 jmp 0x6fe7f6
// 006fe7f0  8b06                 mov eax, dword ptr [esi]
// 006fe7f2  ebec                 jmp 0x6fe7e0
// 006fe7f4  33f6                 xor esi, esi
// 006fe7f6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006fe7f9  7306                 jae 0x6fe801
// 006fe7fb  ff15ace98900         call dword ptr [0x89e9ac]
// 006fe801  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe805  897804               mov dword ptr [eax + 4], edi
// 006fe808  5f                   pop edi
// 006fe809  5e                   pop esi
// 006fe80a  8928                 mov dword ptr [eax], ebp
// 006fe80c  5d                   pop ebp
// 006fe80d  5b                   pop ebx
// 006fe80e  83c408               add esp, 8
// 006fe811  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
