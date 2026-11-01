// from server: 100% by auto
// roc 2009-06 00760d40  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760d40
//
// 00760d40  8b442418             mov eax, dword ptr [esp + 0x18]
// 00760d44  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760d48  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760d4b  8b5210               mov edx, dword ptr [edx + 0x10]
// 00760d4e  56                   push esi
// 00760d4f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00760d53  50                   push eax
// 00760d54  83ec10               sub esp, 0x10
// 00760d57  8bc4                 mov eax, esp
// 00760d59  8930                 mov dword ptr [eax], esi
// 00760d5b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760d5f  897004               mov dword ptr [eax + 4], esi
// 00760d62  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760d66  83c1fc               add ecx, -4
// 00760d69  897008               mov dword ptr [eax + 8], esi
// 00760d6c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760d70  89700c               mov dword ptr [eax + 0xc], esi
// 00760d73  ffd2                 call edx
// 00760d75  5e                   pop esi
// 00760d76  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
