// from server: 100% by auto
// roc 2010-06 0040e840  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040e840
//
// 0040e840  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040e844  85d2                 test edx, edx
// 0040e846  7406                 je 0x40e84e
// 0040e848  c70200000000         mov dword ptr [edx], 0
// 0040e84e  57                   push edi
// 0040e84f  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040e853  85ff                 test edi, edi
// 0040e855  7509                 jne 0x40e860
// 0040e857  b857000780           mov eax, 0x80070057
// 0040e85c  5f                   pop edi
// 0040e85d  c21000               ret 0x10
// 0040e860  56                   push esi
// 0040e861  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040e865  85f6                 test esi, esi
// 0040e867  0f8499000000         je 0x40e906
// 0040e86d  83ff01               cmp edi, 1
// 0040e870  7408                 je 0x40e87a
// 0040e872  85d2                 test edx, edx
// 0040e874  0f848c000000         je 0x40e906
// 0040e87a  53                   push ebx
// 0040e87b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040e87f  837b0800             cmp dword ptr [ebx + 8], 0
// 0040e883  7476                 je 0x40e8fb
// 0040e885  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0040e888  85c0                 test eax, eax
// 0040e88a  746f                 je 0x40e8fb
// 0040e88c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0040e88f  85c9                 test ecx, ecx
// 0040e891  7468                 je 0x40e8fb
// 0040e893  2bc1                 sub eax, ecx
// 0040e895  c1f802               sar eax, 2
// 0040e898  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0040e8a0  3bf8                 cmp edi, eax
// 0040e8a2  7608                 jbe 0x40e8ac
// 0040e8a4  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0040e8ac  7202                 jb 0x40e8b0
// 0040e8ae  8bf8                 mov edi, eax
// 0040e8b0  85d2                 test edx, edx
// 0040e8b2  7402                 je 0x40e8b6
// 0040e8b4  893a                 mov dword ptr [edx], edi
// 0040e8b6  85ff                 test edi, edi
// 0040e8b8  742d                 je 0x40e8e7
// 0040e8ba  8d9b00000000         lea ebx, [ebx]
// 0040e8c0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0040e8c3  4f                   dec edi
// 0040e8c4  85f6                 test esi, esi
// 0040e8c6  7429                 je 0x40e8f1
// 0040e8c8  85c0                 test eax, eax
// 0040e8ca  7425                 je 0x40e8f1
// 0040e8cc  8b00                 mov eax, dword ptr [eax]
// 0040e8ce  8906                 mov dword ptr [esi], eax
// 0040e8d0  85c0                 test eax, eax
// 0040e8d2  7408                 je 0x40e8dc
// 0040e8d4  8b08                 mov ecx, dword ptr [eax]
// 0040e8d6  8b5104               mov edx, dword ptr [ecx + 4]
// 0040e8d9  50                   push eax
// 0040e8da  ffd2                 call edx
// 0040e8dc  83431004             add dword ptr [ebx + 0x10], 4
// 0040e8e0  83c604               add esi, 4
// 0040e8e3  85ff                 test edi, edi
// 0040e8e5  75d9                 jne 0x40e8c0
// 0040e8e7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040e8eb  5b                   pop ebx
// 0040e8ec  5e                   pop esi
// 0040e8ed  5f                   pop edi
// 0040e8ee  c21000               ret 0x10
// 0040e8f1  6805400080           push 0x80004005
// 0040e8f6  e8d542ffff           call 0x402bd0
// 0040e8fb  5b                   pop ebx
// 0040e8fc  5e                   pop esi
// 0040e8fd  b805400080           mov eax, 0x80004005
// 0040e902  5f                   pop edi
// 0040e903  c21000               ret 0x10
// 0040e906  5e                   pop esi
// 0040e907  b803400080           mov eax, 0x80004003
// 0040e90c  5f                   pop edi
// 0040e90d  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?Next@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJKPAPAUIUnknown@@PAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
