// from server: 100% by auto
// roc 2007-03 00686520  unit: seg_00680000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686520
//
// 00686520  8b442418             mov eax, dword ptr [esp + 0x18]
// 00686524  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686528  8b51fc               mov edx, dword ptr [ecx - 4]
// 0068652b  8b5254               mov edx, dword ptr [edx + 0x54]
// 0068652e  56                   push esi
// 0068652f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686533  50                   push eax
// 00686534  83ec10               sub esp, 0x10
// 00686537  8bc4                 mov eax, esp
// 00686539  8930                 mov dword ptr [eax], esi
// 0068653b  8b742424             mov esi, dword ptr [esp + 0x24]
// 0068653f  897004               mov dword ptr [eax + 4], esi
// 00686542  8b742428             mov esi, dword ptr [esp + 0x28]
// 00686546  83c1fc               add ecx, -4
// 00686549  897008               mov dword ptr [eax + 8], esi
// 0068654c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686550  89700c               mov dword ptr [eax + 0xc], esi
// 00686553  ffd2                 call edx
// 00686555  5e                   pop esi
// 00686556  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?put_accValue@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
