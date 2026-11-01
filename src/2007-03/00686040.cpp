// from server: 100% by auto
// roc 2007-03 00686040  unit: seg_00680000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686040
//
// 00686040  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686044  8b41fc               mov eax, dword ptr [ecx - 4]
// 00686047  8b5058               mov edx, dword ptr [eax + 0x58]
// 0068604a  83c1fc               add ecx, -4
// 0068604d  ffd2                 call edx
// 0068604f  8bc8                 mov ecx, eax
// 00686051  e8d0520b00           call 0x73b326
// 00686056  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
