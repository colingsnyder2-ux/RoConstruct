// from server: 100% by auto
// roc 2009-12 00809c80  unit: CXTPImageManagerResource::CBitmapDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809c80
//
// 00809c80  8b442408             mov eax, dword ptr [esp + 8]
// 00809c84  8b542404             mov edx, dword ptr [esp + 4]
// 00809c88  50                   push eax
// 00809c89  8b4104               mov eax, dword ptr [ecx + 4]
// 00809c8c  52                   push edx
// 00809c8d  50                   push eax
// 00809c8e  ff15f4b09800         call dword ptr [0x98b0f4]
// 00809c94  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?DeleteMenu@CMenu@@QAEHII@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
