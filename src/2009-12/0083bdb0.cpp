// from server: 100% by auto
// roc 2009-12 0083bdb0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bdb0
//
// 0083bdb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083bdb4  8b51fc               mov edx, dword ptr [ecx - 4]
// 0083bdb7  8b523c               mov edx, dword ptr [edx + 0x3c]
// 0083bdba  56                   push esi
// 0083bdbb  8b742410             mov esi, dword ptr [esp + 0x10]
// 0083bdbf  83ec10               sub esp, 0x10
// 0083bdc2  8bc4                 mov eax, esp
// 0083bdc4  8930                 mov dword ptr [eax], esi
// 0083bdc6  8b742424             mov esi, dword ptr [esp + 0x24]
// 0083bdca  897004               mov dword ptr [eax + 4], esi
// 0083bdcd  8b742428             mov esi, dword ptr [esp + 0x28]
// 0083bdd1  897008               mov dword ptr [eax + 8], esi
// 0083bdd4  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0083bdd8  83c1fc               add ecx, -4
// 0083bddb  89700c               mov dword ptr [eax + 0xc], esi
// 0083bdde  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0083bde2  50                   push eax
// 0083bde3  ffd2                 call edx
// 0083bde5  5e                   pop esi
// 0083bde6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accSelect@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
