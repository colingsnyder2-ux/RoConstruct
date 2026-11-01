// from server: 100% by auto
// roc 2009-06 00760dc0  unit: CXTPAccessible::XAccessible  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760dc0
//
// 00760dc0  8b442418             mov eax, dword ptr [esp + 0x18]
// 00760dc4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760dc8  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760dcb  8b5218               mov edx, dword ptr [edx + 0x18]
// 00760dce  56                   push esi
// 00760dcf  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00760dd3  50                   push eax
// 00760dd4  83ec10               sub esp, 0x10
// 00760dd7  8bc4                 mov eax, esp
// 00760dd9  8930                 mov dword ptr [eax], esi
// 00760ddb  8b742424             mov esi, dword ptr [esp + 0x24]
// 00760ddf  897004               mov dword ptr [eax + 4], esi
// 00760de2  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760de6  83c1fc               add ecx, -4
// 00760de9  897008               mov dword ptr [eax + 8], esi
// 00760dec  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760df0  89700c               mov dword ptr [eax + 0xc], esi
// 00760df3  ffd2                 call edx
// 00760df5  5e                   pop esi
// 00760df6  c21800               ret 0x18
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accDescription@XAccessible@CXTPAccessible@@UAGJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
