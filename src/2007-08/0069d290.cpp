// from server: 100% by auto
// roc 2007-08 0069d290  unit: CXTPPropertyGridView::UWNDRECT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069d290
//
// 0069d290  56                   push esi
// 0069d291  57                   push edi
// 0069d292  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0069d296  8b4718               mov eax, dword ptr [edi + 0x18]
// 0069d299  f7d0                 not eax
// 0069d29b  a801                 test al, 1
// 0069d29d  8bf1                 mov esi, ecx
// 0069d29f  741e                 je 0x69d2bf
// 0069d2a1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0069d2a4  51                   push ecx
// 0069d2a5  8bcf                 mov ecx, edi
// 0069d2a7  e80034f9ff           call 0x6306ac
// 0069d2ac  8b5608               mov edx, dword ptr [esi + 8]
// 0069d2af  8b4604               mov eax, dword ptr [esi + 4]
// 0069d2b2  52                   push edx
// 0069d2b3  50                   push eax
// 0069d2b4  57                   push edi
// 0069d2b5  e896faffff           call 0x69cd50
// 0069d2ba  5f                   pop edi
// 0069d2bb  5e                   pop esi
// 0069d2bc  c20400               ret 4
// 0069d2bf  8bcf                 mov ecx, edi
// 0069d2c1  e8e033f9ff           call 0x6306a6
// 0069d2c6  6aff                 push -1
// 0069d2c8  50                   push eax
// 0069d2c9  8bce                 mov ecx, esi
// 0069d2cb  e880d9ffff           call 0x69ac50
// 0069d2d0  8b5608               mov edx, dword ptr [esi + 8]
// 0069d2d3  8b4604               mov eax, dword ptr [esi + 4]
// 0069d2d6  52                   push edx
// 0069d2d7  50                   push eax
// 0069d2d8  57                   push edi
// 0069d2d9  e872faffff           call 0x69cd50
// 0069d2de  5f                   pop edi
// 0069d2df  5e                   pop esi
// 0069d2e0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?Serialize@?$CArray@HABH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
