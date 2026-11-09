// from server: 100% by auto
// roc 2007-08 00411de0  unit: boost::bad_any_cast  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00411de0
//
// 00411de0  8b442404             mov eax, dword ptr [esp + 4]
// 00411de4  56                   push esi
// 00411de5  8bf1                 mov esi, ecx
// 00411de7  50                   push eax
// 00411de8  66c7060000           mov word ptr [esi], 0
// 00411ded  e88efaffff           call 0x411880
// 00411df2  8bc6                 mov eax, esi
// 00411df4  5e                   pop esi
// 00411df5  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
