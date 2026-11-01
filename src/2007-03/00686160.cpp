// from server: 100% by auto
// roc 2007-03 00686160  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686160
//
// 00686160  8b442418             mov eax, dword ptr [esp + 0x18]
// 00686164  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686168  8b51fc               mov edx, dword ptr [ecx - 4]
// 0068616b  8b5214               mov edx, dword ptr [edx + 0x14]
// 0068616e  56                   push esi
// 0068616f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686173  50                   push eax
// 00686174  83ec10               sub esp, 0x10
// 00686177  8bc4                 mov eax, esp
// 00686179  8930                 mov dword ptr [eax], esi
// 0068617b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0068617f  897004               mov dword ptr [eax + 4], esi
// 00686182  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686186  83c1fc               add ecx, -4
// 00686189  897008               mov dword ptr [eax + 8], esi
// 0068618c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686190  89700c               mov dword ptr [eax + 0xc], esi
// 00686193  ffd2                 call edx
// 00686195  5e                   pop esi
// 00686196  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
