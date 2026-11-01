// from server: 100% by auto
// roc 2009-06 00760ec0  unit: CXTPAccessible::XAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760ec0
//
// 00760ec0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00760ec4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760ec8  8b51fc               mov edx, dword ptr [ecx - 4]
// 00760ecb  8b5228               mov edx, dword ptr [edx + 0x28]
// 00760ece  56                   push esi
// 00760ecf  8b742410             mov esi, dword ptr [esp + 0x10]
// 00760ed3  50                   push eax
// 00760ed4  83ec10               sub esp, 0x10
// 00760ed7  8bc4                 mov eax, esp
// 00760ed9  8930                 mov dword ptr [eax], esi
// 00760edb  8b742428             mov esi, dword ptr [esp + 0x28]
// 00760edf  897004               mov dword ptr [eax + 4], esi
// 00760ee2  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00760ee6  897008               mov dword ptr [eax + 8], esi
// 00760ee9  8b742430             mov esi, dword ptr [esp + 0x30]
// 00760eed  83c1fc               add ecx, -4
// 00760ef0  89700c               mov dword ptr [eax + 0xc], esi
// 00760ef3  8b442420             mov eax, dword ptr [esp + 0x20]
// 00760ef7  50                   push eax
// 00760ef8  ffd2                 call edx
// 00760efa  5e                   pop esi
// 00760efb  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?get_accHelpTopic@XAccessible@CXTPAccessible@@UAGJPAPA_WUtagVARIANT@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
