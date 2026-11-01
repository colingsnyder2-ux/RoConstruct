// from server: 100% by auto
// roc 2009-12 0083bb70  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bb70
//
// 0083bb70  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bb74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bb78  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bb7b  8b5214               mov edx, dword ptr [edx + 0x14]
// 0083bb7e  56                   push esi
// 0083bb7f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bb83  50                   push eax
// 0083bb84  83ec10               sub esp, 0x10
// 0083bb87  8bc4                 mov eax, esp
// 0083bb89  8930                 mov dword ptr [eax], esi
// 0083bb8b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bb8f  897004               mov dword ptr [eax + 4], esi
// 0083bb92  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bb96  83c1fc               add ecx, -4
// 0083bb99  897008               mov dword ptr [eax + 8], esi
// 0083bb9c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bba0  89700c               mov dword ptr [eax + 0xc], esi
// 0083bba3  ffd2                 call edx
// 0083bba5  5e                   pop esi
// 0083bba6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
