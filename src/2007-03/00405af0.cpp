// from server: 100% by auto
// roc 2007-03 00405af0  unit: seg_00400000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00405af0
//
// 00405af0  56                   push esi
// 00405af1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00405af5  85f6                 test esi, esi
// 00405af7  7509                 jne 0x405b02
// 00405af9  b857000780           mov eax, 0x80070057
// 00405afe  5e                   pop esi
// 00405aff  c20800               ret 8
// 00405b02  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00405b06  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00405b09  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00405b0c  2bc2                 sub eax, edx
// 00405b0e  c1f802               sar eax, 2
// 00405b11  3bf0                 cmp esi, eax
// 00405b13  7702                 ja 0x405b17
// 00405b15  8bc6                 mov eax, esi
// 00405b17  8d1482               lea edx, [edx + eax*4]
// 00405b1a  895110               mov dword ptr [ecx + 0x10], edx
// 00405b1d  33c9                 xor ecx, ecx
// 00405b1f  3bf0                 cmp esi, eax
// 00405b21  0f95c1               setne cl
// 00405b24  5e                   pop esi
// 00405b25  8bc1                 mov eax, ecx
// 00405b27  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Skip@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
