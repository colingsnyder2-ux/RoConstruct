// from server: 100% by auto
// roc 2010-06 007efff0  unit: CXTPAccessible::XAccessible  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efff0
//
// 007efff0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efff4  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efff7  56                   push esi
// 007efff8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007efffc  83ec10               sub esp, 0x10
// 007effff  8bc4                 mov eax, esp
// 007f0001  8930                 mov dword ptr [eax], esi
// 007f0003  8b742420             mov esi, dword ptr [esp + 0x20]
// 007f0007  897004               mov dword ptr [eax + 4], esi
// 007f000a  8b742424             mov esi, dword ptr [esp + 0x24]
// 007f000e  897008               mov dword ptr [eax + 8], esi
// 007f0011  8b742428             mov esi, dword ptr [esp + 0x28]
// 007f0015  83c1fc               add ecx, -4
// 007f0018  89700c               mov dword ptr [eax + 0xc], esi
// 007f001b  8b424c               mov eax, dword ptr [edx + 0x4c]
// 007f001e  ffd0                 call eax
// 007f0020  5e                   pop esi
// 007f0021  c21400               ret 0x14
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accDoDefaultAction@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
