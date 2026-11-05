// from server: 100% by auto
// roc 2010-06 007f0070  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f0070
//
// 007f0070  8b442418             mov eax, dword ptr [esp + 0x18]
// 007f0074  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007f0078  8b51fc               mov edx, dword ptr [ecx - 4]
// 007f007b  8b5254               mov edx, dword ptr [edx + 0x54]
// 007f007e  56                   push esi
// 007f007f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f0083  50                   push eax
// 007f0084  83ec10               sub esp, 0x10
// 007f0087  8bc4                 mov eax, esp
// 007f0089  8930                 mov dword ptr [eax], esi
// 007f008b  8b742424             mov esi, dword ptr [esp + 0x24]
// 007f008f  897004               mov dword ptr [eax + 4], esi
// 007f0092  8b742428             mov esi, dword ptr [esp + 0x28]
// 007f0096  83c1fc               add ecx, -4
// 007f0099  897008               mov dword ptr [eax + 8], esi
// 007f009c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007f00a0  89700c               mov dword ptr [eax + 0xc], esi
// 007f00a3  ffd2                 call edx
// 007f00a5  5e                   pop esi
// 007f00a6  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
