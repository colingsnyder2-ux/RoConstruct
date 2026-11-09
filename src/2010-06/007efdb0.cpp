// from server: 100% by auto
// roc 2010-06 007efdb0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efdb0
//
// 007efdb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efdb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efdb8  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efdbb  8b5224               mov edx, dword ptr [edx + 0x24]
// 007efdbe  56                   push esi
// 007efdbf  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efdc3  50                   push eax
// 007efdc4  83ec10               sub esp, 0x10
// 007efdc7  8bc4                 mov eax, esp
// 007efdc9  8930                 mov dword ptr [eax], esi
// 007efdcb  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efdcf  897004               mov dword ptr [eax + 4], esi
// 007efdd2  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efdd6  83c1fc               add ecx, -4
// 007efdd9  897008               mov dword ptr [eax + 8], esi
// 007efddc  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efde0  89700c               mov dword ptr [eax + 0xc], esi
// 007efde3  ffd2                 call edx
// 007efde5  5e                   pop esi
// 007efde6  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accHelp@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
