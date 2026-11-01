// from server: 100% by auto
// roc 2010-06 00403200  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403200
//
// 00403200  8b442404             mov eax, dword ptr [esp + 4]
// 00403204  57                   push edi
// 00403205  33ff                 xor edi, edi
// 00403207  85c0                 test eax, eax
// 00403209  7502                 jne 0x40320d
// 0040320b  5f                   pop edi
// 0040320c  c3                   ret 
// 0040320d  8a08                 mov cl, byte ptr [eax]
// 0040320f  84c9                 test cl, cl
// 00403211  7424                 je 0x403237
// 00403213  53                   push ebx
// 00403214  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 00403218  56                   push esi
// 00403219  8b3564ba9e00         mov esi, dword ptr [0x9eba64]
// 0040321f  90                   nop 
// 00403220  3acb                 cmp cl, bl
// 00403222  740f                 je 0x403233
// 00403224  50                   push eax
// 00403225  ffd6                 call esi
// 00403227  8a08                 mov cl, byte ptr [eax]
// 00403229  84c9                 test cl, cl
// 0040322b  75f3                 jne 0x403220
// 0040322d  5e                   pop esi
// 0040322e  5b                   pop ebx
// 0040322f  8bc7                 mov eax, edi
// 00403231  5f                   pop edi
// 00403232  c3                   ret 
// 00403233  5e                   pop esi
// 00403234  8bf8                 mov edi, eax
// 00403236  5b                   pop ebx
// 00403237  8bc7                 mov eax, edi
// 00403239  5f                   pop edi
// 0040323a  c3                   ret 
// library atl-8.0/atl.cpp (function ?StrChrA@CRegParser@ATL@@KAPADPADD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
