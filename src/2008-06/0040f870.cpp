// from server: 100% by auto
// roc 2008-06 0040f870  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f870
//
// 0040f870  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040f874  85d2                 test edx, edx
// 0040f876  7406                 je 0x40f87e
// 0040f878  c70200000000         mov dword ptr [edx], 0
// 0040f87e  57                   push edi
// 0040f87f  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040f883  85ff                 test edi, edi
// 0040f885  7509                 jne 0x40f890
// 0040f887  b857000780           mov eax, 0x80070057
// 0040f88c  5f                   pop edi
// 0040f88d  c21000               ret 0x10
// 0040f890  56                   push esi
// 0040f891  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040f895  85f6                 test esi, esi
// 0040f897  0f8499000000         je 0x40f936
// 0040f89d  83ff01               cmp edi, 1
// 0040f8a0  7408                 je 0x40f8aa
// 0040f8a2  85d2                 test edx, edx
// 0040f8a4  0f848c000000         je 0x40f936
// 0040f8aa  53                   push ebx
// 0040f8ab  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040f8af  837b0800             cmp dword ptr [ebx + 8], 0
// 0040f8b3  7476                 je 0x40f92b
// 0040f8b5  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0040f8b8  85c0                 test eax, eax
// 0040f8ba  746f                 je 0x40f92b
// 0040f8bc  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0040f8bf  85c9                 test ecx, ecx
// 0040f8c1  7468                 je 0x40f92b
// 0040f8c3  2bc1                 sub eax, ecx
// 0040f8c5  c1f802               sar eax, 2
// 0040f8c8  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0040f8d0  3bf8                 cmp edi, eax
// 0040f8d2  7608                 jbe 0x40f8dc
// 0040f8d4  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0040f8dc  7202                 jb 0x40f8e0
// 0040f8de  8bf8                 mov edi, eax
// 0040f8e0  85d2                 test edx, edx
// 0040f8e2  7402                 je 0x40f8e6
// 0040f8e4  893a                 mov dword ptr [edx], edi
// 0040f8e6  85ff                 test edi, edi
// 0040f8e8  742d                 je 0x40f917
// 0040f8ea  8d9b00000000         lea ebx, [ebx]
// 0040f8f0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0040f8f3  4f                   dec edi
// 0040f8f4  85f6                 test esi, esi
// 0040f8f6  7429                 je 0x40f921
// 0040f8f8  85c0                 test eax, eax
// 0040f8fa  7425                 je 0x40f921
// 0040f8fc  8b00                 mov eax, dword ptr [eax]
// 0040f8fe  8906                 mov dword ptr [esi], eax
// 0040f900  85c0                 test eax, eax
// 0040f902  7408                 je 0x40f90c
// 0040f904  8b08                 mov ecx, dword ptr [eax]
// 0040f906  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f909  50                   push eax
// 0040f90a  ffd2                 call edx
// 0040f90c  83431004             add dword ptr [ebx + 0x10], 4
// 0040f910  83c604               add esi, 4
// 0040f913  85ff                 test edi, edi
// 0040f915  75d9                 jne 0x40f8f0
// 0040f917  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040f91b  5b                   pop ebx
// 0040f91c  5e                   pop esi
// 0040f91d  5f                   pop edi
// 0040f91e  c21000               ret 0x10
// 0040f921  6805400080           push 0x80004005
// 0040f926  e8d516ffff           call 0x401000
// 0040f92b  5b                   pop ebx
// 0040f92c  5e                   pop esi
// 0040f92d  b805400080           mov eax, 0x80004005
// 0040f932  5f                   pop edi
// 0040f933  c21000               ret 0x10
// 0040f936  5e                   pop esi
// 0040f937  b803400080           mov eax, 0x80004003
// 0040f93c  5f                   pop edi
// 0040f93d  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?Next@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJKPAPAUIUnknown@@PAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
