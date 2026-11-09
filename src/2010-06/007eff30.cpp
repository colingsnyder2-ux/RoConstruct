// from server: 100% by auto
// roc 2010-06 007eff30  unit: CXTPAccessible::XAccessible  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007eff30
//
// 007eff30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007eff34  56                   push esi
// 007eff35  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007eff39  8b51fc               mov edx, dword ptr [ecx - 4]
// 007eff3c  8b5240               mov edx, dword ptr [edx + 0x40]
// 007eff3f  83ec10               sub esp, 0x10
// 007eff42  8bc4                 mov eax, esp
// 007eff44  8930                 mov dword ptr [eax], esi
// 007eff46  8b742430             mov esi, dword ptr [esp + 0x30]
// 007eff4a  897004               mov dword ptr [eax + 4], esi
// 007eff4d  8b742434             mov esi, dword ptr [esp + 0x34]
// 007eff51  897008               mov dword ptr [eax + 8], esi
// 007eff54  8b742438             mov esi, dword ptr [esp + 0x38]
// 007eff58  89700c               mov dword ptr [eax + 0xc], esi
// 007eff5b  8b442428             mov eax, dword ptr [esp + 0x28]
// 007eff5f  50                   push eax
// 007eff60  8b442428             mov eax, dword ptr [esp + 0x28]
// 007eff64  50                   push eax
// 007eff65  8b442428             mov eax, dword ptr [esp + 0x28]
// 007eff69  83c1fc               add ecx, -4
// 007eff6c  50                   push eax
// 007eff6d  8b442428             mov eax, dword ptr [esp + 0x28]
// 007eff71  50                   push eax
// 007eff72  ffd2                 call edx
// 007eff74  5e                   pop esi
// 007eff75  c22400               ret 0x24
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accLocation@XAccessible@CXTPAccessible@@UAGJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
