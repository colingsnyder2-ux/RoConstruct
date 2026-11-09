// from server: 100% by auto
// roc 2010-06 007efb90  unit: CXTPAccessible::XAccessible  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efb90
//
// 007efb90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efb94  8b41fc               mov eax, dword ptr [ecx - 4]
// 007efb97  8b5058               mov edx, dword ptr [eax + 0x58]
// 007efb9a  83c1fc               add ecx, -4
// 007efb9d  ffd2                 call edx
// 007efb9f  8bc8                 mov ecx, eax
// 007efba1  e8e685fbff           call 0x7a818c
// 007efba6  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
