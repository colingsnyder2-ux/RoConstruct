// from server: 100% by auto
// roc 2007-03 00686120  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686120
//
// 00686120  8b442418             mov eax, dword ptr [esp + 0x18]
// 00686124  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686128  8b51fc               mov edx, dword ptr [ecx - 4]
// 0068612b  8b5210               mov edx, dword ptr [edx + 0x10]
// 0068612e  56                   push esi
// 0068612f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686133  50                   push eax
// 00686134  83ec10               sub esp, 0x10
// 00686137  8bc4                 mov eax, esp
// 00686139  8930                 mov dword ptr [eax], esi
// 0068613b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0068613f  897004               mov dword ptr [eax + 4], esi
// 00686142  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686146  83c1fc               add ecx, -4
// 00686149  897008               mov dword ptr [eax + 8], esi
// 0068614c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686150  89700c               mov dword ptr [eax + 0xc], esi
// 00686153  ffd2                 call edx
// 00686155  5e                   pop esi
// 00686156  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
