// from server: 100% by auto
// roc 2007-03 00686220  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686220
//
// 00686220  8b442418             mov eax, dword ptr [esp + 0x18]
// 00686224  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686228  8b51fc               mov edx, dword ptr [ecx - 4]
// 0068622b  8b5220               mov edx, dword ptr [edx + 0x20]
// 0068622e  56                   push esi
// 0068622f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686233  50                   push eax
// 00686234  83ec10               sub esp, 0x10
// 00686237  8bc4                 mov eax, esp
// 00686239  8930                 mov dword ptr [eax], esi
// 0068623b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0068623f  897004               mov dword ptr [eax + 4], esi
// 00686242  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686246  83c1fc               add ecx, -4
// 00686249  897008               mov dword ptr [eax + 8], esi
// 0068624c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686250  89700c               mov dword ptr [eax + 0xc], esi
// 00686253  ffd2                 call edx
// 00686255  5e                   pop esi
// 00686256  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accState@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
