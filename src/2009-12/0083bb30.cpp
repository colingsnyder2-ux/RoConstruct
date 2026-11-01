// from server: 100% by auto
// roc 2009-12 0083bb30  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bb30
//
// 0083bb30  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bb34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bb38  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bb3b  8b5210               mov edx, dword ptr [edx + 0x10]
// 0083bb3e  56                   push esi
// 0083bb3f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bb43  50                   push eax
// 0083bb44  83ec10               sub esp, 0x10
// 0083bb47  8bc4                 mov eax, esp
// 0083bb49  8930                 mov dword ptr [eax], esi
// 0083bb4b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bb4f  897004               mov dword ptr [eax + 4], esi
// 0083bb52  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bb56  83c1fc               add ecx, -4
// 0083bb59  897008               mov dword ptr [eax + 8], esi
// 0083bb5c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bb60  89700c               mov dword ptr [eax + 0xc], esi
// 0083bb63  ffd2                 call edx
// 0083bb65  5e                   pop esi
// 0083bb66  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
