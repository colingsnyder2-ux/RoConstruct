// from server: 100% by auto
// roc 2010-06 007efd70  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efd70
//
// 007efd70  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efd74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efd78  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efd7b  8b5220               mov edx, dword ptr [edx + 0x20]
// 007efd7e  56                   push esi
// 007efd7f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efd83  50                   push eax
// 007efd84  83ec10               sub esp, 0x10
// 007efd87  8bc4                 mov eax, esp
// 007efd89  8930                 mov dword ptr [eax], esi
// 007efd8b  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efd8f  897004               mov dword ptr [eax + 4], esi
// 007efd92  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efd96  83c1fc               add ecx, -4
// 007efd99  897008               mov dword ptr [eax + 8], esi
// 007efd9c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efda0  89700c               mov dword ptr [eax + 0xc], esi
// 007efda3  ffd2                 call edx
// 007efda5  5e                   pop esi
// 007efda6  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accState@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
