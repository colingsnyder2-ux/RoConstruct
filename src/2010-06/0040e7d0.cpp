// from server: 100% by auto
// roc 2010-06 0040e7d0  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040e7d0
//
// 0040e7d0  56                   push esi
// 0040e7d1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040e7d5  85f6                 test esi, esi
// 0040e7d7  7509                 jne 0x40e7e2
// 0040e7d9  b857000780           mov eax, 0x80070057
// 0040e7de  5e                   pop esi
// 0040e7df  c20800               ret 8
// 0040e7e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040e7e6  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0040e7e9  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0040e7ec  2bc2                 sub eax, edx
// 0040e7ee  c1f802               sar eax, 2
// 0040e7f1  3bf0                 cmp esi, eax
// 0040e7f3  7702                 ja 0x40e7f7
// 0040e7f5  8bc6                 mov eax, esi
// 0040e7f7  8d1482               lea edx, [edx + eax*4]
// 0040e7fa  895110               mov dword ptr [ecx + 0x10], edx
// 0040e7fd  33c9                 xor ecx, ecx
// 0040e7ff  3bf0                 cmp esi, eax
// 0040e801  0f95c1               setne cl
// 0040e804  5e                   pop esi
// 0040e805  8bc1                 mov eax, ecx
// 0040e807  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Skip@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
