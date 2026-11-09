// from server: 100% by auto
// roc 2010-06 007efcb0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efcb0
//
// 007efcb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007efcb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efcb8  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efcbb  8b5214               mov edx, dword ptr [edx + 0x14]
// 007efcbe  56                   push esi
// 007efcbf  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efcc3  50                   push eax
// 007efcc4  83ec10               sub esp, 0x10
// 007efcc7  8bc4                 mov eax, esp
// 007efcc9  8930                 mov dword ptr [eax], esi
// 007efccb  8b742424             mov esi, dword ptr [esp + 0x24]
// 007efccf  897004               mov dword ptr [eax + 4], esi
// 007efcd2  8b742428             mov esi, dword ptr [esp + 0x28]
// 007efcd6  83c1fc               add ecx, -4
// 007efcd9  897008               mov dword ptr [eax + 8], esi
// 007efcdc  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007efce0  89700c               mov dword ptr [eax + 0xc], esi
// 007efce3  ffd2                 call edx
// 007efce5  5e                   pop esi
// 007efce6  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
