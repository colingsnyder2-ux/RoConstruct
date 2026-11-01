// from server: 100% by auto
// roc 2009-12 0083bd70  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bd70
//
// 0083bd70  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bd74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bd78  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bd7b  8b5238               mov edx, dword ptr [edx + 0x38]
// 0083bd7e  56                   push esi
// 0083bd7f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bd83  50                   push eax
// 0083bd84  83ec10               sub esp, 0x10
// 0083bd87  8bc4                 mov eax, esp
// 0083bd89  8930                 mov dword ptr [eax], esi
// 0083bd8b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bd8f  897004               mov dword ptr [eax + 4], esi
// 0083bd92  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bd96  83c1fc               add ecx, -4
// 0083bd99  897008               mov dword ptr [eax + 8], esi
// 0083bd9c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bda0  89700c               mov dword ptr [eax + 0xc], esi
// 0083bda3  ffd2                 call edx
// 0083bda5  5e                   pop esi
// 0083bda6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
