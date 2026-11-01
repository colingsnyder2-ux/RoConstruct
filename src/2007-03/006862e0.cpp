// from server: 100% by auto
// roc 2007-03 006862e0  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006862e0
//
// 006862e0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006862e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006862e8  8b51fc               mov edx, dword ptr [ecx - 4]
// 006862eb  8b522c               mov edx, dword ptr [edx + 0x2c]
// 006862ee  56                   push esi
// 006862ef  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006862f3  50                   push eax
// 006862f4  83ec10               sub esp, 0x10
// 006862f7  8bc4                 mov eax, esp
// 006862f9  8930                 mov dword ptr [eax], esi
// 006862fb  8b742424             mov esi, dword ptr [esp + 0x24]
// 006862ff  897004               mov dword ptr [eax + 4], esi
// 00686302  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686306  83c1fc               add ecx, -4
// 00686309  897008               mov dword ptr [eax + 8], esi
// 0068630c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686310  89700c               mov dword ptr [eax + 0xc], esi
// 00686313  ffd2                 call edx
// 00686315  5e                   pop esi
// 00686316  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accKeyboardShortcut@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
