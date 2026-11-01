// from server: 100% by auto
// roc 2009-12 00809da0  unit: CXTPImageManagerResource::CBitmapDC  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809da0
//
// 00809da0  8b442414             mov eax, dword ptr [esp + 0x14]
// 00809da4  8b542410             mov edx, dword ptr [esp + 0x10]
// 00809da8  8b4904               mov ecx, dword ptr [ecx + 4]
// 00809dab  50                   push eax
// 00809dac  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809db0  52                   push edx
// 00809db1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00809db5  50                   push eax
// 00809db6  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809dba  52                   push edx
// 00809dbb  50                   push eax
// 00809dbc  51                   push ecx
// 00809dbd  ff1500cb9800         call dword ptr [0x98cb00]
// 00809dc3  c21400               ret 0x14
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?DrawTextExA@CDC@@UAEHPADHPAUtagRECT@@IPAUtagDRAWTEXTPARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
