// from server: 100% by auto
// roc 2009-06 0040e690  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040e690
//
// 0040e690  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040e694  85d2                 test edx, edx
// 0040e696  7406                 je 0x40e69e
// 0040e698  c70200000000         mov dword ptr [edx], 0
// 0040e69e  57                   push edi
// 0040e69f  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040e6a3  85ff                 test edi, edi
// 0040e6a5  7509                 jne 0x40e6b0
// 0040e6a7  b857000780           mov eax, 0x80070057
// 0040e6ac  5f                   pop edi
// 0040e6ad  c21000               ret 0x10
// 0040e6b0  56                   push esi
// 0040e6b1  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040e6b5  85f6                 test esi, esi
// 0040e6b7  0f8499000000         je 0x40e756
// 0040e6bd  83ff01               cmp edi, 1
// 0040e6c0  7408                 je 0x40e6ca
// 0040e6c2  85d2                 test edx, edx
// 0040e6c4  0f848c000000         je 0x40e756
// 0040e6ca  53                   push ebx
// 0040e6cb  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040e6cf  837b0800             cmp dword ptr [ebx + 8], 0
// 0040e6d3  7476                 je 0x40e74b
// 0040e6d5  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0040e6d8  85c0                 test eax, eax
// 0040e6da  746f                 je 0x40e74b
// 0040e6dc  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0040e6df  85c9                 test ecx, ecx
// 0040e6e1  7468                 je 0x40e74b
// 0040e6e3  2bc1                 sub eax, ecx
// 0040e6e5  c1f802               sar eax, 2
// 0040e6e8  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0040e6f0  3bf8                 cmp edi, eax
// 0040e6f2  7608                 jbe 0x40e6fc
// 0040e6f4  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0040e6fc  7202                 jb 0x40e700
// 0040e6fe  8bf8                 mov edi, eax
// 0040e700  85d2                 test edx, edx
// 0040e702  7402                 je 0x40e706
// 0040e704  893a                 mov dword ptr [edx], edi
// 0040e706  85ff                 test edi, edi
// 0040e708  742d                 je 0x40e737
// 0040e70a  8d9b00000000         lea ebx, [ebx]
// 0040e710  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0040e713  4f                   dec edi
// 0040e714  85f6                 test esi, esi
// 0040e716  7429                 je 0x40e741
// 0040e718  85c0                 test eax, eax
// 0040e71a  7425                 je 0x40e741
// 0040e71c  8b00                 mov eax, dword ptr [eax]
// 0040e71e  8906                 mov dword ptr [esi], eax
// 0040e720  85c0                 test eax, eax
// 0040e722  7408                 je 0x40e72c
// 0040e724  8b08                 mov ecx, dword ptr [eax]
// 0040e726  8b5104               mov edx, dword ptr [ecx + 4]
// 0040e729  50                   push eax
// 0040e72a  ffd2                 call edx
// 0040e72c  83431004             add dword ptr [ebx + 0x10], 4
// 0040e730  83c604               add esi, 4
// 0040e733  85ff                 test edi, edi
// 0040e735  75d9                 jne 0x40e710
// 0040e737  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040e73b  5b                   pop ebx
// 0040e73c  5e                   pop esi
// 0040e73d  5f                   pop edi
// 0040e73e  c21000               ret 0x10
// 0040e741  6805400080           push 0x80004005
// 0040e746  e86547ffff           call 0x402eb0
// 0040e74b  5b                   pop ebx
// 0040e74c  5e                   pop esi
// 0040e74d  b805400080           mov eax, 0x80004005
// 0040e752  5f                   pop edi
// 0040e753  c21000               ret 0x10
// 0040e756  5e                   pop esi
// 0040e757  b803400080           mov eax, 0x80004003
// 0040e75c  5f                   pop edi
// 0040e75d  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?Next@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJKPAPAUIUnknown@@PAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
