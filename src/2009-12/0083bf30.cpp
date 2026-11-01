// from server: 100% by auto
// roc 2009-12 0083bf30  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bf30
//
// 0083bf30  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bf34  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bf38  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bf3b  8b5254               mov edx, dword ptr [edx + 0x54]
// 0083bf3e  56                   push esi
// 0083bf3f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bf43  50                   push eax
// 0083bf44  83ec10               sub esp, 0x10
// 0083bf47  8bc4                 mov eax, esp
// 0083bf49  8930                 mov dword ptr [eax], esi
// 0083bf4b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bf4f  897004               mov dword ptr [eax + 4], esi
// 0083bf52  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bf56  83c1fc               add ecx, -4
// 0083bf59  897008               mov dword ptr [eax + 8], esi
// 0083bf5c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bf60  89700c               mov dword ptr [eax + 0xc], esi
// 0083bf63  ffd2                 call edx
// 0083bf65  5e                   pop esi
// 0083bf66  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
