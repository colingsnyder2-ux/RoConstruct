// from server: 100% by auto
// roc 2009-12 008352c0  unit: CXTPControls  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008352c0
//
// 008352c0  8b442404             mov eax, dword ptr [esp + 4]
// 008352c4  85c0                 test eax, eax
// 008352c6  7514                 jne 0x8352dc
// 008352c8  50                   push eax
// 008352c9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008352cc  50                   push eax
// 008352cd  ff1538cb9800         call dword ptr [0x98cb38]
// 008352d3  89442404             mov dword ptr [esp + 4], eax
// 008352d7  e94ee8fbff           jmp 0x7f3b2a
// 008352dc  8b4020               mov eax, dword ptr [eax + 0x20]
// 008352df  50                   push eax
// 008352e0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008352e3  50                   push eax
// 008352e4  ff1538cb9800         call dword ptr [0x98cb38]
// 008352ea  89442404             mov dword ptr [esp + 4], eax
// 008352ee  e937e8fbff           jmp 0x7f3b2a
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
