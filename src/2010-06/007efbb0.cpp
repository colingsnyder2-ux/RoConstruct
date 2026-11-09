// from server: 100% by auto
// roc 2010-06 007efbb0  unit: CXTPAccessible::XAccessible  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efbb0
//
// 007efbb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efbb4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007efbb8  8b542408             mov edx, dword ptr [esp + 8]
// 007efbbc  83c1fc               add ecx, -4
// 007efbbf  50                   push eax
// 007efbc0  8b01                 mov eax, dword ptr [ecx]
// 007efbc2  52                   push edx
// 007efbc3  8b5058               mov edx, dword ptr [eax + 0x58]
// 007efbc6  ffd2                 call edx
// 007efbc8  8bc8                 mov ecx, eax
// 007efbca  e8c385fbff           call 0x7a8192
// 007efbcf  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?QueryInterface@XAccessible@CXTPAccessible@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
