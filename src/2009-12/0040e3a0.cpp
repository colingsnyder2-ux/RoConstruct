// from server: 100% by auto
// roc 2009-12 0040e3a0  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040e3a0
//
// 0040e3a0  56                   push esi
// 0040e3a1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040e3a5  85f6                 test esi, esi
// 0040e3a7  7509                 jne 0x40e3b2
// 0040e3a9  b857000780           mov eax, 0x80070057
// 0040e3ae  5e                   pop esi
// 0040e3af  c20800               ret 8
// 0040e3b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040e3b6  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0040e3b9  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0040e3bc  2bc2                 sub eax, edx
// 0040e3be  c1f802               sar eax, 2
// 0040e3c1  3bf0                 cmp esi, eax
// 0040e3c3  7702                 ja 0x40e3c7
// 0040e3c5  8bc6                 mov eax, esi
// 0040e3c7  8d1482               lea edx, [edx + eax*4]
// 0040e3ca  895110               mov dword ptr [ecx + 0x10], edx
// 0040e3cd  33c9                 xor ecx, ecx
// 0040e3cf  3bf0                 cmp esi, eax
// 0040e3d1  0f95c1               setne cl
// 0040e3d4  5e                   pop esi
// 0040e3d5  8bc1                 mov eax, ecx
// 0040e3d7  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Skip@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
