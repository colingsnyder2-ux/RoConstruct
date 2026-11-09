// from server: 100% by auto
// roc 2010-06 007efef0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efef0
//
// 007efef0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efef4  8b51fc               mov edx, dword ptr [ecx - 4]
// 007efef7  8b523c               mov edx, dword ptr [edx + 0x3c]
// 007efefa  56                   push esi
// 007efefb  8b742410             mov esi, dword ptr [esp + 0x10]
// 007efeff  83ec10               sub esp, 0x10
// 007eff02  8bc4                 mov eax, esp
// 007eff04  8930                 mov dword ptr [eax], esi
// 007eff06  8b742424             mov esi, dword ptr [esp + 0x24]
// 007eff0a  897004               mov dword ptr [eax + 4], esi
// 007eff0d  8b742428             mov esi, dword ptr [esp + 0x28]
// 007eff11  897008               mov dword ptr [eax + 8], esi
// 007eff14  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007eff18  83c1fc               add ecx, -4
// 007eff1b  89700c               mov dword ptr [eax + 0xc], esi
// 007eff1e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007eff22  50                   push eax
// 007eff23  ffd2                 call edx
// 007eff25  5e                   pop esi
// 007eff26  c21800               ret 0x18
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accSelect@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
