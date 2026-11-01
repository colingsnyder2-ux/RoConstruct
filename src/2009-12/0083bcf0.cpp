// from server: 100% by auto
// roc 2009-12 0083bcf0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bcf0
//
// 0083bcf0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bcf4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bcf8  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bcfb  8b522c               mov edx, dword ptr [edx + 0x2c]
// 0083bcfe  56                   push esi
// 0083bcff  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bd03  50                   push eax
// 0083bd04  83ec10               sub esp, 0x10
// 0083bd07  8bc4                 mov eax, esp
// 0083bd09  8930                 mov dword ptr [eax], esi
// 0083bd0b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bd0f  897004               mov dword ptr [eax + 4], esi
// 0083bd12  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bd16  83c1fc               add ecx, -4
// 0083bd19  897008               mov dword ptr [eax + 8], esi
// 0083bd1c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bd20  89700c               mov dword ptr [eax + 0xc], esi
// 0083bd23  ffd2                 call edx
// 0083bd25  5e                   pop esi
// 0083bd26  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accKeyboardShortcut@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
