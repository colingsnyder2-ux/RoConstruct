// from server: 100% by auto
// roc 2009-06 007610c0  unit: CXTPAccessible::XAccessible  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007610c0
//
// 007610c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007610c4  8b51fc               mov edx, dword ptr [ecx - 4]
// 007610c7  56                   push esi
// 007610c8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007610cc  83ec10               sub esp, 0x10
// 007610cf  8bc4                 mov eax, esp
// 007610d1  8930                 mov dword ptr [eax], esi
// 007610d3  8b742420             mov esi, dword ptr [esp + 0x20]
// 007610d7  897004               mov dword ptr [eax + 4], esi
// 007610da  8b742424             mov esi, dword ptr [esp + 0x24]
// 007610de  897008               mov dword ptr [eax + 8], esi
// 007610e1  8b742428             mov esi, dword ptr [esp + 0x28]
// 007610e5  83c1fc               add ecx, -4
// 007610e8  89700c               mov dword ptr [eax + 0xc], esi
// 007610eb  8b424c               mov eax, dword ptr [edx + 0x4c]
// 007610ee  ffd0                 call eax
// 007610f0  5e                   pop esi
// 007610f1  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accDoDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
