// from server: 100% by auto
// roc 2010-06 007efcf0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efcf0
//
// 007efcf0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efcf4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efcf8  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efcfb  8b5218               mov edx, dword ptr [edx + 0x18]
// 007efcfe  56                   push esi
// 007efcff  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efd03  50                   push eax
// 007efd04  83ec10               sub esp, 0x10
// 007efd07  8bc4                 mov eax, esp
// 007efd09  8930                 mov dword ptr [eax], esi
// 007efd0b  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efd0f  897004               mov dword ptr [eax + 4], esi
// 007efd12  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efd16  83c1fc               add ecx, -4
// 007efd19  897008               mov dword ptr [eax + 8], esi
// 007efd1c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efd20  89700c               mov dword ptr [eax + 0xc], esi
// 007efd23  ffd2                 call edx
// 007efd25  5e                   pop esi
// 007efd26  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDescription@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
