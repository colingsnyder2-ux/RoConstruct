// from server: 100% by auto
// roc 2009-12 008e1fb0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e1fb0
//
// 008e1fb0  53                   push ebx
// 008e1fb1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008e1fb5  56                   push esi
// 008e1fb6  8bf1                 mov esi, ecx
// 008e1fb8  3bf3                 cmp esi, ebx
// 008e1fba  7505                 jne 0x8e1fc1
// 008e1fbc  e84b1bf1ff           call 0x7f3b0c
// 008e1fc1  8b4308               mov eax, dword ptr [ebx + 8]
// 008e1fc4  57                   push edi
// 008e1fc5  8b7e08               mov edi, dword ptr [esi + 8]
// 008e1fc8  6aff                 push -1
// 008e1fca  03c7                 add eax, edi
// 008e1fcc  50                   push eax
// 008e1fcd  e8ce33f7ff           call 0x8553a0
// 008e1fd2  8b4b08               mov ecx, dword ptr [ebx + 8]
// 008e1fd5  8b5304               mov edx, dword ptr [ebx + 4]
// 008e1fd8  8b4604               mov eax, dword ptr [esi + 4]
// 008e1fdb  51                   push ecx
// 008e1fdc  52                   push edx
// 008e1fdd  8d0cb8               lea ecx, [eax + edi*4]
// 008e1fe0  51                   push ecx
// 008e1fe1  e89aeffaff           call 0x890f80
// 008e1fe6  8bc7                 mov eax, edi
// 008e1fe8  5f                   pop edi
// 008e1fe9  5e                   pop esi
// 008e1fea  5b                   pop ebx
// 008e1feb  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarEventLabel.cpp (function ?Append@?$CArray@II@@QAEHABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarEventLabel.cpp
