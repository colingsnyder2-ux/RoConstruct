// from server: 100% by auto
// roc 2009-12 00822ad0  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822ad0
//
// 00822ad0  56                   push esi
// 00822ad1  57                   push edi
// 00822ad2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00822ad6  8b4718               mov eax, dword ptr [edi + 0x18]
// 00822ad9  f7d0                 not eax
// 00822adb  8bf1                 mov esi, ecx
// 00822add  a801                 test al, 1
// 00822adf  741e                 je 0x822aff
// 00822ae1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00822ae4  51                   push ecx
// 00822ae5  8bcf                 mov ecx, edi
// 00822ae7  e80819fdff           call 0x7f43f4
// 00822aec  8b5608               mov edx, dword ptr [esi + 8]
// 00822aef  8b4604               mov eax, dword ptr [esi + 4]
// 00822af2  52                   push edx
// 00822af3  50                   push eax
// 00822af4  57                   push edi
// 00822af5  e8e6c2ffff           call 0x81ede0
// 00822afa  5f                   pop edi
// 00822afb  5e                   pop esi
// 00822afc  c20400               ret 4
// 00822aff  8bcf                 mov ecx, edi
// 00822b01  e8e818fdff           call 0x7f43ee
// 00822b06  6aff                 push -1
// 00822b08  50                   push eax
// 00822b09  8bce                 mov ecx, esi
// 00822b0b  e820c1ffff           call 0x81ec30
// 00822b10  8b5608               mov edx, dword ptr [esi + 8]
// 00822b13  8b4604               mov eax, dword ptr [esi + 4]
// 00822b16  52                   push edx
// 00822b17  50                   push eax
// 00822b18  57                   push edi
// 00822b19  e8c2c2ffff           call 0x81ede0
// 00822b1e  5f                   pop edi
// 00822b1f  5e                   pop esi
// 00822b20  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?Serialize@?$CArray@HH@@UAEXAAVCArchive@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
