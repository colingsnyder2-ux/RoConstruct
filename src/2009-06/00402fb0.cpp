// from server: 100% by auto
// roc 2009-06 00402fb0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402fb0
//
// 00402fb0  8b442404             mov eax, dword ptr [esp + 4]
// 00402fb4  85c0                 test eax, eax
// 00402fb6  7e0a                 jle 0x402fc2
// 00402fb8  25ffff0000           and eax, 0xffff
// 00402fbd  0d00000780           or eax, 0x80070000
// 00402fc2  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function _HRESULT_FROM_WIN32)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
