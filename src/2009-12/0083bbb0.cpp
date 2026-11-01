// from server: 100% by auto
// roc 2009-12 0083bbb0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bbb0
//
// 0083bbb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083bbb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bbb8  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bbbb  8b5218               mov edx, dword ptr [edx + 0x18]
// 0083bbbe  56                   push esi
// 0083bbbf  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bbc3  50                   push eax
// 0083bbc4  83ec10               sub esp, 0x10
// 0083bbc7  8bc4                 mov eax, esp
// 0083bbc9  8930                 mov dword ptr [eax], esi
// 0083bbcb  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bbcf  897004               mov dword ptr [eax + 4], esi
// 0083bbd2  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bbd6  83c1fc               add ecx, -4
// 0083bbd9  897008               mov dword ptr [eax + 8], esi
// 0083bbdc  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bbe0  89700c               mov dword ptr [eax + 0xc], esi
// 0083bbe3  ffd2                 call edx
// 0083bbe5  5e                   pop esi
// 0083bbe6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDescription@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
