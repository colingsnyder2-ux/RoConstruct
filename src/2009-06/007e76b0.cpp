// from server: 100% by auto
// roc 2009-06 007e76b0  unit: CStatic  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e76b0
//
// 007e76b0  83ec0c               sub esp, 0xc
// 007e76b3  56                   push esi
// 007e76b4  8bf1                 mov esi, ecx
// 007e76b6  8b4620               mov eax, dword ptr [esi + 0x20]
// 007e76b9  89442404             mov dword ptr [esp + 4], eax
// 007e76bd  c744240cfeffffff     mov dword ptr [esp + 0xc], 0xfffffffe
// 007e76c5  e8944a0600           call 0x84c15e
// 007e76ca  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007e76cd  51                   push ecx
// 007e76ce  8944240c             mov dword ptr [esp + 0xc], eax
// 007e76d2  ff1598ee8900         call dword ptr [0x89ee98]
// 007e76d8  50                   push eax
// 007e76d9  e82416f3ff           call 0x718d02
// 007e76de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e76e2  8d542404             lea edx, [esp + 4]
// 007e76e6  52                   push edx
// 007e76e7  8b5020               mov edx, dword ptr [eax + 0x20]
// 007e76ea  51                   push ecx
// 007e76eb  6a4e                 push 0x4e
// 007e76ed  52                   push edx
// 007e76ee  ff1590ee8900         call dword ptr [0x89ee90]
// 007e76f4  5e                   pop esi
// 007e76f5  83c40c               add esp, 0xc
// 007e76f8  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonDown@CXTPImageEditorPicker@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
