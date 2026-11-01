// from server: 100% by auto
// roc 2009-12 0083ba40  unit: CXTPAccessible::XAccessible  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083ba40
//
// 0083ba40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083ba44  8b41fc               mov eax, dword ptr [ecx - 4]
// 0083ba47  8b5058               mov edx, dword ptr [eax + 0x58]
// 0083ba4a  83c1fc               add ecx, -4
// 0083ba4d  ffd2                 call edx
// 0083ba4f  8bc8                 mov ecx, eax
// 0083ba51  e8f685fbff           call 0x7f404c
// 0083ba56  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?AddRef@XAccessible@CXTPAccessible@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
