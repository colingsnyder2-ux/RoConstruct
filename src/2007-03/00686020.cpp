// from server: 100% by auto
// roc 2007-03 00686020  unit: seg_00680000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686020
//
// 00686020  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686024  8b41fc               mov eax, dword ptr [ecx - 4]
// 00686027  8b5058               mov edx, dword ptr [eax + 0x58]
// 0068602a  83c1fc               add ecx, -4
// 0068602d  ffd2                 call edx
// 0068602f  8bc8                 mov ecx, eax
// 00686031  e8ea520b00           call 0x73b320
// 00686036  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
