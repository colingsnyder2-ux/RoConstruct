// from server: 100% by auto
// roc 2009-12 0083bdf0  unit: CXTPAccessible::XAccessible  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bdf0
//
// 0083bdf0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bdf4  56                   push esi
// 0083bdf5  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0083bdf9  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bdfc  8b5240               mov edx, dword ptr [edx + 0x40]
// 0083bdff  83ec10               sub esp, 0x10
// 0083be02  8bc4                 mov eax, esp
// 0083be04  8930                 mov dword ptr [eax], esi
// 0083be06  8b742430             mov esi, dword ptr [esp + 0x30]
// 0083be0a  897004               mov dword ptr [eax + 4], esi
// 0083be0d  8b742434             mov esi, dword ptr [esp + 0x34]
// 0083be11  897008               mov dword ptr [eax + 8], esi
// 0083be14  8b742438             mov esi, dword ptr [esp + 0x38]
// 0083be18  89700c               mov dword ptr [eax + 0xc], esi
// 0083be1b  8b442428             mov eax, dword ptr [esp + 0x28]
// 0083be1f  50                   push eax
// 0083be20  8b442428             mov eax, dword ptr [esp + 0x28]
// 0083be24  50                   push eax
// 0083be25  8b442428             mov eax, dword ptr [esp + 0x28]
// 0083be29  83c1fc               add ecx, -4
// 0083be2c  50                   push eax
// 0083be2d  8b442428             mov eax, dword ptr [esp + 0x28]
// 0083be31  50                   push eax
// 0083be32  ffd2                 call edx
// 0083be34  5e                   pop esi
// 0083be35  c22400               ret 0x24
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accLocation@XAccessible@CXTPAccessible@@UAGJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
