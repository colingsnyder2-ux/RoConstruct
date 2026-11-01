// from server: 100% by auto
// roc 2009-12 0083baf0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083baf0
//
// 0083baf0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083baf4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083baf8  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bafb  8b520c               mov edx, dword ptr [edx + 0xc]
// 0083bafe  56                   push esi
// 0083baff  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bb03  50                   push eax
// 0083bb04  83ec10               sub esp, 0x10
// 0083bb07  8bc4                 mov eax, esp
// 0083bb09  8930                 mov dword ptr [eax], esi
// 0083bb0b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bb0f  897004               mov dword ptr [eax + 4], esi
// 0083bb12  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bb16  83c1fc               add ecx, -4
// 0083bb19  897008               mov dword ptr [eax + 8], esi
// 0083bb1c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bb20  89700c               mov dword ptr [eax + 0xc], esi
// 0083bb23  ffd2                 call edx
// 0083bb25  5e                   pop esi
// 0083bb26  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accChild@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
