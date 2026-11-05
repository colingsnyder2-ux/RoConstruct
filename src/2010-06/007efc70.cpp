// from server: 100% by auto
// roc 2010-06 007efc70  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efc70
//
// 007efc70  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efc74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efc78  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efc7b  8b5210               mov edx, dword ptr [edx + 0x10]
// 007efc7e  56                   push esi
// 007efc7f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efc83  50                   push eax
// 007efc84  83ec10               sub esp, 0x10
// 007efc87  8bc4                 mov eax, esp
// 007efc89  8930                 mov dword ptr [eax], esi
// 007efc8b  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efc8f  897004               mov dword ptr [eax + 4], esi
// 007efc92  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efc96  83c1fc               add ecx, -4
// 007efc99  897008               mov dword ptr [eax + 8], esi
// 007efc9c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efca0  89700c               mov dword ptr [eax + 0xc], esi
// 007efca3  ffd2                 call edx
// 007efca5  5e                   pop esi
// 007efca6  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
