// from server: 100% by auto
// roc 2007-03 006ef750  unit: seg_006e0000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ef750
//
// 006ef750  56                   push esi
// 006ef751  8bf1                 mov esi, ecx
// 006ef753  8b4620               mov eax, dword ptr [esi + 0x20]
// 006ef756  50                   push eax
// 006ef757  ff1574ed7700         call dword ptr [0x77ed74]
// 006ef75d  85c0                 test eax, eax
// 006ef75f  7422                 je 0x6ef783
// 006ef761  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006ef764  6af0                 push -0x10
// 006ef766  51                   push ecx
// 006ef767  ff1504ed7700         call dword ptr [0x77ed04]
// 006ef76d  8b5620               mov edx, dword ptr [esi + 0x20]
// 006ef770  0d00010000           or eax, 0x100
// 006ef775  50                   push eax
// 006ef776  6af0                 push -0x10
// 006ef778  52                   push edx
// 006ef779  ff15e8ec7700         call dword ptr [0x77ece8]
// 006ef77f  b001                 mov al, 1
// 006ef781  5e                   pop esi
// 006ef782  c3                   ret 
// 006ef783  32c0                 xor al, al
// 006ef785  5e                   pop esi
// 006ef786  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?Init@CXTPColorBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
