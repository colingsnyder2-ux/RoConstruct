// from server: 100% by auto
// roc 2007-03 00686360  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686360
//
// 00686360  8b442418             mov eax, dword ptr [esp + 0x18]
// 00686364  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686368  8b51fc               mov edx, dword ptr [ecx - 4]
// 0068636b  8b5238               mov edx, dword ptr [edx + 0x38]
// 0068636e  56                   push esi
// 0068636f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686373  50                   push eax
// 00686374  83ec10               sub esp, 0x10
// 00686377  8bc4                 mov eax, esp
// 00686379  8930                 mov dword ptr [eax], esi
// 0068637b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0068637f  897004               mov dword ptr [eax + 4], esi
// 00686382  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686386  83c1fc               add ecx, -4
// 00686389  897008               mov dword ptr [eax + 8], esi
// 0068638c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686390  89700c               mov dword ptr [eax + 0xc], esi
// 00686393  ffd2                 call edx
// 00686395  5e                   pop esi
// 00686396  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
