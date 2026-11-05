// from server: 100% by auto
// roc 2010-06 007efd30  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efd30
//
// 007efd30  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efd34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efd38  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efd3b  8b521c               mov edx, dword ptr [edx + 0x1c]
// 007efd3e  56                   push esi
// 007efd3f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efd43  50                   push eax
// 007efd44  83ec10               sub esp, 0x10
// 007efd47  8bc4                 mov eax, esp
// 007efd49  8930                 mov dword ptr [eax], esi
// 007efd4b  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efd4f  897004               mov dword ptr [eax + 4], esi
// 007efd52  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efd56  83c1fc               add ecx, -4
// 007efd59  897008               mov dword ptr [eax + 8], esi
// 007efd5c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efd60  89700c               mov dword ptr [eax + 0xc], esi
// 007efd63  ffd2                 call edx
// 007efd65  5e                   pop esi
// 007efd66  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accRole@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
