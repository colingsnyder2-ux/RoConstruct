// from server: 100% by auto
// roc 2007-03 006861a0  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006861a0
//
// 006861a0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006861a4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006861a8  8b51fc               mov edx, dword ptr [ecx - 4]
// 006861ab  8b5218               mov edx, dword ptr [edx + 0x18]
// 006861ae  56                   push esi
// 006861af  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006861b3  50                   push eax
// 006861b4  83ec10               sub esp, 0x10
// 006861b7  8bc4                 mov eax, esp
// 006861b9  8930                 mov dword ptr [eax], esi
// 006861bb  8b742424             mov esi, dword ptr [esp + 0x24]
// 006861bf  897004               mov dword ptr [eax + 4], esi
// 006861c2  8b742428             mov esi, dword ptr [esp + 0x28]
// 006861c6  83c1fc               add ecx, -4
// 006861c9  897008               mov dword ptr [eax + 8], esi
// 006861cc  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 006861d0  89700c               mov dword ptr [eax + 0xc], esi
// 006861d3  ffd2                 call edx
// 006861d5  5e                   pop esi
// 006861d6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDescription@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
