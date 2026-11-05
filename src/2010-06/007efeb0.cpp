// from server: 100% by auto
// roc 2010-06 007efeb0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efeb0
//
// 007efeb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efeb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efeb8  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efebb  8b5238               mov edx, dword ptr [edx + 0x38]
// 007efebe  56                   push esi
// 007efebf  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efec3  50                   push eax
// 007efec4  83ec10               sub esp, 0x10
// 007efec7  8bc4                 mov eax, esp
// 007efec9  8930                 mov dword ptr [eax], esi
// 007efecb  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efecf  897004               mov dword ptr [eax + 4], esi
// 007efed2  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efed6  83c1fc               add ecx, -4
// 007efed9  897008               mov dword ptr [eax + 8], esi
// 007efedc  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efee0  89700c               mov dword ptr [eax + 0xc], esi
// 007efee3  ffd2                 call edx
// 007efee5  5e                   pop esi
// 007efee6  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
