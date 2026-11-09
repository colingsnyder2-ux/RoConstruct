// from server: 100% by auto
// roc 2009-12 008d08c0  unit: CXTPTabPaintManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d08c0
//
// 008d08c0  8b442404             mov eax, dword ptr [esp + 4]
// 008d08c4  50                   push eax
// 008d08c5  e8669af7ff           call 0x84a330
// 008d08ca  59                   pop ecx
// 008d08cb  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ??3CObject@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
