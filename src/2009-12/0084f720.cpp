// from server: 100% by auto
// roc 2009-12 0084f720  unit: CXTPPropertyGrid  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084f720
//
// 0084f720  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0084f723  85c0                 test eax, eax
// 0084f725  750a                 jne 0x84f731
// 0084f727  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0084f72a  50                   push eax
// 0084f72b  ff15bccb9800         call dword ptr [0x98cbbc]
// 0084f731  50                   push eax
// 0084f732  e8f343faff           call 0x7f3b2a
// 0084f737  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0084f73b  8b542404             mov edx, dword ptr [esp + 4]
// 0084f73f  8b4020               mov eax, dword ptr [eax + 0x20]
// 0084f742  51                   push ecx
// 0084f743  52                   push edx
// 0084f744  68df2a0000           push 0x2adf
// 0084f749  50                   push eax
// 0084f74a  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0084f750  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SendNotifyMessageA@CXTPPropertyGrid@@UAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
