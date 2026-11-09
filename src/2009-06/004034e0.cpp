// from server: 100% by auto
// roc 2009-06 004034e0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004034e0
//
// 004034e0  8b442404             mov eax, dword ptr [esp + 4]
// 004034e4  57                   push edi
// 004034e5  33ff                 xor edi, edi
// 004034e7  85c0                 test eax, eax
// 004034e9  7502                 jne 0x4034ed
// 004034eb  5f                   pop edi
// 004034ec  c3                   ret 
// 004034ed  8a08                 mov cl, byte ptr [eax]
// 004034ef  84c9                 test cl, cl
// 004034f1  7424                 je 0x403517
// 004034f3  53                   push ebx
// 004034f4  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 004034f8  56                   push esi
// 004034f9  8b3580ee8900         mov esi, dword ptr [0x89ee80]
// 004034ff  90                   nop 
// 00403500  3acb                 cmp cl, bl
// 00403502  740f                 je 0x403513
// 00403504  50                   push eax
// 00403505  ffd6                 call esi
// 00403507  8a08                 mov cl, byte ptr [eax]
// 00403509  84c9                 test cl, cl
// 0040350b  75f3                 jne 0x403500
// 0040350d  5e                   pop esi
// 0040350e  5b                   pop ebx
// 0040350f  8bc7                 mov eax, edi
// 00403511  5f                   pop edi
// 00403512  c3                   ret 
// 00403513  5e                   pop esi
// 00403514  8bf8                 mov edi, eax
// 00403516  5b                   pop ebx
// 00403517  8bc7                 mov eax, edi
// 00403519  5f                   pop edi
// 0040351a  c3                   ret 
// library atl-8.0/atl.cpp (function ?StrChrA@CRegParser@ATL@@KAPADPADD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
