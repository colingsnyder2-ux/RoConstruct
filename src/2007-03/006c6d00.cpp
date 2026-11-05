// from server: 100% by auto
// roc 2007-03 006c6d00  unit: seg_006c0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c6d00
//
// 006c6d00  56                   push esi
// 006c6d01  57                   push edi
// 006c6d02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006c6d06  8b4718               mov eax, dword ptr [edi + 0x18]
// 006c6d09  f7d0                 not eax
// 006c6d0b  a801                 test al, 1
// 006c6d0d  8bf1                 mov esi, ecx
// 006c6d0f  741e                 je 0x6c6d2f
// 006c6d11  8b4e08               mov ecx, dword ptr [esi + 8]
// 006c6d14  51                   push ecx
// 006c6d15  8bcf                 mov ecx, edi
// 006c6d17  e8fa80f5ff           call 0x61ee16
// 006c6d1c  8b5608               mov edx, dword ptr [esi + 8]
// 006c6d1f  8b4604               mov eax, dword ptr [esi + 4]
// 006c6d22  52                   push edx
// 006c6d23  50                   push eax
// 006c6d24  57                   push edi
// 006c6d25  e836eaffff           call 0x6c5760
// 006c6d2a  5f                   pop edi
// 006c6d2b  5e                   pop esi
// 006c6d2c  c20400               ret 4
// 006c6d2f  8bcf                 mov ecx, edi
// 006c6d31  e8da80f5ff           call 0x61ee10
// 006c6d36  6aff                 push -1
// 006c6d38  50                   push eax
// 006c6d39  8bce                 mov ecx, esi
// 006c6d3b  e830e5ffff           call 0x6c5270
// 006c6d40  8b5608               mov edx, dword ptr [esi + 8]
// 006c6d43  8b4604               mov eax, dword ptr [esi + 4]
// 006c6d46  52                   push edx
// 006c6d47  50                   push eax
// 006c6d48  57                   push edi
// 006c6d49  e812eaffff           call 0x6c5760
// 006c6d4e  5f                   pop edi
// 006c6d4f  5e                   pop esi
// 006c6d50  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
