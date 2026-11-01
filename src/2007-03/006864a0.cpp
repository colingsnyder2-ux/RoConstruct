// from server: 100% by auto
// roc 2007-03 006864a0  unit: seg_00680000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006864a0
//
// 006864a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006864a4  8b51fc               mov edx, dword ptr [ecx - 4]
// 006864a7  56                   push esi
// 006864a8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006864ac  83ec10               sub esp, 0x10
// 006864af  8bc4                 mov eax, esp
// 006864b1  8930                 mov dword ptr [eax], esi
// 006864b3  8b742420             mov esi, dword ptr [esp + 0x20]
// 006864b7  897004               mov dword ptr [eax + 4], esi
// 006864ba  8b742424             mov esi, dword ptr [esp + 0x24]
// 006864be  897008               mov dword ptr [eax + 8], esi
// 006864c1  8b742428             mov esi, dword ptr [esp + 0x28]
// 006864c5  83c1fc               add ecx, -4
// 006864c8  89700c               mov dword ptr [eax + 0xc], esi
// 006864cb  8b424c               mov eax, dword ptr [edx + 0x4c]
// 006864ce  ffd0                 call eax
// 006864d0  5e                   pop esi
// 006864d1  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accDoDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
