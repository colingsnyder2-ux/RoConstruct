// from server: 100% by auto
// roc 2009-12 0083bef0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bef0
//
// 0083bef0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bef4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bef8  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083befb  8b5250               mov edx, dword ptr [edx + 0x50]
// 0083befe  56                   push esi
// 0083beff  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bf03  50                   push eax
// 0083bf04  83ec10               sub esp, 0x10
// 0083bf07  8bc4                 mov eax, esp
// 0083bf09  8930                 mov dword ptr [eax], esi
// 0083bf0b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bf0f  897004               mov dword ptr [eax + 4], esi
// 0083bf12  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bf16  83c1fc               add ecx, -4
// 0083bf19  897008               mov dword ptr [eax + 8], esi
// 0083bf1c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bf20  89700c               mov dword ptr [eax + 0xc], esi
// 0083bf23  ffd2                 call edx
// 0083bf25  5e                   pop esi
// 0083bf26  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
