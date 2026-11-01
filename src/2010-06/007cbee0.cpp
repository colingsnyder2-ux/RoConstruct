// from server: 100% by auto
// roc 2010-06 007cbee0  unit: CXTPCommandBarsOptions  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cbee0
//
// 007cbee0  8b442404             mov eax, dword ptr [esp + 4]
// 007cbee4  85c0                 test eax, eax
// 007cbee6  7403                 je 0x7cbeeb
// 007cbee8  8b4004               mov eax, dword ptr [eax + 4]
// 007cbeeb  8b542414             mov edx, dword ptr [esp + 0x14]
// 007cbeef  8b4904               mov ecx, dword ptr [ecx + 4]
// 007cbef2  52                   push edx
// 007cbef3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007cbef7  52                   push edx
// 007cbef8  8b542414             mov edx, dword ptr [esp + 0x14]
// 007cbefc  52                   push edx
// 007cbefd  50                   push eax
// 007cbefe  8b442418             mov eax, dword ptr [esp + 0x18]
// 007cbf02  50                   push eax
// 007cbf03  51                   push ecx
// 007cbf04  e855bdfdff           call 0x7a7c5e
// 007cbf09  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 007cbf0f  8b09                 mov ecx, dword ptr [ecx]
// 007cbf11  e88afeffff           call 0x7cbda0
// 007cbf16  c21400               ret 0x14
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPOffice2003Theme.cpp (function ?Draw@CImageList@@QAEHPAVCDC@@HUtagPOINT@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPOffice2003Theme.cpp
