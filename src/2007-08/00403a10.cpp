// from server: 100% by tester
// roc 2007-03 00403890  unit: seg_00400000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00403890
//
// 00403890  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403894  85c9                 test ecx, ecx
// 00403896  b803400080           mov eax, 0x80004003
// 0040389b  7443                 je 0x4038e0
// 0040389d  8b542408             mov edx, dword ptr [esp + 8]
// 004038a1  85d2                 test edx, edx
// 004038a3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004038a7  c70100000000         mov dword ptr [ecx], 0
// 004038ad  7425                 je 0x4038d4
// 004038af  833800               cmp dword ptr [eax], 0
// 004038b2  7518                 jne 0x4038cc
// 004038b4  83780400             cmp dword ptr [eax + 4], 0
// 004038b8  7512                 jne 0x4038cc
// 004038ba  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004038c1  7509                 jne 0x4038cc
// 004038c3  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 004038ca  7408                 je 0x4038d4
// 004038cc  b810010480           mov eax, 0x80040110
// 004038d1  c21000               ret 0x10
// 004038d4  51                   push ecx
// 004038d5  50                   push eax
// 004038d6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004038da  8b4824               mov ecx, dword ptr [eax + 0x24]
// 004038dd  52                   push edx
// 004038de  ffd1                 call ecx
// 004038e0  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
