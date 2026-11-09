// from server: 100% by auto
// roc 2010-06 007efb70  unit: CXTPAccessible::XAccessible  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efb70
//
// 007efb70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efb74  8b41fc               mov eax, dword ptr [ecx - 4]
// 007efb77  8b5058               mov edx, dword ptr [eax + 0x58]
// 007efb7a  83c1fc               add ecx, -4
// 007efb7d  ffd2                 call edx
// 007efb7f  8bc8                 mov ecx, eax
// 007efb81  e80086fbff           call 0x7a8186
// 007efb86  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
