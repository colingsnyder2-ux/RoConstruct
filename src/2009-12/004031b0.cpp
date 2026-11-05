// from server: 100% by auto
// roc 2009-12 004031b0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004031b0
//
// 004031b0  8b442404             mov eax, dword ptr [esp + 4]
// 004031b4  57                   push edi
// 004031b5  33ff                 xor edi, edi
// 004031b7  85c0                 test eax, eax
// 004031b9  7502                 jne 0x4031bd
// 004031bb  5f                   pop edi
// 004031bc  c3                   ret 
// 004031bd  8a08                 mov cl, byte ptr [eax]
// 004031bf  84c9                 test cl, cl
// 004031c1  7424                 je 0x4031e7
// 004031c3  53                   push ebx
// 004031c4  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 004031c8  56                   push esi
// 004031c9  8b35d4cb9800         mov esi, dword ptr [0x98cbd4]
// 004031cf  90                   nop 
// 004031d0  3acb                 cmp cl, bl
// 004031d2  740f                 je 0x4031e3
// 004031d4  50                   push eax
// 004031d5  ffd6                 call esi
// 004031d7  8a08                 mov cl, byte ptr [eax]
// 004031d9  84c9                 test cl, cl
// 004031db  75f3                 jne 0x4031d0
// 004031dd  5e                   pop esi
// 004031de  5b                   pop ebx
// 004031df  8bc7                 mov eax, edi
// 004031e1  5f                   pop edi
// 004031e2  c3                   ret 
// 004031e3  5e                   pop esi
// 004031e4  8bf8                 mov edi, eax
// 004031e6  5b                   pop ebx
// 004031e7  8bc7                 mov eax, edi
// 004031e9  5f                   pop edi
// 004031ea  c3                   ret 
// library atl-8.0/atl.cpp (function ?StrChrA@CRegParser@ATL@@KAPADPADD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
