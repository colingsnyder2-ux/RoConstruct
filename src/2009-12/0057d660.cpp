// from server: 100% by auto
// roc 2009-12 0057d660  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d660
//
// 0057d660  53                   push ebx
// 0057d661  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0057d665  55                   push ebp
// 0057d666  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0057d66c  56                   push esi
// 0057d66d  57                   push edi
// 0057d66e  8bf9                 mov edi, ecx
// 0057d670  c70300000000         mov dword ptr [ebx], 0
// 0057d676  85ff                 test edi, edi
// 0057d678  740e                 je 0x57d688
// 0057d67a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0057d67e  39470c               cmp dword ptr [edi + 0xc], eax
// 0057d681  7705                 ja 0x57d688
// 0057d683  3b4710               cmp eax, dword ptr [edi + 0x10]
// 0057d686  7606                 jbe 0x57d68e
// 0057d688  ffd5                 call ebp
// 0057d68a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0057d68e  8b742424             mov esi, dword ptr [esp + 0x24]
// 0057d692  8b0f                 mov ecx, dword ptr [edi]
// 0057d694  890b                 mov dword ptr [ebx], ecx
// 0057d696  894304               mov dword ptr [ebx + 4], eax
// 0057d699  39770c               cmp dword ptr [edi + 0xc], esi
// 0057d69c  7705                 ja 0x57d6a3
// 0057d69e  3b7710               cmp esi, dword ptr [edi + 0x10]
// 0057d6a1  7606                 jbe 0x57d6a9
// 0057d6a3  ffd5                 call ebp
// 0057d6a5  8b742424             mov esi, dword ptr [esp + 0x24]
// 0057d6a9  8b03                 mov eax, dword ptr [ebx]
// 0057d6ab  8b0f                 mov ecx, dword ptr [edi]
// 0057d6ad  85c0                 test eax, eax
// 0057d6af  7404                 je 0x57d6b5
// 0057d6b1  3bc1                 cmp eax, ecx
// 0057d6b3  7402                 je 0x57d6b7
// 0057d6b5  ffd5                 call ebp
// 0057d6b7  8b5304               mov edx, dword ptr [ebx + 4]
// 0057d6ba  3bd6                 cmp edx, esi
// 0057d6bc  742b                 je 0x57d6e9
// 0057d6be  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0057d6c1  8bc1                 mov eax, ecx
// 0057d6c3  2bc6                 sub eax, esi
// 0057d6c5  c1f803               sar eax, 3
// 0057d6c8  8d2cc2               lea ebp, [edx + eax*8]
// 0057d6cb  8bc6                 mov eax, esi
// 0057d6cd  3bf1                 cmp esi, ecx
// 0057d6cf  7415                 je 0x57d6e6
// 0057d6d1  2bd6                 sub edx, esi
// 0057d6d3  8b30                 mov esi, dword ptr [eax]
// 0057d6d5  893402               mov dword ptr [edx + eax], esi
// 0057d6d8  8b7004               mov esi, dword ptr [eax + 4]
// 0057d6db  89740204             mov dword ptr [edx + eax + 4], esi
// 0057d6df  83c008               add eax, 8
// 0057d6e2  3bc1                 cmp eax, ecx
// 0057d6e4  75ed                 jne 0x57d6d3
// 0057d6e6  896f10               mov dword ptr [edi + 0x10], ebp
// 0057d6e9  5f                   pop edi
// 0057d6ea  5e                   pop esi
// 0057d6eb  5d                   pop ebp
// 0057d6ec  8bc3                 mov eax, ebx
// 0057d6ee  5b                   pop ebx
// 0057d6ef  c21400               ret 0x14
// standard library vector<pod8> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
