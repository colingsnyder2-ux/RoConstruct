// from server: 100% by auto
// roc 2009-12 0083bc30  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bc30
//
// 0083bc30  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bc34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bc38  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bc3b  8b5220               mov edx, dword ptr [edx + 0x20]
// 0083bc3e  56                   push esi
// 0083bc3f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bc43  50                   push eax
// 0083bc44  83ec10               sub esp, 0x10
// 0083bc47  8bc4                 mov eax, esp
// 0083bc49  8930                 mov dword ptr [eax], esi
// 0083bc4b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bc4f  897004               mov dword ptr [eax + 4], esi
// 0083bc52  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bc56  83c1fc               add ecx, -4
// 0083bc59  897008               mov dword ptr [eax + 8], esi
// 0083bc5c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bc60  89700c               mov dword ptr [eax + 0xc], esi
// 0083bc63  ffd2                 call edx
// 0083bc65  5e                   pop esi
// 0083bc66  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accState@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
