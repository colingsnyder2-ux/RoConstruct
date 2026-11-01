// from server: 100% by auto
// roc 2009-06 00760c70  unit: CXTPAccessible::XAccessible  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760c70
//
// 00760c70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760c74  8b41fc               mov eax, dword ptr [ecx - 4]
// 00760c77  8b5058               mov edx, dword ptr [eax + 0x58]
// 00760c7a  83c1fc               add ecx, -4
// 00760c7d  ffd2                 call edx
// 00760c7f  8bc8                 mov ecx, eax
// 00760c81  e89e85fbff           call 0x719224
// 00760c86  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
