// from server: 100% by auto
// roc 2009-06 00404b30  unit: ATL::CComClassFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404b30
//
// 00404b30  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00404b34  b803400080           mov eax, 0x80004003
// 00404b39  85c9                 test ecx, ecx
// 00404b3b  7443                 je 0x404b80
// 00404b3d  8b542408             mov edx, dword ptr [esp + 8]
// 00404b41  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404b45  c70100000000         mov dword ptr [ecx], 0
// 00404b4b  85d2                 test edx, edx
// 00404b4d  7425                 je 0x404b74
// 00404b4f  833800               cmp dword ptr [eax], 0
// 00404b52  7518                 jne 0x404b6c
// 00404b54  83780400             cmp dword ptr [eax + 4], 0
// 00404b58  7512                 jne 0x404b6c
// 00404b5a  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 00404b61  7509                 jne 0x404b6c
// 00404b63  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00404b6a  7408                 je 0x404b74
// 00404b6c  b810010480           mov eax, 0x80040110
// 00404b71  c21000               ret 0x10
// 00404b74  51                   push ecx
// 00404b75  50                   push eax
// 00404b76  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404b7a  8b4824               mov ecx, dword ptr [eax + 0x24]
// 00404b7d  52                   push edx
// 00404b7e  ffd1                 call ecx
// 00404b80  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
