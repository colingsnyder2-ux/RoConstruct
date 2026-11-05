// from server: 100% by auto
// roc 2008-06 00401fc0  unit: VCWorkspace::?$CComObject  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401fc0
//
// 00401fc0  8b442404             mov eax, dword ptr [esp + 4]
// 00401fc4  57                   push edi
// 00401fc5  33ff                 xor edi, edi
// 00401fc7  85c0                 test eax, eax
// 00401fc9  7502                 jne 0x401fcd
// 00401fcb  5f                   pop edi
// 00401fcc  c3                   ret 
// 00401fcd  8a08                 mov cl, byte ptr [eax]
// 00401fcf  84c9                 test cl, cl
// 00401fd1  7424                 je 0x401ff7
// 00401fd3  53                   push ebx
// 00401fd4  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 00401fd8  56                   push esi
// 00401fd9  8b352c2e8000         mov esi, dword ptr [0x802e2c]
// 00401fdf  90                   nop 
// 00401fe0  3acb                 cmp cl, bl
// 00401fe2  740f                 je 0x401ff3
// 00401fe4  50                   push eax
// 00401fe5  ffd6                 call esi
// 00401fe7  8a08                 mov cl, byte ptr [eax]
// 00401fe9  84c9                 test cl, cl
// 00401feb  75f3                 jne 0x401fe0
// 00401fed  5e                   pop esi
// 00401fee  5b                   pop ebx
// 00401fef  8bc7                 mov eax, edi
// 00401ff1  5f                   pop edi
// 00401ff2  c3                   ret 
// 00401ff3  5e                   pop esi
// 00401ff4  8bf8                 mov edi, eax
// 00401ff6  5b                   pop ebx
// 00401ff7  8bc7                 mov eax, edi
// 00401ff9  5f                   pop edi
// 00401ffa  c3                   ret 
// library atl-8.0/atl.cpp (function ?StrChrA@CRegParser@ATL@@KAPADPADD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
