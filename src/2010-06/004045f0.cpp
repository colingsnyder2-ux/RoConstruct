// from server: 100% by auto
// roc 2010-06 004045f0  unit: ATL::CComClassFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004045f0
//
// 004045f0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004045f4  b803400080           mov eax, 0x80004003
// 004045f9  85c9                 test ecx, ecx
// 004045fb  7443                 je 0x404640
// 004045fd  8b542408             mov edx, dword ptr [esp + 8]
// 00404601  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404605  c70100000000         mov dword ptr [ecx], 0
// 0040460b  85d2                 test edx, edx
// 0040460d  7425                 je 0x404634
// 0040460f  833800               cmp dword ptr [eax], 0
// 00404612  7518                 jne 0x40462c
// 00404614  83780400             cmp dword ptr [eax + 4], 0
// 00404618  7512                 jne 0x40462c
// 0040461a  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00404621  7509                 jne 0x40462c
// 00404623  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 0040462a  7408                 je 0x404634
// 0040462c  b810010480           mov eax, 0x80040110
// 00404631  c21000               ret 0x10
// 00404634  51                   push ecx
// 00404635  50                   push eax
// 00404636  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040463a  8b4824               mov ecx, dword ptr [eax + 0x24]
// 0040463d  52                   push edx
// 0040463e  ffd1                 call ecx
// 00404640  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
