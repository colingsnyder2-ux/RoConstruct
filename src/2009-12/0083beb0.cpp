// from server: 100% by auto
// roc 2009-12 0083beb0  unit: CXTPAccessible::XAccessible  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083beb0
//
// 0083beb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083beb4  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083beb7  56                   push esi
// 0083beb8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083bebc  83ec10               sub esp, 0x10
// 0083bebf  8bc4                 mov eax, esp
// 0083bec1  8930                 mov dword ptr [eax], esi
// 0083bec3  8b742420             mov esi, dword ptr [esp + 0x20]
// 0083bec7  897004               mov dword ptr [eax + 4], esi
// 0083beca  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bece  897008               mov dword ptr [eax + 8], esi
// 0083bed1  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bed5  83c1fc               add ecx, -4
// 0083bed8  89700c               mov dword ptr [eax + 0xc], esi
// 0083bedb  8b424c               mov eax, dword ptr [edx + 0x4c]
// 0083bede  ffd0                 call eax
// 0083bee0  5e                   pop esi
// 0083bee1  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accDoDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
