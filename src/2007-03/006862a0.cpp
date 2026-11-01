// from server: 100% by auto
// roc 2007-03 006862a0  unit: seg_00680000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006862a0
//
// 006862a0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006862a4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006862a8  8b51fc               mov edx, dword ptr [ecx - 4]
// 006862ab  8b5228               mov edx, dword ptr [edx + 0x28]
// 006862ae  56                   push esi
// 006862af  8b742410             mov esi, dword ptr [esp + 0x10]
// 006862b3  50                   push eax
// 006862b4  83ec10               sub esp, 0x10
// 006862b7  8bc4                 mov eax, esp
// 006862b9  8930                 mov dword ptr [eax], esi
// 006862bb  8b742428             mov esi, dword ptr [esp + 0x28]
// 006862bf  897004               mov dword ptr [eax + 4], esi
// 006862c2  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 006862c6  897008               mov dword ptr [eax + 8], esi
// 006862c9  8b742430             mov esi, dword ptr [esp + 0x30]
// 006862cd  83c1fc               add ecx, -4
// 006862d0  89700c               mov dword ptr [eax + 0xc], esi
// 006862d3  8b442420             mov eax, dword ptr [esp + 0x20]
// 006862d7  50                   push eax
// 006862d8  ffd2                 call edx
// 006862da  5e                   pop esi
// 006862db  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accHelpTopic@XAccessible@CXTPAccessible@@UAGJPAPA_WUtagVARIANT@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
