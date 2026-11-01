// from server: 100% by auto
// roc 2007-03 006e0ee0  unit: seg_006e0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e0ee0
//
// 006e0ee0  56                   push esi
// 006e0ee1  8bf1                 mov esi, ecx
// 006e0ee3  e886dbf3ff           call 0x61ea6e
// 006e0ee8  c706248b7d00         mov dword ptr [esi], 0x7d8b24
// 006e0eee  c7465400000000       mov dword ptr [esi + 0x54], 0
// 006e0ef5  8bc6                 mov eax, esi
// 006e0ef7  5e                   pop esi
// 006e0ef8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
