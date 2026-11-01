// from server: 100% by auto
// roc 2009-06 00761140  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761140
//
// 00761140  8b442418             mov eax, dword ptr [esp + 0x18]
// 00761144  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00761148  8b51fc               mov edx, dword ptr [ecx - 4]
// 0076114b  8b5254               mov edx, dword ptr [edx + 0x54]
// 0076114e  56                   push esi
// 0076114f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00761153  50                   push eax
// 00761154  83ec10               sub esp, 0x10
// 00761157  8bc4                 mov eax, esp
// 00761159  8930                 mov dword ptr [eax], esi
// 0076115b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0076115f  897004               mov dword ptr [eax + 4], esi
// 00761162  8b742428             mov esi, dword ptr [esp + 0x28]
// 00761166  83c1fc               add ecx, -4
// 00761169  897008               mov dword ptr [eax + 8], esi
// 0076116c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00761170  89700c               mov dword ptr [eax + 0xc], esi
// 00761173  ffd2                 call edx
// 00761175  5e                   pop esi
// 00761176  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
