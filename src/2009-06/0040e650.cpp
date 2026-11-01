// from server: 100% by auto
// roc 2009-06 0040e650  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040e650
//
// 0040e650  56                   push esi
// 0040e651  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040e655  85f6                 test esi, esi
// 0040e657  7509                 jne 0x40e662
// 0040e659  b857000780           mov eax, 0x80070057
// 0040e65e  5e                   pop esi
// 0040e65f  c20800               ret 8
// 0040e662  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040e666  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0040e669  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0040e66c  2bc2                 sub eax, edx
// 0040e66e  c1f802               sar eax, 2
// 0040e671  3bf0                 cmp esi, eax
// 0040e673  7702                 ja 0x40e677
// 0040e675  8bc6                 mov eax, esi
// 0040e677  8d1482               lea edx, [edx + eax*4]
// 0040e67a  895110               mov dword ptr [ecx + 0x10], edx
// 0040e67d  33c9                 xor ecx, ecx
// 0040e67f  3bf0                 cmp esi, eax
// 0040e681  0f95c1               setne cl
// 0040e684  5e                   pop esi
// 0040e685  8bc1                 mov eax, ecx
// 0040e687  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Skip@?$CComEnumImpl@UIEnumUnknown@@$1?_GUID_00000100_0000_0000_c000_000000000046@@3U__s_GUID@@BPAUIUnknown@@V?$_CopyInterface@UIUnknown@@@ATL@@@ATL@@UAGJK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
