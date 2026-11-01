// from server: 100% by auto
// roc 2009-12 0083bcb0  unit: CXTPAccessible::XAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bcb0
//
// 0083bcb0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0083bcb4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bcb8  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bcbb  8b5228               mov edx, dword ptr [edx + 0x28]
// 0083bcbe  56                   push esi
// 0083bcbf  8b742410             mov esi, dword ptr [esp + 0x10]
// 0083bcc3  50                   push eax
// 0083bcc4  83ec10               sub esp, 0x10
// 0083bcc7  8bc4                 mov eax, esp
// 0083bcc9  8930                 mov dword ptr [eax], esi
// 0083bccb  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bccf  897004               mov dword ptr [eax + 4], esi
// 0083bcd2  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bcd6  897008               mov dword ptr [eax + 8], esi
// 0083bcd9  8b742430             mov esi, dword ptr [esp + 0x30]
// 0083bcdd  83c1fc               add ecx, -4
// 0083bce0  89700c               mov dword ptr [eax + 0xc], esi
// 0083bce3  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083bce7  50                   push eax
// 0083bce8  ffd2                 call edx
// 0083bcea  5e                   pop esi
// 0083bceb  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accHelpTopic@XAccessible@CXTPAccessible@@UAGJPAPA_WUtagVARIANT@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
