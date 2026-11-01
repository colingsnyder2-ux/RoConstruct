// from server: 100% by auto
// roc 2007-03 006863e0  unit: seg_00680000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006863e0
//
// 006863e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006863e4  56                   push esi
// 006863e5  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006863e9  8b51fc               mov edx, dword ptr [ecx - 4]
// 006863ec  8b5240               mov edx, dword ptr [edx + 0x40]
// 006863ef  83ec10               sub esp, 0x10
// 006863f2  8bc4                 mov eax, esp
// 006863f4  8930                 mov dword ptr [eax], esi
// 006863f6  8b742430             mov esi, dword ptr [esp + 0x30]
// 006863fa  897004               mov dword ptr [eax + 4], esi
// 006863fd  8b742434             mov esi, dword ptr [esp + 0x34]
// 00686401  897008               mov dword ptr [eax + 8], esi
// 00686404  8b742438             mov esi, dword ptr [esp + 0x38]
// 00686408  89700c               mov dword ptr [eax + 0xc], esi
// 0068640b  8b442428             mov eax, dword ptr [esp + 0x28]
// 0068640f  50                   push eax
// 00686410  8b442428             mov eax, dword ptr [esp + 0x28]
// 00686414  50                   push eax
// 00686415  8b442428             mov eax, dword ptr [esp + 0x28]
// 00686419  83c1fc               add ecx, -4
// 0068641c  50                   push eax
// 0068641d  8b442428             mov eax, dword ptr [esp + 0x28]
// 00686421  50                   push eax
// 00686422  ffd2                 call edx
// 00686424  5e                   pop esi
// 00686425  c22400               ret 0x24
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accLocation@XAccessible@CXTPAccessible@@UAGJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
