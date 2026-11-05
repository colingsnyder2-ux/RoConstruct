// from server: 100% by auto
// roc 2012-06 00405b60  unit: ATL::CComClassFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405b60
//
// 00405b60  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00405b64  b803400080           mov eax, 0x80004003
// 00405b69  85c9                 test ecx, ecx
// 00405b6b  7443                 je 0x405bb0
// 00405b6d  8b542408             mov edx, dword ptr [esp + 8]
// 00405b71  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00405b75  c70100000000         mov dword ptr [ecx], 0
// 00405b7b  85d2                 test edx, edx
// 00405b7d  7425                 je 0x405ba4
// 00405b7f  833800               cmp dword ptr [eax], 0
// 00405b82  7518                 jne 0x405b9c
// 00405b84  83780400             cmp dword ptr [eax + 4], 0
// 00405b88  7512                 jne 0x405b9c
// 00405b8a  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00405b91  7509                 jne 0x405b9c
// 00405b93  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00405b9a  7408                 je 0x405ba4
// 00405b9c  b810010480           mov eax, 0x80040110
// 00405ba1  c21000               ret 0x10
// 00405ba4  51                   push ecx
// 00405ba5  50                   push eax
// 00405ba6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00405baa  8b4824               mov ecx, dword ptr [eax + 0x24]
// 00405bad  52                   push edx
// 00405bae  ffd1                 call ecx
// 00405bb0  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
