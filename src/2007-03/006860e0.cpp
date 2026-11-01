// from server: 100% by auto
// roc 2007-03 006860e0  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006860e0
//
// 006860e0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006860e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006860e8  8b51fc               mov edx, dword ptr [ecx - 4]
// 006860eb  8b520c               mov edx, dword ptr [edx + 0xc]
// 006860ee  56                   push esi
// 006860ef  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006860f3  50                   push eax
// 006860f4  83ec10               sub esp, 0x10
// 006860f7  8bc4                 mov eax, esp
// 006860f9  8930                 mov dword ptr [eax], esi
// 006860fb  8b742424             mov esi, dword ptr [esp + 0x24]
// 006860ff  897004               mov dword ptr [eax + 4], esi
// 00686102  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686106  83c1fc               add ecx, -4
// 00686109  897008               mov dword ptr [eax + 8], esi
// 0068610c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686110  89700c               mov dword ptr [eax + 0xc], esi
// 00686113  ffd2                 call edx
// 00686115  5e                   pop esi
// 00686116  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accChild@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
