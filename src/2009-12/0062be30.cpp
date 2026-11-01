// from server: 100% by auto
// roc 2009-12 0062be30  unit: seg_00620000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0062be30
//
// 0062be30  8b442404             mov eax, dword ptr [esp + 4]
// 0062be34  50                   push eax
// 0062be35  e856eb0900           call 0x6ca990
// 0062be3a  59                   pop ecx
// 0062be3b  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ??3CObject@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
