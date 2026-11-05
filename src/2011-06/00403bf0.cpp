// from server: 100% by auto
// roc 2011-06 00403bf0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403bf0
//
// 00403bf0  8b442404             mov eax, dword ptr [esp + 4]
// 00403bf4  57                   push edi
// 00403bf5  33ff                 xor edi, edi
// 00403bf7  85c0                 test eax, eax
// 00403bf9  7502                 jne 0x403bfd
// 00403bfb  5f                   pop edi
// 00403bfc  c3                   ret 
// 00403bfd  8a08                 mov cl, byte ptr [eax]
// 00403bff  84c9                 test cl, cl
// 00403c01  7424                 je 0x403c27
// 00403c03  53                   push ebx
// 00403c04  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 00403c08  56                   push esi
// 00403c09  8b35d419a400         mov esi, dword ptr [0xa419d4]
// 00403c0f  90                   nop 
// 00403c10  3acb                 cmp cl, bl
// 00403c12  740f                 je 0x403c23
// 00403c14  50                   push eax
// 00403c15  ffd6                 call esi
// 00403c17  8a08                 mov cl, byte ptr [eax]
// 00403c19  84c9                 test cl, cl
// 00403c1b  75f3                 jne 0x403c10
// 00403c1d  5e                   pop esi
// 00403c1e  5b                   pop ebx
// 00403c1f  8bc7                 mov eax, edi
// 00403c21  5f                   pop edi
// 00403c22  c3                   ret 
// 00403c23  5e                   pop esi
// 00403c24  8bf8                 mov edi, eax
// 00403c26  5b                   pop ebx
// 00403c27  8bc7                 mov eax, edi
// 00403c29  5f                   pop edi
// 00403c2a  c3                   ret 
// library atl-8.0/atl.cpp (function ?StrChrA@CRegParser@ATL@@KAPADPADD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
