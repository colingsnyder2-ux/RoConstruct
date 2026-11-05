// from server: 100% by auto
// roc 2009-06 007074a0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007074a0
//
// 007074a0  83ec08               sub esp, 8
// 007074a3  53                   push ebx
// 007074a4  55                   push ebp
// 007074a5  56                   push esi
// 007074a6  8bf1                 mov esi, ecx
// 007074a8  8b4610               mov eax, dword ptr [esi + 0x10]
// 007074ab  57                   push edi
// 007074ac  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007074af  8bc8                 mov ecx, eax
// 007074b1  2bcf                 sub ecx, edi
// 007074b3  f7c1fcffffff         test ecx, 0xfffffffc
// 007074b9  7504                 jne 0x7074bf
// 007074bb  33db                 xor ebx, ebx
// 007074bd  eb27                 jmp 0x7074e6
// 007074bf  3bf8                 cmp edi, eax
// 007074c1  7606                 jbe 0x7074c9
// 007074c3  ff15ace98900         call dword ptr [0x89e9ac]
// 007074c9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007074cd  8b06                 mov eax, dword ptr [esi]
// 007074cf  85c9                 test ecx, ecx
// 007074d1  7404                 je 0x7074d7
// 007074d3  3bc8                 cmp ecx, eax
// 007074d5  7406                 je 0x7074dd
// 007074d7  ff15ace98900         call dword ptr [0x89e9ac]
// 007074dd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007074e1  2bdf                 sub ebx, edi
// 007074e3  c1fb02               sar ebx, 2
// 007074e6  8b542428             mov edx, dword ptr [esp + 0x28]
// 007074ea  8b442424             mov eax, dword ptr [esp + 0x24]
// 007074ee  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007074f2  52                   push edx
// 007074f3  6a01                 push 1
// 007074f5  50                   push eax
// 007074f6  51                   push ecx
// 007074f7  8bce                 mov ecx, esi
// 007074f9  e812faffff           call 0x706f10
// 007074fe  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00707501  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00707504  7606                 jbe 0x70750c
// 00707506  ff15ace98900         call dword ptr [0x89e9ac]
// 0070750c  8b36                 mov esi, dword ptr [esi]
// 0070750e  8bee                 mov ebp, esi
// 00707510  897c2414             mov dword ptr [esp + 0x14], edi
// 00707514  85f6                 test esi, esi
// 00707516  7518                 jne 0x707530
// 00707518  ff15ace98900         call dword ptr [0x89e9ac]
// 0070751e  33c0                 xor eax, eax
// 00707520  8d3c9f               lea edi, [edi + ebx*4]
// 00707523  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00707526  7713                 ja 0x70753b
// 00707528  85f6                 test esi, esi
// 0070752a  7408                 je 0x707534
// 0070752c  8b36                 mov esi, dword ptr [esi]
// 0070752e  eb06                 jmp 0x707536
// 00707530  8b06                 mov eax, dword ptr [esi]
// 00707532  ebec                 jmp 0x707520
// 00707534  33f6                 xor esi, esi
// 00707536  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00707539  7306                 jae 0x707541
// 0070753b  ff15ace98900         call dword ptr [0x89e9ac]
// 00707541  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00707545  897804               mov dword ptr [eax + 4], edi
// 00707548  5f                   pop edi
// 00707549  5e                   pop esi
// 0070754a  8928                 mov dword ptr [eax], ebp
// 0070754c  5d                   pop ebp
// 0070754d  5b                   pop ebx
// 0070754e  83c408               add esp, 8
// 00707551  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
