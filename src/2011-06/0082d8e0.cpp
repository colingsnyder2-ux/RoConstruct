// from server: 100% by auto
// roc 2011-06 0082d8e0  unit: CXTPCommandBarsOptions  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082d8e0
//
// 0082d8e0  8b442404             mov eax, dword ptr [esp + 4]
// 0082d8e4  85c0                 test eax, eax
// 0082d8e6  7403                 je 0x82d8eb
// 0082d8e8  8b4004               mov eax, dword ptr [eax + 4]
// 0082d8eb  8b542414             mov edx, dword ptr [esp + 0x14]
// 0082d8ef  8b4904               mov ecx, dword ptr [ecx + 4]
// 0082d8f2  52                   push edx
// 0082d8f3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0082d8f7  52                   push edx
// 0082d8f8  8b542414             mov edx, dword ptr [esp + 0x14]
// 0082d8fc  52                   push edx
// 0082d8fd  50                   push eax
// 0082d8fe  8b442418             mov eax, dword ptr [esp + 0x18]
// 0082d902  50                   push eax
// 0082d903  51                   push ecx
// 0082d904  e813cafdff           call 0x80a31c
// 0082d909  8b8894000000         mov ecx, dword ptr [eax + 0x94]
// 0082d90f  8b09                 mov ecx, dword ptr [ecx]
// 0082d911  e8bafeffff           call 0x82d7d0
// 0082d916  c21400               ret 0x14
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPOffice2003Theme.cpp (function ?Draw@CImageList@@QAEHPAVCDC@@HUtagPOINT@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPOffice2003Theme.cpp
