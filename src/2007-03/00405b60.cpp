// from server: 100% by auto
// roc 2007-03 00405b60  unit: seg_00400000  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00405b60
//
// 00405b60  8b542410             mov edx, dword ptr [esp + 0x10]
// 00405b64  85d2                 test edx, edx
// 00405b66  7406                 je 0x405b6e
// 00405b68  c70200000000         mov dword ptr [edx], 0
// 00405b6e  57                   push edi
// 00405b6f  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00405b73  85ff                 test edi, edi
// 00405b75  7509                 jne 0x405b80
// 00405b77  b857000780           mov eax, 0x80070057
// 00405b7c  5f                   pop edi
// 00405b7d  c21000               ret 0x10
// 00405b80  56                   push esi
// 00405b81  8b742414             mov esi, dword ptr [esp + 0x14]
// 00405b85  85f6                 test esi, esi
// 00405b87  0f849b000000         je 0x405c28
// 00405b8d  83ff01               cmp edi, 1
// 00405b90  7408                 je 0x405b9a
// 00405b92  85d2                 test edx, edx
// 00405b94  0f848e000000         je 0x405c28
// 00405b9a  53                   push ebx
// 00405b9b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00405b9f  837b0800             cmp dword ptr [ebx + 8], 0
// 00405ba3  7478                 je 0x405c1d
// 00405ba5  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00405ba8  85c0                 test eax, eax
// 00405baa  7471                 je 0x405c1d
// 00405bac  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00405baf  85c9                 test ecx, ecx
// 00405bb1  746a                 je 0x405c1d
// 00405bb3  2bc1                 sub eax, ecx
// 00405bb5  c1f802               sar eax, 2
// 00405bb8  3bf8                 cmp edi, eax
// 00405bba  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00405bc2  7608                 jbe 0x405bcc
// 00405bc4  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00405bcc  7202                 jb 0x405bd0
// 00405bce  8bf8                 mov edi, eax
// 00405bd0  85d2                 test edx, edx
// 00405bd2  7402                 je 0x405bd6
// 00405bd4  893a                 mov dword ptr [edx], edi
// 00405bd6  85ff                 test edi, edi
// 00405bd8  742f                 je 0x405c09
// 00405bda  8d9b00000000         lea ebx, [ebx]
// 00405be0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00405be3  83ef01               sub edi, 1
// 00405be6  85f6                 test esi, esi
// 00405be8  7429                 je 0x405c13
// 00405bea  85c0                 test eax, eax
// 00405bec  7425                 je 0x405c13
// 00405bee  8b00                 mov eax, dword ptr [eax]
// 00405bf0  85c0                 test eax, eax
// 00405bf2  8906                 mov dword ptr [esi], eax
// 00405bf4  7408                 je 0x405bfe
// 00405bf6  8b08                 mov ecx, dword ptr [eax]
// 00405bf8  8b5104               mov edx, dword ptr [ecx + 4]
// 00405bfb  50                   push eax
// 00405bfc  ffd2                 call edx
// 00405bfe  83431004             add dword ptr [ebx + 0x10], 4
// 00405c02  83c604               add esi, 4
// 00405c05  85ff                 test edi, edi
// 00405c07  75d7                 jne 0x405be0
// 00405c09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00405c0d  5b                   pop ebx
// 00405c0e  5e                   pop esi
// 00405c0f  5f                   pop edi
// 00405c10  c21000               ret 0x10
// 00405c13  6805400080           push 0x80004005
// 00405c18  e8e3b3ffff           call 0x401000
// 00405c1d  5b                   pop ebx
// 00405c1e  5e                   pop esi
// 00405c1f  b805400080           mov eax, 0x80004005
// 00405c24  5f                   pop edi
// 00405c25  c21000               ret 0x10
// 00405c28  5e                   pop esi
// 00405c29  b803400080           mov eax, 0x80004003
// 00405c2e  5f                   pop edi
// 00405c2f  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?Next@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJKPAPAUIUnknown@@PAK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
