// roc 2012-06 0097d850  unit: boost::iostreams::zlib_error  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097d850
//
// 0097d850  56                   push esi
// 0097d851  8bf1                 mov esi, ecx
// 0097d853  8b06                 mov eax, dword ptr [esi]
// 0097d855  85c0                 test eax, eax
// 0097d857  740d                 je 0x97d866
// 0097d859  50                   push eax
// 0097d85a  ff15e821b200         call dword ptr [0xb221e8]
// 0097d860  c70600000000         mov dword ptr [esi], 0
// 0097d866  5e                   pop esi
// 0097d867  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
