// from server: 100% by auto
// roc 2007-03 00686060  unit: seg_00680000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686060
//
// 00686060  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686064  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00686068  8b542408             mov edx, dword ptr [esp + 8]
// 0068606c  83c1fc               add ecx, -4
// 0068606f  50                   push eax
// 00686070  8b01                 mov eax, dword ptr [ecx]
// 00686072  52                   push edx
// 00686073  8b5058               mov edx, dword ptr [eax + 0x58]
// 00686076  ffd2                 call edx
// 00686078  8bc8                 mov ecx, eax
// 0068607a  e8ad520b00           call 0x73b32c
// 0068607f  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?QueryInterface@XAccessible@CXTPAccessible@@UAGJABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
