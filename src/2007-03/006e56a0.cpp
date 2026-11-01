// from server: 100% by auto
// roc 2007-03 006e56a0  unit: seg_006e0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e56a0
//
// 006e56a0  56                   push esi
// 006e56a1  8bf1                 mov esi, ecx
// 006e56a3  8b06                 mov eax, dword ptr [esi]
// 006e56a5  85c0                 test eax, eax
// 006e56a7  740f                 je 0x6e56b8
// 006e56a9  50                   push eax
// 006e56aa  e8058df3ff           call 0x61e3b4
// 006e56af  83c404               add esp, 4
// 006e56b2  c70600000000         mov dword ptr [esi], 0
// 006e56b8  5e                   pop esi
// 006e56b9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledisp2.cpp
