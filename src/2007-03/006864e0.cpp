// from server: 100% by auto
// roc 2007-03 006864e0  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006864e0
//
// 006864e0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006864e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006864e8  8b51fc               mov edx, dword ptr [ecx - 4]
// 006864eb  8b5250               mov edx, dword ptr [edx + 0x50]
// 006864ee  56                   push esi
// 006864ef  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006864f3  50                   push eax
// 006864f4  83ec10               sub esp, 0x10
// 006864f7  8bc4                 mov eax, esp
// 006864f9  8930                 mov dword ptr [eax], esi
// 006864fb  8b742424             mov esi, dword ptr [esp + 0x24]
// 006864ff  897004               mov dword ptr [eax + 4], esi
// 00686502  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686506  83c1fc               add ecx, -4
// 00686509  897008               mov dword ptr [eax + 8], esi
// 0068650c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686510  89700c               mov dword ptr [eax + 0xc], esi
// 00686513  ffd2                 call edx
// 00686515  5e                   pop esi
// 00686516  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accName@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
