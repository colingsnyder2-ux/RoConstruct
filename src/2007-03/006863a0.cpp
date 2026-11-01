// from server: 100% by auto
// roc 2007-03 006863a0  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006863a0
//
// 006863a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006863a4  8b51fc               mov edx, dword ptr [ecx - 4]
// 006863a7  8b523c               mov edx, dword ptr [edx + 0x3c]
// 006863aa  56                   push esi
// 006863ab  8b742410             mov esi, dword ptr [esp + 0x10]
// 006863af  83ec10               sub esp, 0x10
// 006863b2  8bc4                 mov eax, esp
// 006863b4  8930                 mov dword ptr [eax], esi
// 006863b6  8b742424             mov esi, dword ptr [esp + 0x24]
// 006863ba  897004               mov dword ptr [eax + 4], esi
// 006863bd  8b742428             mov esi, dword ptr [esp + 0x28]
// 006863c1  897008               mov dword ptr [eax + 8], esi
// 006863c4  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 006863c8  83c1fc               add ecx, -4
// 006863cb  89700c               mov dword ptr [eax + 0xc], esi
// 006863ce  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006863d2  50                   push eax
// 006863d3  ffd2                 call edx
// 006863d5  5e                   pop esi
// 006863d6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accSelect@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
