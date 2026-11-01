// from server: 100% by auto
// roc 2007-03 006e7cc0  unit: seg_006e0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7cc0
//
// 006e7cc0  8b442404             mov eax, dword ptr [esp + 4]
// 006e7cc4  50                   push eax
// 006e7cc5  e80630f8ff           call 0x66acd0
// 006e7cca  59                   pop ecx
// 006e7ccb  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ??3CObject@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
