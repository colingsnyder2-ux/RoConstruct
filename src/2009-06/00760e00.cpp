// from server: 100% by auto
// roc 2009-06 00760e00  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760e00
//
// 00760e00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00760e04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760e08  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760e0b  8b521c               mov edx, dword ptr [edx + 0x1c]
// 00760e0e  56                   push esi
// 00760e0f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00760e13  50                   push eax
// 00760e14  83ec10               sub esp, 0x10
// 00760e17  8bc4                 mov eax, esp
// 00760e19  8930                 mov dword ptr [eax], esi
// 00760e1b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760e1f  897004               mov dword ptr [eax + 4], esi
// 00760e22  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760e26  83c1fc               add ecx, -4
// 00760e29  897008               mov dword ptr [eax + 8], esi
// 00760e2c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760e30  89700c               mov dword ptr [eax + 0xc], esi
// 00760e33  ffd2                 call edx
// 00760e35  5e                   pop esi
// 00760e36  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accRole@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
