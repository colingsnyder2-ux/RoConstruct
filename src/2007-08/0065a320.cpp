// from server: 100% by auto
// roc 2007-08 0065a320  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0065a320
//
// 0065a320  56                   push esi
// 0065a321  57                   push edi
// 0065a322  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0065a326  8b4718               mov eax, dword ptr [edi + 0x18]
// 0065a329  f7d0                 not eax
// 0065a32b  a801                 test al, 1
// 0065a32d  8bf1                 mov esi, ecx
// 0065a32f  741e                 je 0x65a34f
// 0065a331  8b4e08               mov ecx, dword ptr [esi + 8]
// 0065a334  51                   push ecx
// 0065a335  8bcf                 mov ecx, edi
// 0065a337  e87063fdff           call 0x6306ac
// 0065a33c  8b5608               mov edx, dword ptr [esi + 8]
// 0065a33f  8b4604               mov eax, dword ptr [esi + 4]
// 0065a342  52                   push edx
// 0065a343  50                   push eax
// 0065a344  57                   push edi
// 0065a345  e8b6caffff           call 0x656e00
// 0065a34a  5f                   pop edi
// 0065a34b  5e                   pop esi
// 0065a34c  c20400               ret 4
// 0065a34f  8bcf                 mov ecx, edi
// 0065a351  e85063fdff           call 0x6306a6
// 0065a356  6aff                 push -1
// 0065a358  50                   push eax
// 0065a359  8bce                 mov ecx, esi
// 0065a35b  e8f0c8ffff           call 0x656c50
// 0065a360  8b5608               mov edx, dword ptr [esi + 8]
// 0065a363  8b4604               mov eax, dword ptr [esi + 4]
// 0065a366  52                   push edx
// 0065a367  50                   push eax
// 0065a368  57                   push edi
// 0065a369  e892caffff           call 0x656e00
// 0065a36e  5f                   pop edi
// 0065a36f  5e                   pop esi
// 0065a370  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
