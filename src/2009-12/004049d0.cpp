// from server: 100% by auto
// roc 2009-12 004049d0  unit: ATL::CComClassFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004049d0
//
// 004049d0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004049d4  b803400080           mov eax, 0x80004003
// 004049d9  85c9                 test ecx, ecx
// 004049db  7443                 je 0x404a20
// 004049dd  8b542408             mov edx, dword ptr [esp + 8]
// 004049e1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004049e5  c70100000000         mov dword ptr [ecx], 0
// 004049eb  85d2                 test edx, edx
// 004049ed  7425                 je 0x404a14
// 004049ef  833800               cmp dword ptr [eax], 0
// 004049f2  7518                 jne 0x404a0c
// 004049f4  83780400             cmp dword ptr [eax + 4], 0
// 004049f8  7512                 jne 0x404a0c
// 004049fa  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00404a01  7509                 jne 0x404a0c
// 00404a03  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00404a0a  7408                 je 0x404a14
// 00404a0c  b810010480           mov eax, 0x80040110
// 00404a11  c21000               ret 0x10
// 00404a14  51                   push ecx
// 00404a15  50                   push eax
// 00404a16  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404a1a  8b4824               mov ecx, dword ptr [eax + 0x24]
// 00404a1d  52                   push edx
// 00404a1e  ffd1                 call ecx
// 00404a20  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
