// from server: 100% by auto
// roc 2009-06 00760f00  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760f00
//
// 00760f00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00760f04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760f08  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760f0b  8b522c               mov edx, dword ptr [edx + 0x2c]
// 00760f0e  56                   push esi
// 00760f0f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00760f13  50                   push eax
// 00760f14  83ec10               sub esp, 0x10
// 00760f17  8bc4                 mov eax, esp
// 00760f19  8930                 mov dword ptr [eax], esi
// 00760f1b  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760f1f  897004               mov dword ptr [eax + 4], esi
// 00760f22  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760f26  83c1fc               add ecx, -4
// 00760f29  897008               mov dword ptr [eax + 8], esi
// 00760f2c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760f30  89700c               mov dword ptr [eax + 0xc], esi
// 00760f33  ffd2                 call edx
// 00760f35  5e                   pop esi
// 00760f36  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accKeyboardShortcut@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
