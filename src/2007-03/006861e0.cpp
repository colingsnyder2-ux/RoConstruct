// from server: 100% by auto
// roc 2007-03 006861e0  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006861e0
//
// 006861e0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006861e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006861e8  8b51fc               mov edx, dword ptr [ecx - 4]
// 006861eb  8b521c               mov edx, dword ptr [edx + 0x1c]
// 006861ee  56                   push esi
// 006861ef  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006861f3  50                   push eax
// 006861f4  83ec10               sub esp, 0x10
// 006861f7  8bc4                 mov eax, esp
// 006861f9  8930                 mov dword ptr [eax], esi
// 006861fb  8b742424             mov esi, dword ptr [esp + 0x24]
// 006861ff  897004               mov dword ptr [eax + 4], esi
// 00686202  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686206  83c1fc               add ecx, -4
// 00686209  897008               mov dword ptr [eax + 8], esi
// 0068620c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686210  89700c               mov dword ptr [eax + 0xc], esi
// 00686213  ffd2                 call edx
// 00686215  5e                   pop esi
// 00686216  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accRole@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
