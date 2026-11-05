// from server: 100% by auto
// roc 2010-06 007efc10  unit: CXTPAccessible::XAccessible  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efc10
//
// 007efc10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efc14  8b41fc               mov eax, dword ptr [ecx - 4]
// 007efc17  8b542408             mov edx, dword ptr [esp + 8]
// 007efc1b  8b4008               mov eax, dword ptr [eax + 8]
// 007efc1e  83c1fc               add ecx, -4
// 007efc21  52                   push edx
// 007efc22  ffd0                 call eax
// 007efc24  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accChildCount@XAccessible@CXTPAccessible@@UAGJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
