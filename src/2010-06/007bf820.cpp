// from server: 100% by auto
// roc 2010-06 007bf820  unit: CXTPImageManagerResource::CBitmapDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bf820
//
// 007bf820  8b442404             mov eax, dword ptr [esp + 4]
// 007bf824  56                   push esi
// 007bf825  8b7108               mov esi, dword ptr [ecx + 8]
// 007bf828  50                   push eax
// 007bf829  56                   push esi
// 007bf82a  e8811c0200           call 0x7e14b0
// 007bf82f  8bc6                 mov eax, esi
// 007bf831  5e                   pop esi
// 007bf832  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?Add@CPtrArray@@QAEHPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
