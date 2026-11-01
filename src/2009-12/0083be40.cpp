// from server: 100% by auto
// roc 2009-12 0083be40  unit: CXTPAccessible::XAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083be40
//
// 0083be40  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0083be44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083be48  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083be4b  8b5244               mov edx, dword ptr [edx + 0x44]
// 0083be4e  56                   push esi
// 0083be4f  8b742410             mov esi, dword ptr [esp + 0x10]
// 0083be53  50                   push eax
// 0083be54  83ec10               sub esp, 0x10
// 0083be57  8bc4                 mov eax, esp
// 0083be59  8930                 mov dword ptr [eax], esi
// 0083be5b  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083be5f  897004               mov dword ptr [eax + 4], esi
// 0083be62  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083be66  897008               mov dword ptr [eax + 8], esi
// 0083be69  8b742430             mov esi, dword ptr [esp + 0x30]
// 0083be6d  83c1fc               add ecx, -4
// 0083be70  89700c               mov dword ptr [eax + 0xc], esi
// 0083be73  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083be77  50                   push eax
// 0083be78  ffd2                 call edx
// 0083be7a  5e                   pop esi
// 0083be7b  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accNavigate@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
