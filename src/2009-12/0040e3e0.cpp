// from server: 100% by auto
// roc 2009-12 0040e3e0  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040e3e0
//
// 0040e3e0  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040e3e4  85d2                 test edx, edx
// 0040e3e6  7406                 je 0x40e3ee
// 0040e3e8  c70200000000         mov dword ptr [edx], 0
// 0040e3ee  57                   push edi
// 0040e3ef  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040e3f3  85ff                 test edi, edi
// 0040e3f5  7509                 jne 0x40e400
// 0040e3f7  b857000780           mov eax, 0x80070057
// 0040e3fc  5f                   pop edi
// 0040e3fd  c21000               ret 0x10
// 0040e400  56                   push esi
// 0040e401  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040e405  85f6                 test esi, esi
// 0040e407  0f8499000000         je 0x40e4a6
// 0040e40d  83ff01               cmp edi, 1
// 0040e410  7408                 je 0x40e41a
// 0040e412  85d2                 test edx, edx
// 0040e414  0f848c000000         je 0x40e4a6
// 0040e41a  53                   push ebx
// 0040e41b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0040e41f  837b0800             cmp dword ptr [ebx + 8], 0
// 0040e423  7476                 je 0x40e49b
// 0040e425  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0040e428  85c0                 test eax, eax
// 0040e42a  746f                 je 0x40e49b
// 0040e42c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0040e42f  85c9                 test ecx, ecx
// 0040e431  7468                 je 0x40e49b
// 0040e433  2bc1                 sub eax, ecx
// 0040e435  c1f802               sar eax, 2
// 0040e438  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0040e440  3bf8                 cmp edi, eax
// 0040e442  7608                 jbe 0x40e44c
// 0040e444  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0040e44c  7202                 jb 0x40e450
// 0040e44e  8bf8                 mov edi, eax
// 0040e450  85d2                 test edx, edx
// 0040e452  7402                 je 0x40e456
// 0040e454  893a                 mov dword ptr [edx], edi
// 0040e456  85ff                 test edi, edi
// 0040e458  742d                 je 0x40e487
// 0040e45a  8d9b00000000         lea ebx, [ebx]
// 0040e460  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0040e463  4f                   dec edi
// 0040e464  85f6                 test esi, esi
// 0040e466  7429                 je 0x40e491
// 0040e468  85c0                 test eax, eax
// 0040e46a  7425                 je 0x40e491
// 0040e46c  8b00                 mov eax, dword ptr [eax]
// 0040e46e  8906                 mov dword ptr [esi], eax
// 0040e470  85c0                 test eax, eax
// 0040e472  7408                 je 0x40e47c
// 0040e474  8b08                 mov ecx, dword ptr [eax]
// 0040e476  8b5104               mov edx, dword ptr [ecx + 4]
// 0040e479  50                   push eax
// 0040e47a  ffd2                 call edx
// 0040e47c  83431004             add dword ptr [ebx + 0x10], 4
// 0040e480  83c604               add esi, 4
// 0040e483  85ff                 test edi, edi
// 0040e485  75d9                 jne 0x40e460
// 0040e487  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040e48b  5b                   pop ebx
// 0040e48c  5e                   pop esi
// 0040e48d  5f                   pop edi
// 0040e48e  c21000               ret 0x10
// 0040e491  6805400080           push 0x80004005
// 0040e496  e8e546ffff           call 0x402b80
// 0040e49b  5b                   pop ebx
// 0040e49c  5e                   pop esi
// 0040e49d  b805400080           mov eax, 0x80004005
// 0040e4a2  5f                   pop edi
// 0040e4a3  c21000               ret 0x10
// 0040e4a6  5e                   pop esi
// 0040e4a7  b803400080           mov eax, 0x80004003
// 0040e4ac  5f                   pop edi
// 0040e4ad  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?Next@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJKPAPAUIUnknown@@PAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
