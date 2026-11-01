// from server: 100% by auto
// roc 2009-06 00761100  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761100
//
// 00761100  8b442418             mov eax, dword ptr [esp + 0x18]
// 00761104  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00761108  8b51fc               mov edx, dword ptr [ecx - 4]
// 0076110b  8b5250               mov edx, dword ptr [edx + 0x50]
// 0076110e  56                   push esi
// 0076110f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00761113  50                   push eax
// 00761114  83ec10               sub esp, 0x10
// 00761117  8bc4                 mov eax, esp
// 00761119  8930                 mov dword ptr [eax], esi
// 0076111b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0076111f  897004               mov dword ptr [eax + 4], esi
// 00761122  8b742428             mov esi, dword ptr [esp + 0x28]
// 00761126  83c1fc               add ecx, -4
// 00761129  897008               mov dword ptr [eax + 8], esi
// 0076112c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00761130  89700c               mov dword ptr [eax + 0xc], esi
// 00761133  ffd2                 call edx
// 00761135  5e                   pop esi
// 00761136  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
