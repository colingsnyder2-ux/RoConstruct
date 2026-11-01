// from server: 100% by auto
// roc 2007-03 00401050  unit: seg_00400000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401050
//
// 00401050  8b442404             mov eax, dword ptr [esp + 4]
// 00401054  50                   push eax
// 00401055  e896d02100           call 0x61e0f0
// 0040105a  59                   pop ecx
// 0040105b  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ??3CObject@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
