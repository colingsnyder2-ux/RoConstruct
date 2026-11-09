// from server: 100% by auto
// roc 2009-06 00404f70  unit: ATL::CComClassFactory  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404f70
//
// 00404f70  8b01                 mov eax, dword ptr [ecx]
// 00404f72  8b542404             mov edx, dword ptr [esp + 4]
// 00404f76  83e810               sub eax, 0x10
// 00404f79  56                   push esi
// 00404f7a  8b7004               mov esi, dword ptr [eax + 4]
// 00404f7d  3bf2                 cmp esi, edx
// 00404f7f  7e02                 jle 0x404f83
// 00404f81  8bd6                 mov edx, esi
// 00404f83  83780c01             cmp dword ptr [eax + 0xc], 1
// 00404f87  5e                   pop esi
// 00404f88  7e09                 jle 0x404f93
// 00404f8a  89542404             mov dword ptr [esp + 4], edx
// 00404f8e  e9cdf4ffff           jmp 0x404460
// 00404f93  8b4008               mov eax, dword ptr [eax + 8]
// 00404f96  3bc2                 cmp eax, edx
// 00404f98  7d1f                 jge 0x404fb9
// 00404f9a  3d00040000           cmp eax, 0x400
// 00404f9f  7e07                 jle 0x404fa8
// 00404fa1  0500040000           add eax, 0x400
// 00404fa6  eb02                 jmp 0x404faa
// 00404fa8  03c0                 add eax, eax
// 00404faa  3bc2                 cmp eax, edx
// 00404fac  7d02                 jge 0x404fb0
// 00404fae  8bc2                 mov eax, edx
// 00404fb0  89442404             mov dword ptr [esp + 4], eax
// 00404fb4  e927f5ffff           jmp 0x4044e0
// 00404fb9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?PrepareWrite2@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
