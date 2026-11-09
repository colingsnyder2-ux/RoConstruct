// from server: 100% by coldek
// from server: 100% by auto
// roc 2008-06 00403180  unit: ATL::CComClassFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403180
//
// 00403180  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403184  b803400080           mov eax, 0x80004003
// 00403189  85c9                 test ecx, ecx
// 0040318b  7443                 je 0x4031d0
// 0040318d  8b542408             mov edx, dword ptr [esp + 8]
// 00403191  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403195  c70100000000         mov dword ptr [ecx], 0
// 0040319b  85d2                 test edx, edx
// 0040319d  7425                 je 0x4031c4
// 0040319f  833800               cmp dword ptr [eax], 0
// 004031a2  7518                 jne 0x4031bc
// 004031a4  83780400             cmp dword ptr [eax + 4], 0
// 004031a8  7512                 jne 0x4031bc
// 004031aa  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004031b1  7509                 jne 0x4031bc
// 004031b3  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 004031ba  7408                 je 0x4031c4
// 004031bc  b810010480           mov eax, 0x80040110
// 004031c1  c21000               ret 0x10
// 004031c4  51                   push ecx
// 004031c5  50                   push eax
// 004031c6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004031ca  8b4824               mov ecx, dword ptr [eax + 0x24]
// 004031cd  52                   push edx
// 004031ce  ffd1                 call ecx
// 004031d0  c21000               ret 0x10
// library atl-9.0/atl.cpp (function ?CreateInstance@CComClassFactory@ATL@@UAGJPAUIUnknown@@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
