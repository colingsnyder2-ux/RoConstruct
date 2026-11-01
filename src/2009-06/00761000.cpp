// from server: 100% by auto
// roc 2009-06 00761000  unit: CXTPAccessible::XAccessible  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761000
//
// 00761000  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00761004  56                   push esi
// 00761005  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00761009  8b51fc               mov edx, dword ptr [ecx - 4]
// 0076100c  8b5240               mov edx, dword ptr [edx + 0x40]
// 0076100f  83ec10               sub esp, 0x10
// 00761012  8bc4                 mov eax, esp
// 00761014  8930                 mov dword ptr [eax], esi
// 00761016  8b742430             mov esi, dword ptr [esp + 0x30]
// 0076101a  897004               mov dword ptr [eax + 4], esi
// 0076101d  8b742434             mov esi, dword ptr [esp + 0x34]
// 00761021  897008               mov dword ptr [eax + 8], esi
// 00761024  8b742438             mov esi, dword ptr [esp + 0x38]
// 00761028  89700c               mov dword ptr [eax + 0xc], esi
// 0076102b  8b442428             mov eax, dword ptr [esp + 0x28]
// 0076102f  50                   push eax
// 00761030  8b442428             mov eax, dword ptr [esp + 0x28]
// 00761034  50                   push eax
// 00761035  8b442428             mov eax, dword ptr [esp + 0x28]
// 00761039  83c1fc               add ecx, -4
// 0076103c  50                   push eax
// 0076103d  8b442428             mov eax, dword ptr [esp + 0x28]
// 00761041  50                   push eax
// 00761042  ffd2                 call edx
// 00761044  5e                   pop esi
// 00761045  c22400               ret 0x24
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accLocation@XAccessible@CXTPAccessible@@UAGJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
