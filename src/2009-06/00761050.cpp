// from server: 100% by auto
// roc 2009-06 00761050  unit: CXTPAccessible::XAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761050
//
// 00761050  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00761054  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00761058  8b51fc               mov edx, dword ptr [ecx - 4]
// 0076105b  8b5244               mov edx, dword ptr [edx + 0x44]
// 0076105e  56                   push esi
// 0076105f  8b742410             mov esi, dword ptr [esp + 0x10]
// 00761063  50                   push eax
// 00761064  83ec10               sub esp, 0x10
// 00761067  8bc4                 mov eax, esp
// 00761069  8930                 mov dword ptr [eax], esi
// 0076106b  8b742428             mov esi, dword ptr [esp + 0x28]
// 0076106f  897004               mov dword ptr [eax + 4], esi
// 00761072  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00761076  897008               mov dword ptr [eax + 8], esi
// 00761079  8b742430             mov esi, dword ptr [esp + 0x30]
// 0076107d  83c1fc               add ecx, -4
// 00761080  89700c               mov dword ptr [eax + 0xc], esi
// 00761083  8b442420             mov eax, dword ptr [esp + 0x20]
// 00761087  50                   push eax
// 00761088  ffd2                 call edx
// 0076108a  5e                   pop esi
// 0076108b  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accNavigate@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
