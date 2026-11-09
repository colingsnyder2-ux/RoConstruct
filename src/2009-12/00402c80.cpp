// from server: 100% by auto
// roc 2009-12 00402c80  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402c80
//
// 00402c80  8b442404             mov eax, dword ptr [esp + 4]
// 00402c84  85c0                 test eax, eax
// 00402c86  7e0a                 jle 0x402c92
// 00402c88  25ffff0000           and eax, 0xffff
// 00402c8d  0d00000780           or eax, 0x80070000
// 00402c92  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function _HRESULT_FROM_WIN32)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
