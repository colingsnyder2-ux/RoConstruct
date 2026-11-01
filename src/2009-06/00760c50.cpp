// from server: 100% by auto
// roc 2009-06 00760c50  unit: CXTPAccessible::XAccessible  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760c50
//
// 00760c50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760c54  8b41fc               mov eax, dword ptr [ecx - 4]
// 00760c57  8b5058               mov edx, dword ptr [eax + 0x58]
// 00760c5a  83c1fc               add ecx, -4
// 00760c5d  ffd2                 call edx
// 00760c5f  8bc8                 mov ecx, eax
// 00760c61  e8b885fbff           call 0x71921e
// 00760c66  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
