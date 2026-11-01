// from server: 100% by auto
// roc 2009-12 0083bbf0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bbf0
//
// 0083bbf0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bbf4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bbf8  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bbfb  8b521c               mov edx, dword ptr [edx + 0x1c]
// 0083bbfe  56                   push esi
// 0083bbff  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bc03  50                   push eax
// 0083bc04  83ec10               sub esp, 0x10
// 0083bc07  8bc4                 mov eax, esp
// 0083bc09  8930                 mov dword ptr [eax], esi
// 0083bc0b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bc0f  897004               mov dword ptr [eax + 4], esi
// 0083bc12  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bc16  83c1fc               add ecx, -4
// 0083bc19  897008               mov dword ptr [eax + 8], esi
// 0083bc1c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bc20  89700c               mov dword ptr [eax + 0xc], esi
// 0083bc23  ffd2                 call edx
// 0083bc25  5e                   pop esi
// 0083bc26  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accRole@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
