// from server: 100% by auto
// roc 2010-06 007f0030  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f0030
//
// 007f0030  8b442418             mov eax, dword ptr [esp + 0x18]
// 007f0034  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007f0038  8b51fc               mov edx, dword ptr [ecx - 4]
// 007f003b  8b5250               mov edx, dword ptr [edx + 0x50]
// 007f003e  56                   push esi
// 007f003f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f0043  50                   push eax
// 007f0044  83ec10               sub esp, 0x10
// 007f0047  8bc4                 mov eax, esp
// 007f0049  8930                 mov dword ptr [eax], esi
// 007f004b  8b742424             mov esi, dword ptr [esp + 0x24]
// 007f004f  897004               mov dword ptr [eax + 4], esi
// 007f0052  8b742428             mov esi, dword ptr [esp + 0x28]
// 007f0056  83c1fc               add ecx, -4
// 007f0059  897008               mov dword ptr [eax + 8], esi
// 007f005c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007f0060  89700c               mov dword ptr [eax + 0xc], esi
// 007f0063  ffd2                 call edx
// 007f0065  5e                   pop esi
// 007f0066  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
