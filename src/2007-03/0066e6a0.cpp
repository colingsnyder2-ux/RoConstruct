// from server: 100% by auto
// roc 2007-03 0066e6a0  unit: seg_00660000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e6a0
//
// 0066e6a0  8b442404             mov eax, dword ptr [esp + 4]
// 0066e6a4  85c0                 test eax, eax
// 0066e6a6  750e                 jne 0x66e6b6
// 0066e6a8  50                   push eax
// 0066e6a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0066e6ac  50                   push eax
// 0066e6ad  ff1554ef7700         call dword ptr [0x77ef54]
// 0066e6b3  c20400               ret 4
// 0066e6b6  8b4020               mov eax, dword ptr [eax + 0x20]
// 0066e6b9  50                   push eax
// 0066e6ba  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0066e6bd  50                   push eax
// 0066e6be  ff1554ef7700         call dword ptr [0x77ef54]
// 0066e6c4  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlinplc.cpp (function ?IsChild@CWnd@@QBEHPBV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlinplc.cpp
