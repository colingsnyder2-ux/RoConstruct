// from server: 100% by auto
// roc 2007-03 00647de0  unit: seg_00640000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00647de0
//
// 00647de0  56                   push esi
// 00647de1  57                   push edi
// 00647de2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00647de6  8b4718               mov eax, dword ptr [edi + 0x18]
// 00647de9  f7d0                 not eax
// 00647deb  a801                 test al, 1
// 00647ded  8bf1                 mov esi, ecx
// 00647def  741e                 je 0x647e0f
// 00647df1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00647df4  51                   push ecx
// 00647df5  8bcf                 mov ecx, edi
// 00647df7  e81a70fdff           call 0x61ee16
// 00647dfc  8b5608               mov edx, dword ptr [esi + 8]
// 00647dff  8b4604               mov eax, dword ptr [esi + 4]
// 00647e02  52                   push edx
// 00647e03  50                   push eax
// 00647e04  57                   push edi
// 00647e05  e866c9ffff           call 0x644770
// 00647e0a  5f                   pop edi
// 00647e0b  5e                   pop esi
// 00647e0c  c20400               ret 4
// 00647e0f  8bcf                 mov ecx, edi
// 00647e11  e8fa6ffdff           call 0x61ee10
// 00647e16  6aff                 push -1
// 00647e18  50                   push eax
// 00647e19  8bce                 mov ecx, esi
// 00647e1b  e8a0c7ffff           call 0x6445c0
// 00647e20  8b5608               mov edx, dword ptr [esi + 8]
// 00647e23  8b4604               mov eax, dword ptr [esi + 4]
// 00647e26  52                   push edx
// 00647e27  50                   push eax
// 00647e28  57                   push edi
// 00647e29  e842c9ffff           call 0x644770
// 00647e2e  5f                   pop edi
// 00647e2f  5e                   pop esi
// 00647e30  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
