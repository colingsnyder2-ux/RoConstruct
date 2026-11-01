// from server: 100% by auto
// roc 2009-06 00760d00  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760d00
//
// 00760d00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00760d04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760d08  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760d0b  8b520c               mov edx, dword ptr [edx + 0xc]
// 00760d0e  56                   push esi
// 00760d0f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00760d13  50                   push eax
// 00760d14  83ec10               sub esp, 0x10
// 00760d17  8bc4                 mov eax, esp
// 00760d19  8930                 mov dword ptr [eax], esi
// 00760d1b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760d1f  897004               mov dword ptr [eax + 4], esi
// 00760d22  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760d26  83c1fc               add ecx, -4
// 00760d29  897008               mov dword ptr [eax + 8], esi
// 00760d2c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760d30  89700c               mov dword ptr [eax + 0xc], esi
// 00760d33  ffd2                 call edx
// 00760d35  5e                   pop esi
// 00760d36  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accChild@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
