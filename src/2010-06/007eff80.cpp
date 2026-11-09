// from server: 100% by auto
// roc 2010-06 007eff80  unit: CXTPAccessible::XAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007eff80
//
// 007eff80  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007eff84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007eff88  8b51fc               mov edx, dword ptr [ecx - 4]
// 007eff8b  8b5244               mov edx, dword ptr [edx + 0x44]
// 007eff8e  56                   push esi
// 007eff8f  8b742410             mov esi, dword ptr [esp + 0x10]
// 007eff93  50                   push eax
// 007eff94  83ec10               sub esp, 0x10
// 007eff97  8bc4                 mov eax, esp
// 007eff99  8930                 mov dword ptr [eax], esi
// 007eff9b  8b742428             mov esi, dword ptr [esp + 0x28]
// 007eff9f  897004               mov dword ptr [eax + 4], esi
// 007effa2  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007effa6  897008               mov dword ptr [eax + 8], esi
// 007effa9  8b742430             mov esi, dword ptr [esp + 0x30]
// 007effad  83c1fc               add ecx, -4
// 007effb0  89700c               mov dword ptr [eax + 0xc], esi
// 007effb3  8b442420             mov eax, dword ptr [esp + 0x20]
// 007effb7  50                   push eax
// 007effb8  ffd2                 call edx
// 007effba  5e                   pop esi
// 007effbb  c21c00               ret 0x1c
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accNavigate@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
