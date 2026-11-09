// from server: 100% by auto
// roc 2009-12 0080b6d0  unit: CXTPImageManagerResource::CBitmapDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080b6d0
//
// 0080b6d0  8b442404             mov eax, dword ptr [esp + 4]
// 0080b6d4  56                   push esi
// 0080b6d5  8b7108               mov esi, dword ptr [ecx + 8]
// 0080b6d8  50                   push eax
// 0080b6d9  56                   push esi
// 0080b6da  e891f50500           call 0x86ac70
// 0080b6df  8bc6                 mov eax, esi
// 0080b6e1  5e                   pop esi
// 0080b6e2  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?Add@CPtrArray@@QAEHPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
