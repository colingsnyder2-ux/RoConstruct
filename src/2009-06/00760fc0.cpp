// from server: 100% by auto
// roc 2009-06 00760fc0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760fc0
//
// 00760fc0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760fc4  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760fc7  8b523c               mov edx, dword ptr [edx + 0x3c]
// 00760fca  56                   push esi
// 00760fcb  8b742410             mov esi, dword ptr [esp + 0x10]
// 00760fcf  83ec10               sub esp, 0x10
// 00760fd2  8bc4                 mov eax, esp
// 00760fd4  8930                 mov dword ptr [eax], esi
// 00760fd6  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760fda  897004               mov dword ptr [eax + 4], esi
// 00760fdd  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760fe1  897008               mov dword ptr [eax + 8], esi
// 00760fe4  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760fe8  83c1fc               add ecx, -4
// 00760feb  89700c               mov dword ptr [eax + 0xc], esi
// 00760fee  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00760ff2  50                   push eax
// 00760ff3  ffd2                 call edx
// 00760ff5  5e                   pop esi
// 00760ff6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accSelect@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
