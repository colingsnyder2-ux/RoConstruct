// from server: 100% by auto
// roc 2009-06 00740830  unit: HH::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00740830
//
// 00740830  56                   push esi
// 00740831  57                   push edi
// 00740832  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00740836  8b4718               mov eax, dword ptr [edi + 0x18]
// 00740839  f7d0                 not eax
// 0074083b  8bf1                 mov esi, ecx
// 0074083d  a801                 test al, 1
// 0074083f  741e                 je 0x74085f
// 00740841  8b4e08               mov ecx, dword ptr [esi + 8]
// 00740844  51                   push ecx
// 00740845  8bcf                 mov ecx, edi
// 00740847  e87a8dfdff           call 0x7195c6
// 0074084c  8b5608               mov edx, dword ptr [esi + 8]
// 0074084f  8b4604               mov eax, dword ptr [esi + 4]
// 00740852  52                   push edx
// 00740853  50                   push eax
// 00740854  57                   push edi
// 00740855  e8e6b40100           call 0x75bd40
// 0074085a  5f                   pop edi
// 0074085b  5e                   pop esi
// 0074085c  c20400               ret 4
// 0074085f  8bcf                 mov ecx, edi
// 00740861  e85a8dfdff           call 0x7195c0
// 00740866  6aff                 push -1
// 00740868  50                   push eax
// 00740869  8bce                 mov ecx, esi
// 0074086b  e8a01c0100           call 0x752510
// 00740870  8b5608               mov edx, dword ptr [esi + 8]
// 00740873  8b4604               mov eax, dword ptr [esi + 4]
// 00740876  52                   push edx
// 00740877  50                   push eax
// 00740878  57                   push edi
// 00740879  e8c2b40100           call 0x75bd40
// 0074087e  5f                   pop edi
// 0074087f  5e                   pop esi
// 00740880  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
