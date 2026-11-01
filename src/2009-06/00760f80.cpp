// from server: 100% by auto
// roc 2009-06 00760f80  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760f80
//
// 00760f80  8b442418             mov eax, dword ptr [esp + 0x18]
// 00760f84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760f88  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760f8b  8b5238               mov edx, dword ptr [edx + 0x38]
// 00760f8e  56                   push esi
// 00760f8f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00760f93  50                   push eax
// 00760f94  83ec10               sub esp, 0x10
// 00760f97  8bc4                 mov eax, esp
// 00760f99  8930                 mov dword ptr [eax], esi
// 00760f9b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760f9f  897004               mov dword ptr [eax + 4], esi
// 00760fa2  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760fa6  83c1fc               add ecx, -4
// 00760fa9  897008               mov dword ptr [eax + 8], esi
// 00760fac  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760fb0  89700c               mov dword ptr [eax + 0xc], esi
// 00760fb3  ffd2                 call edx
// 00760fb5  5e                   pop esi
// 00760fb6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
