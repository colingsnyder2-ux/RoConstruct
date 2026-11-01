// from server: 100% by auto
// roc 2007-03 00686430  unit: seg_00680000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686430
//
// 00686430  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00686434  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00686438  8b51fc               mov edx, dword ptr [ecx - 4]
// 0068643b  8b5244               mov edx, dword ptr [edx + 0x44]
// 0068643e  56                   push esi
// 0068643f  8b742410             mov esi, dword ptr [esp + 0x10]
// 00686443  50                   push eax
// 00686444  83ec10               sub esp, 0x10
// 00686447  8bc4                 mov eax, esp
// 00686449  8930                 mov dword ptr [eax], esi
// 0068644b  8b742428             mov esi, dword ptr [esp + 0x28]
// 0068644f  897004               mov dword ptr [eax + 4], esi
// 00686452  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00686456  897008               mov dword ptr [eax + 8], esi
// 00686459  8b742430             mov esi, dword ptr [esp + 0x30]
// 0068645d  83c1fc               add ecx, -4
// 00686460  89700c               mov dword ptr [eax + 0xc], esi
// 00686463  8b442420             mov eax, dword ptr [esp + 0x20]
// 00686467  50                   push eax
// 00686468  ffd2                 call edx
// 0068646a  5e                   pop esi
// 0068646b  c21c00               ret 0x1c
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?accNavigate@XAccessible@CXTPAccessible@@UAGJJUtagVARIANT@@PAU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
