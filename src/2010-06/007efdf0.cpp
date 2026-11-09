// from server: 100% by auto
// roc 2010-06 007efdf0  unit: CXTPAccessible::XAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efdf0
//
// 007efdf0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007efdf4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efdf8  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efdfb  8b5228               mov edx, dword ptr [edx + 0x28]
// 007efdfe  56                   push esi
// 007efdff  8b742410             mov esi, dword ptr [esp + 0x10]
// 007efe03  50                   push eax
// 007efe04  83ec10               sub esp, 0x10
// 007efe07  8bc4                 mov eax, esp
// 007efe09  8930                 mov dword ptr [eax], esi
// 007efe0b  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efe0f  897004               mov dword ptr [eax + 4], esi
// 007efe12  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efe16  897008               mov dword ptr [eax + 8], esi
// 007efe19  8b742430             mov esi, dword ptr [esp + 0x30]
// 007efe1d  83c1fc               add ecx, -4
// 007efe20  89700c               mov dword ptr [eax + 0xc], esi
// 007efe23  8b442420             mov eax, dword ptr [esp + 0x20]
// 007efe27  50                   push eax
// 007efe28  ffd2                 call edx
// 007efe2a  5e                   pop esi
// 007efe2b  c21c00               ret 0x1c
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accHelpTopic@XAccessible@CXTPAccessible@@UAGJPAPA_WUtagVARIANT@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
