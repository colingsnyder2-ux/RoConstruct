// from server: 100% by auto
// roc 2008-06 0040f830  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f830
//
// 0040f830  56                   push esi
// 0040f831  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040f835  85f6                 test esi, esi
// 0040f837  7509                 jne 0x40f842
// 0040f839  b857000780           mov eax, 0x80070057
// 0040f83e  5e                   pop esi
// 0040f83f  c20800               ret 8
// 0040f842  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040f846  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0040f849  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0040f84c  2bc2                 sub eax, edx
// 0040f84e  c1f802               sar eax, 2
// 0040f851  3bf0                 cmp esi, eax
// 0040f853  7702                 ja 0x40f857
// 0040f855  8bc6                 mov eax, esi
// 0040f857  8d1482               lea edx, [edx + eax*4]
// 0040f85a  895110               mov dword ptr [ecx + 0x10], edx
// 0040f85d  33c9                 xor ecx, ecx
// 0040f85f  3bf0                 cmp esi, eax
// 0040f861  0f95c1               setne cl
// 0040f864  5e                   pop esi
// 0040f865  8bc1                 mov eax, ecx
// 0040f867  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Skip@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
