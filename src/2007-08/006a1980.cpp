// from server: 100% by auto
// roc 2007-08 006a1980  unit: CXTPDockBar::UDOCK_INFO::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a1980
//
// 006a1980  56                   push esi
// 006a1981  57                   push edi
// 006a1982  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006a1986  8b4718               mov eax, dword ptr [edi + 0x18]
// 006a1989  f7d0                 not eax
// 006a198b  a801                 test al, 1
// 006a198d  8bf1                 mov esi, ecx
// 006a198f  741e                 je 0x6a19af
// 006a1991  8b4e08               mov ecx, dword ptr [esi + 8]
// 006a1994  51                   push ecx
// 006a1995  8bcf                 mov ecx, edi
// 006a1997  e810edf8ff           call 0x6306ac
// 006a199c  8b5608               mov edx, dword ptr [esi + 8]
// 006a199f  8b4604               mov eax, dword ptr [esi + 4]
// 006a19a2  52                   push edx
// 006a19a3  50                   push eax
// 006a19a4  57                   push edi
// 006a19a5  e826fcffff           call 0x6a15d0
// 006a19aa  5f                   pop edi
// 006a19ab  5e                   pop esi
// 006a19ac  c20400               ret 4
// 006a19af  8bcf                 mov ecx, edi
// 006a19b1  e8f0ecf8ff           call 0x6306a6
// 006a19b6  6aff                 push -1
// 006a19b8  50                   push eax
// 006a19b9  8bce                 mov ecx, esi
// 006a19bb  e840f9ffff           call 0x6a1300
// 006a19c0  8b5608               mov edx, dword ptr [esi + 8]
// 006a19c3  8b4604               mov eax, dword ptr [esi + 4]
// 006a19c6  52                   push edx
// 006a19c7  50                   push eax
// 006a19c8  57                   push edi
// 006a19c9  e802fcffff           call 0x6a15d0
// 006a19ce  5f                   pop edi
// 006a19cf  5e                   pop esi
// 006a19d0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
