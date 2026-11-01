// from server: 100% by auto
// roc 2007-08 00405a40  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00405a40
//
// 00405a40  8b542410             mov edx, dword ptr [esp + 0x10]
// 00405a44  85d2                 test edx, edx
// 00405a46  7406                 je 0x405a4e
// 00405a48  c70200000000         mov dword ptr [edx], 0
// 00405a4e  57                   push edi
// 00405a4f  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00405a53  85ff                 test edi, edi
// 00405a55  7509                 jne 0x405a60
// 00405a57  b857000780           mov eax, 0x80070057
// 00405a5c  5f                   pop edi
// 00405a5d  c21000               ret 0x10
// 00405a60  56                   push esi
// 00405a61  8b742414             mov esi, dword ptr [esp + 0x14]
// 00405a65  85f6                 test esi, esi
// 00405a67  0f849b000000         je 0x405b08
// 00405a6d  83ff01               cmp edi, 1
// 00405a70  7408                 je 0x405a7a
// 00405a72  85d2                 test edx, edx
// 00405a74  0f848e000000         je 0x405b08
// 00405a7a  53                   push ebx
// 00405a7b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00405a7f  837b0800             cmp dword ptr [ebx + 8], 0
// 00405a83  7478                 je 0x405afd
// 00405a85  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00405a88  85c0                 test eax, eax
// 00405a8a  7471                 je 0x405afd
// 00405a8c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00405a8f  85c9                 test ecx, ecx
// 00405a91  746a                 je 0x405afd
// 00405a93  2bc1                 sub eax, ecx
// 00405a95  c1f802               sar eax, 2
// 00405a98  3bf8                 cmp edi, eax
// 00405a9a  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00405aa2  7608                 jbe 0x405aac
// 00405aa4  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00405aac  7202                 jb 0x405ab0
// 00405aae  8bf8                 mov edi, eax
// 00405ab0  85d2                 test edx, edx
// 00405ab2  7402                 je 0x405ab6
// 00405ab4  893a                 mov dword ptr [edx], edi
// 00405ab6  85ff                 test edi, edi
// 00405ab8  742f                 je 0x405ae9
// 00405aba  8d9b00000000         lea ebx, [ebx]
// 00405ac0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00405ac3  83ef01               sub edi, 1
// 00405ac6  85f6                 test esi, esi
// 00405ac8  7429                 je 0x405af3
// 00405aca  85c0                 test eax, eax
// 00405acc  7425                 je 0x405af3
// 00405ace  8b00                 mov eax, dword ptr [eax]
// 00405ad0  85c0                 test eax, eax
// 00405ad2  8906                 mov dword ptr [esi], eax
// 00405ad4  7408                 je 0x405ade
// 00405ad6  8b08                 mov ecx, dword ptr [eax]
// 00405ad8  8b5104               mov edx, dword ptr [ecx + 4]
// 00405adb  50                   push eax
// 00405adc  ffd2                 call edx
// 00405ade  83431004             add dword ptr [ebx + 0x10], 4
// 00405ae2  83c604               add esi, 4
// 00405ae5  85ff                 test edi, edi
// 00405ae7  75d7                 jne 0x405ac0
// 00405ae9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00405aed  5b                   pop ebx
// 00405aee  5e                   pop esi
// 00405aef  5f                   pop edi
// 00405af0  c21000               ret 0x10
// 00405af3  6805400080           push 0x80004005
// 00405af8  e803b5ffff           call 0x401000
// 00405afd  5b                   pop ebx
// 00405afe  5e                   pop esi
// 00405aff  b805400080           mov eax, 0x80004005
// 00405b04  5f                   pop edi
// 00405b05  c21000               ret 0x10
// 00405b08  5e                   pop esi
// 00405b09  b803400080           mov eax, 0x80004003
// 00405b0e  5f                   pop edi
// 00405b0f  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?Next@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJKPAPAUIUnknown@@PAK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
