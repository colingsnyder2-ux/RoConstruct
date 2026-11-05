// from server: 100% by auto
// roc 2010-06 0080ad10  unit: VCRect::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080ad10
//
// 0080ad10  56                   push esi
// 0080ad11  57                   push edi
// 0080ad12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080ad16  8b4718               mov eax, dword ptr [edi + 0x18]
// 0080ad19  f7d0                 not eax
// 0080ad1b  8bf1                 mov esi, ecx
// 0080ad1d  a801                 test al, 1
// 0080ad1f  741e                 je 0x80ad3f
// 0080ad21  8b4e08               mov ecx, dword ptr [esi + 8]
// 0080ad24  51                   push ecx
// 0080ad25  8bcf                 mov ecx, edi
// 0080ad27  e808d8f9ff           call 0x7a8534
// 0080ad2c  8b5608               mov edx, dword ptr [esi + 8]
// 0080ad2f  8b4604               mov eax, dword ptr [esi + 4]
// 0080ad32  52                   push edx
// 0080ad33  50                   push eax
// 0080ad34  57                   push edi
// 0080ad35  e886e8ffff           call 0x8095c0
// 0080ad3a  5f                   pop edi
// 0080ad3b  5e                   pop esi
// 0080ad3c  c20400               ret 4
// 0080ad3f  8bcf                 mov ecx, edi
// 0080ad41  e8e8d7f9ff           call 0x7a852e
// 0080ad46  6aff                 push -1
// 0080ad48  50                   push eax
// 0080ad49  8bce                 mov ecx, esi
// 0080ad4b  e8d0e6ffff           call 0x809420
// 0080ad50  8b5608               mov edx, dword ptr [esi + 8]
// 0080ad53  8b4604               mov eax, dword ptr [esi + 4]
// 0080ad56  52                   push edx
// 0080ad57  50                   push eax
// 0080ad58  57                   push edi
// 0080ad59  e862e8ffff           call 0x8095c0
// 0080ad5e  5f                   pop edi
// 0080ad5f  5e                   pop esi
// 0080ad60  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
