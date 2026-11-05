// from server: 100% by auto
// roc 2007-08 00403070  unit: VCWorkspace::?$CComObject  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00403070
//
// 00403070  56                   push esi
// 00403071  8bf1                 mov esi, ecx
// 00403073  8b06                 mov eax, dword ptr [esi]
// 00403075  85c0                 test eax, eax
// 00403077  740d                 je 0x403086
// 00403079  50                   push eax
// 0040307a  ff1508d07700         call dword ptr [0x77d008]
// 00403080  c70600000000         mov dword ptr [esi], 0
// 00403086  5e                   pop esi
// 00403087  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
