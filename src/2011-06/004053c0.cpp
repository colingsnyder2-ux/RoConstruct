// from server: 100% by auto
// roc 2011-06 004053c0  unit: ATL::CComClassFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004053c0
//
// 004053c0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004053c4  b803400080           mov eax, 0x80004003
// 004053c9  85c9                 test ecx, ecx
// 004053cb  7443                 je 0x405410
// 004053cd  8b542408             mov edx, dword ptr [esp + 8]
// 004053d1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004053d5  c70100000000         mov dword ptr [ecx], 0
// 004053db  85d2                 test edx, edx
// 004053dd  7425                 je 0x405404
// 004053df  833800               cmp dword ptr [eax], 0
// 004053e2  7518                 jne 0x4053fc
// 004053e4  83780400             cmp dword ptr [eax + 4], 0
// 004053e8  7512                 jne 0x4053fc
// 004053ea  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004053f1  7509                 jne 0x4053fc
// 004053f3  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 004053fa  7408                 je 0x405404
// 004053fc  b810010480           mov eax, 0x80040110
// 00405401  c21000               ret 0x10
// 00405404  51                   push ecx
// 00405405  50                   push eax
// 00405406  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040540a  8b4824               mov ecx, dword ptr [eax + 0x24]
// 0040540d  52                   push edx
// 0040540e  ffd1                 call ecx
// 00405410  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
